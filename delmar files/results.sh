#!/bin/sh
#steven guo
#this program determines if participants in some competition made it to the finals
#Numbers of participants
echo "Enter the total number of participants: "
read n
#this loop gets the infomation for each participant
while [ $n -gt 0 ]
do
#this is getting the information
echo "Enter name: "
read name
echo "Enter the 1st judge score: "
read score1
echo "Enter the 2nd judge score: "
read score2
echo "Enter the 3rd judge score: "
read score3
#this command gets the sum

sum=`expr $score1 + $score2 + $score3`
point=3
#this command calculates the average
avg=`echo "$sum / $point" | bc -l`

echo 
limit=7.5

#This if statement checks if the average is above or below 7.5
if [ 1 -eq "$(echo "${avg} > ${limit}" | bc)" ]
then
echo "$name $score1 $score2 $score3 Average: $avg Good luck tomorrow".
else
echo "$name $score1 $score2 $score3 Average: $avg better luck next time"
fi

#this counts down n so it can get out of the loop
n=`expr $n - 1`
done

