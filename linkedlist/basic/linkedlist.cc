#include "linkedlist.hpp"

int LinkedList::get(int index) const
{
    LinkedList *p = this->next;
    for (int i = 0; p && i < index; ++i)
        p = p->next;
    if (p)
        return p->val;
    return LinkedList::ERROR;
}

void LinkedList::addAtHead(int val)
{
    LinkedList *p = new LinkedList(val);
    p->prev       = this;
    p->next       = this->next;
    if (p->next)
        p->next->prev = p;
    this->next = p;
}

void LinkedList::addAtTail(int val)
{
    LinkedList *p = this;
    while (p->next)
        p = p->next;
    p->next       = new LinkedList(val);
    p->next->prev = p;
}

void LinkedList::addAtIndex(int index, int val)
{
    LinkedList *p, *q;
    p = findPrev(index);
    if (!p)
        return;
    q       = new LinkedList(val);
    q->next = p->next;
    q->prev = p;
    p->next = q;
    if (q->next)
        q->next->prev = q;
}

void LinkedList::deleteAtIndex(int index)
{
    LinkedList *p = findPrev(index);
    if (p && p->next) {
        LinkedList *tmp = p->next;
        p->next         = p->next->next;
        if (p->next)
            p->next->prev = p;
        delete tmp;
    }
}

LinkedList *LinkedList::findPrev(int index)
{
    LinkedList *p = this;
    for (int i = 0; p && i < index; ++i)
        p = p->next;
    return p;
}
