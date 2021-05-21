#!/bin/bash
#Steven Guo 
#This script prints out numbers from 1- (30<= user inputted number <=60)that are#divisible by 5 and 15

# this command gets the number that the user wants that is < than 60 
echo "enter the number that is > 30 and < than 60"
read n
#this loop keeps repeating until it goes from 1 - n
for (( i=n; 1<=i;i-- ))
do
#this if statement checks if the number i is divisible by 5
	if (( $i % 5 == 0 ))
	then
#this nested loop checks if it its divisible by 5 and 3 
		if (( $i % 3 == 0 ))
		then
#this then and else statement prints out the numbers divisible by 5 or 15
			echo "$i is divisible by 15"
		else
			echo "$i is divisble by 5"
		fi
	fi
done		 
