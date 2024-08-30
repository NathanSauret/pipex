#!/bin/bash

clear


echo "Welcome to Pipex_Tester(Valgrind), by nsauret."
echo
echo "--------------------------------------------------------------"
echo



rm infile > /dev/null 2>&1
echo "\t\t\t~~~ [WITHOUT INFILE] ~~~"
echo

echo
ARG='./pipex infile cat cat outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo



echo The quick brown fox jumps over norminette > infile
echo "\t\t\t~~~ [WITH INFILE] ~~~"
echo

echo
ARG='./pipex infile cat cat'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex infile cat cat outfile patapon'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex infile cat cat outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex infile wrong_command "echo write this anyway" outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex infile wrong_command wrong_command outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex wrong_infile cat "echo write this anyway" outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo
ARG='./pipex wrong_infile cat wrong_command outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo



echo
chmod 000 infile
echo "\t\t\t~~~ [WITH WRONG PERMISSIONS INFILE] ~~~"
echo

echo
ARG='./pipex infile cat "echo write this anyway" outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo "~"

echo
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

chmod 777 infile
rm infile
rm outfile
rm tmp
