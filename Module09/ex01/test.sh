#!/bin/bash
# Color code
# Where there is a '1' before the semi-colon this means that the color is BOLD (1), otherwise not bold (0)
RED="\033[1;31m"
GREEN="\033[0;32m"
LIGRAY="\e[37m"
YELLOW="\033[0;33m"
RESET="\033[0m\n"

# TEST FOR COLORS 
printf "\n\n\e[1;94m------TESTING FOR COLORS------\e[0m\n\n"
printf "\n\033[0;33mThis text is in YELLOW: \033[0;33m2000 1000\033[0m\n"
printf ${YELLOW}"This text is in YELLOW: ${YELLOW}2000 1000"${RESET}

# COMPILING THE PROGRAM
printf "\n\n\e[1;94m------COMPILING THE PROGRAM-----\e[0m\n\n"
make 

#TESTING BASIC CASES OF PDF"
printf "\n\n\e[1;94m------TESTING BASIC CASES OF PDF ------\e[0m\n\n"
printf "\033[1;31mThis is the test  with expression (8 9 * 9 - 9 - 9 - 4 - 1 +): \033[0;32m  \033[0m\n\n"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

printf "\033[1;31mThis is the test  with expression (7 7 * 7 -): \033[0;32m  \033[0m\n\n"
./RPN "7 7 * 7 -"

printf "\033[1;31mThis is the test  with expression (1 2 * 2 / 2 * 2 4 - +): \033[0;32m  \033[0m\n\n"
./RPN "1 2 * 2 / 2 * 2 4 - +"

printf "\033[1;31mThis is the test  with expression (1 + 1): \033[0;32m  \033[0m\n\n"
./RPN "1 + 1"

#TESTING RNP contains numbers not only digit between 0-9"

printf "\n\n\e[1;94m------TESTING RNP expressions contains NUMBERS not only digits ------\e[0m\n\n"
printf "\033[1;31mThis is the test  with expression (41 9 * 9 - 9 - 9 - 4 - 1 +): \033[0;32m  \033[0m\n\n"
./RPN "41 9 * 9 - 9 - 9 - 4 - 1 +"

printf "\n\033[1;31mThis is the test  with expression (1 9 * 9 - 9 - 9 - 41 - 1 +): \033[0;32m  \033[0m\n\n"
./RPN "1 9 * 9 - 9 - 9 - 41 - 1 +"


printf "\n\n\e[1;94m------TESTING RNP expressions contains characters different than 0-9 and + - * / ------\e[0m\n\n"
printf "\033[1;31mThis is the test  with expression (1 9 * 9 - 9 - 9 - 4 - 1 - c +): \033[0;32m  \033[0m\n\n"
./RPN "1 9 * 9 - 9 - 9 - 4 - 1 - c +"

printf "\033[1;31mThis is the test  with expression (1 9 * 9 - 9 - 9  + ! - 4 - 1 - +): \033[0;32m  \033[0m\n\n"
./RPN "1 9 * 9 - 9 - 9  + ! - 4 - 1 - +"


printf "\n\n\e[1;94m------TESTING INVALID RNP Expression / ------\e[0m\n\n"
printf "\033[1;31mThis is the test  with expression (1 2 * 2 / 2 * 2 4 - + +): \033[0;32m  \033[0m\n\n"
./RPN "1 2 * 2 / 2 * 2 4 - + +"

printf "\033[1;31mThis is the test  with expression (+ 1 9 * 9 - 9 - 9 - 4 - 1 - +): \033[0;32m  \033[0m\n\n"
./RPN "+ 1 9 * 9 - 9 - 9 - 4 - 1 - +"

printf "\033[1;31mThis is the test  with expression (+ + 1 9 * 9 - 9 - 9 - 4 - 1 - +): \033[0;32m  \033[0m\n\n"
./RPN "+ + 1 9 * 9 - 9 - 9 - 4 - 1 - +"


printf "\n\n\e[1;94m------END OF TESTS------\e[0m\n\n"