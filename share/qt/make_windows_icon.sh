#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/yescoin.png
ICON_DST=../../src/qt/res/icons/yescoin.ico
convert ${ICON_SRC} -resize 16x16 yescoin-16.png
convert ${ICON_SRC} -resize 32x32 yescoin-32.png
convert ${ICON_SRC} -resize 48x48 yescoin-48.png
convert yescoin-16.png yescoin-32.png yescoin-48.png ${ICON_DST}

