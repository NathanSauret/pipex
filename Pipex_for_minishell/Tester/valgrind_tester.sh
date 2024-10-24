#!/bin/bash

clear


echo "Welcome to Pipex_Tester(Valgrind), by nsauret."
echo
echo "--------------------------------------------------------------"
echo



rm infile > /dev/null 2>&1
echo "\t\t\t~~~ [WITHOUT INFILE] ~~~"
echo

# normal without infile
echo
ARG='./pipex infile cat cat outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo



echo The quick brown fox jumps over norminette > infile
echo "\t\t\t~~~ [WITH INFILE] ~~~"
echo

# Not enough parameters
echo
ARG='./pipex infile cat cat'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# normal with infile
echo
ARG='./pipex infile cat cat outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# wrong first command
echo
ARG='./pipex infile wrong_command "echo write this anyway" outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# wrong second command
echo
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# wrong both commands
echo
ARG='./pipex infile wrong_command wrong_command outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# empty first command
echo
ARG='./pipex infile "" cat outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# empty second command
echo
ARG='./pipex infile cat "" outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# empty second command
echo
ARG='./pipex infile "" "" outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# wrong infile
echo
ARG='./pipex wrong_infile cat "echo write this anyway" outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# wrong infile and wrong second command
echo
ARG='./pipex wrong_infile cat wrong_command outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# absolute command
echo
ARG='./pipex infile /usr/bin/cat /usr/bin/cat outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo



echo
chmod 000 infile
echo "\t\t\t~~~ [WITH WRONG PERMISSIONS INFILE] ~~~"
echo

# normal wrong infile permissions
echo
ARG='./pipex infile cat "echo write this anyway" outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# normal wrong infile permissions and wrong second command
echo
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo



echo
chmod 777 infile
chmod 000 outfile
echo "\t\t\t~~~ [WITH WRONG PERMISSIONS OUTFILE] ~~~"
echo

# normal wrong outfile permissions and wrong second command
echo
ARG='./pipex infile cat wrong_command outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo



echo
chmod 777 outfile
echo "\t\t\t~~~ [WITHOUT PATH] ~~~"
echo

# without path with commands
echo
ARG='env -i ./pipex infile cat cat outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo "~"

# without path with absolute commands
echo
ARG='env -i ./pipex infile /usr/bin/cat /usr/bin/cat outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

echo
echo "\t\t\t~~~ [TIME TESTS] ~~~"
echo

# two sleeps
echo
echo empty > outfile
ARG='./pipex infile "" "sleep 1" "sleep 3" "echo write this anyway" outfile'
echo $ARG; eval valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --quiet $ARG
echo

rm infile
rm outfile
