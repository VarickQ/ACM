/*      
* 程序的版权和版本声明部分      
* Copyright (c)2013, 烟台大学计算机学院学生      
* All rightsreserved.      
* 文件名称：time .cpp                                 
* 作    者：徐本锡                                  
* 完成日期：2013年4月13日      
* 版本号： v1.0            
* 输入描述：      
* 问题描述：    
*/ 
#include<iostream>
using namespace std;
template<class numtype>
class Complex
{
	public:
		Complex(){real=0;imag=0;}
		Complex(numtype r, numtype i){real=r;imag= i;}
	    Complex complex_add(Complex &c2); 
		Complex complex_cut(Complex &c2);  
		Complex complex_mul(Complex &c2);  
		Complex complex_div(Complex &c2);  
		void display();
	private:
		numtype real;
		numtype imag;
};
template <class numtype>  
Complex<numtype> Complex<numtype>::complex_add(Complex &c2)
{
	Complex c;
	c.real=real+c2.real;
	c.imag=imag+c2.imag;
	return c;
}
template <class numtype>
Complex<numtype> Complex<numtype>::complex_cut(Complex &c2)
{
	Complex c;
	c.real=real-c2.real;
	c.imag=imag-c2.imag;
	return c;
}
template <class numtype>
Complex<numtype> Complex<numtype>::complex_mul(Complex &c2)
{
	Complex c;
	 c.real = real*c2.real-imag*c2.imag;  
	 c.imag = real*c2.imag+imag*c2.real;  
	return c;
}
template <class numtype>
Complex<numtype> Complex<numtype>::complex_div(Complex &c2)
{
	Complex c;
   c.real=(real*c2.real+imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);  
   c.imag=(-real*c2.imag+imag*c2.real)/(c2.real*c2.real+c2.imag*c2.imag);  
	return c;
}
template <class numtype>
void Complex<numtype>::display()
{
	cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main( )
{
	Complex<int> c1(1,1),c2(2,2),c3;  
	c3=c1.complex_add(c2);  
	cout<<"c1+c2="; 
	c3.display( );  
	Complex<double> c4(1.1,1.1),c5(2.2,2.2),c6;  
	c6=c4.complex_add(c5);  
	cout<<"c4+c5="; 
	c6.display( ); 
    Complex<int> c7(3, 3), c8(4, 4), c9;   
    c9 = c7.complex_cut(c8);    
    cout << "c7-c8=";   
    c9.display( );  
    Complex<int> c10(5, 5), c11(6,6), c12;   
    c12=c10.complex_mul(c11);    
   cout << "c10*c11=";   
    c12.display( ); 
	   Complex<double> c13(7,7), c14(8,8), c15;   
    c15=c13.complex_mul(c14);    
   cout << "c13/c14=";   
    c15.display( ); 
	return 0;
}