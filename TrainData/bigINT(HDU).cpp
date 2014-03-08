#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef int   INT;
#define BASE  1000000   //���� 
#define NUM   100       //���Ա�ʾ��������Ϊ BASE^(NUM-1);
#define N     6
class  BigNum
{
    private:	
        INT num[NUM];	
        INT len;         //��ǰ���ĳ���	
        INT flag;       //1������0����
        public:	BigNum()	
        {		
            len=1;		
            num[0]=0;		
            flag=1;	
        };	
        BigNum( const BigNum & value);   //��������	
        BigNum( string str);		//����������   �ַ������ɴ���	
        BigNum( INT value);              //32��ת��Ϊ����	
        void add( BigNum &first, BigNum &second);//�������	
        void sub( BigNum &first, BigNum &second);//�������	
        void GetNum(INT* _num);                 //ȡ����ʾ����������	
        INT GetPointer(); 	INT GetFlag();                     //������	
        bool Iszero();                       //�ж����Ƿ�Ϊ0	
        bool Isoneyushu();                  //�ж������Ƿ�Ϊ1	
        BigNum	operator + ( BigNum &first);  //���������	
        void	operator += ( BigNum &first);	
        BigNum	operator + ( INT first);	
        void	operator += ( INT first);	
        BigNum	operator - ( BigNum &first);	
        void	operator -= ( BigNum &first);	
        BigNum  operator - (INT first);	
        void operator -= (INT first);	
        BigNum	operator * ( INT first);	
        void	operator *= ( INT first);	
        BigNum  operator * (BigNum &);          //δʵ��	
        void    operator *= (BigNum &);        //δʵ��	
        BigNum	operator / (INT first );	
        void	operator /= ( INT first);	
        INT  operator  % (INT first);				
        friend bool IsMax(BigNum &first,BigNum &second);	
        friend void print(BigNum result);
};


