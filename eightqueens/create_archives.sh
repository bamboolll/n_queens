#!/bin/bash

SOURCE=eightqueens
BASENAME=eightqueens
VERSION=$1

if [ -z "$VERSION" ]; then

	echo "Version number missing!"
	echo "Usage: $0 [version]"
	exit 1
fi

BZIP_ARCHIV="$BASENAME-${VERSION}.tar.bz2"
ZIP_ARCHIV="$BASENAME-${VERSION}.zip"

make clean && make distclean
cd ..
rm -f $BZIP_ARCHIV
rm -f $ZIP_ARCHIV

tar cvfj $BZIP_ARCHIV $SOURCE
echo "$BZIP_ARCHIV successfully created."

zip $ZIP_ARCHIV -r $SOURCE
echo "$ZIP_ARCHIV successfully created."

