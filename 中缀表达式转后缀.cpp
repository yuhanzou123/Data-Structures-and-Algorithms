#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool Primer(char New, char top)
{	
	if ((New == '*' || New == '/') && (top == '+' || top == '-'))
	{
		return true;
	}
	if(top=='(')
	{
	return true;
	}
	if (New == '(')
	{
		return true;
	}
	return false;
}
string MiddleToEndExpr(string s)
{	
	string m;
	stack<char> ch;
	for (auto w : s)
	{
		if (w >= '0' && w <= '9')
		{
			m.push_back(w);
		}
		else {
			if (ch.empty())
			{
				ch.push(w);
				continue;
			}
			else {
				if (w == ')')
				{
					while (!ch.empty() && ch.top() != '(')
					{
						m.push_back(ch.top());
						ch.pop();
					}
					ch.pop();
					continue;
				}
				if (Primer(w, ch.top()))
				{
					ch.push(w);
				}
				else {
					while (true)
					{
						if ((!ch.empty()&&Primer(w, ch.top())) || ch.empty())
						{
							ch.push(w);
							break;
						}
						else {
							m.push_back( ch.top());
							ch.pop();
						}
					}
				}
			}
		}
	}
	while (!ch.empty())
	{
		m.push_back(ch.top());
		ch.pop();
	}
	return m;
}
int main()
{
	string p= MiddleToEndExpr("5*(2+3)+1/5");
	cout << p;
	/*for (char w : p)
	{
		if (w != '(' && w != ')')
		{
			cout << w;
		}
	}*/
}
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//bool Primer(char New, char top)
//{
//	// 当栈顶为 '(' 时，新运算符应直接入栈
//	if (top == '(') return true;
//	// 左括号直接入栈
//	if (New == '(') return true;
//	// 乘除优先级高于加减，返回 true 表示可以入栈
//	if ((New == '*' || New == '/') && (top == '+' || top == '-'))
//	{
//		return true;
//	}
//	// 其它情况（同级或栈顶优先更高）返回 false，表示需要先弹栈
//	return false;
//}
//string MiddleToEndExpr(string s)
//{
//	string m;
//	stack<char> ch;
//	for (auto w : s)
//	{
//		if (w >= '0' && w <= '9')
//		{
//			m.push_back(w);
//		}
//		else {
//			// 特殊处理右括号：弹出直到遇到左括号并丢弃左右括号
//			if (w == ')') {
//				while (!ch.empty() && ch.top() != '(') {
//					m.push_back(ch.top());
//					ch.pop();
//				}
//				if (!ch.empty() && ch.top() == '(') {
//					ch.pop(); // 丢弃 '('
//				}
//				continue;
//			}
//			// 其它符号（运算符或左括号）
//			if (ch.empty())
//			{
//				ch.push(w);
//				continue;
//			}
//			else {
//				if (Primer(w, ch.top()))
//				{
//					ch.push(w);
//				}
//				else {
//					while (true)
//					{
//						if ((!ch.empty() && Primer(w, ch.top())) || ch.empty())
//						{
//							ch.push(w);
//							break;
//						}
//						else {
//							// 若遇到左括号也停止弹出（安全检查）
//							if (ch.top() == '(') break;
//							m.push_back(ch.top());
//							ch.pop();
//						}
//					}
//				}
//			}
//		}
//	}
//	while (!ch.empty())
//	{
//		// 忽略残留的括号
//		if (ch.top() != '(' && ch.top() != ')')
//			m.push_back(ch.top());
//		ch.pop();
//	}
//	return m;
//}
//int main()
//{
//	string p = MiddleToEndExpr("5*(2+3)+1/5");
//	for (char w : p)
//	{
//		if (w != '(' && w != ')')
//		{
//			cout << w;
//		}
//	}
//}
