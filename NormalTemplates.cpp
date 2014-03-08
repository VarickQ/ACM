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
eclipse ����F11 ���ϵ�F8 ����F5

//ceil(x)(����ȡ��)���ز�С��x����С����ֵ��Ȼ��ת��Ϊdouble�ͣ���
//floor(x)������ȡ�������ز�����x���������ֵ��
//round(x)����x��������������ֵ��
//arcsin() ==> asin();

//itoa     ��һ ���� ת��Ϊ �ַ���  <stdlib.h>
//itoa(numҪת��������,strĿ���ַ���,2ת������ʱ���õĻ���);
//���У�ת������Ϊ10��10��ʮ���ƣ�2�������ơ���
//atoi     �� �ַ��� ת���� ������
//char str[];int a;

//sprintf(str,"%d",a);
����ת�����ַ��� char * itoa(int value,char * str,int base);
itoa(a,str,10); itoa(a,str,16); itoa(a,str,2);

//sscanf(str,"%d",&a);
�ַ���ת�������� int atoi(const char * str);
a = atoi(str);
//ȥ��
len = unique( a, a+len ) - a;

#include <time.h>
clock_t start;
start = clock();
double duration = ((double)(clock()-start))/CLOCKS_PER_SEC;

//����bool�����޸�����ֵ������з���false
int cmp(char a,char b){
	if(tolower(a) == tolower(b))
		return a < b;
	else
		return tolower(a) < tolower(b);
}
next_permutation(a,a+n,cmp)//�ַ�������
//��aת����Сд
tolower(a)
a&b��| a and b //��λ�봦������������ͬ�Ķ�������, ������Ӧ�Ķ���λ��Ϊ1, ��λ�Ľ��ֵ��Ϊ1,����Ϊ0.
a|b��| a or b  //��λ��������������ͬ�Ķ�������, ������Ӧ�Ķ���λ��ֻҪ��һ��Ϊ1, ��λ�Ľ��ֵΪ1.
a^b  | a xor   //(��)��λ�������, �Եȳ�������ģʽ�����������ÿһλִ���߼�������. �����Ľ�������ĳλ��ͬ���λΪ1, �����λΪ0.
 ~a��|   not a //ȡ����һԪ�����, ��һ������������ÿһλִ���߼�������. ʹ����1��Ϊ0, 0��Ϊ1.
