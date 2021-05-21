#include "parser.h"
#include "token.h"
#include "scanner.h"
#include "semantics.h"

Token tk;
vector<string> variables;
static int varCount = 0;
static int varLabel = 0;


Token scanner()
{
	static int i = -1;
	i++;
	return tokenList[i];
}

string newVar()
{
	string name = "T" + to_string(varCount++);
	variables.push_back(name + " 0");
	return name;
}
string newLabel() {
	string label = "L" + to_string(varLabel++);
	return label;
}

Node* parser() {
	Node* root = new Node();
	root->label = "parser";
	tk = scanner();
	root->child1 = program();
	if (tk.token == EOF_tk)
	{
		//cout << "semantics is done correctly" << endl;
		//printScope();
		fprintf(op,"STOP\n");
		fprintf(op, "\t TOUT 0\n"); //only uses one variable instead of calling a new temp variable everytime
		for (auto &var:variables)
			fprintf(op, "\t %s\n", var.c_str());
		return root;
	}
	else Error("tk received, EOFTk expected", tk.lineNum);

}

Node* program()
{
	Node* node = new Node();
	node->label = "program";

	node->child1 = vars();
	node->child2 = block();
	return node;
}
Node* block()
{
	Node* node = new Node;
	node->label = "block";

	if (tk.token == KW_tk && tk.instance == "begin")
	{
		tk = scanner();

		node->child1 = vars();
		node->child2 = stats();
		if (tk.token == KW_tk && tk.instance == "end")
		{
			tk = scanner();

			return node;
		}
		else
		{
			Error("expeted end keyword", tk.lineNum);
		}
	}
	else
	{
		Error("expected begin keyword", tk.lineNum);
	}
}
Node* vars()
{
	if (tk.token == KW_tk && tk.instance == "data")
	{
		Node* node = new Node;
		node->label = "vars";
		tk = scanner();
		string variable;
		if (tk.token == ID_tk)
		{
			insert(tk);
			node->token1 = new Token(tk);
			variable = node->token1->instance;
			tk = scanner();

			if (tk.token == OP_tk && tk.instance == "=")
			{
				tk = scanner();
				
				if (tk.token == NUM_tk)
				{
					node->token2 = new Token(tk);
					variable = variable + " " + node->token2->instance;
					variables.push_back(variable);
					tk = scanner();

					if (tk.token == OP_tk && tk.instance == ".")
					{
						tk = scanner();

						node->child1 = vars();
						return node;
					}
					else
						Error("expected . token", tk.lineNum);
				}
				else
					Error("expected number token", tk.lineNum);

			}
			else
				Error("expected = token", tk.lineNum);
		}
		else
			Error("expected identifier token", tk.lineNum);
	}
	else
		return NULL;
}
Node* expr()
{
	Node* node = new Node;
	node->label = "expr";

	node->child1 = n();
	if (tk.token == OP_tk && tk.instance == "-")
	{
		string var = newVar();
		fprintf(op, "\tSTORE\t%s\n", var.c_str());
		node->token1 = new Token(tk);
		tk = scanner();

		node->child2 = expr();
		fprintf(op, "\tMULT -1\n");
		fprintf(op, "\tADD\t%s\n", var.c_str());
		//multiply by -1 
		//same as node a

		// SUB var
		// subtract whatever in the acc - var
		// but what you have after child2 is the rhv in the acc
		// so if you want  to use sub, you need to save child2 into another var, say var2
		// then load var1 inot acc
		// then write the instruction sub var2
	}
	return node;


}
Node* n()
{
	
	Node* node = new Node;
	node->label = "n";

	node->child1 = a();
	//save a->var1
	if (tk.token == OP_tk && tk.instance == "/")
	{
		//same as expr 
		string var = newVar();
		fprintf(op, "\tSTORE\t%s\n", var.c_str());
		node->token1 = new Token(tk);
		tk = scanner();
		string var2 = newVar();
		node->child2 = n();
		//save n into var2 
		fprintf(op, "\tSTORE\t%s\n", var2.c_str());
		//then load var1 
		fprintf(op, "\tLOAD\t%s\n", var.c_str());
		//then div var2
		fprintf(op, "\tDIV\t%s\n", var2.c_str());
	}
	else if (tk.token == OP_tk && tk.instance == "*")
	{
		//same as a just change add-> mult
		string var = newVar();
		fprintf(op, "\tSTORE\t%s\n", var.c_str());
		node->token1 = new Token(tk);
		tk = scanner();
		node->child2 = n();
		fprintf(op, "\tMULT\t%s\n", var.c_str());
	}

	return node;
}
Node* a()
{
	Node* node = new Node;
	node->label = "a";

	node->child1 = m();
	if (tk.token == OP_tk && tk.instance == "+")
	{
		string var = newVar();
		fprintf(op, "\tSTORE\t%s\n", var.c_str());
		node->token1 = new Token(tk);// no ambiguity
		tk = scanner();

		node->child2 = a();
		fprintf(op, "\tADD\t%s\n", var.c_str());
	}
	return node;
}
Node* m()
{
	Node* node = new Node;
	node->label = "m";

	if (tk.token == OP_tk && tk.instance == "*")
	{
		node->token1 = new Token(tk);
		tk = scanner();

		node->child1 = m();
		fprintf(op, "\tMULT -1\n");
	}
	else
		node->child1 = r();
	return node;
}
Node* r()
{
	Node* node = new Node;
	node->label = "r";

	if (tk.token == OP_tk && tk.instance == "(")
	{
		tk = scanner();

		node->child1 = expr();
		if (tk.token == OP_tk && tk.instance == ")")
		{
			tk = scanner();

			return node;
		}
		else
			Error("expected ) token", tk.lineNum);


	}
	else if (tk.token == ID_tk)
	{
		use(tk);
		node->token1 = new Token(tk);
		fprintf(op, "\tLOAD\t%s\n", node->token1->instance.c_str());
		tk = scanner();
		return node;
	}
	else if (tk.token == NUM_tk)
	{
		node->token1 = new Token(tk);
		fprintf(op, "\tLOAD\t%s\n", node->token1->instance.c_str());
		tk = scanner();
		return node;
	}
	else
		Error("expected ( , identifier, or number token", tk.lineNum);
}
Node* stats()
{
	Node* node = new Node;
	node->label = "stats";

	node->child1 = stat();
	node->child2 = mStat();
	return node;
}

