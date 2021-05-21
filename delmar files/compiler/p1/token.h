#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <vector>
using namespace std;



enum tokenID { ID_tk, NUM_tk, KW_tk, OP_tk, EOF_tk };

vector < string > tokenNames = { "Identifier", "Number", "Keyword", "Operation", "End of file" };

enum states { INIT, OPER, IDEN, INTG, COMM, EQEQ, ENDC, ERRO, FINL };

vector < string > keywords = { "begin", "end", "loop", "void", "var", "return", "in", "out", "program", "iffy", "then", "let", "data" };

states table[7][22]={ {OPER, OPER, IDEN, INTG, FINL, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, OPER, ERRO, COMM, FINL, FINL},
					{  FINL, EQEQ, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
					{  FINL, FINL, IDEN, IDEN, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
					{  FINL, FINL, FINL, INTG, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
					{  COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, COMM, ENDC, COMM, COMM},
					{  FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL},
					{  FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL, FINL}};


/*index	>	=	L	D	EOF	<	:	+	-	*	.	(	)	,	{	}	[	]	others	@	newLine	WS
0(init_st)	1	1	2	3	final EOF_tk	1	1	1	1	1	1	1	1	1	1	1	1	1	error	4	0	0
1(op_st)	final op_tk	5	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk
2(id_st)	final id_tk	final id_tk	2	2	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk	final id_tk
3(int_st)	final int_tk	final int_tk	final int_tk	3	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk	final int_tk
4(comment_st)	4	4	4	4	4	4	4	4	4	4	4	4	4	4	4	4	4	4	4	0	4	4
5(==_st)	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk	final op_tk
*/
struct Token
{
	tokenID token;
	string instance;
	int lineNum;
};
#endif
