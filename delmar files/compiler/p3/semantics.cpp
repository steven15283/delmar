#include "semantics.h"
#include "scanner.h"

vector<Token> scope;
void printScope()
{
	for (auto i = scope.begin(); i != scope.end(); ++i)
		cout << (*i).instance << ' ';
}
void insert(Token var)
{
	if (verify(var))
	{
		Error("variable "+ var.instance + " is already defined", var.lineNum);
	}
	else
	{
		scope.push_back(var);
	}

}

Token use(Token var)
{
	if (verify(var))
	{
		cout << var.instance << endl;
		return var;
	}
	else
	{
		Error("unidentified variable", var.lineNum);
	}

}

bool verify(Token var)
{
	if (find(scope.begin(), scope.end(), var) != scope.end())
	{
		return true;
	}
	else
		return false;
}

