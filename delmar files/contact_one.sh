#!/bin/bash
#steven guo
# this program uses a here document and reads a pattern from the user using grep into a until loop


#grep <<HERE
#John Doe, jdoe@great.com, 800-555-1111, California
#Jane Doe, jand@super.edu, 876-555-1321, New York
#John Smith, bsmith@fast.net, 780-555-1234, Florida
#Paul Wang, pwang@cs.kent.edu, 330-672-9050, Ohio
#HERE

echo "enter the string you want to search for"
read input
until [[ $input == "quit" ]]
do 

 
grep -i "$input" <<HERE
John Doe, jdoe@great.com, 800-555-1111, California
Jane Doe, jand@super.edu, 876-555-1321, New York
John Smith, bsmith@fast.net, 780-555-1234, Florida
Paul Wang, pwang@cs.kent.edu, 330-672-9050, Ohio
HERE

echo "enter another string you want to look for.Type quit to exit" 
read input
done
