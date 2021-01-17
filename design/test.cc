#include "lru.hpp"
#include <iostream>
#include <random>

using namespace std;

constexpr size_t N = 100000;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> distrib(1, 100), d1(1, 20), d2(21, 100);

void random_access(LRUCache& cache)
{
    for (int i = 0; i < N; ++i)
        cache.put(distrib(gen), i);
}

void locality_acess(LRUCache& cache)
{
    for (int i = 0; i < N; ++i)
        cache.put(distrib(gen) <= 80 ? d1(gen) : d2(gen), i);
}

void test()
{
    freopen("local_hit_rate.txt", "w", stdout);
    // freopen("random_hit_rate.txt", "w", stdout);
    // 1024 cache size
    auto acess_func = locality_acess;
    for (size_t n = 5; n <= 100; n+=5) {
        LRUCache cache(n);
        acess_func(cache);
        cout << cache.hit_rate() << "\n";
    }
}

int main()
{
    test();
    return 0;
}
