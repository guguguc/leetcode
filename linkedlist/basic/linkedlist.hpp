
class LinkedList {
public:
    LinkedList(): prev(nullptr), next(nullptr){ }
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index);
    void deleteAtIndex(int index);
private:
    int val;
    LinkedList *prev;
    LinkedList *next;
};

