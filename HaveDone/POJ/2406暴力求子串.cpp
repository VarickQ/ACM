#include <iostream>
#include <string>
using namespace std;
char str[1000001];
int main()
{
	while(gets(str))
	{
		string s;
		s = str;
		if(s == ".")break;
		string c="";
		for(int i=0 ; i < s.length() ; i++ )
		{
			c += s[i];
			if(s.length()%c.length() != 0)
				continue;
			int numS = s.length()/c.length();
			string f="";
			for(int j=0 ; j < numS ; j++ )
				f += c;
			if(f==s)
			{
				printf("%d\n", numS); break;
			}
		}
	}
	return 0;
}