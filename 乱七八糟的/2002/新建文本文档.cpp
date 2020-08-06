#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
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
int a[100001][2], asd;
int messon(int n)
{
	int x = n, j = 1, ans = 0;
	while (n)
	{
		j *= 10;
		int c = n % 10;
		for (int i = 0; i < asd; i++)
		{
			n /= 10;
			if (c == a[i][0])
				ans++, n *= 10, n += a[i][1], messon(n * j + x % j);
		}
	}
	return ans;
}
int main()
{
	int ans = 1;
	int n, m;
	cin >> n >> m;
	asd = m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	ans = messon(n);
	cout << ans << endl;
	return 0;
}
//
