//2。根据算法2计算解决题目的程序代码：


/*问题描述

80年代全世界流行一种数字游戏，在中国我们把这种游戏称为“24点”。现在我们
把这个有趣的游戏推广一下：您作为游戏者将得到6个不同的自然数作为操作数，
以及另外一个自然数作为理想目标数，而您的任务是对这6个操作数进行适当的算
术运算，要求运算结果小于或等于理想目标数，并且我们希望所得结果是最优的，
即结果要最接近理想目标数。
您可以使用的运算只有：+，-，*，/，您还可以使用（）来改变运算顺序。注意：
所有的中间结果必须是整数，所以一些除法运算是不允许的（例如，（2*2）/4是
合法的，2*（2/4）是不合法的）
下面我们给出一个游戏的具体例子：
若给出的6个操作数是：1，2，3，4，7和25，理想目标数是573；
则最优结果是573：（（（4*25-1）*2）-7）*3。

输入：

输入文件名为game.in。输入文件仅一行，包含7个整数，前6个整数Mi,
1<=Mi<=100，表示操作数，最后一个整数T, 1<=T<=1000,表示理想目标数。

输出：

输出文件名为game.out。输出文件有两行，第一行仅一个整数，表示您的程序计算
得到的最优结果；第二行是一个表达式，即您得到的最优结果的运算方案。

输入输出示例：

输入文件

1 2 3 4 7 25 573

输出文件

573 

((4*25-1)*2)-7)*3

*/
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>
#include <cmath>
#include <climits>
#include <bitset>
using namespace std;

const char* INPUT_FILE  = "game.in";
const char* OUTPUT_FILE = "game.out";
const int NUMBER_COUNT  = 6;
const int STATE_COUNT   = (1 << NUMBER_COUNT);
const int MAX_NUMBER    = 100;
const int MAX_EXPECTION = 1000;
const int MAX_VALUE             = MAX_EXPECTION * MAX_NUMBER;

struct Node {
        int value;
        int left, right;        
        int leftvalue, rightvalue;
        char opr;
};

typedef list<Node> NodeList;

struct State {
        bitset<MAX_VALUE+10> exist;
        NodeList nodelist;
};

int number[NUMBER_COUNT], expection;
State state[STATE_COUNT];

void ReadData()
{
        ifstream fin(INPUT_FILE);
        
        for (int i = 0; i < NUMBER_COUNT; i++) {
                fin >> number[i];
        }
        fin >> expection;
}

void Init()
{
        Node node ;
        for (int i = 0; i < NUMBER_COUNT; i++) {
                node.value              = number[i];
                node.left = node.right = -1;
                state[(1 << i)].nodelist.push_back(node);
                state[(1 << i)].exist[node.value] = true;
        }
}

void Merge(int a, int b, int x)
{       
        Node node;      
        NodeList::const_iterator i, j;

        for (i = state[a].nodelist.begin(); i != state[a].nodelist.end(); 
i++) {
                for (j = state[b].nodelist.begin(); j != state[b].nodelist.en
d(); j++)
 {                                      
                        node.value = (*i).value + (*j).value;
                        node.left  = a;
                        node.right = b;                 
                        node.leftvalue  = (*i).value;
                        node.rightvalue = (*j).value;
                        node.opr   = '+';
                        if ( (node.value <= MAX_VALUE) && (!state[x].exist[no
de.value]) ) {
                                state[x].nodelist.push_back(node);
                                state[x].exist[node.value] = true;
                        }

                        /////////////////////////////////////////////////////
                        double tmp = double((*i).value) * double((*j).value);
                        if (tmp < INT_MAX) {
                                node.value = (*i).value * (*j).value;
                                node.left  = a;
                                node.right = b;
                                node.leftvalue  = (*i).value;
                                node.rightvalue = (*j).value;
                                node.opr   = '*';
                                if ( (node.value <= MAX_VALUE) && (!state[x].
exist[node.value]) ) 
{
                                        state[x].nodelist.push_back(node);
                                        state[x].exist[node.value] = true;
                                }
                        }

                        /////////////////////////////////////////////////////
                        if ((*i).value >= (*j).value) {
                                node.value = (*i).value - (*j).value;
                                node.left  = a;
                                node.right = b;
                                node.leftvalue  = (*i).value;
                                node.rightvalue = (*j).value;
                                node.opr   = '-';
                        } else {
                                node.value = (*j).value - (*i).value;
                                node.left  = b;
                                node.right = a;
                                node.leftvalue  = (*j).value;
                                node.rightvalue = (*i).value;
                                node.opr   = '-';
                        }
                                                
                        if ( (node.value <= MAX_VALUE) && (!state[x].exist[no
de.value]) ) {
                                state[x].nodelist.push_back(node);
                                state[x].exist[node.value] = true;
                        }

                        /////////////////////////////////////////////////////

                        if ( ((*j).value != 0) && ((*i).value >= (*j).value) && 
                                        ((*i).value % (*j).value == 0) ) 
                        {
                                node.value = (*i).value / (*j).value;
                                node.left  = a;
                                node.right = b;         
                                node.leftvalue  = (*i).value;
                                node.rightvalue = (*j).value;
                                node.opr   = '/';
                        } else if ( ((*i).value != 0) && ((*j).value >= (*i).
value) && 
                                        ((*j).value % (*i).value == 0) ) 
                        {
                                node.value = (*j).value / (*i).value;
                                node.left  = b;
                                node.right = a;
                                node.leftvalue  = (*j).value;
                                node.rightvalue = (*i).value;
                                node.opr   = '/';
                        }
                                                
                        if ( (node.value <= MAX_VALUE) && (!state[x].exist[no
de.value]) ) 
{                               
                                state[x].nodelist.push_back(node);
                                state[x].exist[node.value] = true;
                        }                       
                        /////////////////////////////////////////////////////
                }
        }
}

void Solve()
{
        Init(); 
        
        for (int x = 2; x < STATE_COUNT; x++) {
                for (int i = 1; i < x; i++) {                   
                        if ( (x & i) == i ) {
                                int j = x - i;
                                if (i <= j) {
                                        Merge(i, j, x);         
                                }
                        }
                }
        }
}

void PrintExpression(ostream& out, Node node)
{
        if (node.left == -1) {
                out << node.value;
        } else {
                NodeList::const_iterator iter;
                
                out << "(";

                for (iter = state[node.left].nodelist.begin();
                                iter != state[node.left].nodelist.end();
                                iter++)
                {
                        if ((*iter).value == node.leftvalue) {
                                PrintExpression(out, *iter);
                                break;
                        }
                }

                out << node.opr;

                for (iter = state[node.right].nodelist.begin();
                                iter != state[node.right].nodelist.end();
                                iter++)
                {
                        if ((*iter).value == node.rightvalue) {
                                PrintExpression(out, *iter);
                                break;
                        }
                }

                out << ")";
        }               
}

void Output()
{
        ofstream fout(OUTPUT_FILE);

        int bestValue = -INT_MAX;       
        NodeList::const_iterator iter, bestIter;

        NodeList& nodelist = state[STATE_COUNT-1].nodelist;

        for (iter = nodelist.begin(); iter != nodelist.end(); iter++) 
        {       
                if ( ((*iter).value <= expection) && (bestValue < (*iter).val
ue) ) {
                        bestValue = (*iter).value;
                        bestIter  = iter;
                }
        }       
        fout << bestValue << endl;
        PrintExpression(fout, *bestIter );
        fout << endl;
}

int main()
{
        ReadData();
        Solve();
        Output();
        return 0;
}