
#include "Tree.h"
Tree::Tree(){
	this->root = nullptr;
}

node* Tree::getRoot(){
	return this->root;
}

void Tree::printInorder(node* rootP , string filename)//prints inorder traverals of tree
{
	
		if (rootP == NULL)//when rootp is null it ends recursive loop
			return;
	
		ofstream op(filename);
		printInorder(rootP->Left_link, filename);//recursive loop to traverse to most left link
		op << setfill(' ') << setw(rootP->length);
		op << rootP->length << ": ";
		for (auto w : rootP->words)//this outputs all the strings in the node
		{
			cout<<w<< " "<<endl;
			op << w << " ";
		}
		op << endl;
		printInorder(rootP->Right_link, filename);// recursive loop to traverse to most right link
		op.close();
	
}
void Tree::printPreorder(node* rootP, string filename)// prints traversal of tree in preorder
{
		
		ofstream op(filename);
		if (rootP == NULL)
		{
			return;
		}
		else
		{
			cout <<"I should not be printed" << endl;
			op << setfill(' ') << setw(rootP->length);
			op << rootP->length << ": ";
			for (auto w : rootP->words)//this outputs all the strings in the node
			{
				op << w << " ";
			}
			op << endl;
			printPreorder(rootP->Left_link, filename);// recursive loop to traverse to most left link
			printPreorder(rootP->Right_link, filename);// recursive loop to traverse to most right link
		}
		op.close();
	
	
}
void Tree::printPostorder(node* rootP, string filename)//prints traversal of tree in postorder
{
	
		ofstream op(filename);
		if (rootP == NULL)
		{
			return;
		}
		else
		{
			printPostorder(rootP->Left_link, filename);// recursive loop to traverse to most left link
			printPostorder(rootP->Right_link, filename);// recursive loop to traverse to most right link
			op << setfill(' ') << setw(rootP->length);
			op << rootP->length << ": ";
			for (auto w : rootP->words)//this outputs all the strings in the node
			{
				op << w << " ";
			}
			op << endl;
		}
		op.close();
	
	
}
void Tree::add(node* temp, string x, int length)// adds in the string into the tree
{
	if (temp == NULL)
	{
		// create new node and assign it to temp
		node* newnode = new node;
		newnode->Left_link = NULL;
		newnode->Right_link = NULL;
		newnode->words.push_back(x);// pushes string into node
		newnode->length = length;//sets length
	}
	else if (temp->length < length)//compares string x length traverse tree to put in correct place
	{
		add(temp->Left_link, x, length);
	}
	else if (temp->length > length)//compares string x length traverse tree to put it in correct place
	{
		add(temp->Right_link, x, length);
	}
	else// this means that the lengths are equal
	{
		for (size_t i = 0; i < temp->words.size(); i++)// loops through the vector to check for duplicates
		{
			if (temp->words.at(i) != x)
			{
				temp->words.push_back(x);// if theres no duplicate then push into vector
			}
		}
		
	}
	
}
void Tree::buildTree( string x)// takes root and string to call add
{
	add(root, x, x.length());
}


