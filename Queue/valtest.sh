#!/bin/bash

touch memcheck.txt
valgrind --leak-check=full chrisTest &>> memcheck.txt
valgrind --leak-check=full test1to4 &>> memcheck.txt

grep "ERROR SUMMARY\| Command: " memcheck.txt
rm memcheck.txt
