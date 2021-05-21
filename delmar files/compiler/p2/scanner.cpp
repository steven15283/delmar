#include "scanner.h"

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
						//printToken(currentToken);
						tokenList.push_back(currentToken);
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
						//printToken(currentToken);
						tokenList.push_back(currentToken);
						break;

					}
					else {// just an identifier
						currentToken.lineNum = count;
						currentToken.token = ID_tk;
						currentToken.instance = instance;
						tokenList.push_back(currentToken);
						//printToken(currentToken);
						break;

					}
				}
				if (state == OPER || state == EQEQ) {
					currentToken.lineNum = count;
					currentToken.token = OP_tk;
					currentToken.instance = instance;
					tokenList.push_back(currentToken);
					//printToken(currentToken);
					break;

				}
				if (state == INTG) {
					currentToken.lineNum = count;
					currentToken.token = NUM_tk;
					currentToken.instance = instance;
					tokenList.push_back(currentToken);
					//printToken(currentToken);
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
	tokenList.push_back(currentToken);
	//printToken(currentToken);
	


}