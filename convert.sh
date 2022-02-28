#!/bin/bash

while getopts s: flag
do
    case "${flag}" in
        s) speed=${OPTARG};;
    esac
done

rm audio -r
rm speed -r
rm list.txt
rm result.mp4
mkdir audio
mkdir speed
files=`find . -name "*.mp4" -printf '%h\0%d\0%p\n' | sort -t '\0' -n | awk -F '\0' '{print $3}'`
var= 1
((var++))
for f in $files; do
  Path=`realpath $f`
  echo  "rpth=" $Path
  BaseName="$(basename -- $Path)"
  echo "base= $BaseName"
  ffmpeg -hwaccel cuda -i $Path -c copy -an audio/$BaseName
  ffmpeg -hwaccel cuda -i audio/$BaseName -filter:v "setpts=PTS/$speed" "speed/$var.mp4"
  ((var++))
  done


speedupfiles=`find ./speed -type f -printf '%h\0%d\0%p\n' | sort -t '\0' -n | awk -F '\0' '{print $3}'`
for f in $speedupfiles; do
  Path=`realpath $f`

  ## FOR WINDOWS ONLY
  removedHead="${Path:2}" 
  echo "file '$(echo $removedHead | sed -e 's/^/c:/')'">> list.txt

  ## FOR LINUX ONLY
  # echo  file "'$Path'" >> list.txt
  done

ffmpeg -hwaccel cuda -f concat -safe 0 -i list.txt -c copy result.mp4
rm speed -r
rm audio -r
rm list.txt
echo  "finished"


