#include <iostream>

int coutPrimes(int n)
{
    if (n == 0 || n == 1) return 0;
    int cnt = 0;
    bool *aux = new bool[n];
    for (int i = 0; i < n; ++i) aux[i] = true;
    aux[0] = aux[1] = false;
    for (int i = 2; i * i < n; ++i) {
        if (!aux[i]) continue;
        for (int j = i*i; j < n; j+=i)
            aux[j] = false;
    }
    for (int i = 0; i < n; ++i) if (aux[i]) cnt++;
    delete [] aux;
    return cnt;
}

int main()
{
    std::cout << coutPrimes(10);
    return 0;
}
