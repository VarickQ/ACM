//求最大子段和,复杂度O(n)
//传入串长n和内容list[]
//返回最大子段和,重载返回子段位置(maxsum=list[start]+...+list[end])
//可更改元素类型
typedef int elem_t;

elem_t maxsum(int n,elem_t* list){
	elem_t ret,sum=0;
	int i;
	for (ret=list[i=0];i<n;i++)
		sum=(sum>0?sum:0)+list[i],ret=(sum>ret?sum:ret);
	return ret;
}

elem_t maxsum(int n,elem_t* list,int& start,int& end){
	elem_t ret,sum=0;
	int s,i;
	for (ret=list[start=end=s=i=0];i<n;i++,s=(sum>0?s:i))
		if ((sum=(sum>0?sum:0)+list[i])>ret)
			ret=sum,start=s,end=i;
	return ret;
}