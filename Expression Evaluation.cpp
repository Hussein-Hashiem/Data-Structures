#include <iostream>
#include <stack>
#include <string>

using namespace std;
// Function to verify whether a character is operator symbol or not
bool IsOperator(char C);
// Function to verify whether a character is number or not
bool IsNumber(char C);
// Perform operaion function
int performOperation(int op1, int op2, char op);
int main()
{
	stack<int>s;
	string expression, num = "";
	int j = 0;
	cout << "Enter a Postfix Expression: ( e.g. 4 5 * )" << endl;
	getline(cin, expression);
	for (int i = 0; i < expression.size(); i++)
	{
		if (IsNumber(expression[i]))
		{
			num += expression[i];
			j++;
		}
		else if (expression[i] == ' ')
		{
			if (j > 0)
			{
				int x = stoi(num);
				s.push(x);
				num = "";
				j = 0;
			}
		}
		else if (IsOperator(expression[i]))
		{
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			s.push(performOperation(op1, op2, expression[i]));
		}
	}
	cout << "Answer = " << s.top() << endl;
	return 0;
}
bool IsOperator(char C) { return (C == '+' || C == '-' || C == '*' || C == '/'); }
bool IsNumber(char C) { return C >= '0' && C <= '9'; }
int performOperation(int op1, int op2, char op)
{
	switch (op)
	{
	case '+':
		return op2 + op1;
		break;
	case '-':
		return op2 - op1;
		break;
	case '*':
		return op2 * op1;
		break;
	case '/':
		return op2 / op1;
		break;
	}
}
