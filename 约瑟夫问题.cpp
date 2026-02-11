#include <iostream>
#include <cstring> 
#include<string>
#include<ctime>
#include<vector>
#include<stdlib.h>


	struct Node {
		Node(int data = 0) : data(data), next(nullptr) {}
		int data;
		Node* next;
	};
	void Jesopy(Node* head, int k) {
		Node* p = head; Node* q = head;
		for (;;) {
			q = p;
			p = p->next;
			if (p == q) {
				std::cout << p->data << std::endl;
				delete p;
				return;
			}
			q->next = p->next;
			std::cout << p->data << ' ';
			delete p;
			p = q->next;
		}
	}
	int main() {
		srand(time(0));
		Node* head = new Node(100);
		Node* n2 = new Node(20);
		Node* n3=new Node(30);
		Node* n4=new Node(55);
		Node* n5=new Node(25);
		Node* n6=new Node(17);
		Node* n7=new Node(88);
		Node* n8=new Node(28);
		Node* n9=new Node(54);
	    Node* n10=new Node(33);
		head->next = n2;
		n2->next=n3;
		n3->next=n4;
		n4->next=n5;
		n5->next=n6;
		n6->next=n7;
		n7->next=n8;
		n8->next=n9;
		n9->next=n10;
		n10->next = head;
		Jesopy(head, 2);
	}

