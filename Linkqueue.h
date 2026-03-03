#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdexcept>

class LinkQueue {
private:
    struct Node {
        int data;
        Node* pre;
        Node* next;
        Node(int data = 0) : data(data), pre(nullptr), next(nullptr) {}
    };

    Node* head;
public:
    LinkQueue();
    ~LinkQueue();

    void push(int val);
    void pop();
    int front() const;
    int back() const;
    bool empty() const;
    int size() const;
};

#endif