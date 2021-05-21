#!/bin/bash
#steven Guo 
#this program  presents a user with information about a given file or directory. it checks to see what type of file it is also.

#this function shows the information on the file
function FileInfo()
{
if [ -e "$i" ]
then
echo "$i exists"
FileType
else
exit 1
fi
}

#this function checks what type of file it is
function FileType()
{
if [ -f "$i" ]
then
echo "$i is a regular file"
elif [ -d "$i" ]
then
echo "$i is a directory file"
else
echo "$i is a special file"
fi
}
#this takes the number of parameter inputs and checks for the usage
if [ "$#" -eq 0 ]
then
echo "Incorrect input. Usage: bash fileInfo.sh {file1}{file2}{file3}{file etc}"
exit 1
else
#this is the loop to run all the parameter inputs through the functions
	for i in "$@"
	do
	FileInfo
	done
fi
