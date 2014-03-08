#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char str[1000010];
char ans[50010][11];
int fa[50010],st[50010];
vector<int> ve[50010];

void dfs(int x)
{
	for(int i = 0;i < ve[x].size();++i)
	{
		printf("%d %d\n",x,ve[x][i]);
		dfs(ve[x][i]);
		printf("%d %d\n",ve[x][i],x);
	}
}

int main()
{
	int t,n,m,i,a,j;
	scanf("%d",&t);
	gets(str);
	while(t--)
	{
		gets(str);
		j = 1;
		int len = strlen(str);
		char temp[21];
		int k = 0;
		int beg = 0,end = 0;
		st[0] = 1;
		for(i = 0;i < len;++i)
		{
			if(str[i] == '(')
			{
				ve[1].clear();
				temp[k] = '\0';
				k = 0;
				strcpy(ans[j++],temp);
				i++;
				break;
			}
			temp[k++] = str[i];
		}
		if(i == len)
		{
			temp[k] = '\0';
			k = 0;
			strcpy(ans[j++],temp);
		}
		for(;i < len;++i)
		{
			if(str[i] == '(' || str[i] == ')' || str[i] == ',')
			{
				if(k == 0)
				{
					if(str[i] == ')')
						end--;
					continue;
				}
				temp[k] = '\0';
				k = 0;
				ve[j].clear();
				strcpy(ans[j++],temp);
				if(str[i] == '(')
				{
					fa[j-1] = st[end];
					ve[fa[j-1]].push_back(j-1);
					st[++end] = j-1;
				}
				else if(str[i] == ')')
				{
					fa[j-1] = st[end];
					ve[fa[j-1]].push_back(j-1);
					end--;
				}
				else
				{
					fa[j-1] = st[end];
					ve[fa[j-1]].push_back(j-1);
				}
			}
			else
				temp[k++] = str[i];
		}

		printf("%d\n",j-1);
		for(i = 1;i < j;++i)
			printf("%s\n",ans[i]);
		if(j != 2)
		{
			dfs(1);
		}
		printf("\n");
	}
	return 0;
}