#!/bin/bash

<<<<<<< HEAD
touch memcheck.txt
valgrind --leak-check=full testPut &>> memcheck.txt
valgrind --leak-check=full testGet &>> memcheck.txt
valgrind --leak-check=full testApply &>> memcheck.txt
valgrind --leak-check=full testRemove &>> memcheck.txt

grep "ERROR SUMMARY\| Command: " memcheck.txt
rm memcheck.txt
=======
valgrind --leak-check=full testPut 
printf "\n\n\n\n"
valgrind --leak-check=full testGet
printf "\n\n\n\n"
valgrind --leak-check=full testApply
printf "\n\n\n\n"
valgrind --leak-check=full testRemove
printf "\n\n\n\n"
>>>>>>> 767a730a01a8acbc43be5072cdc07a9378d9f553
