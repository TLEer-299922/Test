#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
int fread()
{
    char c = getchar();
    int n;
    while (c < '0' || c > '9')
        c = getchar();
    n = c - '0';
    while (c >= '0' && c <= '9')
    {
        c = getchar();
        if (c < '0' || c > '9')
            break;
        n *= 10;
        n += c - '0';
    }
    return n;
}
struct heap
{
    void init()
    {
        val[++n] = fread();
        wh(n);
    }
    void wh(int i)
    {
        if (i == 1)
            return;
        if (val[i] < val[i / 2])
        {
            std::swap(val[i], val[i / 2]);
            wh(i / 2);
        }
    }
    void whf(int i)
    {
        if (i * 2 < n && val[i * 2] < val[i] && val[i] > val[i * 2 + 1])
        {
            if (val[i * 2] < val[i * 2 + 1])
            {
                std::swap(val[i * 2], val[i]);
                whf(i * 2);
            }
            else
            {
                std::swap(val[i * 2 + 1], val[i]);
                whf(i * 2 + 1);
            }
        }
        else if (i * 2 <= n && val[i * 2] < val[i])
        {
            std::swap(val[i * 2], val[i]);
            whf(i * 2);
        }
        else if (i * 2 < n && val[i * 2 + 1] < val[i])
        {
            std::swap(val[i * 2 + 1], val[i]);
            whf(i * 2 + 1);
        }
    }
    void print()
    {
        std::cout << val[1] << std::endl;
    }
    void del()
    {
        std::swap(val[1], val[n]);
        n--;
        whf(1);
    }
    int val[200005], n;
} H;
int main()
{
    H.n = 0;
    int n = fread(), x;
    for (int i = 0; i < n; i++)
    {
        x = fread();
        if (x == 1)
            H.init();
        if (x == 2)
            H.print();
        if (x == 3)
            H.del();
    }
    return 0;
}