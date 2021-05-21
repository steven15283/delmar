#pragma once
#ifndef PARSER_H
#define PARSER_H
#include "token.h"
Token scanner();
Node* parser();
Node* program();
Node* block();
Node* vars();
Node* expr();
Node* n();
Node* a();
Node* m();
Node* r();
Node* stats();
Node* mStat();
Node* stat();
Node* in();
Node* out();
Node* IF();
Node* loop();
Node* assign();
Node* ro();

string newName();
string newVar();
#endif
