#!/bin/bash

valgrind --leak-check=full testPut 
printf "\n\n\n\n"
valgrind --leak-check=full testGet
printf "\n\n\n\n"
valgrind --leak-check=full testApply
printf "\n\n\n\n"
<<<<<<< HEAD
valgrind --leak-check=full testRemove
=======
valgrind --leak-check=full testRemove
printf "\n\n\n\n"
>>>>>>> 9bfdde1b544839566080d017a92d492872b49dbd
