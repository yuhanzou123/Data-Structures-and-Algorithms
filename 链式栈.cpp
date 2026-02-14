#include <iostream>
#include <stdexcept>//标准异常头文件
using namespace std;
class linkStack 
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node(int data = 0) :data(data), next(nullptr) {};
	};
	Node* head;
	int size;
public:
	linkStack():size(0)
	{
		head = new Node();
	}
	~linkStack()
	{
		Node* p = head;
		while (p != nullptr)
		{
			head = head->next;
			delete p;
			p = head;
		}
	}
	void push(int val)
	{	
		++size;
		Node* curr = new Node(val);
		if (head->next == nullptr)
		{
			head->next = curr;
			return;
		}
		curr->next = head->next;
		head->next = curr;
	}
	void pop() 
	{
		if (head->next == nullptr)
		{
			throw runtime_error("Stack is empty, cannot pop!");
		}
		size -= 1;
		Node* temp = head->next;
		head->next = temp->next;
		delete temp;
	}
	int top()
	{
		if (head->next == nullptr)
		{
			throw runtime_error("Stack is empty, cannot get top!");
		}
		return head->next->data;
	}
	bool Isempty()
	{
		return head->next == nullptr;
	}
	int Size()
	{
		return size;
	}
};
int main() {
	linkStack Stack;
	Stack.push(100);
	Stack.push(20);
	while (Stack.Size()!= 0)
	{
		cout << Stack.top() << endl;
		Stack.pop();
	}
	try
	{
		Stack.pop();  // 尝试弹出空栈
	}
	catch (const runtime_error& e)
	{
		// 打印异常信息
		cerr << "Error: " << e.what() << endl;
	}
}