#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
inline int read()
{
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            flag = false;
            ch = getchar();
        }
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x - 1);
}
inline void write(int X)
{
    if (X < 0)
    {
        X = ~(X - 1);
        putchar('-');
    }
    if (X > 9)
        write(X / 10);
    putchar(X % 10 + '0');
}
using namespace std;
struct cxk
{
public:
    int shili, bianh, fenshu;
} a[200001];
bool cmp(cxk a, cxk b)
{
    if (a.fenshu != b.fenshu)
        return a.fenshu > b.fenshu;
    return a.bianh < b.bianh;
}
int main()
{
    int r, n, q;
    n = read();
    r = read();
    q = read();
    // cout<<n<<' '<<r<<' '<<q<<endl;
    for (int i = 0; i < n * 2; i++)
    {
        a[i].fenshu = read();
    }
    for (int i = 0; i < n * 2; i++)
    {
        a[i].shili = read();
        a[i].bianh = i + 1;
    }
    /*for (int i = 0; i < n * 2; i++)
    {
        cout << a[i].bianh << ' ' << a[i].fenshu << endl;
    }
    cout << endl;*/
    sort(a, a + n * 2, cmp);
    /*for (int i = 0; i < n * 2; i++)
    {
        cout << a[i].bianh << ' ' << a[i].fenshu << endl;
    }
    cout << endl;*/
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < n * 2; j += 2)
        {
            if (a[j].shili < a[j + 1].shili)
                a[j + 1].fenshu++ /*,cout<<"a["<<j+1<<"]->"*/;
            else
                a[j].fenshu++ /*,cout<<"a["<<j<<"]->"*/;
        }
        /*for (int i = 0; i < n * 2; i++)
        {
            cout << a[i].bianh << ' ' << a[i].fenshu << endl;
        }*/
        sort(a, a + n * 2, cmp);
    }
    /*for(int i=0;i<n*2;i++)
    {
        cout<<a[i].bianh<<' '<<a[i].fenshu<<endl;
    }*/
    int x = a[q - 1].bianh;
    write(x);
    return 0;
}
/*
input:
2 4 3
107 106 106 107
100 50 200 150

output:
4

input:
2 4 2 
7 6 6 7 
10 5 20 15 

output:
1
*/