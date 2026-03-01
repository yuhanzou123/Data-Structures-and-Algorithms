#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
class LinkQueue
{
private:
	struct Node
	{
		int data;
		Node* pre;
		Node* next;
		Node(int data = 0)
			:data(data)
			,pre(nullptr)
			,next(nullptr)
		{}
	};
	Node* head;
	
public:
	LinkQueue()
	{
		Node* node = new Node();
		head = node;
		head->next = head;
		head->pre = head;
	}
	~LinkQueue()
	{
		if (head == head->next)
		{
			delete head;
			head = nullptr;
		}
		else {
			Node* p = head->next;
			while (p != head)
			{
				Node* temp = p;
				p = p->next;
				delete temp;
			}
			delete head;
			head = nullptr;
		}
	}
	void push(int val)
	{
		Node* node = new Node(val);
		Node* p = head->pre;
		p->next = node;
		node->pre = p;
		node->next = head;
		head->pre = node;
	}
	void pop()
	{
		if (head->next == head)
		{
			throw std::underflow_error("queue underflow");
		}
		Node* p = head->next;
		head->next = head->next->next;
		head->next->pre = head;
		delete p;
		p = nullptr;
	}
	int front()
	{
		if (head->next == head)
		{
			throw std::underflow_error("queue underflow");
		}
		return head->next->data;
	}
	int back()
	{
		if (head->next == head)
		{
			throw std::underflow_error("queue underflow");
		}
		return head->pre->data;
	}
	bool empty()
	{
		return head->next == head;
	}
	int size()
	{
		if (head->next == head)
		{
			return 0;
		}
		int sum = 1;
		Node* p = head->next;
		while (p != head)
		{
			sum++;
			p = p->next;
		}
		return sum;
	}
};
int main()
{
	LinkQueue que;
	int arr[10] = { 100,20,30,60,42,52,10,5,10,65 };
	for (int i = 0;i < 10;i++)
	{
		que.push(arr[i]);
	}
	while (!que.empty())
	{
		cout << que.front() << ' ' << que.back() << endl;
		que.pop();
	}
}