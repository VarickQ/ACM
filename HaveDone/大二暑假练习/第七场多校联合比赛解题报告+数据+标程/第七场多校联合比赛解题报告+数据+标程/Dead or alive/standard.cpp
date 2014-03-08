#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;
#define abs(x) ((x<0)?(-(x)):(x))
#define M 15

struct coo
{
	int x,y;
};

struct pie
{
	coo p;
	char ch;
};

class coo_less_1
{
public:
	bool operator()(coo &a,coo &b)
	{
		int r1,r2;
		r1=min(a.x,a.y);
		r2=min(b.x,b.y);
		if (abs(r1-2)<abs(r2-2))
			return true;
		else if (r1==r2 && a.x+a.y-r1<b.x+b.y-r2)
			return true;
		else
			return false;
	}
};

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

char cb[M][M];
int n,m,sx,sy;
char sc;
coo fz[M*M];

void getdata(void);
bool inrange(int wx,int wy);
bool serch(int px,int py,char c);
int find(vector<pie> &v,int fx,int fy,int mode=0);
void recovery(vector<pie> &v);

int main()
{
	int ca,ttt = clock();
	priority_queue<coo,vector<coo>,coo_less_1> z;
	coo temp,h;
	int s,t;
	int i,j;
	bool win;
	bool om[M][M];
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
	scanf("%d",&ca);
	while (ca--)
	{
		getdata();
		while (!z.empty()) z.pop();
		temp.x=sx;
		temp.y=sy;
		z.push(temp);
		win=false;
		memset(om,true,sizeof(om));
		om[sx][sy]=false;
		while (!z.empty())
		{
			h=z.top();
			z.pop();
			if (cb[h.x][h.y]=='.' && serch(h.x,h.y,'B'))
			{
				win=true;
				break;
			}
			for (i=0;i<4;i++)
			{
				if (inrange(h.x+dx[i],h.y+dy[i]) && om[h.x+dx[i]][h.y+dy[i]])
				{
					temp.x=h.x+dx[i];
					temp.y=h.y+dy[i];
					om[temp.x][temp.y]=false;
					z.push(temp);
				}
			}
		}
		if (win)
		{
			if (cb[sx][sy]=='B')
				printf("alive!\n");
			else
				printf("dead!\n");
		}
		else
		{
			if (cb[sx][sy]=='W')
				printf("alive!\n");
			else
				printf("dead!\n");
		}
	}
	//printf("%d\n",clock()-ttt);
	return 0;
}

void getdata(void)
{
	int i,j;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&sx,&sy);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf(" %c",&cb[i][j]);
	sc=cb[sx][sy];
	for (i=0;i<=n+1;i++)
	{
		cb[i][0]='#';
		cb[i][m+1]='.';
	}
	for (j=0;j<=m+1;j++)
	{
		cb[0][j]='#';
		cb[n+1][j]='.';
	}
}

bool inrange(int wx,int wy)
{
	return (wx>0 && wx<=n && wy>0 && wy<=m);
}

bool serch(int px,int py,char c)
{
	char next_c=(c=='W'?'B':'W');
	bool mode=(c=='W'?false:true);
	bool o[M][M];
	vector<pie> chi;
	queue<coo> q;
	coo temp,h;
	int i,j;
	int cnt;
	cb[px][py]=c;
	cnt=0;
	for (i=0;i<4;i++)
	{
		if (inrange(px+dx[i],py+dy[i]) && cb[px+dx[i]][py+dy[i]]==next_c)
		{
			find(chi,px+dx[i],py+dy[i]);
		}
	}
	if (cb[sx][sy]=='.')
	{
		if (sc=='B')
		{
			recovery(chi);
			cb[px][py]='.';
			return false;
		}
		else
		{
			recovery(chi);
			cb[px][py]='.';
			return true;
		}
	}
	cnt=find(chi,px,py,1);
	if (cnt>0)
	{
		temp.x=px;
		temp.y=py;
		q.push(temp);
		memset(o,true,sizeof(o));
		o[px][py]=false;
		if (chi.size()==1)
		{
			o[chi[0].p.x][chi[0].p.y]=false;
		}
		while (!q.empty())
		{
			h=q.front();
			q.pop();
			if (cb[h.x][h.y]=='.')
			{
				if (serch(h.x,h.y,next_c))
				{
					if (c=='W')
					{
						recovery(chi);
						cb[px][py]='.';
						return true;
					}
				}
				else
				{
					if (c=='B')
					{
						recovery(chi);
						cb[px][py]='.';
						return false;
					}
				}
			}
			for (i=0;i<4;i++)
			{
				temp.x=h.x+dx[i];
				temp.y=h.y+dy[i];
				if (inrange(temp.x,temp.y) && o[temp.x][temp.y])
				{
					o[temp.x][temp.y]=false;
					q.push(temp);
				}
			}
		}
	}
	else
	{
		recovery(chi);
		cb[px][py]='.';
		return !mode;
	}
	recovery(chi);
	cb[px][py]='.';
	return mode;
}

int find(vector<pie> &v,int fx,int fy,int mode)
{
	bool o[M][M];
	int res=0;
	int s,t;
	int i,size;
	coo h,temp;
	pie cp;

	s=t=1;
	fz[1].x=fx;
	fz[1].y=fy;
	memset(o,true,sizeof(o));
	o[fx][fy]=false;
	while (s<=t)
	{
		h=fz[s];
		for (i=0;i<4;i++)
		{
			if (o[h.x+dx[i]][h.y+dy[i]])
			{
				temp.x=h.x+dx[i];
				temp.y=h.y+dy[i];
				o[temp.x][temp.y]=false;
				if (cb[temp.x][temp.y]=='.')
				{
					res++;
				}
				else if (cb[temp.x][temp.y]==cb[fx][fy])
				{
					fz[++t]=temp;
				}
			}
		}
		s++;
	}
	if (res==0 && mode==0)
	{
		for (i=1;i<=t;i++)
		{
			cp.p=fz[i];
			cp.ch=cb[fz[i].x][fz[i].y];
			cb[fz[i].x][fz[i].y]='.';
			v.push_back(cp);
		}
	}
	return res;
}

void recovery(vector<pie> &v)
{
	int i,size;
	size=v.size();
	for (i=0;i<size;i++)
		cb[v[i].p.x][v[i].p.y]=v[i].ch;
}
