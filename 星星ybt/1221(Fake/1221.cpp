#include <bits/stdc++.h>
#define ULL unsigned long long;
using namespace std;
int n, a[21], cnt = 99999;
ULL b[21];
ULL gcd(ULL a, ULL b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
void dfs(int k, int step)
{
	if (step == n + 1)
	{
		if (k < cnt)
			cnt = k;
		return;
	}
	for (int i = 1; i <= k; i++)
	{
		if (gcd(b[i], a[step]) == 1)
		{
			b[i] *= a[step];
			dfs(k, step + 1);
			b[i] /= a[step];
		}
		b[k + 1] *= a[step];
		dfs(k + 1, step + 1);
		b[k + 1] /= a[step];
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = 1;
	}
	sort(a + 1, a + 1 + n);
	dfs(1, 1);
	cout << cnt << endl;
	return 0;
}