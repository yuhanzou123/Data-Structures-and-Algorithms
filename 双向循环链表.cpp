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
class DoubleCircleLink {
private:
	Node* head;
	Node* tail;
public:
	DoubleCircleLink()
	{
		head = new Node();
		tail = head;
		head->next = head;
		head->pre = head;
	}
	~DoubleCircleLink(){
		Node* p = head->next;
		while (p != head)
		{
			Node* temp = p->next;
			delete p;
			p = temp;
			
		}
		delete head;
	}
public:
	void InsertHead(int val) {
		Node* node = new Node(val);
		if (head->next == head)
		{
			head->next = node;
			node->pre = head;
			tail = node;
			tail->next = head;
			head->pre = tail;
			return;
		}
		node->next = head->next;
		node->next->pre = node;
		head->next = node;
		node->pre = head;
	}
	void InsertBack(int val) {
		Node* p = new Node(val);
		tail->next = p;
		p->pre = tail;
		tail = p;
		tail->next = head;
		head->pre = tail;
	}
	void Frontshow() {
		Node* p = head->next;
		while (p != head)
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
	void remove(int val) {
		Node* p = head->next;
		while (p != head) {
			if (p->data == val) {
				p->pre->next = p->next;
				p->next->pre = p->pre;
				if (p == tail) {
					tail = p->pre;
					tail->next = head;
				}
				delete p;
				return;
			}
			p = p->next;
		}
		cout << "未找到需要移除的元素" << endl;
	}
	bool Find(int val) {
		Node* p = head->next;
		while (p != head) {
			if (p->data == val) {
				cout << "找到" << endl;
				return true;
			}
				p = p->next;
		
		}
		cout << "无此元素" << endl;
		return false;
	}
};
int main() {
	DoubleCircleLink link;
	link.InsertBack(30);
	link.InsertHead(100);
	link.InsertHead(20);
	link.remove(30);
	link.Frontshow();
	link.Backshow();
	link.Find(20);
}
