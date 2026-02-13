#include <iostream>
#include <cstring> 
#include<string>
#include<ctime>
#include<vector>
#include<stdlib.h>
using namespace std;
/*
知识点讲解：
栈实现的本质是数组，依靠top来进行栈顶定位，top个数和栈里有的元素个数相等，
通过top是否等于最大容量判断。
栈的特性：先进后出，后进先出。
有段题型：
1：给出一组元素的入栈顺序，判断相关出栈顺序是否可能，只需知道栈中某出元素之后的出栈元素一定和自己所处数组下表相邻。
*/
class Stack {
private:
	int* arr;
	int top;
	int mcap;
private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, arr, top * sizeof(int));
		delete[] arr;
		arr = p;
		mcap = size;
	}
public:
	Stack(int size = 10)
		:top(0),
		 mcap(size)
	
	{
		arr = new int[size];
	}
	~Stack()
	{
		delete[] arr;
		arr = nullptr;
	}
public:
	void push(int val)
	{
		if (top < mcap)
		{
			arr[top++] = val;
			return;
		}
		else 
		{
			expand(2 * mcap);
			arr[top++] = val;
			return;
		}
	}
	void pop()
	{
		if (top == 0)
		{
			throw "Stack is empty";
			cout << endl;
			return;
		}
		top--;
	}
	int Mtop()const
	{	
		if (top == 0)throw "Stack is empty";
		if(top>0) return arr[top-1];
	}
	bool empty() const{
		if (top > 0)return false;
		return true;
	}
	int size()const {
		return top;
	}
};
int main() 
{
	Stack mystack;
	mystack.push(100);
	mystack.push(20);
	mystack.push(5);
	mystack.push(85);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	mystack.push(9);
	while (!mystack.empty())
	{
		cout << mystack.Mtop() << ' ';
		mystack.pop();
	}
}