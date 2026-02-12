#include <iostream>
#include <cstring> 
#include<string>
#include<ctime>
#include<vector>
#include<stdlib.h>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* pre;
	Node(int data=0)
		:data(data)
		, next(nullptr)
		, pre(nullptr)
	{ };
};
class DoubleLink {
private:
	Node* head;
	Node* tail;
public:
	DoubleLink()
	{
		head = new Node();
		tail = head;
	}
	~DoubleLink(){
		Node* p = head;
		while (p != nullptr)
		{
			head = head->next;
			delete p;
			p = head;
		}
	}
public:
	void InsertHead(int val) {
		Node* node = new Node(val);
		if (head->next == nullptr)
		{
			head->next = node;
			node->pre = head;
			tail = node;
			return;
		}
		node->next = head->next;
		node->next->pre = node;
		head->next = node;
		node->pre = head;
	}
	void InsertFront(int val) {
		Node* p = new Node(val);
		tail->next = p;
		p->pre = tail;
		tail = p;
	}
	void Frontshow() {
		Node* p = head->next;
		while (p != nullptr)
		{
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
	}
	void Backshow() {
		Node* p = tail;
		while (p != head)
		{
			cout << p->data << ' ';
			p = p->pre;
		}
		cout << endl;
	}
};
int main() {
	DoubleLink link;
	link.InsertHead(100);
	link.InsertHead(20);
	link.Frontshow();
	link.Backshow();
}
