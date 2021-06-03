#include "node.h"
#include "Tree.h"

int main(int argc, char* argv[])
{
	string filename;//this string is to store the file name
	Tree *obj = new Tree;// this initializes the obj tree 
	FILE* fp;// this is for file read and writing
	node* root = nullptr;// declare root
	
	if(argc == 1)// checks to see if there is only one argument when calling the program
	{
		
		cout << "enter strings to put into tree" << endl;
		fp = stdin;
		char c;//char variable to hold next character
		string word = "";//holds each word
		while ((c = fgetc(fp)) != EOF)// loop until EOF
		{

			if (!isspace(c))//if c is not a space append char to word
			{
				word = word + c;
			}

			else//c is a space so send word into tree
			{
				obj->buildTree(word);
				word = "";// reset word for next word
			}

		}
		fclose(fp);
		
		//obj->printPreorder(root,"output.Preorder");//prints tree in preorder traversal
		//obj->printPostorder(root, "output.Postorder");//prints tree in postorder traversal
		obj->printInorder(obj->getRoot(), "output.Inorder");//prints tree in inorder traversal
	}
	else if (argc == 2)// checks to see if there's two arguements, which means that teh second argument should have a file name
	{
		
		string temp = argv[1];//this holds the file name from the argument
		int dot= temp.find('.');//this finds the position of the . , so i can cut out the extention
		filename = temp.substr(0, dot);//trunkates the extention so i only get the filename

		fp = fopen(argv[1], "r");//opens the file

		//if fp doesnt open, output error message
		if (!fp)
		{
			perror("File opening failed");
			return EXIT_FAILURE;
		}
    
		else
		{
			char c;//char variable to hold next character
			string word = "";//holds each word
			cout<<"break"<<endl;
			while ((c = fgetc(fp)) != EOF)// loop until EOF
			{

				if (!isspace(c))//it c is a space append char to word
				{
					word = word + c;
				}

				else//c is a space so send word into tree
				{
					obj->buildTree(word);
					cout<<word<<" "<<endl;
					word = "";// reset word for next word
				}

			}
			fclose(fp);

			//obj->printPreorder(root, filename+".Preorder");//prints tree in preorder traversal, we send in the 
			//obj->printPostorder(root, filename+".Postorder");//prints tree in postorder traversal
			obj->printInorder(obj->getRoot(), filename+".Inorder");//prints tree in inorder traversal
		}
		
			
		
	}
	else
	{
		cout<<"Incorrect command line arguement"<<endl;
		return EXIT_FAILURE;
	}
	
}
