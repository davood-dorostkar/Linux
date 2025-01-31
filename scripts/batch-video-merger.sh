#!/bin/bash
speed=20
while getopts s: flag
do
    case "${flag}" in
        s) speed=${OPTARG};;
    esac
done

rm audio -r &> /dev/null
rm speed -r &> /dev/null
rm list.txt &> /dev/null
rm result.mp4 &> /dev/null
mkdir audio
mkdir speed
files=`find . -name "*.mp4" -printf '%h\0%d\0%p\n' | sort -t '\0' -n | awk -F '\0' '{print $3}'`
totalFilesCount=$(find . -name "*.mp4" | wc -l)

var=1
for f in $files; do
  echo "Processing: " $var "of" $totalFilesCount
  echo $((100*$var/totalFilesCount)) "%"
  Path=`realpath $f`
  echo  "Current File:" $Path
  BaseName="$(basename -- $Path)"
  ffmpeg -hide_banner -loglevel error -hwaccel cuda -i $Path -c copy -an audio/$BaseName
  if [ $? -ne 0 ]
  then
    echo "Error in audio of" $BaseName
    echo "Error in audio of" $BaseName  >> errorLog.txt 
  fi
  ffmpeg -hide_banner -loglevel error -hwaccel cuda -i audio/$BaseName -filter:v "setpts=PTS/$speed" "speed/$var.mp4"
  if [ $? -ne 0 ]
  then
    echo "Error in speed up of" $BaseName
    echo "Error in speed up of" $BaseName  >> errorLog.txt 
  fi
  ((var++))
  done

speedupfiles=`ls ./speed -1v`
dir=`pwd`
for f in $speedupfiles; do
  Path=$dir"/speed/"$f
  echo "Appending: "$Path

#   ## FOR WINDOWS ONLY
  removedHead="${Path:2}"
  echo "file '$(echo $removedHead | sed -e 's/^/c:/')'">> list.txt

#   ## FOR LINUX ONLY
#   # echo  file "'$Path'" >> list.txt
  done

echo "Merging all files together"
ffmpeg -hide_banner -loglevel error -hwaccel cuda -f concat -safe 0 -i list.txt -c copy result.mp4
if [ $? -ne 0 ]
then
  echo "Error in concatenation"
  echo "Error in concatenation" >> errorLog.txt 
fi
rm speed -r
rm audio -r
rm list.txt
echo  "Finished Rendering"