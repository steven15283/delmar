#!/bin/bash
#Steven Guo
#this program lists the empty directories of the given directory.

#this is usage line
USAGE="wrong usage format is bash listEmptyDir.sh  {directory}"

#this checks for usage
[ $# -lt 1 ] && echo "$USAGE" && exit 1


#this loops through directory for files
for file in "$1"/* 
do 	
#this checks if the file is a directory or not
if [ -d "$file" ]
then
	#this checks if the directory is empty or not
	if [ "$(ls -A $file)" ];
	then
	echo "$file is not empty"
	else
	echo "$file is empty"
	#this prints the empty directory name to emptydir.txt
	echo "$file" >> EmptyDir.txt
	fi
fi
done


