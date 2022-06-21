#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& sll) {
	elem* tmpElem = sll.head;
	while (tmpElem != nullptr) {
		this->pushBack(tmpElem->val);
		tmpElem = tmpElem->next;
	}
}
SinglyLinkedList::SinglyLinkedList(SinglyLinkedList&& sll) {
	std::swap(this->head, sll.head);
	std::swap(this->tail, sll.tail);
	std::swap(this->size, sll.size);
}
SinglyLinkedList::~SinglyLinkedList() {
	while (this->head != nullptr)
		this->popFront();
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& sll) {
	if (this == &sll)
		return *this;
	this->~SinglyLinkedList();
	elem* tmpElem = sll.head;
	while (tmpElem != nullptr) {
		this->pushBack(tmpElem->val);
		tmpElem = tmpElem->next;
	}
	return *this;
}
SinglyLinkedList& SinglyLinkedList::operator=(SinglyLinkedList&& sll) {
	std::swap(this->head, sll.head);
	std::swap(this->tail, sll.tail);
	std::swap(this->size, sll.size);
	return *this;
}

void SinglyLinkedList::print() const {
	elem* tmp = this->head;
	while (tmp != nullptr) {
		if (tmp != this->head)
			std::cout << ' ';
		std::cout << tmp->val;
		tmp = tmp->next;
	}
}
void SinglyLinkedList::pushBack(int val) {
	elem* nElem = new elem;
	nElem->val = val;
	this->size++;
	if (this->head == nullptr) {
		this->head = this->tail = nElem;
		return;
	}
	this->tail->next = nElem;
	this->tail = nElem;
}
void SinglyLinkedList::pushFront(int val) {
	elem* nElem = new elem;
	nElem->val = val;
	this->size++;
	if (this->head == nullptr) {
		this->head = this->tail = nElem;
		return;
	}
	nElem->next = this->head;
	this->head = nElem;
}
void SinglyLinkedList::popBack() {
	if (this->head == nullptr)
		return;
	if (this->head == this->tail) {
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
		return;
	}
	elem* tmp = this->head;
	while (tmp->next != this->tail) {
		tmp = tmp->next;
	}
	tmp->next = nullptr;
	delete this->tail;
	this->tail = tmp;
	this->size--;
}
void SinglyLinkedList::popFront() {
	if (this->head == nullptr)
		return;
	if (this->head == this->tail) {
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
		return;
	}
	elem* tmp = this->head->next;
	delete this->head;
	this->head = tmp;
	this->size--;
}
void SinglyLinkedList::insert(int val, int index) {
	if (index < 0 || index > this->size)
		return;
	if (index == 0) {
		this->pushFront(val);
		return;
	}
	if (index == this->size) {
		this->pushBack(val);
		return;
	}
	elem* nElem = new elem;
	nElem->val = val;
	elem* tmpElem = this->head;
	int tmp = 0;
	while (tmp < index - 1) {
		tmpElem = tmpElem->next;
		tmp++;
	}
	nElem->next = tmpElem->next;
	tmpElem->next = nElem;
	this->size++;
}
void SinglyLinkedList::erase(int index) {
	if (index < 0 || index > this->size - 1)
		return;
	if (index == 0) {
		this->popFront();
		return;
	}
	if (index == this->size - 1) {
		this->popBack();
		return;
	}
	elem* tmpElem = this->head;
	for (size_t i = 0; i < index - 1; i++)
		tmpElem = tmpElem->next;
	elem* tmpElem2 = tmpElem->next->next;
	delete tmpElem->next;
	tmpElem->next = tmpElem2;
	this->size--;
}

void SinglyLinkedList::remove(int val) {
	if (this->head == nullptr)
		return;
	if (this->size == 1 && this->head->val == val) {
		this->popBack();
		return;
	}
	elem* tmp = this->head;
	int index = 0;
	while (tmp != nullptr) {
		if (tmp->val == val) {
			tmp = tmp->next;
			this->erase(index);
			continue;
		}
		tmp = tmp->next;
		index++;
	}
}
void SinglyLinkedList::reverse() {
	if (this->head == nullptr || this->size == 1)
		return;
	if (this->size == 2) {
		std::swap(this->head, this->tail);
		return;
	}
	elem* first = this->head;
	elem* second = this->tail;
	elem* tmp;
	while (second->next != first && first != second) {
		std::swap(first->val, second->val);
		first = first->next;
		tmp = this->head;
		while (tmp->next != second)
			tmp = tmp->next;
		second = tmp;
	}
}
void SinglyLinkedList::sort() {
	if (this->head == nullptr)
		return;
	elem* start = this->head;
	elem* min;
	elem* step;
	while (start->next != nullptr) {
		min = start;
		step = start;
		while (step != nullptr) {
			if (min->val > step->val)
				min = step;
			step = step->next;
		}
		std::swap(start->val, min->val);
		start = start->next;
	}
}
void SinglyLinkedList::unique() {
	if (this->head == nullptr || this->size == 1)
		return;
	if (this->size == 2) {
		if (this->head == this->tail)
			this->popBack();
		return;
	}
	elem* tmp = this->head;
	while (tmp->next != nullptr) {
		if (tmp->val > tmp->next->val)
			return;
		tmp = tmp->next;
	}
	tmp = this->head;
	int index = 0;
	while (tmp->next != nullptr) {
		if (tmp->val == tmp->next->val) {
			tmp = tmp->next;
			this->erase(index);
			continue;
		}
		tmp = tmp->next;
		index++;
	}
}
