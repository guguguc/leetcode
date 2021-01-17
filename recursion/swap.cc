#include <vector>
#include <fmt/core.h>

#define swap_(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))
#define swap(a, b) ((&(a) == &(b)) ? (a) : swap_(a, b))

int main()
{
    std::vector<int> v{-1, -2};
    swap(v[0], v[1]);
    fmt::print("a={}, b={}", v[0], v[1]);
    return 0;
}
