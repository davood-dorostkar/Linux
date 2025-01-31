#!/bin/bash

# ffmpeg -i sc.webm -vf "setpts=PTS/10" -b:v 2000k -r 25 agv-1.mp4
# ffmpeg -hwaccel cuda -hwaccel_output_format cuda -i  -vf "setpts=PTS/4" -c:v h264_nvenc -r 25 output1.mp4
for file in *.webm; do
    ffmpeg -i "$file" -b:v 500k -s 1280x720 -r 25 "${file%.webm}.mp4"
done
