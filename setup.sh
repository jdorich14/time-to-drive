#!/bin/bash

EXTRA_DEPS=(cmake g++)

for dep in "${EXTRA_DEPS[@]}"
do
    echo $dep
done
