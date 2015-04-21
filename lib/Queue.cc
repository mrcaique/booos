#ifndef QUEUE_CC_
#define QUEUE_CC_

#include "Queue.h"

using namespace BOOOS;

Queue::Queue() {
	_length = 0;
}

Queue::~Queue() {}

void Queue::insert(Element * elem) {
	if (_length < 1) {
		_head.next(elem);
		_head.prev(elem);
		elem->next(elem);
		elem->prev(elem);
	} else {
		Element* end = _head.prev();
		end->next(elem);
		elem->prev(end);
		elem->next(_head.next());
		_head.prev(elem);
	}
	_length++;
}

Queue::Element* Queue::remove() {
	if (_length < 1) {
		throw "ERROR"; // Empty queue
	}
	Element* out = _head.next();
	if (_length < 2) {
		_head.next(&(_head));
		_head.prev(&(_head));
	} else {
		Element* end = _head.prev();
		end->next(out->next());
		_head.next(out->next());
		out->next()->prev(end);
	}
	_length--;
	return out;
}

#endif /* QUEUE_CC_ */
