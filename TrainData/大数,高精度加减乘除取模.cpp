#include <iostream>
#include <string>
using namespace std;

inline int compare(string str1, string str2)
{
      if(str1.size() > str2.size()) //���ȳ����������ڳ���С������
            return 1;
      else if(str1.size() < str2.size())
            return -1;
      else
            return str1.compare(str2); //��������ȣ���ͷ��β��λ�Ƚϣ�compare��������ȷ���0�����ڷ���1��С�ڷ��أ�1
}

//�߾��ȼӷ�
string ADD_INT(string str1, string str2)
{
	string MINUS_INT(string str1, string str2);
	int sign = 1; //sign Ϊ����λ
	string str;
	if(str1[0] == '-') {
		if(str2[0] == '-') {
			sign = -1;
			str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));
		}else {
			str = MINUS_INT(str2, str1.erase(0, 1));
		}
	}else {
		if(str2[0] == '-')
			str = MINUS_INT(str1, str2.erase(0, 1));
		else {
			//�������������룬������ǰ���0����
			string::size_type l1, l2;
			int i;
			l1 = str1.size(); l2 = str2.size();
			if(l1 < l2) {
				for(i = 1; i <= l2 - l1; i++)
					str1 = "0" + str1;
			}else {
				for(i = 1; i <= l1 - l2; i++)
					str2 = "0" + str2;
			}
			int int1 = 0, int2 = 0; //int2 ��¼��λ
			for(i = str1.size() - 1; i >= 0; i--) {
				int1 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) % 10;  //48 Ϊ '0' ��ASCII ��
				int2 = (int(str1[i]) - 48 + int(str2[i]) - 48 +int2) / 10;
				str = char(int1 + 48) + str;
			}
			if(int2 != 0) str = char(int2 + 48) + str;
		}
	}
	//����������λ
	if((sign == -1) && (str[0] != '0'))
		str = "-" + str;
	return str;
}


//�߾��ȼ���
string MINUS_INT(string str1, string str2)
{
	//string MULTIPLY_INT(string str1, string str2);
	int sign = 1; //sign Ϊ����λ
	string str;
	if(str2[0] == '-')
		str = ADD_INT(str1, str2.erase(0, 1));
	else {
		int res = compare(str1, str2);
		if(res == 0) return "0";
		if(res < 0) {
			sign = -1;
			string temp = str1;
			str1 = str2;
			str2 = temp;
		}
		string::size_type tempint;
		tempint = str1.size() - str2.size();
		int i,pos;
		for(i = str2.size() - 1; i >= 0; i--) {
			if(str1[i + tempint] < str2[i]) {
				pos = i + tempint - 1;
				while( str1[ pos ] - 1 < 48 ){
					str1[ pos ] = str1[ pos ] + 9;
					pos--;
				}
				str1[ pos ] = str1[ pos ] - 1;
				//str1[i + tempint - 1] = char(int(str1[i + tempint - 1]) - 1);
				str = char(str1[i + tempint] - str2[i] + 58) + str;
			}
			else
				str = char(str1[i + tempint] - str2[i] + 48) + str;
		}
		for(i = tempint - 1; i >= 0; i--)
			str = str1[i] + str;
	}
	//ȥ������ж����ǰ��0
	str.erase(0, str.find_first_not_of('0'));
	if(str.empty()) str = "0";
	if((sign == -1) && (str[0] != '0'))
		str = "-" + str;
	return str;
}

