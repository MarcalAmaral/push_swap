#! bin/bash

PROGRAM=./test

GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"
S1="======================="

# ======================
printf "$YELLOW	test00\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 200 203 33 5 4 6
printf "$RESET"

# ======================
printf "$YELLOW	test01\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 -1 2 32 1 0
printf "$RESET"

# ======================

printf "$YELLOW	test01\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM "22 25 0 2 32 1"
printf "$RESET"


printf "$YELLOW	test01\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM "22 25 0 2 32 1"
printf "$RESET"

printf "$YELLOW	test01\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM "22 25 0 2 32 1  0 2 32 1"
printf "$RESET"