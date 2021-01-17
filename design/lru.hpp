#include <vector>
#include <unordered_map>
#include <list>

class LRUQueue {
public:
    int pop();
    void push(int item);
    void moveBack(int item);
    bool empty() const;
    bool exist(int) const;

private:
    std::list<int> list;
    std::unordered_map<int, std::list<int>::iterator> iter_table;
};

class LRUCache {
    typedef int ktype;
    typedef int vtype;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    void put(int key, int value);
    int get(int key);
    bool hit(int key);
    bool full() const;
    size_t size() const;

private:
    void update(int key, int value);
    void insert(int key, int value);

private:
    std::unordered_map<ktype, vtype> cache;
    LRUQueue queue;
    int capacity;
};