INT  BigNum:: operator  % (INT first)
{	
        BigNum temp;	
        temp=*this/first;	
        temp*=first;	
        temp=*this-temp;	//temp=*this-*this/first*first;	
        return temp.num[0];
}
bool BigNum::Iszero ()
{	
        if((len==1||len==0)&&num[0]==0)		
        return true;	
        else		
        return false;
}                        
bool BigNum::Isoneyushu()
{	
        if(num[0]/2)		
        return true;	
        else		
        return false;
}
BigNum BigNum::  operator - (INT first)
{	
        BigNum  fir=first;	
        fir=*this-fir;	
        return fir;
}
void BigNum::operator -= (INT first)
{	
    *this= *this -first;
}
BigNum BigNum::	operator + ( INT first)
{	
    BigNum fir=first;	
    fir=*this+fir;	
    return fir;
}
void	BigNum::operator += ( INT first)
{   
    *this=*this+first;
}
BigNum:: BigNum( string str)
{	
    INT value,t;	
    int i,j;	
    char temp;	
    if(str[0]=='-')		
    flag=0,str.erase ('-');	
    else		
    flag=1;	
    j=str.size()-1;	
    for(i=0;i<str.size()/2;i++)		
    temp=str[i],str[i]=str[j-i],str[j-i]=temp;	
    len=0;	
    for(i=0;i<str.size();)	
    {		
        value=0;		
        t=1;		        
        for(j=0;j<N&&i<str.size();j++,i++)		
        {			
            value=value+(str[i]-'0')*t;			
            t*=10;		
        }		
        num[len++]=value;	
    }
}    
BigNum::BigNum(INT value)                                   //���캯��
{	
    if(value<0)	
    {		
        flag=0;		
        value=-value;	
    }	
    else		
    flag=1;	
    len=0;	
    if(value==0)	
    {		
        len=1;		
        num[0]=0;
   	}	
    else	
    {		
        while(value>=BASE)
  		{			
             num[len++]=value%BASE;			
             value/=BASE;		
        }		
        if(value!=0)			
        num[len++]=value;	
    }
}
BigNum::BigNum( const BigNum & value)                             //,��ȿ�������������	
{		 
    INT i;		
    flag=value.flag ;		
    len=value.len;		
    for(i=0;i<len ;i++)                            			
    num[i]=value.num[i];	
}; 
INT BigNum::GetFlag()                              
{	
    return flag;
} 
INT BigNum::GetPointer()
{	
    return len;
}
void  BigNum::GetNum(INT* _num)
{	 
    INT i;	
    for(i=0;i<len;i++)		
    _num[i]=num[i];
}
bool IsMax(BigNum &first,BigNum &second)                //�ж������ľ���ֵ�Ĵ�С��ǰ�ߴ󷵻�1
{	 
    INT i;  
    if(first.len>second.len)                     	  
    return true;  
    if(first.len==second.len)  
    {	  
        for(i=first.len-1;i>=0;i--)		  
        if(first.num[i]>second.num[i])			
        return true;		  
        else			  
        if(first.num[i]<second.num[i])				  
        return false;  
    }  
    return false;
}
void BigNum::add( BigNum &first,BigNum &second)         // ����ֵ���
{	
    *this=first;	 
    INT i;	
    for(i=0;i<second.len&&i<len-1;i++)		
    {			
        num[i]+=second.num[i];			 
        if(num[i]>=BASE)					 
        {				 
            num[i+1]+=num[i]/BASE;				 
            num[i]%=BASE;			 
        }		
    }	   
    if(i<second.len)	   
    {		   
        num[i]+=second.num[i];		   
        for(i++;i<second.len;i++)		   
        {			   
            num[i]=second.num[i];			   
            if(num[i-1]>=BASE)			   
            {				   
                num[i]+=num[i-1]/BASE;				   
                num[i-1]%=BASE;			   
            }		   
        }		   
        len=second.len;		   
        while(num[i-1]>=BASE)		   
        {			   
            num[len++]=num[i-1]/BASE;			   
            num[(i++)-1]%=BASE;		   
        }	   
    }	   
    else	   
    {		   
        while(num[i]>=BASE&&i<len-1)		   
        {			   
            num[i+1]+=num[i]/BASE;			   
            num[i]%=BASE;			   
            i++;		   
        }		   
        while(num[i]>=BASE)		   
        {			   
            num[len++]=num[i]/BASE;			   
            num[i++]%=BASE;		   
        }		   	   
    }
}
void BigNum::sub( BigNum &first,BigNum &second)        //������������ֵ������ѱ�֤ǰ�ߴ��ں���
{	
    *this=first;	 
    INT i;	
    for(i=0;i<second.len;i++)	
    {		
        if(num[i]<second.num[i])		
        {			
            num[i+1]--;			
            num[i]+=BASE-second.num[i];		
        }		
        else			
        num[i]-=second.num[i];	
    }	
    if(i==len)		
    while(num[--i]==0)		
    {			
        len--;			
        if(len==0)			
        {				
            len=1;				
            num[0]=0;				
            break;			
        }		
    }	
    else	
    {		
        while(num[i]<0)		
        {			
            num[i+1]--;			
            num[i++]+=BASE;		
        }		
        if(i==len-1)			
        while(num[i--]==0)			
        {				
            len--;				
            if(len==0)				
            {					
                len=1;					
                num[0]=0;					
                break;				
            }			
        }	
    }
}
BigNum BigNum::operator + (BigNum &first)              //����������� 
{	
    BigNum temp ;	
    if((flag+first.flag)%2)	
    {		
        if(IsMax(*this,first))		
        {			
            temp.sub(*this,first);			
            temp.flag=flag;		
        }		
        else		
        {			
            temp.sub(first,*this);			
            temp.flag=first.flag ;		
        }	
    }	
    else	
    {		
        temp.add(*this,first);		
        temp.flag =first.flag;	
    }	
    return temp;
}
BigNum	BigNum::operator - (BigNum &first)
{	
    BigNum temp;	
    if((flag+first.flag)%2)                  //�������Ų�ͬ�������	
    {		
        temp.add(*this,first);		
        temp.flag=flag;
   	}	
    else	
    {		
        if(IsMax(*this,first))		
        {			
            temp.sub(*this,first);			
            temp.flag=flag;		
        }		
        else		
        {			
            temp.sub(first,*this);			
            temp.flag=1-first.flag;		
        }	
    }	
    return temp;	
}
void	BigNum::operator += (BigNum &first)
{    
    *this=*this+first;	
}	
BigNum	BigNum::operator * ( INT first)
{	
    BigNum  temp =*this;	 
    INT i;	
    if(first==0)	
    {		
        temp=0;		
        return temp;	
    }	
    if(first<0)	
    {		
        temp.flag=1-temp.flag;		
        first=-first;	
    }	
    for(i=0;i<temp.len;i++)		
    temp.num[i]*=first;	
    for(i=0;i<temp.len-1;i++)	   
    if(temp.num[i]>=BASE)	   
    {		   
        temp.num[i+1]+=temp.num[i]/BASE;		   
        temp.num[i]%=BASE;	   
    }   
    while(temp.num[i]>=BASE)   
    {	   
        temp.num[temp.len++]=temp.num[i]/BASE;	   
        temp.num[i++]%=BASE;   
    }	  
    return temp;
}
BigNum	BigNum::operator / ( INT first)
{	
    BigNum temp=*this;	 
    INT i;	
    bool fla;	
    fla=true;	
    if(first<0)	
    {		
        temp.flag=1-temp.flag;		
        first=-first;	
    }	
    for(i=temp.len-1;i>0;i--)   
    {	   
        if(temp.num[i]%first!=0)		   
        temp.num[i-1]+=(temp.num[i]%first)*BASE;	   
        temp.num[i]/=first;	   
        if(temp.num[i]==0&&fla)		   
        temp.len--;	   
        else		   
        fla=false;   
    }   
    temp.num[i]/=first;
    return temp;	  
}
void	BigNum::operator *= ( INT first)
{	
    *this=(*this)*first;	 
}
void	BigNum::operator -= (BigNum &first)
{	
    *this=*this-first;
}
void	BigNum::operator /= ( INT first)
{	
    *this=*this/first;
}
void print(BigNum result)
{	 
    INT i;	
    if(result.len==1&&result.num[0]==0)		
    cout<<"0"<<endl;	
    else	
    {		
        if(result.flag==0)			
        cout<<"-";
  		i=result.len-1;		
        cout<<result.num[i];		
        for(i--;i>=0;i--)			
        cout<<setw(6)<<setfill('0')<<result.num[i];		
        cout<<endl;	
    }
} 
/*int main()
{
    BigNum a,b;
    while(1)
    {
        GetNum(a);
        GetNum(b);
        cout<<print(a+b)<<endl;
    }
    ;
    return 0;
}*/
