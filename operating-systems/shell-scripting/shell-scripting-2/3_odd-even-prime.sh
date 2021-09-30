#!/bin/bash

if [[ ${#} != 1 ]]; then
    echo "Please enter a file name which contains the numbers."
    echo "Example usage: ./3_odd-even-prime.sh numbers.txt"
    exit 1
fi

printOddNumbers() {
    echo "Printing odd numbers..."
    
    while read line ; do
        if [[ $((${line} % 2)) != 0 ]]; then
            echo -n "${line}, "
        fi
    done < "${filename}"
    
    echo
}

printEvenNumbers() {
    echo "Printing even numbers..."
    
    while read line ; do
        if [[ $((${line} % 2)) == 0 ]]; then
            echo -n "${line}, "
        fi
    done < "${filename}"
    
    echo
}

printPrimeNumbers() {
    echo "Printing prime numbers..."
    while read line ; do
        is_prime=true
        for((i=2; i<=${line}/2; i++))
        do
            if [[ $(( ${line} % i )) == 0 ]]
            then
                is_prime=false
                break
            fi
        done
        
        if [[ (${is_prime} == true) && (${line} != 1) ]]; then
            echo -n "${line}, "
        fi
        
    done < "${filename}"
    
    echo
}

filename=${1}

echo "=> What do you want to do?"
echo "1. Print odd numbers."
echo "2. Print even numbers."
echo "3. Print prime numbers."
echo "4. Exit"

while true; do
    echo "----------------------------"
    echo -n "Enter an option (1-4): "
    read option
    
    case ${option} in
        1)
            printOddNumbers
            ;;
        2)
            printEvenNumbers
            ;;
        3)
            printPrimeNumbers
            ;;
        4)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid option, try again!"
    esac
done
