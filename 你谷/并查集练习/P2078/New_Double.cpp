#include<iostream>
#include<vector>
struct Union {
    Union(int n) {
        a.resize(n+1);
        for (int i=1;i<=n;i++) {
            a[i]=i;
        }
    }
    int find(int n) {
        return a[n]==n?n:a[n]=find(a[n]);
    }
    void merge(int n, int m) {
        a[find(n)]=find(m);
    }
    bool bro(int n, int m) {
        return find(n)==find(m);
    }
    std::vector<int>a;
};
int n, m, p, q, ansa=1, ansb=1, x, y;
int main() {
    std::cin>>n>>m>>p>>q;
    Union A(n), B(m);
    for (int i=1;i<=p;i++) {
        std::cin>>x>>y;
        A.merge(x, y);
    }
    for (int i=1;i<=q;i++) {
        std::cin>>x>>y;
        B.merge(-x, -y);
    }
    for (int i=2;i<=n;i++) {
        if (A.bro(i, 1))ansa++;
    }
    for (int i=2;i<=m;i++) {
        if (B.bro(i, 1))ansb++;
    }
    if (ansb<ansa) {
        std::cout<<ansb<<std::endl;
    }
    else {
        std::cout<<ansa<<std::endl;
    }
    return 0;
}