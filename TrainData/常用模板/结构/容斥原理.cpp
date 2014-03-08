int a[20];
int n,m;

int run(bitset<20>& mask,int p,int len)
{
    if(mask.count() == len)
    {
        int val=1;
        for(int i=0;i<20;++i)            
        {
            if(mask[i])
                val*=a[i];
        }
        return m/val;
    }
    if(p==n)
        return 0;
    int re=run(mask, p+1,len);
    mask[p]=1;
    re+=run(mask, p+1, len);
    mask[p]=0;
    return re;
}
    
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    int b[20];
    int i,j,len;
    int p[20][20];

    while(cin>>n>>m)
    {
        memset(p,0,sizeof p);
        memset(b,0,sizeof b);

        for(i=0;i<n;++i)
            cin>>a[i];
        sort(a,a+n);
        for(i=n-1;i>=0;--i)
        {
            for(j=0;j<i;++j)//important: ascending order. e.g, 2 4 8
                if(a[i]!=a[j] && a[i]%a[j]==0)
                {
                    b[a[j]]=1;
                    break;
                }
            if(j==i)
                b[a[i]]=1;
        }
        for(n=0,i=0;i<20;++i)
        {
            if(b[i])
                a[n++]=i;
        }

        int re=0,positive=1;
        for(i=0;i<n;++i)
            p[0][i]=1;
        for(len=1;len<=n;++len)
        {
            bitset<20> mask;
            int val=run(mask,0,len);
            re+=positive? val: -val;
            positive=1-positive;
        }
        cout<<re<<endl;
    }
}
