#!/bin/bash

EXTRA_DEPS=(cmake g++)

echo 'Installing dependencies...'

for dep in "${EXTRA_DEPS[@]}"
do
    sudo apt-get install $dep
done

git clone https://github.com/google/googletest.git test/googletest
make -C test/googletest/googletest/make gtest.a
mkdir test/lib
cp test/googletest/googletest/make/gtest.a test/lib
