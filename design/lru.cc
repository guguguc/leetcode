<<<<<<< HEAD
#include "lru.hpp"
#include <cassert>

int LRUQueue::pop()
{
    int res = list.front();
    list.pop_front();
    iter_table.erase(res);
    return res;
}

void LRUQueue::push(int item)
{
    list.push_back(item);
    iter_table[item] = --list.end();
}

void LRUQueue::moveBack(int item)
{
    if (list.back() == item)
        return;
    list.erase(iter_table.at(item));
    push(item);
}

bool LRUQueue::empty() const
{
    return list.empty();
}

bool LRUQueue::exist(int item) const
{
    return iter_table.find(item) != iter_table.end();
}

int LRUCache::get(int key)
{
    if (!hit(key))
        return -1;

    return cache.at(key);
}

void LRUCache::put(int key, int value)
{
    if (hit(key)) {
        update(key, value);
        return;
    }

    if (full())
        cache.erase(queue.pop());
    insert(key, value);
    queue.push(key);
}

void LRUCache::update(int key, int value)
{
    assert(cache.find(key) != cache.end());
    cache[key] = value;
}

void LRUCache::insert(int key, int value)
{
    assert(cache.find(key) == cache.end());
    cache[key] = value;
}

bool LRUCache::hit(int key)
{
    if (cache.find(key) == cache.end())
        return false;

    queue.moveBack(key);
    return true;
}

bool LRUCache::full() const
{
    return size() == capacity;
}

size_t LRUCache::size() const
{
    return cache.size();
}

=======
#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class LRUCache {
    typedef int ktype;
    typedef int vtype;

public:
    LRUCache(int capacity) : capacity(capacity), counter(0) {}

    int get(int key)
    {
        if (cache.count(key)) {
            cache[key].second = counter++;
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (size() < capacity) {
            if (get(key) == -1) {
                cache[key] = {value, counter++};
            }
            else {
                int weight = cache[key].second;
                cache[key] = {value, weight + 1};
            }
        }
        else {
            cache.erase(next());
            cache[key] = {value, counter++};
        }
    }

    ktype next()
    {
        ktype c;
        int min = INT_MAX;
        for (auto &[k, v] : cache) {
            if (v.second < min) {
                min = v.second;
                c   = k;
            }
        }
        return c;
    }

    int size() { return cache.size(); }

private:
    unordered_map<ktype, pair<vtype, int>> cache;
    int capacity;
    int counter;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cout << cache.get(2);
}
>>>>>>> 503552d4ae19e9dc0747cbc2d4e367428d91436f
