#!/bin/sh

echo
echo
echo
echo "\t\t\t[~WITHOUT INFILE~]"
echo

ARG='./pipex'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

ARG='./pipex infile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

ARG='./pipex infile cat'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

ARG='./pipex infile cat cat'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

ARG='./pipex infile cat cat outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo

echo The quick brown fox jumps over norminette > infile
echo
echo
echo
echo "\t\t\t[~WITH INFILE~]"
echo


ARG='./pipex infile cat cat outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo outfile: | cat outfile
echo

ARG='./pipex infile "grep -o fox.*" cat outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"
echo outfile: | cat outfile
echo

ARG='./pipex infile "grep -o fox.*" catcat outfile'
echo $ARG; eval $ARG
valgrind $ARG > tmp 2>&1
cat tmp | grep -a "ERROR"; cat tmp | grep -a "no leaks"

rm infile
rm outfile
rm tmp
