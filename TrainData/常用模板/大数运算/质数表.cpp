//用质数表判定质数,先调用initprime
int plist[10000],pcount=0;

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
	return n>1;
}

void initprime(){
	int i;
	for (plist[pcount++]=2,i=3;i<50000;i++)
		if (prime(i))
			plist[pcount++]=i;
}