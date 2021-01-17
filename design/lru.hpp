#include <vector>
#include <unordered_map>
#include <list>

class KVItem {
public:
    KVItem(int key, int val): key(key), val(val) {}
    int key;
    int val;
};

class LRUCache {
    typedef int ktype;
    typedef int vtype;

public:
    LRUCache(int capacity) : _capacity(capacity), _hit_count(0), _access_count(0) {}
    int get(int key);
    void put(int key, int value);
    bool hit(int key) const;
    size_t capacity() const;
    size_t size() const;
    size_t hit_count() const;
    size_t access_count() const;
    double hit_rate() const;

private:
    void moveBack(int key);

private:
    std::unordered_map<ktype, std::list<KVItem>::iterator> cache;
    std::list<KVItem> list;
    size_t _capacity;
    size_t _hit_count;
    size_t _access_count;
};

