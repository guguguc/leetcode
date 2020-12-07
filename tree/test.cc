#include "tree.h"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int genRandom(int min, int max) { return min + rand() % (max - min + 1); }

void testInsert()
{
    BinaryTree tree = BinaryTree();
    const int N     = 10000000;
    vector<int> vec(N);
    generate(vec.begin(), vec.end(), [&]() { return genRandom(1, N); });
    for (const auto &v : vec)
        tree.insert(v);
}

void testBuild()
{
    const string pre_order_seq = "ABDFCEGH";
    const string in_order_seq  = "BFDAGEHC";
}

void testIsAVL()
{
    BinaryTree t1(vector<int>({1, 2, 3, 4, 5}));
    assert(isAVL(t1) == false);

    BinaryTree t2(vector<int>({5, 2, 7, 6, 1, -1}));
    assert(isAVL(t2) == false);

    BinaryTree t3(vector<int>({5, -4, 8, 9, 6, -2}));
    assert(isAVL(t3) == true);

    cout << "[*] test success in 3 cases\n";
}

int main()
{
    srand(time(nullptr));
    testIsAVL();

    return 0;
}
