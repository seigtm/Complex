#! /bin/bash

# Usage example: sudo ./deploy.sh executable lib ./test

# Variables.
EXECUTABLE=$1   # Path to executable (ComplexExample).
LIB=$2          # Path to library (libComplex.so).
DESTINATION=$3  # Destination folder.

echo "$EXECUTABLE $LIB $DESTINATION"

# If passed arguments number is not equal to 3.
if [[ $# -ne 3 ]]; then
    echo "[ERROR] > Illegal number of params. Expected executable, library and destination folder."
    exit 2
fi

# Create directory if it doesn't exist.
if [[ ! -d $EXECUTABLE ]]; then
    mkdir -p "$DESTINATION"
fi

# Copy files to this directory.
cp -fr "$EXECUTABLE" "$DESTINATION"
cp -fr "$LIB" "$DESTINATION"