//�߾��ȳ˷�
string MULTIPLY_INT(string str1, string str2)
{
	int sign = 1; //sign Ϊ����λ
	string str;
	if(str1[0] == '-') {
		sign *= -1;
		str1 = str1.erase(0, 1);
	}
	if(str2[0] == '-') {
		sign *= -1;
		str2 = str2.erase(0, 1);
	}
	int i, j;
	string::size_type l1, l2;
	l1 = str1.size(); l2 = str2.size();
	for(i = l2 - 1; i >= 0; i --) {  //ʵ���ֹ��˷�
		string tempstr;
		int int1 = 0, int2 = 0, int3 = int(str2[i]) - 48;
		if(int3 != 0) {
			for(j = 1; j <= (int)(l2 - 1 - i); j++)
				tempstr = "0" + tempstr;
			for(j = l1 - 1; j >= 0; j--) {
				int1 = (int3 * (int(str1[j]) - 48) + int2) % 10;
				int2 = (int3 * (int(str1[j]) - 48) + int2) / 10;
				tempstr = char(int1 + 48) + tempstr;
			}
			if(int2 != 0) tempstr = char(int2 + 48) + tempstr;
		}
		str = ADD_INT(str, tempstr);
	}
	//ȥ������е�ǰ��0
	str.erase(0, str.find_first_not_of('0'));
	if(str.empty()) str = "0";
	if((sign == -1) && (str[0] != '0'))
		str = "-" + str;
	return str;
}
//�߾��ȳ���
string DIVIDE_INT(string str1, string str2, int flag)
{
	//flag = 1ʱ,������; flag = 0ʱ,��������
	string quotient, residue; //�����̺�����
	int sign1 = 1, sign2 = 1;
	if(str2 == "0") {  //�жϳ����Ƿ�Ϊ0
		quotient = "ERROR!";
		residue = "ERROR!";
		if(flag == 1) return quotient;
		else return residue;
	}
	if(str1 == "0") { //�жϱ������Ƿ�Ϊ0
		quotient = "0";
		residue = "0";
	}
	if(str1[0] == '-') {
		str1 = str1.erase(0, 1);
		sign1 *= -1;
		sign2 = -1;
	}
	if(str2[0] == '-') {
		str2 = str2.erase(0, 1);
		sign1 *= -1;
	}
	int res = compare(str1, str2);
	if(res < 0) {
		quotient = "0";
		residue = str1;
	}else if(res == 0) {
		quotient = "1";
		residue = "0";
	} else {
		string::size_type l1, l2;
		l1 = str1.size(); l2 = str2.size();
		string tempstr;
		tempstr.append(str1, 0, l2 - 1);
		//ģ���ֹ�����
		for(int i = l2 - 1; i < l1; i++) {
			tempstr = tempstr + str1[i];
			for(char ch = '9'; ch >= '0'; ch --) { //����
				string str;
				str = str + ch;
				if(compare(MULTIPLY_INT(str2, str), tempstr) <= 0) {
					quotient = quotient + ch;
					tempstr = MINUS_INT(tempstr, MULTIPLY_INT(str2, str));
					break;
				}
			}
		}
		residue = tempstr;
	}
	//ȥ������е�ǰ��0
	quotient.erase(0, quotient.find_first_not_of('0'));
	if(quotient.empty()) quotient = "0";
	if((sign1 == -1) && (quotient[0] != '0'))
		quotient = "-" + quotient;
	if((sign2 == -1) && (residue[0] != '0'))
		residue = "-" + residue;
	if(flag == 1) return quotient;
	else return residue;
}

//�߾��ȳ���,������
string DIV_INT(string str1, string str2){
	return DIVIDE_INT(str1, str2, 1);
}
//�߾��ȳ���,��������
string MOD_INT(string str1, string str2){
	return DIVIDE_INT(str1, str2, 0);
}
                  
int main()
{
	char ch;
	string s1, s2, res;
	while(cin >> ch) {
		cin >> s1 >> s2;
		switch(ch) {
			case '+':  res = ADD_INT(s1, s2); break;   //�߾��ȼӷ�
			case '-':  res = MINUS_INT(s1, s2); break; //�߾��ȼ���
			case '*':  res = MULTIPLY_INT(s1, s2); break; //�߾��ȳ˷�
			case '/':  res = DIV_INT(s1, s2); break; //�߾��ȳ���, ������
			case 'm':  res = MOD_INT(s1, s2); break; //�߾��ȳ���, ��������
			default :  break;
		}
		cout << res << endl;
	}
	return(0);
}
