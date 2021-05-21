#pragma warning(disable : 4996)
#include "scanner.h"
#include "parser.h"
#include "token.h"
#include "semantics.h"
//using namespace std;

FILE* op;
int main(int argc, char* argv[])
{
	string filename;//this string is to store the file name
	FILE* fp;// this is for file read and writing

	if (argc == 1)// checks to see if there is only one argument when calling the program
	{

		//cout << "enter strings to put into tree" << endl;
		fp = stdin;
		filter(fp);
		op = fopen("kb.asm", "w");
		Node* root = parser();
		cout<<"kb.asm"<<endl;
		//printTree(root, 1);
		fclose(fp);
	}
	else if (argc == 2)// checks to see if there's two arguements, which means that teh second argument should have a file name
	{

		//if fp doesnt open, output error message
		if (!fp)
		{
			perror("File opening failed");
			return EXIT_FAILURE;
		}

		else
		{
			string temp = argv[1];//this holds the file name from the argument
                	int dot = temp.find('.');//this finds the position of the . , so i can cut out the extention
                	filename = temp.substr(0, dot)+".asm";//trunkates the extention so i only get the filename

                	op = fopen(filename.c_str(), "w");
               		fp = fopen(argv[1], "r");//opens the file

			filter(fp);
				
			Node* root = parser();
			cout<<filename<<endl;
			//cout << "scope: ";
			//printScope();
			//printTree(root, 1);
		}
		fclose(fp);

	}
	else
	{
		//cout << "Incorrect command line arguement" << endl;
		return EXIT_FAILURE;
	}
	return 0;
}


