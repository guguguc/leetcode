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

