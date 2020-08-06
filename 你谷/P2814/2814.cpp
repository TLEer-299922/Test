#include<iostream>
#include<map>
#include<string>
struct Union
{
    void merge(std::string i, std::string j)
    {
        std::string fatheri = find(i), fatherj = find(j);
        if (fatheri == fatherj)
            return;
        nums[fatheri] = fatherj;
    }
    std::string find(std::string n)
    {
        std::string s = n;
        while (nums[n] != n)
            n = nums[n];
        while (s != n)
        {
            std::string t = nums[s];
            nums[s] = n;
            s = t;
        }
        return n;
    }
    bool is_bro(int i, int j)
    {
        int fi = find(i), fj = find(j);
        return fi == fj;
    }
    std::map<std::string, std::string> nums;
};
int main(){
    char c;
    std::string k,last_;
    do{
        std::cin >> c;
        if(c=='$')
            break;
        std::cin >> k;
        if(c=='#'){
            last_ = k;
        }
        
    } while (1);
    return 0;
}