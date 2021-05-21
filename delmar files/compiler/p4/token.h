#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
using namespace std;


// Enums, not variables
enum tokenID { ID_tk, NUM_tk, KW_tk, OP_tk, EOF_tk };
enum states { INIT, OPER, IDEN, INTG, COMM, EQEQ, ENDC, ERRO, FINL };
// Declaration of variables (with extern keyword) , not definition (without extern
extern vector < string > tokenNames;
extern vector < string > keywords;
extern states table[7][22];

struct Token
{
	tokenID token;
	string instance;
	int lineNum;
	Token() {}

	Token(const Token& another)
	{
		this->token = another.token;
		this->instance = another.instance;
		this->lineNum = another.lineNum;
	}

	bool operator==(const Token& token1)
	{
		return token1.instance == this->instance;
	}
};

struct Node {
	string label;
	Node* child1, * child2, * child3, * child4;
	Token* token1, * token2;
	Node() {
		label = "";
		child1 = NULL;
		child2 = child3 = child4 = NULL;
		token1 = token2 = NULL;
	}
};

extern vector<Token> tokenList;
extern Token tk;
extern vector<string> variables;
extern FILE* op;
#endif
