#!/bin/bash
argc=$#
argv=("$@")

function add(){
    #calc operands
    local sum=${argv[1]}
    for((ops=2;ops<$argc;ops++))
    do
        ((sum=sum + ${argv[ops]}))
    done
    echo $sum
}

function sub(){
    #calc operands
    local sum=${argv[1]}
    for((ops=2;ops<$argc;ops++))
    do
        ((sum=sum - ${argv[ops]}))
    done
    echo $sum
}

function mul(){
    #calc operands
    local sum=${argv[1]}
    for((ops=2;ops<$argc;ops++))
    do
        ((sum=sum * ${argv[ops]}))
    done
    echo $sum
}

function div(){
    #considering same behavious as --sub 1 2 3 = 1-(2+3)
    # --div 1 2 3 = 1/(2+3)
    local sum=${argv[1]}
    for((ops=2;ops<$argc;ops++))
    do
        ((sum=sum + ${argv[ops]}))
    done
    ((sum=sum-${argv[1]}))
    ((sum=${argv[1]}/sum))
    echo $sum
}

function exp(){
    #considering same behavious as --sub 1 2 3 = 1-(2+3)
    # --exp 1 2 3 = 1^(2+3)
    local sum=${argv[1]}
    for((ops=2;ops<$argc;ops++))
    do
        ((sum=sum + ${argv[ops]}))
    done
    ((sum=sum-${argv[1]}))
    ((sum=${argv[1]}**sum))
    echo $sum
}

if [ $argc -eq 0 ] 
then
    echo "No args"
    exit
elif [ $argc -eq 1 ]
then
    echo "supply operands"
    exit
elif [ $argc -eq 2 ]
then
    echo "supply more operands (+1)"
    exit
fi

re="^--"
if [[((${argv[0]} =~ $re))]]
then
    if [[((${argv[0]} == "--add"))]]
        then
        add
        exit
    elif [[((${argv[0]} == "--sub"))]]
        then
        sub
        exit
    elif [[((${argv[0]} == "--div"))]]
        then
        div
        exit
    elif [[((${argv[0]} == "--mul"))]]
        then
        mul
        exit
    elif [[((${argv[0]} == "--exp"))]]
        then
        exp
        exit
    else
        echo "Incorrect option"
    fi
else
    echo "use -- on option argument"
fi
