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

int main(){
	string s1,s2,res;
	int T;
	scanf("%d", &T);
	while( T-- ){
		cin >> s1 >> s2;
		if( s1[0]=='+' ) s1.erase( s1.begin() );
		if( s2[0]=='+' ) s2.erase( s2.begin() );
		
		res = ADD_INT( s1, s2 );
		cout << res << endl;
	}
	return 0;
}