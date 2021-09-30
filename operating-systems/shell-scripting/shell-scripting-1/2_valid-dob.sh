#!/bin/bash

if [[ ${#} != 3 ]]; then
    echo "Error: please enter date of birth in the format: dd mm yyyy"
    exit 1
fi

isLeap() {
    if [[ $(( ${1} % 4 )) != 0 ]]; then
        echo "no"
        exit
    fi
    
    # non-centurial leap year
    if [[ $(( ${1} % 4 )) == 0 && $(( ${1} % 100 )) != 0 ]]; then
        echo "yes"
        exit
    fi
    
    # a centurial leap year must be divisible by 400
    if [[ $(( ${1} % 4 )) == 0 && $(( ${1} % 100 )) == 0 && $(( ${1} % 400 )) != 0 ]]; then
        echo "no"
        exit
    fi
    
    echo "yes"
}

dd="${1}"
mm="${2}"
yyyy="${3}"

# number of days in each month in a common year
num_days=(0 31 28 31 30 31 30 31 31 30 31 30 31)

# if it's a leap year, then there are 29 days in February
if [[ $(isLeap "${yyyy}") == "yes" ]]; then
    num_days[2]=29
fi


# number of months in a year
num_months=12

# if year is the current year, then it's a special case
if [[ ${yyyy} -eq $(date +%Y) ]]; then
    num_months=$(date +%m)
    num_days[num_months]=$(date +%d)
fi

if [[ ${yyyy} -ge 1 && ${yyyy} -le $(date +%Y) ]]; then
    if [[ ${mm} -ge 1 && ${mm} -le ${num_months} ]]; then
        if [[ (${dd} -ge 1) && (${dd} -le ${num_days[${mm}]}) ]]; then
            echo "${dd}-${mm}-${yyyy} is a valid date of birth!"
        else
            echo "Invalid DOB: month ${mm} has days in the range [1, ${num_days[${mm}]}] in year ${yyyy}."
        fi
    else
        echo "Invalid DOB: month must be in the range [1, ${num_months}] in the year ${yyyy}."
    fi
else
    echo "Invalid DOB: year must be in the range [1, $(date +%Y)]"
fi
