#!/bin/bash

if [[ ${#} != 1 ]]; then
    echo "Please enter a file name which contains the marks data."
    echo "Example usage: ./2_compute-grades.sh student-marks.csv"
    exit 1
fi

computeGrade() {
    if (( $(echo "${1} >= 85" | bc) )); then
        grade="A"
    elif (( $(echo "${1} >= 75" | bc) )); then
        grade="A-"
    elif (( $(echo "${1} >= 65" | bc) )); then
        grade="B"
    elif (( $(echo "${1} >= 55" | bc) )); then
        grade="B-"
    elif (( $(echo "${1} >= 40" | bc) )); then
        grade="C"
    else
        grade="F"
    fi
    
    echo "${grade}"
}

filename="${1}"
echo "Name,Percentage,Grade"
{
    # eat up first line consisting of headers
    read
    while read line ; do
        name=$(echo "${line}" | cut -d',' -f1)
        marks1=$(echo "${line}" | cut -d',' -f2)
        marks2=$(echo "${line}" | cut -d',' -f3)
        marks3=$(echo "${line}" | cut -d',' -f4)
        
        percentage=$( echo "scale=2; (${marks1} + ${marks2} + ${marks3})/3" | bc )
        studentgrade=$(computeGrade "${percentage}")
        
        echo "${name},${percentage},${studentgrade}"
    done
} < "${filename}"