a << b| a shl b//ʵ���Ͼ���a����2��b�η�  ����bλ
a >> b| a shr b//�൱��a����2��b�η���ȡ����  ����bλ
//���ȶ���(����ԭ���෴)
struct Node{
	int c;
	bool operator < (const Node &a) const{
		return c < a.c;//�Ӵ�С
		//return c > a.c;//��С����
	}
}
struct cmp1{//�Ӵ�С
	bool operator()(const int &x,const int &y){
		return x < y;
	}
};
priority_queue<int,vector<int>,cmp1> qu1;
struct cmp2{//��С����
	bool operator()(const int &x,const int &y){
		return x > y;
	}
};
priority_queue<int,vector<int>,cmp2> qu2;
//���������գ��������ڼ�(0������)
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
//��n(10)ת��Ϊa���ƣ����Ҵ���tmp(δ����)�У����������鳤��
int tmp[32];
int Tento(int n,int a){
	int i=0;
	while(n){
		tmp[i++]=n%a; //i=i*10+n%a;
		n/=a;
	}
	return i;
}
//������a����ת��Ϊ10����
int toTen(int n,int a){
	int ans=0,i=0;
	while(n){
		ans += (n%10)*Pow(a,i);
		i++;
		n /= 10;
	}
	return ans;
}
//˹����(Stirling)��ʽ��
n! �� sqrt(2*Pi*n)*(n/e)^n
//�ڶ���˹������
//��n��Ԫ�ػ���Ϊk���ǿռ���
S(n, m) = m * S(n - 1, m) + S(n - 1, m - 1)
//������Ϲ�ʽC(n,k),n����ѡm������ n>=k
//����C(n,k),��n&k == k ��c(n,k)Ϊ����������Ϊż��
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
//��� (p2-p0)X(p1-p0)
int xmul(point p0,point p1,point p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//��������
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
//dijkstra����ͼ�е���Դ�㵽������������·��
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
//���·SPFA
struct Node{
	int c,v,next;
}edge[N*2];
int heade[N],k,n;
long long dist[N];
int qu[N];
bool vis[N];
void spfa(int s)//sΪԭ��
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
	d[x]=0;//��ʼ��
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
//����η���� (���ص�����ĳ����ܺ�)
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
//���鼯
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
//Kruskal��С������
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
//Prim��С������
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
void NEXT(char *str){//ƥ�䴮
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
    int s1 = strlen(cs); //����
    int s2 = strlen(str); //ƥ�䴮
	int ans = 0;
	while(cs[i]){//����������ÿ���ַ�
		while(i < s1 && j < s2){
			if(j == -1 || cs[i] == str[j])
				i ++,j ++;
			else j = nxt[j];
		}
		if(j == s2){//�ҵ�ƥ��
			ans++;
			j = nxt[j];//��������һ��
		}
	}
	printf("%d\n",ans);//һ���ж��ٸ�ƥ�䴮
}
//��״���� http://fqq11679.blog.hexun.com/21722866_d.html
int Lowbit(int t){//����lowbit
    return t & ( -t );
}
void plus(int pos,int num){//����pos��Ԫ�ظ���Ϊnum
	while(pos <= n){//int n;
		c[pos] += num;
		pos += Lowbit(pos);
	}
}
int Sum(int end){//��ǰend���
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
//������ x^n%M
LL sPow(int x,int n,LL M){
	LL sum=1;
	while(n){
		if(n&1)sum = sum*x%M;
		x = x*x%M;
		n >>= 1;
	}
	return sum%M;
}
a_ = sPow(a,M-2,M);//a_Ϊa����Ԫ

//������˿�����
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
//joseph(Լɪ��)ģ��,��������n,ÿ����������k,�������һ���˵����1..n
int joseph(int n,int k){
	int ret=-1,i;
	for (i=1;i<=n;i++)
		ret=(ret+k)%i;
	return ret+1;
}
//�ж��Ƿ��ǻ�����
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
//���������ж�����
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
//n!���ж��ٸ�����k
int f(int n, int k){
	int i, ans = 0;
	while(n > 0){
		ans += n / k;
		n /= k;
	}
	return ans;
}
//��ӡ�������
int yh[n][n];
for(i=1 ; i <= n ; i++)
	for(j=1 ; j <= i ; j++)
		if(i==1 || j==i) yh[i][j]=1;
		else yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
//��1..n-1����n���ʵ����ĸ���
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
void euler(){//ŷ���������TŶ~~(*o*)~~
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
//��չŷ����� a*x+b*y=k �õ�x,y�Ľ� (((x*k/gcd(a,b))%M)+M)%M
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
//�ַ���ѭ��ͬ������С��ʾ��
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
//qsort��Ӧ�ã�
//cmp����ֵ�����࣬С�ڷ��ظ�������ȷ���0�����ڷ�������.

//һ����int������������
int num[100];
int cmp ( const void *a , const void *b ){
    return *(int *)a - *(int *)b;
}
qsort(num,100,sizeof(num[0]),cmp);
//������char������������ͬint���ͣ�
char word[100];
int cmp( const void *a , const void *b ){
    return *(char *)a - *(int *)b;
}
qsort(word,100,sizeof(word[0]),cmp);
//������double������������
double in[100];
int cmp( const void *a , const void *b ){
    return *(double *)a > *(double *)b ? 1 : -1;
}
qsort(in,100,sizeof(in[0]),cmp);
//�ġ��Խṹ��һ������
struct Sample{
    double data;
    int other;
}s[100];
//����data��ֵ��С���󽫽ṹ������
int cmp( const void *a ,const void *b){
    return (*(Sample *)a).data > (*(Sample *)b).data ? 1 : -1;
}
qsort(s,100,sizeof(s[0]),cmp);
//�塢�Խṹ���������
struct Sample{
    int x;
    int y;
}s[100];
//����x��С�������򣬵�x���ʱ����y�Ӵ�С����
int cmp( const void *a , const void *b ){
    struct Sample *c = (Sample *)a;
    struct Sample *d = (Sample *)b;
    if(c->x != d->x) return c->x - d->x;
    else return d->y - c->y;
}
qsort(s,100,sizeof(s[0]),cmp);
//�������ַ�����������
struct Sample{
    int data;
    char str[100];
}s[100];
//���սṹ�����ַ���str���ֵ�˳������
int cmp ( const void *a , const void *b ){
    return strcmp( (*(Sample *)a)->str , (*(Sample *)b)->str );
}
qsort(s,100,sizeof(s[0]),cmp);
//memset
//memset���Է�������һ���ṹ���͵ı��������顣
struct sample_struct{
	char csName[16];
	int iSeq;
	int iType;
};
//���ڱ���
struct sample_strcut stTest;
//��memset�ͷǳ����㣺
memset(&stTest,0,sizeof(struct sample_struct));
//��������飺
struct sample_struct TEST[10];
memset(TEST,0,sizeof(struct sample_struct)*10);