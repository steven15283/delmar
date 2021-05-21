#ifndef TREE_H
#define TREE_H
#include<iomanip>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include"node.h"
#include <fstream>

using namespace std;

class Tree
{
private:
	node* root;
public:
	Tree();
	node *getRoot();

	void printInorder(node* rootP, string filename);// this prints the tree in inorder traversal
	void printPreorder(node* rootP, string filename);//this prints the tree in preorder traversal
	void printPostorder(node* rootP, string filename);//this prints the tree in postorder traversal
	void add(node* temp, string x, int length);//this takes a string to be put into the tree. temp is to point to the root. length is to specify what node to put the string into
	void buildTree(string x);//this gets the root and the string to be put into tree, it calls add with the length of the string
};

#endif
