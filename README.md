# rshell
Assignment 3


# Installation
In order to run our program please run the following commands

1) git clone https://github.com/ralme002/rshell.git

2) cd rshell

3) git checkout hw3

4) make

5) ./bin/rshell

# Introduction

For this assignment we are emulating a shell terminal. When rshell is executed the program takes in user input in the form of commands.
These commands are can be single commands, or multiple commands; the program differantiates between the two of them running the correct command. The program is designed to execute the commands entered by the user, any errors will be displayed so the user can see what went wrong. The test command can be used to check wether or not a file or directory exist. Using test -e ..directory/file.txt we can test if file.txt exits in the directory. We can use -f to check if it exist and is a file and -d to check if it exits and is a directory. These commands will return (true) if they meet the requirements or (false) if they do not. We also included the parentheses precedence in order to group commands together and have them return to the root wether or not a command passed within the parentheses, after that we are able to continue throught he root. This will also work with nested parentheses and will execute them in the same way through recursion.



# Known Bugs

When && and || commands are entered together ex:" ls -a && || pwd" the program will crash. Parentheses must be treated as acommand, in the sense that they need to be in between the connectors. The test command needs to be treated the same way or else it will change the order that the algorithm takes and will crash. 
