#include "LinkQueue.h"

LinkQueue::LinkQueue() {
    head = new Node();
    head->next = head;
    head->pre = head;
}

LinkQueue::~LinkQueue() {
    while (!empty()) {
        pop();
    }
    delete head;
    head = nullptr;
}

void LinkQueue::push(int val) {
    Node* node = new Node(val);
    Node* tail = head->pre;

    tail->next = node;
    node->pre = tail;
    node->next = head;
    head->pre = node;
}

void LinkQueue::pop() {
    if (empty()) {
        throw std::underflow_error("queue underflow");
    }
    Node* toDelete = head->next;
    head->next = toDelete->next;
    toDelete->next->pre = head;
    delete toDelete;
}

int LinkQueue::front() const {
    if (empty()) {
        throw std::underflow_error("queue underflow");
    }
    return head->next->data;
}

int LinkQueue::back() const {
    if (empty()) {
        throw std::underflow_error("queue underflow");
    }
    return head->pre->data;
}

bool LinkQueue::empty() const {
    return head->next == head;
}

int LinkQueue::size() const {
    int count = 0;
    Node* p = head->next;
    while (p != head) {
        ++count;
        p = p->next;
    }
    return count;
}