/* 
    Title : RMQ(Range Minimum Query)问题的Binary Tree解法， 
            查询一指定数列任意一段区间内最(大)元素的位置 
    Time Complex : O(n) 预处理， O(logn) 每次查询 
    Space Complex : O(3*n) Total space 
    Author : song 
    Date : 9.3.2005 
*/ 
#include <cstdio> 
const int MAX = 1<<16;  //MAX is a power of 2 and just bigger than n 
int key[MAX];           //数列 
int n;                  //数列长度 
int pp[MAX*2];          //binary tree数组,pp[i]保存i子树覆盖的区间里最值的序号 

inline bool RMQcmp(int i, int j)    //比较函数 
{ 
    //like a heap, here we us > to get a Minimum Result, 
    //and < to get a Maximum one 
    return key[i] > key[j];      
}    

void RMQCreate()           //预处理，建树 
{ 
     int f = MAX, t = MAX + n - 1, i; 
     for(i = 0; i < n; ++i) 
        pp[i+MAX] = i; 
     for( ;f < t; f /= 2, t /= 2) 
     { 
        for(i = f; i < t ; i+= 2) 
        { 
            if( !RMQcmp(pp[i], pp[i+1]) ) 
                pp[i/2] = pp[i]; 
            else pp[i/2] = pp[i+1]; 
        } 
        if(!(t&1)) pp[t/2] = pp[t]; 
     } 
} 

int RMQFind(int ss, int ee)     //返回原数列key[ss - ee]之间最大(小)元素的序号 
{ 
    int k, f, t; 
    ss += MAX, ee += MAX; 
    k = !RMQcmp(pp[ss] ,pp[ee]) ? pp[ss] : pp[ee]; 
    for( f = ss, t = ee; f < t; f/=2, t/=2) 
    { 
        if( !(f&1) && f + 1 < t && !RMQcmp(pp[f+1], k)) 
            k = pp[f+1]; 
        if( (t&1)  && t - 1 > f && !RMQcmp(pp[t-1], k)) 
            k = pp[t-1]; 
    } 
    return k; 
} 

int main() 
{ 
    /* 
        main()里做的事： 
        1.先初始化好key数列,及比较函数RMQcmp()。key[]的名字可改，只要cmp对应上就行。 
        2.调用RMQCreate()预处理 
        3.查询key[0,n-1]之间最大(小)元素的序号，只需调用RMQFind(0, n-1) 
    */ 
    return 0; 
}    