//#include <iostream>
//#include <cstring> 
//#include<string>
//#include<ctime>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//class Circle {
//private:
//	Node* head;//头结点
//	Node* tail;//尾结点
//public:
//	Circle() {
//		head = new Node(10);
//		tail = head;
//		tail->next = head;
//	}
//	~Circle() {
//		if (head->next == head) {
//			delete head;
//			head = nullptr;
//			tail = nullptr;
//			return;
//		}
//		Node* current = head->next;
//		while (current != head) {
//			Node* temp = current;
//			current = current->next;
//			delete temp;
//		}
//		delete current;
//		head = nullptr;
//		tail = nullptr;
//	}
//	void inserttail(int val) {
//		Node* p = new Node(val);
//		tail->next = p;
//		tail = tail->next;
//		tail->next = head;
//	}
//	void inserthead(int val) {
//		Node* p = new Node(val);
//		if (head->next == head) {
//			tail->next = p;
//			tail = tail->next;
//			tail->next = head;
//			return;
//		}
//		p->next = head->next;
//		head->next = p;
//		tail->next = head;
//	}
//	void remove(int val) {
//		// 不删除哨兵 head，仅删除有效数据节点（首次匹配）
//		if (head->next == head) { // 空表
//			cout << "无此节点" << endl;
//			return;
//		}
//		Node* q = head;        // 前驱，初始为哨兵
//		Node* p = head->next;  // 当前节点
//		while (p != head) {
//			if (p->data == val) {
//				q->next = p->next;
//				// 如果删除的是尾节点，更新 tail
//				if (p == tail) {
//					tail = q;
//				}
//				// 如果删除后变为空表，确保 tail 指回 head
//				if (head->next == head) {
//					tail = head;
//				}
//				delete p;
//				cout << "删除" << val << "成功" << endl;
//				return;
//			}
//			q = p;
//			p = p->next;
//		}
//		cout << "无此节点" << endl;
//		return;
//	}
//	void clink_show() {
//		if (head->next == head) {
//			cout << "链表为空" << endl;
//			return;
//		}
//		Node* p = head->next;
//		while (p != head) {
//			cout << p->data << ' ';
//			p = p->next;
//		}
//		cout << endl;
//		return;
//	}
//	bool find(int val) {
//		Node* p = head->next;
//		while (p != head) {
//			if (p->data == val) {
//				cout << "链表内存在" << val << endl;
//				return true;
//			}
//			p = p->next;
//		}
//		cout << "链表内不存在" << val << endl;
//		return false;
//	}
//	
//};
//int main() {
//	Circle clink;
//	clink.inserthead(100);
//	clink.inserthead(100);
//	clink.inserthead(20);
//	clink.inserthead(100);
//	clink.clink_show();
//	clink.find(20);
//	clink.remove(100);
//	clink.clink_show();
//	
//}
//#include <iostream>
//#include <cstring> 
//#include <string>
//#include <ctime>
//#include <vector>
//#include <stdlib.h>
//#include <memory>
//using namespace std;
//class Circle {
//private:
//	struct Node {
//		Node(int data = 0) : data(data), next(nullptr) {}
//		int data;
//		std::unique_ptr<Node> next;
//	};
//	std::unique_ptr<Node> head; // 哨兵，拥有链表所有节点（通过 unique_ptr 链）
//	Node* tail; // 指向最后一个有效节点（或指向哨兵当链表为空）
//
//public:
//	// 禁用拷贝（unique_ptr 不可拷贝）
//	Circle(const Circle&) = delete;
//	Circle& operator=(const Circle&) = delete;
//
//	// 允许移动
//	Circle(Circle&& other) noexcept {
//		head = std::move(other.head);
//		tail = other.tail;
//		// 将 other 重置为有效的空哨兵状态
//		other.head = std::make_unique<Node>();
//		other.tail = other.head.get();
//	}
//	Circle& operator=(Circle&& other) noexcept {
//		if (this == &other) return *this;
//		head = std::move(other.head);
//		tail = other.tail;
//		other.head = std::make_unique<Node>();
//		other.tail = other.head.get();
//		return *this;
//	}
//
//	Circle() {
//		head = std::make_unique<Node>(); // 哨兵节点，data 未被使用
//		tail = head.get();
//		head->next = nullptr;
//	}
//
//	~Circle() = default; // unique_ptr 自动释放链表节点
//
//	void inserttail(int val) {
//		auto p = std::make_unique<Node>(val);
//		Node* pRaw = p.get();
//		// 如果链表为空（没有有效节点）
//		if (head->next == nullptr) {
//			head->next = std::move(p);
//			tail = pRaw;
//			return;
//		}
//		// 非空：把新节点放到 tail 之后
//		tail->next = std::move(p);
//		tail = pRaw;
//	}
//	void inserthead(int val) {
//		auto p = std::make_unique<Node>(val);
//		if (head->next == nullptr) {
//			// 空表：新节点成为唯一节点，更新 tail
//			head->next = std::move(p);
//			tail = head->next.get();
//			return;
//		}
//		// 非空：插入到第一个有效节点之前
//		p->next = std::move(head->next);
//		head->next = std::move(p);
//	}
//	void remove(int val) {
//		// 不删除哨兵 head，仅删除有效数据节点（首次匹配）
//		Node* prev = head.get();
//		while (prev->next) {
//			Node* cur = prev->next.get();
//			if (cur->data == val) {
//				// 将 prev->next 指向 cur->next（移动 unique_ptr）
//				prev->next = std::move(cur->next);
//				// 如果删除的是尾节点，更新 tail
//				if (cur == tail) {
//					tail = prev;
//				}
//				// 若删除后链表变为空，确保 tail 指回哨兵
//				if (head->next == nullptr) {
//					tail = head.get();
//				}
//				cout << "删除" << val << "成功" << endl;
//				return;
//			}
//			prev = cur;
//		}
//		cout << "无此节点" << endl;
//		return;
//	}
//	void clink_show() {
//		if (head->next == nullptr) {
//			cout << "链表为空" << endl;
//			return;
//		}
//		Node* p = head->next.get();
//		while (p) {
//			cout << p->data << ' ';
//			p = p->next.get();
//		}
//		cout << endl;
//		return;
//	}
//	bool find(int val) {
//		Node* p = head->next.get();
//		while (p) {
//			if (p->data == val) {
//				cout << "链表内存在" << val << endl;
//				return true;
//			}
//			p = p->next.get();
//		}
//		cout << "链表内不存在" << val << endl;
//		return false;
//	}
//};
//int main() {
//	Circle clink;
//	clink.inserthead(100);
//	clink.inserthead(100);
//	clink.inserthead(20);
//	clink.inserthead(100);
//	clink.clink_show();
//	clink.find(20);
//	clink.remove(100);
//	clink.clink_show();
//
//}