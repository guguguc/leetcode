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
