#include "lru.hpp"

int LRUCache::get(int key)
{
    ++(_access_count);

    if (!hit(key))
        return -1;

    ++(_hit_count);
    moveBack(key);
    return (*cache.at(key)).val;
}

void LRUCache::put(int key, int value)
{
    ++(_access_count);

    if (hit(key)) {
        ++(_hit_count);
        (*cache.at(key)).val = value;
        moveBack(key);
        return;
    }

    if (size() == _capacity) {
        cache.erase(list.front().key);
        list.pop_front();
    }
    list.push_back(KVItem(key, value));
    cache[key] = --list.end();
}

void LRUCache::moveBack(int key)
{
    auto pos = cache.at(key);
    list.splice(list.end(), list, pos);
}

bool LRUCache::hit(int key) const
{
    return cache.find(key) != cache.end();
}

size_t LRUCache::capacity() const
{
    return _capacity;
}

size_t LRUCache::size() const
{
    return list.size();
}

size_t LRUCache::access_count() const
{
    return _access_count;
}

size_t LRUCache::hit_count() const
{
    return _hit_count;
}

double LRUCache::hit_rate() const
{
    return static_cast<double>(_hit_count) / (_access_count);
}
