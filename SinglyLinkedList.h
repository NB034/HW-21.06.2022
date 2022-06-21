#pragma once
#include <iostream>

struct elem {
	int val = 0;
	elem* next = nullptr;
};

class SinglyLinkedList {
	elem* head = nullptr;
	elem* tail = nullptr;
	int size = 0;
public:
	SinglyLinkedList() = default;
	SinglyLinkedList(const SinglyLinkedList& sll);
	SinglyLinkedList(SinglyLinkedList&& sll);
	~SinglyLinkedList();

	SinglyLinkedList& operator=(const SinglyLinkedList& sll);
	SinglyLinkedList& operator=(SinglyLinkedList&& sll);

	void print() const;
	void pushBack(int val);
	void pushFront(int val);
	void popBack();
	void popFront();
	void insert(int val, int index);
	void erase(int index);

	inline int* back() { return &this->tail->val; }
	inline int back() const { return this->tail->val; }
	inline int* front() { return &this->head->val; }
	inline int front() const { return this->head->val; }
	inline int getSize() const { return this->size; }
	inline bool empty() const { return this->head == nullptr; }
	inline void clear() { this->~SinglyLinkedList(); }

	void remove(int val);
	void reverse();
	void sort();
	void unique();
};