#include "token.h"
vector <Token> tokenList;
vector < string > tokenNames = { "Identifier", "Number", "Keyword", "Operation", "End of file" };
vector < string > keywords = { "begin", "end", "loop", "Node*", "var", "return", "in", "out", "program", "iffy", "then", "let", "data" };
states table[7][22] = { {OPER, OPER, IDEN, INTG, FINL, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, ERRO, COMM, FINL, FINL},
						{  FINL, EQEQ, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
						{  FINL, FINL, IDEN, IDEN, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
						{  FINL, FINL, FINL, INTG, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
						{  COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, ENDC, COMM, COMM},
						{  FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
						{  FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL} };