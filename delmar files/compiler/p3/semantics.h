#pragma once
#ifndef SEMANTICS_H
#define SEMANTICS_H
#include "token.h"

void insert(Token var);
bool verify(Token var);
Token use(Token var);
void printScope();
extern vector<Token> scope; //scope of vars


#endif