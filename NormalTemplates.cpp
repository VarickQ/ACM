C(n,0)+C(n,1)+C(n,2)+....+C(n,n)=2^n
#define PI 3.1415926535897932384626433832795
#define E  2.71828182845904523536
#define eps 1e-6
bool dd(double x,double y){ return fabs(x-y)<eps;} // x==y
bool dy(double x,double y){ return x>y+eps;}   // x>y
bool xy(double x,double y){ return x<y-eps;}   //x<y
bool dyd(double x,double y){ return x>y-eps;}  //x>=y
bool xyd(double x,double y){ return x<y+eps;}  //x<=y
bool zero(double x){
    return fabs(x)<eps;
}
eclipse 调试F11 跳断点F8 单步F5

//ceil(x)(向上取整)返回不小于x的最小整数值（然后转换为double型）。
//floor(x)（向下取整）返回不大于x的最大整数值。
//round(x)返回x的四舍五入整数值。
//arcsin() ==> asin();

//itoa     把一 整数 转换为 字符串  <stdlib.h>
//itoa(num要转换的数字,str目标字符串,2转移数字时所用的基数);
//例中，转换基数为10。10：十进制；2：二进制……
//atoi     把 字符串 转换成 整型数
//char str[];int a;

//sprintf(str,"%d",a);
数字转化成字符串 char * itoa(int value,char * str,int base);
itoa(a,str,10); itoa(a,str,16); itoa(a,str,2);

//sscanf(str,"%d",&a);
字符串转化成数字 int atoi(const char * str);
a = atoi(str);
//去重
len = unique( a, a+len ) - a;

#include <time.h>
clock_t start;
start = clock();
double duration = ((double)(clock()-start))/CLOCKS_PER_SEC;

//返回bool，若无更大的字典序排列返回false
int cmp(char a,char b){
	if(tolower(a) == tolower(b))
		return a < b;
	else
		return tolower(a) < tolower(b);
}
next_permutation(a,a+n,cmp)//字符串排序
//将a转化成小写
tolower(a)
a&b　| a and b //按位与处理两个长度相同的二进制数, 两个相应的二进位都为1, 该位的结果值才为1,否则为0.
a|b　| a or b  //按位或处理两个长度相同的二进制数, 两个相应的二进位中只要有一个为1, 该位的结果值为1.
a^b  | a xor   //(⊕)按位异或运算, 对等长二进制模式或二进制数的每一位执行逻辑异或操作. 操作的结果是如果某位不同则该位为1, 否则该位为0.
 ~a　|   not a //取反是一元运算符, 对一个二进制数的每一位执行逻辑反操作. 使数字1成为0, 0成为1.
