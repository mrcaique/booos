// Caique Rodrigues Marques (13204303) e Fernando Jorge Mota (13200641)

#ifndef QUEUE_CC_
#define QUEUE_CC_

#include "Queue.h"
#include <stdio.h>
#include <iostream>

using namespace BOOOS;
using namespace std;

Queue::Queue() {
	this->_length = 0;
}

Queue::~Queue() {
	while (this->_length) {
		this->remove();
	}
}

bool Queue::check(Element *elem) {
	return this->search(elem) != NULL;
}

void Queue::insert(Element * elem) {
	if (this->check(elem)) {
		return;
	}
	if (this->_length == 0) {
		this->_head.next(elem);
		this->_head.prev(elem);
		elem->next(elem);
		elem->prev(elem);
	} else {
		this->_head.prev()->next(elem);
		elem->prev(this->_head.prev());
		elem->next(this->_head.next());
		this->_head.next()->prev(elem);
		this->_head.prev(elem);
	}
	this->_length++;
}

Queue::Element* Queue::remove() {
	if (this->_length == 0) {
		throw "ERROR"; // Empty queue
	}
	Element* out = this->_head.next();
	if (this->_length == 1) {
		this->_head.next(0);
		this->_head.prev(0);
	} else {
		Queue:Element *elem = out->next();
		this->_head.prev()->next(elem);
		this->_head.next(elem);
		elem->prev(this->_head.prev());
	}
	this->_length--;
	return out;
}

void Queue::remove(Element * e) {
	Element* sentinel = this->search(e);

	if (this->_length == 0 || sentinel == 0) {
		throw "ERROR";
	} else if (_length == 1) {
		this->remove();
		return;
	}

	Element* s_prev = sentinel->prev();
	Element* s_next = sentinel->next();
	if (sentinel == this->_head.prev()) {
		this->_head.prev(s_prev);
	} 
	if (sentinel == this->_head.next()) {
		this->_head.next(s_next);
	} 
	
	if (this->_length > 1) {
		s_prev->next(s_next);
		s_next->prev(s_prev);
	} else {
		this->_head.prev(0);
		this->_head.next(0);
	}
	this->_length--;
}

void Queue::insert_ordered(Element *elem) {
	if (this->check(elem)) {
		return;
	}
	if (this->_length == 0) {
		this->insert(elem);
		return;
	}
	Element* sentinel = _head.next();
	int count = 0;
	while (count < this->_length) {
		if (elem->rank() < sentinel->rank()) {
			break;
		}
		sentinel = sentinel->next();
		count++;
	}
	elem->next(sentinel);
	elem->prev(sentinel->prev());
	sentinel->prev()->next(elem);
	sentinel->prev(elem);
	if (count == 0) {
		this->_head.next(elem);
	} else if (count == this->_length) {
		this->_head.prev(elem);
	}
	this->_length++;
}

Queue::Element * Queue::search(Element * elem) {
	if (this->_length == 0) {
		return 0;
	}
	Element* sentinel = _head.next();
	do {
		if (sentinel == elem) {
			return sentinel;
		}
		sentinel = sentinel->next();
	} while (sentinel != this->head()->next());
	return 0;
}

#endif /* QUEUE_CC_ */