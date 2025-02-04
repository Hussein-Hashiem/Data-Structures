#include <iostream>
#include <stack>
#include<string>
using namespace std;

// Function to convert infix to postfix
string InfixToPostfix(string expression);
// Function to know which operator has higher precedence
int HasHigherPrecedence(char op1, char op2);
// Function to get weight of an operator. An operator with higher weight will have higher precedence 
int GetOperatorWeight(char op);
// Function to verify whether a character is operator symbol or not
bool IsOperator(char C);
// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool IsOperand(char C);

int main()
{
	string expression;
	cout << "Enter Infix Expression..." << endl;
	getline(cin, expression);
	cout << "Postfix Expression" << endl;
	cout << InfixToPostfix(expression) << endl;
	return 0;
}

string InfixToPostfix(string expression)
{
	stack<char>s;
	string postfix = "";
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == ' ' || expression[i] == ',')continue;
		else if (IsOperator(expression[i]))
		{
			while (!s.empty() && s.top() != '(' && HasHigherPrecedence(s.top(), expression[i]))
			{
				postfix += s.top();
				s.pop();
			}
			s.push(expression[i]);
		}
		else if (IsOperand(expression[i])) { postfix += expression[i]; }
		else if (expression[i] == '(') { s.push(expression[i]); }
		else if (expression[i] == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}
	return postfix;
}
bool IsOperator(char C) { return (C == '+' || C == '-' || C == '*' || C == '/' || C == '$'); }
bool IsOperand(char C) { return ((C >= '0' && C <= '9') || (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z')); }
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);
	if (op1Weight == op2Weight)
	{
		if (op1 == '$') return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}
