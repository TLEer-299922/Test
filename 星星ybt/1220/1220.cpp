/*#include <iostream>
#include <cmath>
#include <string>
std::string sont(std::string a, int n)
{
    std::string ans = "";
    for (int i = 0; i <= n; i++)
    {
        ans += a[i];
    }
    return ans;
}
std::string sonw(std::string a, int n)
{
    std::string ans = "";
    for (int i = a.size() - n; i <= n; i++)
    {
        ans += a[i];
    }
    return ans;
}
struct word
{
    char head;
    std::string val;
    word *nexta[10001];
    int nextt[10001];
    int nextval = 0;
    int havecishu = 2;
    void input()
    {
        std::cin >> val;
        head = val[0];
    }
    void pipnext(word a[], int n)
    {
        bool is = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].val == val)
                continue;
            int j = val.size() - 1;
            if (std::max(a[i].val.size(), j + 1) == a[i].val.size())
                continue;
            for (; j >= 0; j--)
            {
                if (sont(a[i].val, j) == sonw(val, j))
                    break;
            }
            if (j >= 0)
            {
                nextt[nextval] = j;
                nexta[nextval++] = &a[i];
                is = 1;
            }
        }
        if (is)
            nextval--;
    }
    void printnext()
    {
        std::cout << "This is " << val << ",It has " << nextval << " next." << std::endl;
        for (int i = 0; i < nextval; i++)
        {
            std::cout << i + 1 << ". " << nexta[i]->val << std::endl;
        }
    }
    word lian(word a,word b)

} a[10001];
std::string dfs(std::string c, word as)
{
    for (int i = 0; i < as.nextval; i++)
    {
        if (as.nexta[i]->havecishu)
            word a = *as.nexta[i];
        std::string answ = dfs(c + as.nexta[i]->val, *(as.nexta[i]));
        if (answ > c)
            c = answ;
    }
    return c;
}
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; i++)
        a[i].input();
    for (int i = 0; i <= n; i++)
        a[i].pipnext(a, n + 1);
    for (int i = 0; i <= n; i++)
        a[i].printnext();
    std::string ans = dfs(a[n].val, a[n]);
    std::cout << ans << std::endl;
    return 0;
}*/
#include <iostream>
#include <string>
int ans, n;
std::string word[30], beg;
int used[30];
void add(std::string &ift, std::string bh, int kk)
{
    int bsiz = bh.size();
    for (int i = kk; i < bsiz; i++)
    {
        ift += bh[i];
    }
}
bool ck(std::string ift, std::string bh, int kk)
{
    int bsiz = ift.size();
    for (int i = 0; i < kk; i++)
    {
        if (ift[bsiz - kk + i] != bh[i])
            return false;
    }
    return true;
}
void dfs(std::string answ)
{
    int ansize = answ.size();
    if (ansize > ans)
        ans = ansize;
    for (int i = 1; i <= n; i++)
    {
        if (used[i] > 1)
            continue;
        int maxsize = word[i].size();
        for (int j = 1; j <= maxsize; j++)
        {
            if (ck(answ, word[i], j))
            {
                std::string t = answ;
                add(t, word[i], j);
                if (t == answ)
                    continue;
                used[i]++;
                dfs(t);
                used[i]--;
            }
        }
    }
}
int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> word[i];
    std::cin >> beg;
    dfs(beg);
    std::cout << ans << std::endl;
    return 0;
}