struct point{double x,y;};
struct line{point a,b;};

//������ֱ�߽���
point intersection(line u,line v){
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}

//����p1,p2�д���
line pline(point p1,point p2){
	line ret;
	ret.a.x=(p1.x+p2.x)/2;
	ret.a.y=(p1.y+p2.y)/2;
	ret.b.x=ret.a.x-p1.y+p2.y;
	ret.b.y=ret.a.y+p1.x-p2.x;
	return ret;
}

//������Բ��Բ��,һ��Ҫ��֤���㲻����!
inline point circle(point a,point b,point c){
	return intersection(pline(a,b),pline(b,c));
}