a << b| a shl b//实际上就是a乘以2的b次方  左移b位
a >> b| a shr b//相当于a除以2的b次方（取整）  右移b位
//优先队列(排序原则相反)
struct Node{
	int c;
	bool operator < (const Node &a) const{
		return c < a.c;//从大到小
		//return c > a.c;//从小到大
	}
}
struct cmp1{//从大到小
	bool operator()(const int &x,const int &y){
		return x < y;
	}
};
priority_queue<int,vector<int>,cmp1> qu1;
struct cmp2{//从小到大
	bool operator()(const int &x,const int &y){
		return x > y;
	}
};
priority_queue<int,vector<int>,cmp2> qu2;
//传入年月日，传出星期几(0是周日)
int weekday(int y,int m,int d){
	int tm=m>=3?(m-2):(m+10);
	int ty=m>=3?y:(y-1);
	return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+d)%7;
}
int day[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int isleap(int n){
	if((n%4==0 && n%100!=0) || n%400==0)return 366;
	else return 365;
}
int getday(int n,int y){
	if(n!=2) return day[n];
	else return (isleap(y)==366) ? 29:28;
}
//将n(10)转化为a进制，并且存在tmp(未倒序)中，并返回数组长度
int tmp[32];
int Tento(int n,int a){
	int i=0;
	while(n){
		tmp[i++]=n%a; //i=i*10+n%a;
		n/=a;
	}
	return i;
}
//将任意a进制转化为10进制
int toTen(int n,int a){
	int ans=0,i=0;
	while(n){
		ans += (n%10)*Pow(a,i);
		i++;
		n /= 10;
	}
	return ans;
}
//斯特林(Stirling)公式：
n! ≈ sqrt(2*Pi*n)*(n/e)^n
//第二类斯特林数
//将n个元素划分为k个非空集合
S(n, m) = m * S(n - 1, m) + S(n - 1, m - 1)
//排列组合公式C(n,k),n中任选m个种数 n>=k
//对于C(n,k),若n&k == k 则c(n,k)为奇数，否则为偶数
bignum C(int n, int k){
	bignum r;
	r = 1;
	for(int i=1; i <= k ; ++i){
		r *= (n-i+1); r /= i;
	}
	return r;
}
int c[n][k];
void CC(){
	for(int i=1; i <= N; ++i){
		c[i][0] = c[i][i] = 1;
		for(int j=1; j < i; ++j)
			c[i][j] = c[i-1][j-1]+c[i-1][j];
	}
}
//叉乘 (p2-p0)X(p1-p0)
int xmul(point p0,point p1,point p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//拓扑排序
int stack[N],top;
int in[N];
void topsort(){
	memset(stack,0,sizeof(stack));
	top = 0;
	bool f = false;
	for(int i=1 ; i <= n ; ++i){
		if(in[i] == 0){
			stack[top++] = i;
			if(!f){
				printf("%d",i); f=true;
			} else printf(" %d",i);
		}
	}
	while(top){
		int u = stack[--top];
		for(int i=heade[u] ; i!=-1 ; i=e[i].next){
			if(--in[e[i].v] == 0){
				stack[top++] = e[i].v;
				printf(" %d",e[i].v);
			}
		}
	}
}
//dijkstra有向图中单个源点到其他顶点的最短路径
int m,n,d[N],vis[N];
int mat[N][N];
void dijkstra(){
	memset(vis,0,sizeof(vis));
	for(int i=1 ; i <= n ; i++)d[i] = inf;
	d[1] = 0;
	for(int i=1 ; i <= n ; i++)
	{
		int x,Min = inf;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[y] <= Min){
				Min = d[y];
				x = y;
			}
		vis[x] = true;
		for(int y=1 ; y <= n ; y++)
			if(!vis[y] && d[x]+mat[x][y] < d[y])
				d[y] = d[x] + mat[x][y];
	}
}
void dijkstra(int s){
	CLR( vis, 0 );
	for(int i=1 ; i <= n ; ++i) dis[i] = inf;
	dis[s] = 0;
	for(int i=1 ; i <= n ; ++i)
	{
		int x,Min = inf;
		for(int y=1 ; y <= n ; ++y)
			if( !vis[y] && dis[y] <= Min ){
				Min = dis[y];
				x = y;
			}
		vis[x] = true;
		for(int i=heade[x] ; i!=-1 ; i=e[i].next){
			if( dis[i] > dis[x]+e[i].c )
				dis[i] = dis[x]+e[i].c;
		}
	}
}
//最短路SPFA
struct Node{
	int c,v,next;
}edge[N*2];
int heade[N],k,n;
long long dist[N];
int qu[N];
bool vis[N];
void spfa(int s)//s为原点
{
	int i,head=0,tail=1;
	memset(vis,false,sizeof(vis));
	for(i=1 ; i <= n ; i++)dist[i]=inf;
	dist[s] = 0;
	qu[0] = s;
	while(tail > head){
		int u = qu[head++];
		//if(head >= N) head=0;
		vis[u] = false;
		for(i=heade[u] ; i!=-1 ; i=edge[i].next){
			int v=edge[i].v;
			if(dist[v] > dist[u]+edge[i].c){
				dist[v] = dist[u]+edge[i].c;
				if(!vis[v]){
					vis[v] = true;
					qu[tail++] = v;
					//if(tail >= N)tail=0;
				}
			}
		}
	}
}
void spfa(int x){
	int i,head=0,tail=1;
	for(i=1 ; i <= n ; i++)d[i]=inf;
	d[x]=0;//起始点
	qu[0] = x;
	while(tail > head){
		int u=qu[head];
		v[u] = true;
		for(i=1 ; i <= n ; i++){
			if(map[u][i]!=0 && d[i] > d[u]+map[u][i]){
				d[i] = d[u]+map[u][i];
				if(!v[i]){
					v[i] = true;
					qu[tail++] = i;
				}
			}
		}
		v[u] = false;
		head++;
	}
}
//多边形费马点 (返回到各点的长度总和)
struct Point{
	double x,y;
}a[N];
inline double pt_distance(Point a, Point b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double fermat_point(Point pt[], int n, Point& ptres){
	Point u, v;
	double step = 0.0, curlen, explen, minlen;
	int i, j, k, idx;
	bool flag;
	u.x = u.y = v.x = v.y = 0.0;
	for(i = 0; i < n; ++i){
		step += fabs(pt[i].x) + fabs(pt[i].y);
		u.x += pt[i].x;
		u.y += pt[i].y;
	}
	u.x /= n;
	u.y /= n;
	flag = 0;
	while(step > 1e-10){
		for(k = 0; k < 10; step /= 2, ++k)
			for(i = -1; i <= 1; ++i)
				for(j = -1; j <= 1; ++j){
					v.x = u.x + step*i;
					v.y = u.y + step*j;
					curlen = explen = 0.0;
					for(idx = 0; idx < n; ++idx){
						curlen += pt_distance(u, pt[idx]);
						explen += pt_distance(v, pt[idx]);
					}
					if(curlen > explen){
						u = v;
						minlen = explen;
						flag = 1;
					}
				}
	}
	ptres = u;
	return flag ? minlen : curlen;
}
//并查集
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
void Union(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fy != fx)
       fa[fx] = fy;
}
bool same(int x,int y){
   return find(x)==find(y);
}
//Kruskal最小生成树
int fa[N],n,m;
struct edge{
	int x,y,value;
}e[N];
bool cmp(edge a,edge b){
	return a.value < b.value;
}
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void Kruskal(){
	int ans = 0;
	for(int i=0 ; i <= n ; ++i) fa[i] = i;
	sort(e,e+m,cmp);
	for(int i=0 ; i < m ; ++i){
		int x = find(e[i].x);
		int y = find(e[i].y);
		if(x != y){
			ans += e[i].value;
			fa[x] = y;
		}
	}
	printf("%d\n",ans);
}
//Prim最小生成树
int n,m;
int mat[N][N],d[N];
bool vis[N];
void Prim(){
	int i,j,Min,mi,sum=0;
	for( i=0 ; i <= n ; ++i )
		d[i] = mat[1][i];
	CLR( vis, false );
	vis[1] = true;
	for( i=2 ; i <= n ; ++i ){
		Min = inf; mi = i;
		for( j=2 ; j <= n ; ++j ){
			if( !vis[j] && d[j] < Min ){
				Min = d[j];
				mi = j;
			}
		}
		sum += Min;
		vis[mi] = true;
		for( j=2 ; j <= n ; ++j )
			if( !vis[j] && d[j] > mat[mi][j] )
				d[j] = mat[mi][j];
	}
	printf("%d\n", sum);
}
void Prim(){
	int i,j,now,min_node,Min,sum=0;
	int dis[M];
	for(i=1 ; i <= n ; ++i)
		dis[i] = inf;
	now = 1;
	for(i=1 ; i < n ; ++i){
		dis[now] = -1;
		Min = inf;
		for(j=1 ; j <= n ; ++j){
			if(j!=now && dis[j] >= 0){
				dis[j] = min(dis[j],map[now][j]);
				if(dis[j] < Min){
					Min = dis[j];
					min_node = j;
				}
			}
		}
		now = min_node;
		sum += Min;
	}
	printf("%d\n",sum);
}
//KMP
char str[10002],cs[1000002];
int nxt[10002];
void NEXT(char *str){//匹配串
    int i = 0,j = -1;
    nxt[0] = -1;
    int len = strlen(str);
	while(i < len){
        if(j == -1 || str[i] == str[j])
            ++i,++j,nxt[i] = j;
		else j = nxt[j];
    }
}
void KMP(){
    int i = 0, j = 0;
    int s1 = strlen(cs); //主串
    int s2 = strlen(str); //匹配串
	int ans = 0;
	while(cs[i]){//找完主串的每个字符
		while(i < s1 && j < s2){
			if(j == -1 || cs[i] == str[j])
				i ++,j ++;
			else j = nxt[j];
		}
		if(j == s2){//找到匹配
			ans++;
			j = nxt[j];//继续找下一个
		}
	}
	printf("%d\n",ans);//一共有多少个匹配串
}
//树状数组 http://fqq11679.blog.hexun.com/21722866_d.html
int Lowbit(int t){//计算lowbit
    return t & ( -t );
}
void plus(int pos,int num){//将第pos个元素更改为num
	while(pos <= n){//int n;
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int end){//求前end项和
	int sum = 0;
	while(end > 0){
		sum += c[end];
		end -= Lowbit(end);
	}
	return sum;
}
//dfs
int v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y)
{
	int i,a,b;
	for(i=0;i<4;i++)
	{
		a=x+v[i][0];
		b=y+v[i][1];
		if(a>=1 && a<=n && b>=1 && b<=m && s[a][b]==1)
		{
			s[a][b]=0;
			c++;
			dfs(a,b);
		}
	}
}
//bfs
int s[1005][1005];
memset(s,0,sizeof(s));
for(i=1;i<=n;i++)
   s[x[i]][y[i]]=1;
s[500][500]=1;s[x][y]=2;
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int bfs()
{
	cu.c=500; cu.d=500; cu.e=0;   qu.push(cu);
	while(!qu.empty())
	{
		node ff=qu.front(); node f;  qu.pop();
		for(i=0;i<4;i++)
		{
			f.c=ff.c+v[i][0];  f.d=ff.d+v[i][1];  f.e=ff.e+1;
			if(f.c>=0 && f.c<=1000 && f.d>=0 && f.d<=1000 && s[f.c][f.d]==2)
				return f.e;
			if(f.c>=0 && f.c<=1000 && f.d>=0 && f.d<=1000 && s[f.c][f.d]==0)
			{
				s[f.c][f.d]=1;	qu.push(f);
			}
		}
    
	}
    return -1;
}
//快速幂 x^n%M
LL sPow(int x,int n,LL M){
	LL sum=1;
	while(n){
		if(n&1)sum = sum*x%M;
		x = x*x%M;
		n >>= 1;
	}
	return sum%M;
}
a_ = sPow(a,M-2,M);//a_为a的逆元

//矩阵相乘快速幂
int n,k,m;
struct mat{
	int data[N][N];
};
mat mul(const mat a,const mat b){
	int i,j,k;
	mat c;
	memset(c.data,0,sizeof(c.data));
	for (i=0 ; i < n ; i++)
		for (j=0 ; j < n ; j++)
			for (k=0 ; k < n ; k++)
				c.data[i][j]=(c.data[i][j]+(a.data[i][k]%m)*(b.data[k][j]%m))%m;
	return c;
}
//A^2k = A^k*A^k,
//A^(2k+1) = A^k*A^k*A.
mat sPow(mat x,int t){
	mat s,temp;
	memset(s.data,0,sizeof(s.data));
	if(t == 0){
		for(int i=0 ; i < n ; ++i)
			s.data[i][i] = 1;
		return s;
	} else {
		temp = sPow(x,t/2);
		if(t&1)
			return mul(mul(temp,temp),x);
		else return mul(temp,temp);
	}
}
//joseph(约瑟夫环)模拟,传入人数n,每次数的人数k,返回最后一个人的序号1..n
int joseph(int n,int k){
	int ret=-1,i;
	for (i=1;i<=n;i++)
		ret=(ret+k)%i;
	return ret+1;
}
//判断是否是回文数
int ishuiwen(char *c){
    int ilen = strlen(c);
    int iend = ilen-1;
    for(int i=0;i<iend;i++,iend--){
        if(c[i]!= c[iend])
            break;
    }
    if(i<iend) return 0;
    else return 1;
}
//用素数表判定素数
bool su[M];
int prime[N],cnt;
void S(){
	su[1] = su[0] = true;
	for(LL i=2 ; i <= M-100 ; i++)
		if(!su[i]){
			for(LL j=i*i ; j <= M-100 ; j+=i)
				su[j] = true;
		}
	cnt = 0;
	for(int i=2 ; i <= M-100 ; ++i)
		if(!su[i]) prime[cnt++] = i;
}
//n!中有多少个因子k
int f(int n, int k){
	int i, ans = 0;
	while(n > 0){
		ans += n / k;
		n /= k;
	}
	return ans;
}
//打印杨辉三角
int yh[n][n];
for(i=1 ; i <= n ; i++)
	for(j=1 ; j <= i ; j++)
		if(i==1 || j==i) yh[i][j]=1;
		else yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
//求1..n-1中与n互质的数的个数
int euler(int n){
	int ret=1,i;
	for (i=2;i*i<=n;i++)
		if (n%i==0){
			n/=i,ret*=i-1;
			while (n%i==0)
				n/=i,ret*=i;
		}
	if (n>1) ret*=n-1;
	return ret;
}
void euler(){//欧拉这个不会T哦~~(*o*)~~
    int i, j; 
    for( i=1 ; i <= N ; ++i ) b[i]=i;
    for( i=2 ; i <= N ; i+=2 ) b[i]/=2;
    for( i=3 ; i <= N ; i+=2 )
        if( b[i] == i ) {
            for( j=i ; j <= N ; j+=i )
                b[j] = b[j]/i*(i-1);
		}
}
//gcd
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
bignum gcd(bignum a,bignum b){
	bignum temp;
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
//扩展欧几里得 a*x+b*y=k 得到x,y的解 (((x*k/gcd(a,b))%M)+M)%M
LL exGcd(LL a,LL b,LL &x,LL &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    LL d = exGcd( b, a%b, x, y );
    LL temp = x;
    x = y;
    y = temp - (a/b) * y;
    return d;
}
//字符串循环同构的最小表示法
int MinimumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l && k < l) {
        t = s[(i+k)>=l?i+k-l:i+k] - s[(j+k)>=l?j+k-l:j+k];
        if(!t) k++;
        else{
            if(t > 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
    }
    return (i < j ? i : j);
}
//qsort的应用！
//cmp返回值分三类，小于返回负数，相等返回0，大于返回正数.

//一、对int类型数组排序
int num[100];
int cmp ( const void *a , const void *b ){
    return *(int *)a - *(int *)b;
}
qsort(num,100,sizeof(num[0]),cmp);
//二、对char类型数组排序（同int类型）
char word[100];
int cmp( const void *a , const void *b ){
    return *(char *)a - *(int *)b;
}
qsort(word,100,sizeof(word[0]),cmp);
//三、对double类型数组排序
double in[100];
int cmp( const void *a , const void *b ){
    return *(double *)a > *(double *)b ? 1 : -1;
}
qsort(in,100,sizeof(in[0]),cmp);
//四、对结构体一级排序
struct Sample{
    double data;
    int other;
}s[100];
//按照data的值从小到大将结构体排序
int cmp( const void *a ,const void *b){
    return (*(Sample *)a).data > (*(Sample *)b).data ? 1 : -1;
}
qsort(s,100,sizeof(s[0]),cmp);
//五、对结构体二级排序
struct Sample{
    int x;
    int y;
}s[100];
//按照x从小到大排序，当x相等时按照y从大到小排序
int cmp( const void *a , const void *b ){
    struct Sample *c = (Sample *)a;
    struct Sample *d = (Sample *)b;
    if(c->x != d->x) return c->x - d->x;
    else return d->y - c->y;
}
qsort(s,100,sizeof(s[0]),cmp);
//六、对字符串进行排序
struct Sample{
    int data;
    char str[100];
}s[100];
//按照结构体中字符串str的字典顺序排序
int cmp ( const void *a , const void *b ){
    return strcmp( (*(Sample *)a)->str , (*(Sample *)b)->str );
}
qsort(s,100,sizeof(s[0]),cmp);
//memset
//memset可以方便的清空一个结构类型的变量或数组。
struct sample_struct{
	char csName[16];
	int iSeq;
	int iType;
};
//对于变量
struct sample_strcut stTest;
//用memset就非常方便：
memset(&stTest,0,sizeof(struct sample_struct));
//如果是数组：
struct sample_struct TEST[10];
memset(TEST,0,sizeof(struct sample_struct)*10);