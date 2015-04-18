/*
 * Queue_Test.cc
 *
 */
 
#include <iostream>
#include "../Queue.h"
 
using namespace std;
using namespace BOOOS;

class MyElement : public Queue::Element {
public:
    MyElement(string str) : _name(str) {}
 
    virtual ~MyElement() {}
 
    string & name() { return _name; }
 
private:
    string _name;
};

void print_queue(Queue & q) {
    cout << "Queue length: " << q.length() << endl;
 
    if(q.length()) {
        MyElement * elem = dynamic_cast<MyElement *>(q.head()->next());
        do {
            cout << elem->name() << endl;
            elem = dynamic_cast<MyElement *>(elem->next());
        } while (elem != q.head()->next());
    }
 
    cout << "==============================" << endl;
}
 
int main() {
    cout << "Welcome to BOOOS - Basic Object Oriented Operating System!" << endl;
    cout << "This program will test the class: Queue" << endl;
 
    Queue queue;
 
    MyElement * person1 = new MyElement("João");
    MyElement * person2 = new MyElement("Pedro");
    MyElement * person3 = new MyElement("Augusto");
    MyElement * person4 = new MyElement("Fábio");
    print_queue(queue);

    queue.insert(person1);
    print_queue(queue);
    queue.insert(person2);
    print_queue(queue);
    queue.insert(person3);
    print_queue(queue);
    queue.insert(person4);
    print_queue(queue);
 
    MyElement * removed_person = dynamic_cast<MyElement*>(queue.remove());
    delete removed_person; // Which element was removed?
    print_queue(queue);
    removed_person = dynamic_cast<MyElement*>(queue.remove());
    delete removed_person; // Which element was removed?
    print_queue(queue);
    removed_person = dynamic_cast<MyElement*>(queue.remove());
    delete removed_person; // Which element was removed?
    print_queue(queue);
    removed_person = dynamic_cast<MyElement*>(queue.remove());
    delete removed_person; // Which element was removed?
    print_queue(queue);
 
    return 0;
} 
