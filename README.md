# rshell
Assignment 2


# Installation

In order to run our program please run the following commands

git clone https://github.com/ralme002/rshell.git

cd rshell

git checkout hw2

make

./bin/rshell

# Introduction

For this assignment we are emulating a shell terminal. When rshell is executed the program takes in user input in the form of commands. These commands are can be single commands, or multiple commands; the program differantiates between the two of them running the correct command. The program is designed to execute the commands entered by the user, any errors will be displayed so the user can see what went wrong.

# Known Bugs

When && and || commands are entered together ex:" ls -a && || pwd" the program will crash. We are currently resolving this "feature".
