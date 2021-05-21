#pragma warning(disable : 4996)
#include "scanner.h"
#include "parser.h"
#include "token.h"
#include "semantics.h"
//using namespace std;


int main(int argc, char* argv[])
{

	FILE* fp;// this is for file read and writing

	if (argc == 1)// checks to see if there is only one argument when calling the program
	{

		//cout << "enter strings to put into tree" << endl;
		fp = stdin;
		filter(fp);
		Node* root = parser();
		//printTree(root, 1);
		fclose(fp);
	}
	else if (argc == 2)// checks to see if there's two arguements, which means that teh second argument should have a file name
	{

		fp = fopen(argv[1], "r");//opens the file

		//if fp doesnt open, output error message
		if (!fp)
		{
			perror("File opening failed");
			return EXIT_FAILURE;
		}

		else
		{
			filter(fp);

			Node* root = parser();
			cout << "scope: ";
			printScope();
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


