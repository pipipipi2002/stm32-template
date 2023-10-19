#!/bin/zsh
echo "Starting setup"
echo "Initialising Git Repository"
git init

echo "Importing libopencm3"
git submodule add https://github.com/libopencm3/libopencm3 

echo "compile libopencm3"
cd ./libopencm3
make

cd ..
echo "completed"