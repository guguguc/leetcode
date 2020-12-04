#include <iostream>
#include <algorithm>
#include <cassert>
#include "linkedlist.hpp"

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

int main()
{
    LinkedList *list, *p;
    list = new LinkedList();
    p = list;

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

    return 0;
}
