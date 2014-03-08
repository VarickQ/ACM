// ParseExpr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <stack>
#include <math.h>
using namespace std;

enum POS {
	FIRST,
	LAST,
	MIDDLE
};
typedef struct _OPERATOR {
	char OP;
	int unit;
	POS pos;
} OPERATOR;
typedef deque<char> CHAR_DEQUE;
typedef deque<double> DOUBLE_DEQUE;

typedef stack<char, CHAR_DEQUE> CHAR_STACK;
typedef stack<double, DOUBLE_DEQUE> DOUBLE_STACK;

bool isvalid(char* expr) {
	char* p;
	int count = 0;
	for(p=expr;*p;p++) {
		if(*p == '(')	count++;
		else if(*p == ')') count--;
	}
	return (count==0);
}
int alpha2int(char c) {	return c + 1 - '1';}

int isp(char c) {
	switch(c) {
	case '#':	return 0;
	case '(':	return 1;
	case ')':	return 8;
	case '^':	return 7;
	case '*':	case '/':	case '%':	return 5;
	case '+':	case '-':	return 3;
	}
}

int icp(char c) {
	switch(c) {
	case '#':	return 0;
	case '(':	return 8;
	case ')':	return 1;
	case '*':	case '/':	case '%':	return 4;
	case '+':	case '-':	return 2;
	}
}

double expr(double l, double r, char o) {
	double result = 0;
	switch(o) {
	case '+':	result = l+r;			break;
	case '-':	result = l-r;			break;
	case '*':	result = l*r;			break;
	case '/':	result = l/r;			break;
	case '%':	result = (int)l%(int)r;	break;
	case '^':	result = pow(l, r);		break;
	}
	return result;
}
int main(int argc, char* argv[])
{
	CHAR_STACK operator_stack;
	DOUBLE_STACK operand_stack;
	
	if(argc != 2) {
		cerr<<"Parameter error!\n";		return 0;
	}
	if(!isvalid(argv[1])) {
		cerr<<"\"(\", \")\" do not match!\n";	return 0;
	}
	// 将操作数和操作符入栈
	char* pstr = argv[1];
	int len = strlen(pstr);
	int i;
	double operand;
	char operater;
	char last_operater;
	double left_operand;
	double right_operand;
	double cal_result;
	bool flag;
	operator_stack.push('#');
	for(i=0;i<len;i++) {
		// 操作数入栈
		flag = false;
		operand = 0;
		while(isdigit(pstr[i])) {
			operand = operand*10 + alpha2int(pstr[i]);
			i++;
			flag = true;
		}
		if(flag)	// 如果operand 有效
			operand_stack.push(operand);
		
		if(i >= len)
			break;
		// 操作符边入栈边处理
		last_operater = operator_stack.top();
		operater = pstr[i];
		while(isp(last_operater) > icp(operater)) {	//出栈
			operator_stack.pop();	//	弹出上一个操作符
			
			// 弹出上两个操作数
			right_operand = operand_stack.top();		operand_stack.pop();
			left_operand = operand_stack.top();		operand_stack.pop();
			cal_result = expr(left_operand, right_operand, last_operater);
			operand_stack.push(cal_result);	// 压入计算结果（抵消上一个操作符和上两个操作数）

			last_operater = operator_stack.top();		

		}
		if(isp(last_operater) == icp(operater))
			operator_stack.pop();
		// 入栈
		else
			operator_stack.push(operater);
	
	}

	// 处理操作符栈
	while(!operator_stack.empty()) {
		last_operater = operator_stack.top();
		if(last_operater == '#') {
			operator_stack.pop();
			break;
		}
		right_operand = operand_stack.top();	operand_stack.pop();
		left_operand = operand_stack.top();	operand_stack.pop();
		cal_result = expr(left_operand, right_operand, last_operater);
		operator_stack.pop();	//	弹出上一个操作符
		operand_stack.push(cal_result);	// 压入计算结果（抵消上一个操作符和上两个操作数）
	}
	cout<<operand_stack.top()<<endl;
	return 0;
}
