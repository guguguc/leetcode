#include "lru.hpp"
#include <cassert>
#include <iostream>

void test()
{

    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(1, 1);
    std::cout << cache.get(2) << "\n";
    cache.put(4, 1);
    std::cout << cache.get(1) << "\n";
    std::cout << cache.get(2) << "\n";
}

using namespace std;
int main()
{
    test();
    return 0;
}
