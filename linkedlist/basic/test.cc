#include "linkedlist.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

void displayList(LinkedList *list)
{
    LinkedList *p = list->next;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void test1()
{
    LinkedList *list, *p;
    list = new LinkedList();
    p    = list;
    cout << "test add at tail\n";
    for (int i = 1; i < 10 + 1; ++i)
        p->addAtTail(i);
    displayList(list);
    cout << "test add at head\n";
    p->addAtHead(0);
    displayList(list);
    cout << "test get\n";
    assert(p->get(2) == 2);
    assert(p->get(100) == -1);
    cout << "test delete\n";
    p->deleteAtIndex(5);
    displayList(list);
}

void test2()
{
    LinkedList *list = new LinkedList();
    list->addAtHead(1);
    list->addAtTail(3);
    displayList(list);
    list->addAtIndex(1, 2);
    displayList(list);
    assert(list->get(1) == 2);
    list->deleteAtIndex(1);
    displayList(list);
    assert(list->get(1) == 3);
}

int main()
{
    test1();
    test2();
    return 0;
}
