#! bin/bash

cc -g ./tests/implement_movements/*.c -o test4 lib/libft/libft.a

PROGRAM=./test4

GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"
S1="======================="

# Testing swap mov in stack
printf "$YELLOW	test00\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 11 33
printf "$RESET"

# Testing swap mov in stack
printf "$YELLOW	test01\n"
printf "$GREEN$S1$RESET\n"

printf "$BLUE    Program output\n"
$PROGRAM 22 33
printf "$RESET"
