#!/bin/bash
if [ $# -eq 0 ] 
then
    echo "No args"
    exit
elif [ $# -eq 1 ]
then
    echo "supply year"
    exit
fi

# take input as MM YY
if [[(((($1 -gt 12))||(($1 -lt 1))))]] 
then
    string='january february march april may june july august september october november december January February March April May June July August September October November December'
    if [[ $string == *$1* ]]; then
        echo -n 
    else
        echo "Invalid month"
        exit
    fi
elif [[(($2 -lt 1))]]
then
    echo "Invalid year"
    exit
fi
echo "The calendar for the month $1 in $2 is: "
cal $1 $2
