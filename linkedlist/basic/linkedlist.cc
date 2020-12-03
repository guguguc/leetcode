#include "linkedlist.hpp"

int LinkedList::get(int index)
{
  LinkedList *p = this;
  for (int i = 0; p && i != index; ++i, p = p->next)
    ;
  if (!p)
    return -1;
  return p->val;
}

void LinkedList::addAtHead(int val)
{
  LinkedList *p = new LinkedList();
  p->val = val;
  p->next = this->next == nullptr ? nullptr : this->next->next;
  this->next = p;
}

void LinkedList::addAtTail(int val)
{
  LinkedList *p = this;
  while (p->next) p = p->next;
  p->next = new LinkedList();
  p->next->val = val;
}

void LinkedList::addAtIndex(int index)
{
  LinkedList *p = this;
  for (int i = 0; p && i != index - 1; p=p->next, ++i);
}
