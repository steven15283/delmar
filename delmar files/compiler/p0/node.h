#ifndef NODE_H
#define NODE_H

#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define nullptr 0
using namespace std;

//this is the binary tree
struct node
{
	
	int length;//this holds the length of strings that are at the node
	vector <string> words;//this holds all the strings that have the specific length
	node* Left_link = nullptr;//points to left link
	node* Right_link = nullptr;//points to right link
};


#endif
