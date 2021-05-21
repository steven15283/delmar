#include <stdio.h>
#include <string>
#include <iostream>
#include "token.h"

using namespace std;

void Error(string message) {
	cout << message << endl;
	exit(EXIT_FAILURE);
}

void printToken(Token T) {
	cout << tokenNames[T.token] << " " << T.instance << "\tLine:" << T.lineNum << endl;
}


bool isKeyword(string id) {
	for (auto& keyword : keywords) {
		if (id == keyword)
			return true;
	}
	return false;
}

int column(char curchar) {

	if (isalpha(curchar)) {
		return 2;
	}
	if (isdigit(curchar)) {
		return 3;
	}
	if (isspace(curchar)) {
		return 21;
	}
	switch (curchar) {
	case '>':
	case '<':
	case ':':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '.':
	case '(':
	case ')':
	case ',':
	case '{':
	case '}':
	case ';':
	case '[':
	case ']':
		return 0;
	case '=':
		return 1;
	case EOF:
		return 4;
	case '@':
		return 19;
	default:
		return 18;
	}
}

void filter(FILE* fp) {
	int count = 1;
	char curChar;//char variable to hold next character

	curChar = fgetc(fp);

	while (curChar != EOF)
	{
		Token currentToken;
		states state = states::INIT;
		states nextState;
		Token token;
		string instance = "";

		while (state != FINL) {

			nextState = table[state][column(curChar)];
			if (nextState == ERRO)
				Error("SCANNER ERROR: " + to_string(count)); /* report and exit */
			if (nextState == FINL) {
				if (state == INIT) {//encounter a space
					if (curChar == EOF) {
						currentToken.lineNum = count;
						currentToken.token = EOF_tk;
						currentToken.instance = "EOF";
						printToken(currentToken);
						// here return to exit even from the outer loop
						return;
					}
					if (curChar == '\n')
						count++;
					//break;
				}

				if (state == IDEN) {// need reserved keyword lookup
					if (isKeyword(instance)) {
						currentToken.lineNum = count;
						currentToken.token = KW_tk;
						currentToken.instance = instance;
						printToken(currentToken);
						break;

					}
					else {// just an identifier
						currentToken.lineNum = count;
						currentToken.token = ID_tk;
						currentToken.instance = instance;
						printToken(currentToken);
						break;

					}
				}
				if (state == OPER || state == EQEQ) {
					currentToken.lineNum = count;
					currentToken.token = OP_tk;
					currentToken.instance = instance;
					printToken(currentToken);
					break;

				}
				if (state == INTG) {
					currentToken.lineNum = count;
					currentToken.token = NUM_tk;
					currentToken.instance = instance;
					printToken(currentToken);
					break;

				}
				if (state == ENDC)
					break;

			}
			// this is only reachable if not the end of a token, otherwise it will break before
			instance = instance + curChar;
			state = nextState;
			curChar = fgetc(fp);

		}

	}
	Token currentToken;
	states nextState;
	Token token;
	string instance = "";
		currentToken.lineNum = count;
		currentToken.token = EOF_tk;
		currentToken.instance = "EOF";
		printToken(currentToken);
		
	}

int main(int argc, char* argv[])
{
	FILE* fp;// this is for file read and writing

	if (argc == 1)// checks to see if there is only one argument when calling the program
	{

		cout << "enter strings to put into tree" << endl;
		fp = stdin;
		filter(fp);
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
		}
		fclose(fp);

	}
	else
	{
		cout << "Incorrect command line arguement" << endl;
		return EXIT_FAILURE;
	}
	return 0;
}


