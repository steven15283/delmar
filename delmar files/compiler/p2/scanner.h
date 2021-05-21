#pragma once
#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"

void filter(FILE* fp);
void Error(string message);
void printToken(Token T);
bool isKeyword(string id);
int column(char curchar);
#endif
