#include "parser.h"
#include "token.h"
#include "scanner.h"

Token tk;

Token scanner()
{
	static int i = -1;
	i++;
	return tokenList[i];
}


Node* parser() {
	Node* root = new Node();
	root->label = "parser";
	tk = scanner();
	root->child1 = program();
	if (tk.token == EOF_tk)
	{ 
		cout << "parser is done correctly" << endl;
		return root;
	}
	else Error("tk received, EOFTk expected");

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
	
	if(tk.token == KW_tk && tk.instance == "begin")
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
			Error("expeted end keyword");
		}
	}
	else 
	{
		Error("expected begin keyword");
	}
}
Node* vars() 
{
	if (tk.token == KW_tk && tk.instance == "data")
	{
		Node* node = new Node;
		node->label = "vars";
		tk = scanner();
		
		if (tk.token == ID_tk)
		{
			
			node->token1 = new Token(tk);
			tk = scanner();
			
			if (tk.token == OP_tk && tk.instance == "=")
			{
				tk = scanner();
				
				if (tk.token == NUM_tk)
				{
					node->token2 = new Token;
					node->token2->token = tk.token;
					node->token2->instance = tk.instance;
					node->token2->lineNum = tk.lineNum;
					tk = scanner();
					
					if (tk.token == OP_tk && tk.instance == ".")
					{
						tk = scanner();
						
						node->child1 = vars();
						return node;
					}
					else
						Error("expected . token");
				}
				else
					Error("expected number token");

			}
			else
				Error("expected = token");
		}
		else
			Error("expected identifier token");
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
		node->token1 = new Token(tk);
		tk = scanner();
		
		node->child2 = expr();
	}
		return node;
	
	
}
Node* n() 
{
	Node* node = new Node;
	node->label = "n";
	
	node->child1 = a();
	if (tk.token == OP_tk && tk.instance == "/")
	{
		node->token1 = new Token(tk);
		tk = scanner();
		
		node->child2 = n();
	}
	else if (tk.token == OP_tk && tk.instance == "*")
	{
		node->token1 = new Token(tk);
		tk = scanner();
		node->child2 = n();
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
		node->token1 = new Token(tk);// no ambiguity
		tk = scanner();
		
		node->child2 = a();
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
			Error("expected ) token");
		

	}
	else if (tk.token == ID_tk)
	{
		node->token1 = new Token(tk);
		
		tk = scanner();
		return node;
	}
	else if (tk.token == NUM_tk)
	{
		node->token1 = new Token(tk);
		tk = scanner();
		return node;
	}
	else
		Error("expected ( , identifier, or number token");
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
			Error("expected . token");
	}
	else if (tk.token == KW_tk && tk.instance == "out")
	{
		
		tk = scanner();
		
		node->child1 = out();
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();
			
			return node;
		}
		else
			Error("expected . token");
		
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
			Error("expected . token");
		
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
			Error("expected . token");
		
	}
	else if (tk.token == ID_tk)
	{
		node->token1 = new Token(tk);
		tk = scanner();
		
		node->child1 = assign();
		if (tk.token == OP_tk && tk.instance == ".")
		{
			tk = scanner();
			
			return node;
		}
		else
			Error("expected . token");
		
	}
	else
		
		Error("expected in, out, begin, iffy, loop, assign keywords");
	

	
}
Node* in()
{
	Node* node = new Node;
	node->label = "in";
	
	if (tk.token == ID_tk)
	{
		node->token1 = new Token(tk);
		tk = scanner();
		
		return node;
	}
	else
		Error("expected identifier");
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
			node->child2 = ro();
			node->child3 = expr();
			if (tk.token == OP_tk && tk.instance == "]")
			{
				tk = scanner();
				
				if (tk.token == KW_tk && tk.instance == "then")
				{
					tk = scanner();
					
					node->child4 = stat();
					return node;
				}
				else
					Error("expected then token");
					
			}
			else
				Error("expected ] token");
		}
		else
			Error("expected [ token");
	
}
Node* loop()
{
	Node* node = new Node;
	node->label = "loop";
	
		if (tk.token == OP_tk && tk.instance == "[")
		{
			tk = scanner();
			
			node->child1 = expr();
			node->child2 = ro();
			node->child3 = expr();
			if (tk.token == OP_tk && tk.instance == "]")
			{
				tk = scanner();
				
				node->child4 = stat();
				return node;
			}
			else
				Error("expected ] token");
		}
		else
			Error("expected [ token");
	
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
		Error("expected = token");
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
		Error("expected logical operation");
	
}
