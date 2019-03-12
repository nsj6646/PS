#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	stack<int> s1;
	stack<char> s2;
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			s1.push(2);
			s2.push('(');
		}
		else if (str[i] == '[') {
			s1.push(3);
			s2.push('[');
		}
		else {
			if (str[i] == ')') {	
				//예외
				if (s2.empty()|| s2.top() == '[') {
					cout << 0;
					return 0;
				}
				//()
				if (s2.top() == '(') {
					s2.pop();
					if (!s2.empty() && s2.top() == '1') {
						int temp = s1.top();
						s1.pop();
						while (!s2.empty() && s2.top() == '1') {
							temp += s1.top();
							s1.pop();
							s2.pop();
						}
						s1.push(temp);
					}
					s2.push('1');
				}
				else {
					if (s2.size()<2) {
						cout << 0;
						return 0;
					}
					s2.pop();
					if (s2.top() == '[') {
						cout << 0;
						return 0;
					}
					s2.pop();
					int temp = s1.top();
					s1.pop();
					temp *= s1.top();
					s1.pop();
					while (!s2.empty()&&s2.top()=='1') {
						temp += s1.top();
						s1.pop();
						s2.pop();
					}
					s1.push(temp);
					s2.push('1');
				}
			}
			else if (str[i] == ']') {
				//예외
				if (s2.empty()|| s2.top() == '(') {
					cout << 0;
					return 0;
				}
				//[]
				if (s2.top() == '[') {
					s2.pop();
					if (!s2.empty() && s2.top() == '1') {
						int temp = s1.top();
						s1.pop();
						while (!s2.empty() && s2.top() == '1') {
							temp += s1.top();
							s1.pop();
							s2.pop();
						}
						s1.push(temp);
					}
					s2.push('1');
				}
				else {
					if (s2.size()<2) {
						cout << 0;
						return 0;
					}
					s2.pop();
					if (s2.top() == '(') {
						cout << 0;
						return 0;
					}
					s2.pop();
					int temp = s1.top();
					s1.pop();
					temp *= s1.top();
					s1.pop();					
					while (!s2.empty() && s2.top() == '1') {
						temp += s1.top();
						s1.pop();
						s2.pop();
					}
					s1.push(temp);
					s2.push('1');
				}
			}
		}
	}
	if (s2.top()!='1'||s2.size()!=1) {
		cout << 0;
	}
	else {
		cout << s1.top();
	}
	return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack <char> st;
char str[35];

int main()
{
scanf("%s", str);

int nRes = 0;
int nMul = 1;
for (int i = 0; str[i] != NULL; ++i)
{
if (str[i] == '(')
{
st.push(str[i]);
nMul *= 2;
if (str[i + 1] == ')')
nRes += nMul;
}
else if (str[i] == '[')
{
st.push(str[i]);
nMul *= 3;
if (str[i + 1] == ']')
nRes += nMul;
}
else if (str[i] == ')')
{
if (st.empty() || st.top() != '(')
{
printf("0\n");
return 0;
}
nMul /= 2;
st.pop();
}
else if (str[i] == ']')
{
if (st.empty() || st.top() != '[')
{
printf("0\n");
return 0;
}
nMul /= 3;
st.pop();
}
}
if (!st.empty())
printf("0\n");
else
printf("%d\n", nRes);
}
*/