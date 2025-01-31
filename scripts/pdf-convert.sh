#!/bin/bash

for pdf in *.pdf; do
  convert -density 300 -background white -flatten -resize 1024x "$pdf" "${pdf%.pdf}.jpg"
done

