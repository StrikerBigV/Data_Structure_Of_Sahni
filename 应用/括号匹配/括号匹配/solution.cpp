#include <iostream>
#include <string>
using namespace std;
void printmatchpairs(string expr)
{
	arrayStack<int> s;
	int length=(int) expr.size();
	for(int i=0;i<length;i++)
		if(expr[i]='(')
			s.push(expr[i]);
		else
			if(expr[i]=')')
		try
			{
				cout<<s.top()<<' '<<i<<endl;
				s.pop();
			}
		catch(stackEmpty)
		{
			cout<<"no match for right parentesis"<<"at"<<i<<endl;
		}
	while(!s.empty())
	{
		cout<<"no match for left parentesis"<<"at"<<s.top()<<endl;
		s.pop();
	}