Node* mStat()
{
	Node* node = new Node;
	node->label = "mStat";

	if (tk.token == KW_tk && tk.instance == "end")
	{
		return NULL;

	}
	node->child1 = stat();
	node->child2 = mStat();
	return node;
}

Node* stat()
{
	Node* node = new Node;
	node->label = "stat";

	if (tk.token == KW_tk && tk.instance == "in")
	{

		tk = scanner();

		node->child1 = in();
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();
			return node;
		}
		else
			Error("expected . token", tk.lineNum);
	}
	else if (tk.token == KW_tk && tk.instance == "out")
	{

		tk = scanner();

		node->child1 = out();
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();
			fprintf(op, "\tSTORE\tTOUT\n");
			fprintf(op, "\tWRITE\tTOUT\n");
			return node;
		}
		else
			Error("expected . token", tk.lineNum);

	}
	else if (tk.token == KW_tk && tk.instance == "begin")
	{

		node->child1 = block();
		return node;
	}
	else if (tk.token == KW_tk && tk.instance == "iffy")
	{

		tk = scanner();

		node->child1 = IF();
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();

			return node;
		}
		else
			Error("expected . token", tk.lineNum);

	}
	else if (tk.token == KW_tk && tk.instance == "loop")
	{

		tk = scanner();

		node->child1 = loop();
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();

			return node;
		}
		else
			Error("expected . token", tk.lineNum);

	}
	else if (tk.token == ID_tk)
	{
		use(tk);
		node->token1 = new Token(tk);

		tk = scanner();

		node->child1 = assign();
		fprintf(op, "\tSTORE\t%s\n", node->token1->instance.c_str());
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();

			return node;
		}
		else
			Error("expected . token", tk.lineNum);

	}
	else

		Error("expected in, out, begin, iffy, loop, assign keywords", tk.lineNum);



}
Node* in()
{
	Node* node = new Node;
	node->label = "in";

	if (tk.token == ID_tk)
	{
		use(tk);
		node->token1 = new Token(tk);
		fprintf(op, "\tREAD\t%s\n", node->token1->instance.c_str());
		tk = scanner();

		return node;
	}
	else
		Error("expected identifier", tk.lineNum);
}

