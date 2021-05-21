#!/bin/bash
#Steven Guo
#This script outputs the name of the script,the usage message, current date and #time, name of the user, name of current working directory,name of unix machine,#name of login shell, contents of required file, total number of parameters of
#script, calendar for october of current year,disk usage, current number of user#in system, and current time.

#this is the usage message
USAGE="$0 [name of file] [name of directory]"


#this is the conditional statement to check if the script was used properly
#it outputs usage message if there are not 2 command line parameters
if [[ $# != 2 ]]
   then
	echo "$USAGE"
	exit 1;
fi


#this command prints out the name of the script
echo This is the name of the script:

echo "$0"

#this command prints out the date and time
now=$(date)
echo "the date right now is $now"

#this command prints out the name of the user
curUser=$USER

echo "the current user is $curUser"

#this command prints out the current working directory
curDir=$PWD

echo "the current working directory is $curDir"

#this command prints out the name of the unix machine

echo "the unix machine is $HOSTNAME"

#this command prints the name of the login shell
echo "the name of the login shell is $SHELL"

#this command outputs the contents of the required file
echo "file $1 contains this:"
cat "$2/$1"

#This command outputs the listing of the directory
echo "this is the listing of directory $2"
ls "$2"

#this command shows the total number of parameters of the script
echo "The total number of parameters is: $#"

#this command shows the calendar for october of the current year
echo "this is the calendar for october of 2018"

cal 10 2018

#this command shows the disk usage 
echo "this is the disk usage"
df
