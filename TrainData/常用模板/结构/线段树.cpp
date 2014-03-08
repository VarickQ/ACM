//Ïß¶ÎÊ÷
#define MAXN 10000
struct segtree{
	int n,cnt[MAXN],len[MAXN],cut[MAXN],bl[MAXN],br[MAXN];
	void update(int t,int l,int r);
	void inc_seg(int t,int l0,int r0,int l,int r);
	void dec_seg(int t,int l0,int r0,int l,int r);
	int seg_len(int t,int l0,int r0,int l,int r);
	int seg_cut(int t,int l0,int r0,int l,int r);
};

void segtree::update(int t,int l,int r){
	if (cnt[t])
		len[t]=r-l+1,cut[t]=bl[t]=br[t]=1;
	else if (r-l==1)
		len[t]=cut[t]=bl[t]=br[t]=0;
	else{
		len[t]=len[t+t]+len[t+t+1];
		cut[t]=cut[t+t]+cut[t+t+1];
		if (br[t+t]&&bl[t+t+1])
			cut[t]--;
		bl[t]=bl[t+t],br[t]=br[t+t+1];
	}
}

void segtree::inc_seg(int t,int l0,int r0,int l,int r){
	if (l0==l&&r0==r)
		cnt[t]++;
	else{
		int m0=(l0+r0)>>1;
		if (l<m0)
			inc_seg(t+t,l0,m0,l,m0<r?m0:r);
		if (r>m0)
			inc_seg(t+t+1,m0,r0,m0>l?m0:l,r);
		if (cnt[t+t]&&cnt[t+t+1]){
			cnt[t+t]--;
			update(t+t,l0,m0);
			cnt[t+t+1]--;
			update(t+t+1,m0,r0);
			cnt[t]++;
		}
	}
	update(t,l0,r0);
}

void segtree::dec_seg(int t,int l0,int r0,int l,int r){
	if (l0==l&&r0==r)
		cnt[t]--;
	else if (cnt[t]){
		cnt[t]--;
		if (l>l0)
			inc_seg(t,l0,r0,l0,l);
		if (r<r0)
			inc_seg(t,l0,r0,r,r0);
	}
	else{
		int m0=(l0+r0)>>1;
		if (l<m0)
			dec_seg(t+t,l0,m0,l,m0<r?m0:r);
		if (r>m0)
			dec_seg(t+t+1,m0,r0,m0>l?m0:l,r);
	}
	update(t,l0,r0);
}

int segtree::seg_len(int t,int l0,int r0,int l,int r){
	if (cnt[t])
		return r-l+1;
	if (l0==l&&r0==r)
		return len[t];
	else{
		int m0=(l0+r0)>>1,ret=0;
		if (l<m0)
			ret+=seg_len(t+t,l0,m0,l,m0<r?m0:r);
		if (r>m0)
			ret+=seg_len(t+t+1,m0,r0,m0>l?m0:l,r);
		return ret;
	}
}

int segtree::seg_cut(int t,int l0,int r0,int l,int r){
	if (cnt[t])
		return 1;
	if (l0==l&&r0==r)
		return cut[t];
	else{
		int m0=(l0+r0)>>1,ret=0;
		if (l<m0)
			ret+=seg_cut(t+t,l0,m0,l,m0<r?m0:r);
		if (r>m0)
			ret+=seg_cut(t+t+1,m0,r0,m0>l?m0:l,r);
		if (l<m0&&r>m0&&br[t+t]&&bl[t+t+1])
			ret--;
		return ret;
	}
}
