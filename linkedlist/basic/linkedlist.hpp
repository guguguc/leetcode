#include <functional>
#include <vector>

class LinkedList {
public:
    const static int ERROR = -1;

public:
    LinkedList() : LinkedList(0) {}
    LinkedList(int val) : val(val), prev(nullptr), next(nullptr) {}
    int get(int index) const;
    LinkedList *findPrev(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);

public:
    int val;
    LinkedList *prev;
    LinkedList *next;
};
