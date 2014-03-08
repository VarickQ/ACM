/* 
    Title : RMQ(Range Minimum Query)�����Binary Tree�ⷨ�� 
            ��ѯһָ����������һ����������(��)Ԫ�ص�λ�� 
    Time Complex : O(n) Ԥ���� O(logn) ÿ�β�ѯ 
    Space Complex : O(3*n) Total space 
    Author : song 
    Date : 9.3.2005 
*/ 
#include <cstdio> 
const int MAX = 1<<16;  //MAX is a power of 2 and just bigger than n 
int key[MAX];           //���� 
int n;                  //���г��� 
int pp[MAX*2];          //binary tree����,pp[i]����i�������ǵ���������ֵ����� 

inline bool RMQcmp(int i, int j)    //�ȽϺ��� 
{ 
    //like a heap, here we us > to get a Minimum Result, 
    //and < to get a Maximum one 
    return key[i] > key[j];      
}    

void RMQCreate()           //Ԥ�������� 
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

int RMQFind(int ss, int ee)     //����ԭ����key[ss - ee]֮�����(С)Ԫ�ص���� 
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
        main()�������£� 
        1.�ȳ�ʼ����key����,���ȽϺ���RMQcmp()��key[]�����ֿɸģ�ֻҪcmp��Ӧ�Ͼ��С� 
        2.����RMQCreate()Ԥ���� 
        3.��ѯkey[0,n-1]֮�����(С)Ԫ�ص���ţ�ֻ�����RMQFind(0, n-1) 
    */ 
    return 0; 
}    

