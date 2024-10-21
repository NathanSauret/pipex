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

# normal without infile
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

# Not enough parameters
echo
echo empty > outfile
ARG='./pipex infile cat cat'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo "~"

#Too much parameters
echo
echo empty > outfile
ARG='./pipex infile cat cat outfile patapon'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

echo "~"

# nrmal with infile
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

# wrong first command
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

# wrong second command
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

# Wrong both commands
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

# empty first command
echo
echo empty > outfile
ARG='./pipex infile "" cat outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< infile "" | cat > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

# empty second command
echo
echo empty > outfile
ARG='./pipex infile cat "" outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< infile cat | "" > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

# empty both command
echo
echo empty > outfile
ARG='./pipex infile "" "" outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< infile "" | "" > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

# wrong infile
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

echo "~"

# wrong infile and wrong second command
echo
echo empty > outfile
ARG='./pipex wrong_infile cat wrong_command outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo
echo empty > outfile
ARG='< wrong_infile cat | wrong_command > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

# absolute command
echo
echo empty > outfile
ARG='./pipex infile cat /usr/bin/cat outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo empty > outfile
ARG='< infile cat | /usr/bin/cat > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo



echo
chmod 000 infile
echo "\t\t\t~~~ [WITH WRONG PERMISSIONS INFILE] ~~~"
echo

# normal wrong infile permissions
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

# normal wrong infile permissions and wrong second command
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
chmod 777 infile
chmod 000 outfile
echo "\t\t\t~~~ [WITH WRONG PERMISSIONS OUTFILE] ~~~"
echo

# normal wrong outfile permissions
echo
ARG='./pipex infile cat "echo write this anyway" outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
ARG='< infile cat | echo write this anyway > outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo



echo
chmod 777 outfile
echo "\t\t\t~~~ [WITHOUT PATH] ~~~"
echo

# without path with commands
echo
echo empty > outfile
ARG='env -i ./pipex infile cat cat outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo
echo

echo "~"

# without path with absolute commands
echo
echo empty > outfile
ARG='env -i ./pipex infile /usr/bin/cat /usr/bin/cat outfile'
echo $ARG; eval $ARG
echo -n "outfile: " && cat outfile
echo

rm infile
rm outfile