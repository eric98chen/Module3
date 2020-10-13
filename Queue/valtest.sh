#!/bin/bash
echo making object files and executables...
make &>> /dev/null

echo running valgrind...
valgrind --leak-check=full chrisTest &> memcheck.txt
grep "ERROR SUMMARY\| Command: \| no leaks are possible" memcheck.txt; echo
valgrind --leak-check=full test1to4 &> memcheck.txt
grep "ERROR SUMMARY\| Command: \| no leaks are possible" memcheck.txt; echo
valgrind --leak-check=full testQapply &> memcheck.txt
grep "ERROR SUMMARY\| Command: \| no leaks are possible" memcheck.txt; echo
valgrind --leak-check=full testQsearch &> memcheck.txt
grep "ERROR SUMMARY\| Command: \| no leaks are possible" memcheck.txt; echo
valgrind --leak-check=full testQremove &> memcheck.txt
grep "ERROR SUMMARY\| Command: \| no leaks are possible" memcheck.txt; echo
valgrind --leak-check=full testQconcat &> memcheck.txt
grep "ERROR SUMMARY\| Command: \| no leaks are possible" memcheck.txt; echo

rm memcheck.txt
echo making clean...
make clean &>> /dev/null
