#!/bin/bash

valgrind --leak-check=full testPut 
printf "\n\n\n\n"
valgrind --leak-check=full testGet
printf "\n\n\n\n"
valgrind --leak-check=full testApply
printf "\n\n\n\n" 