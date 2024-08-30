#!/bin/bash

clear


echo "Welcome to Pipex_Tester, by nsauret."
echo
echo "The outfile is refilled between each test, so if the outfile contain the word 'nothing' it means that pipex didn't wrote in it."
echo
echo
echo "--------------------------------------------------------------"
echo


rm infile > /dev/null 2>&1
echo "\t\t\t~~~ [WITHOUT INFILE] ~~~"
echo

echo
echo empty > outfile
ARG='./pipex infile cat cat outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< infile cat | cat > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo



echo The quick brown fox jumps over norminette > infile
echo "\t\t\t~~~ [WITH INFILE] ~~~"
echo

echo
echo empty > outfile
ARG='./pipex infile cat cat'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex infile cat cat outfile patapon'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex infile cat cat outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< infile cat | cat > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex infile wrong_command "echo write this anyway" outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< infile wrong_command | echo write this anyway > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< infile cat | wrong_command > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex infile wrong_command wrong_command outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< infile wrong_command | wrong_command > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex wrong_infile cat "echo write this anyway" outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< wrong_infile cat | echo write this anyway > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo
echo empty > outfile
ARG='./pipex wrong_infile cat wrong_command outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< wrong_infile cat | wrong_command > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo
chmod 000 infile
echo "\t\t\t~~~ [WITH WRONG PERMISSIONS INFILE] ~~~"
echo

echo
echo empty > outfile
ARG='./pipex infile cat "echo write this anyway" outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< infile cat | echo write this anyway > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo "~"

echo
echo empty > outfile
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< infile cat | wrong_command > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

chmod 777 infile
rm infile
rm outfile