Node* out()
{
	Node* node = new Node;
	node->label = "out";

	node->child1 = expr();
	return node;

}
Node* IF()
{
	Node* node = new Node;
	node->label = "if";

	if (tk.token == OP_tk && tk.instance == "[")
	{
		tk = scanner();

		node->child1 = expr();
		string var = newVar();
		fprintf(op, "\tSTORE\t%s\n", var.c_str());
		node->child2 = ro();

		node->child3 = expr();
		fprintf(op, "\tSUB\t%s\n", var.c_str());
		
		string label = newLabel();
		if (node->child2->label == ">"){
			// condition is true if acc is positive
			fprintf(op, "\tBRZPOS\t %s\n", label.c_str());
		}
		else if (node->child2->label == "<") {
			fprintf(op, "\tBRZNEG\t %s\n", label.c_str());
		}
		else if (node->child2->label == ">>") {
			fprintf(op, "\tBRPOS\t %s\n", label.c_str());
		}
		else if (node->child2->label == "<<") {
			fprintf(op, "\tBRNEG\t %s\n", label.c_str());
		}
		else if (node->child2->label == "<>") {
			fprintf(op, "\tBRZERO\t %s\n", label.c_str());
		}
		else if (node->child2->label == "==") {
			fprintf(op, "\tBRPOS\t %s\n", label.c_str());
			fprintf(op, "\tBRNEG\t %s\n", label.c_str());
		}

		//evaluakkte condition and do jump
// for example if [ 8 == 8 ] out 0 . .
		// child1 is first 8
		// save it into var1 as a temporary variable
		// once you get into the second value, here it is 8
		// Sub from the second one the first one
		// if the condition is true, then execute child4
		// How to check the condition? 
		// each RO operation is different
		//   > vs < 
		// 4 > 5 vs 4 < 5
		// the result of sub is always the same ( 5 - 4) the second - the first
		// So the result is  one regardless of the logical operation 
		// if < then the condition is true when the result is positive (BRNEG)
		// so execute child4 if positive
		// if > then the condition is true when the result is negative 
		// otherwise go to the label


		if (tk.token == OP_tk && tk.instance == "]")
		{
			tk = scanner();

			if (tk.token == KW_tk && tk.instance == "then")
			{
				tk = scanner();

				node->child4 = stat();
				// add the label (print to the target "L0:")
				fprintf(op, "\t\t%s:NOOP\n", label.c_str());
				return node;
			}
			else
				Error("expected then token", tk.lineNum);

		}
		else
			Error("expected ] token", tk.lineNum);
	}
	else
		Error("expected [ token", tk.lineNum);

}
Node* loop()
{
	Node* node = new Node;
	node->label = "loop";
	string entryLabel = newLabel();
	fprintf(op, "\t%s:NOOP\n", entryLabel.c_str());
	if (tk.token == OP_tk && tk.instance == "[")
	{
		tk = scanner();

		node->child1 = expr();
		string var = newVar();
		fprintf(op, "\tSTORE\t%s\n", var.c_str());
		node->child2 = ro();
		node->child3 = expr();
		fprintf(op, "\tSUB\t%s\n", var.c_str());

		string label = newLabel();
		if (node->child2->label == ">") {
			// condition is true if acc is positive
			fprintf(op, "\tBRZPOS\t %s\n", label.c_str());
		}
		else if (node->child2->label == "<") {
			fprintf(op, "\tBRZNEG\t %s\n", label.c_str());
		}
		else if (node->child2->label == ">>") {
			fprintf(op, "\tBRPOS\t %s\n", label.c_str());
		}
		else if (node->child2->label == "<<") {
			fprintf(op, "\tBRNEG\t %s\n", label.c_str());
		}
		else if (node->child2->label == "<>") {
			fprintf(op, "\tBRZERO\t %s\n", label.c_str());
		}
		else if (node->child2->label == "==") {
			fprintf(op, "\tBRPOS\t %s\n", label.c_str());
			fprintf(op, "\tBRNEG\t %s\n", label.c_str());
		}

		// if (condition ) else goto L1; { statements; } 
		//L1: otherStatments;
		//
		// L0: while (condition) {statemets; goto L0;} goto L1;
		// L1: otherstatements
		//
		// if condition is true, the execute statements, else jump to Label
		// Difference between if and while is that after executing statements, jump back to the condition
		// 
		if (tk.token == OP_tk && tk.instance == "]")
		{
			tk = scanner();

			node->child4 = stat();
			fprintf(op, "\tBR %s\n", entryLabel.c_str());
			fprintf(op, "\t\t%s:NOOP\n", label.c_str());
			return node;
		}
		else
			Error("expected ] token", tk.lineNum);
	}
	else
		Error("expected [ token", tk.lineNum);

}
Node* assign()
{
	Node* node = new Node;
	node->label = "assign";
	
	if (tk.token == OP_tk && tk.instance == "=")
	{
		tk = scanner();

		node->child1 = expr();
		return node;
	}
	else
		Error("expected = token", tk.lineNum);
}
Node* ro()
{
	Node* node = new Node;
	//node->label = "ro";

	if (tk.token == OP_tk && tk.instance == "<")
	{
		tk = scanner();

		if (tk.token == OP_tk && tk.instance == "<")
		{
			node->label = "<<";
			tk = scanner();

			return node;
		}
		else if (tk.token == OP_tk && tk.instance == ">")
		{
			node->label = "<>";
			tk = scanner();

			return node;
		}
		else
		{
			node->label = "<";
			return node;
		}
	}
	else if (tk.token == OP_tk && tk.instance == ">")
	{
		tk = scanner();

		if (tk.token == OP_tk && tk.instance == ">")
		{
			node->label = ">>";
			tk = scanner();

			return node;
		}
		else
		{
			node->label = ">";
			return node;
		}

	}
	else if (tk.token == OP_tk && tk.instance == "==")
	{
		node->label = "==";
		tk = scanner();
		return node;
	}
	else
		Error("expected logical operation", tk.lineNum);

}
