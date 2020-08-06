#include <iostream>
using namespace std;
int head=0, last=0;
struct point
{
    int next, val;
}a[100005];
int main()
{
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        a[i].val=x;
        a[i].next=-1;
        a[i-1].next=i;
        int k=head;
        while (a[k].val<x) {
            if (a[k].next==k)break;
            cout<<-1;
            k=a[k].next;
        }
        if (k==head&&a[head].next!=-1) {
            a[i].next=head;
            head=i;
        }
        else if (a[k].next==-1) {
            a[k].next=i;
        }
        else {
            int s=a[k].next;
            a[k].next=i;
            a[i].next=s;
        }
    }
    for (int i = 0; i!=-1;i++)
    {
        cout << a[i].val << ' ';
        i = a[i].next;
    }
    return 0;
}