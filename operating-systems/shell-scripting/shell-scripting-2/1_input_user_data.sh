#!/bin/bash

echo -n "Enter your Name: "
read name

echo -n "Enter your age: "
read age

echo -n "Enter your profession: "
read profession

echo

filename="${name}.txt"

echo "=> Entered user data:"
echo "Name: ${name}" | tee ${filename}
echo "Age: ${age}" | tee -a ${filename}
echo "Profession: ${profession}" | tee -a ${filename}
echo "=> Saved user data to ${filename}."
