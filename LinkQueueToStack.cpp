#include<iostream>
#include"Linkqueue.h"
using std::cin;
using std::cout;
using std::endl;
class Mystack
{
private:
	LinkQueue* p1;
	LinkQueue* p2;
public:
	Mystack()
	{
		p1 = new LinkQueue();
		p2 = new LinkQueue();
	}
	void push(int val)
	{
		p1->push(val);
		while (!p2->empty())
		{
			p1->push(p2->front());
			p2->pop();
		}
		LinkQueue* p = p1;
		p1 = p2;
		p2 = p;

	}
	void pop()
	{
		if (p2->empty())
		{
			throw std::underflow_error("Stack is under_flow");
		}
		p2->pop();
	}
	bool empty()
	{
		return p2->empty();
	}
	int top()
	{
		return p2->front();
	}
	};
int main()
{
	Mystack s;
	s.push(100);
	s.push(62);
	s.push(2849777642);
	s.push(276674);
	s.push(2653);
	s.push(5893);
	s.push(25);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}