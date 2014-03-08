#define _cp(a,b) ((a)<(b)) 
#define MAXN 10000 
typedef int elem_t; 
  
int subseq(int n,elem_t* a){ 
    int b[MAXN],i,l,r,m,ret=0; 
    for (i=0;i<n;b[l]=i++,ret+=(l>ret)) 
        for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1) 
            if (_cp(a[b[m]],a[i])) 
                l=m+1; 
            else 
                r=m-1; 
    return ret; 
} 