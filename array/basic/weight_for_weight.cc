#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int weight(const std::string &num)
{
    int w = 0;
    std::for_each(num.begin(), num.end(), [&](char c) { w += c - '0'; });
    return w;
}

bool comp(const std::string &left, const std::string &right)
{
    int lw = weight(left), rw = weight(right);
    return lw == rw ? left < right : lw < rw;
}

std::string orderWeight(const std::string &string)
{
    std::vector<std::string> vec;
    std::istringstream ss(string);
    std::string num;

    while (ss >> num) vec.push_back(num);
    std::sort(vec.begin(), vec.end(), comp);
    num.clear();
    for_each(vec.begin(), vec.end(), [&](const std::string &item) {
            num += item + ' '; });

    num.pop_back();
    return num;
}

void test()
{
    std::string str("56 65 74 100 99 68 86 180 90");
    std::cout << orderWeight(str);
}

int main()
{
    test();
    return 0;
}
