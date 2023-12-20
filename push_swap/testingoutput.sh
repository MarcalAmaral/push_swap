#! /bin/bash

PROGRAM=./test3

GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"
S1="======================="

# Testing one param
printf "$YELLOW	test00\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22
printf "$RESET"

# Testing one invalid param with char
printf "\n$YELLOW	test01\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM d22
printf "$RESET"

# Testing with mult params (char)
printf "\n$YELLOW	test02\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 2121 2132 dwdarr[j]
printf "$RESET"

# Testing with mult params (char) passing in one string
printf "\n$YELLOW	test03\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM "22 2121 2132 dwd"
printf "$RESET"

# Testing with mult params (duplicated) passing in one string
printf "\n$YELLOW	test04\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM "22 2121 2132 2121"
printf "$RESET"

# Testing with mult params (duplicated)
printf "\n$YELLOW	test05\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 2121 2132 2121
printf "$RESET"

# Testing with mult params passing in one string
printf "\n$YELLOW	test06\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM "22 2121 --2132"
printf "$RESET"

# Testing with mult params passing in one string
printf "\n$YELLOW	test07\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 2121 --2132
printf "$RESET"


# Testing with mult params passing in one value == 0
printf "\n$YELLOW	test08\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 2121 --2132
printf "$RESET"