/*-----------多边形结构------------*/ 
struct POLYGON{ 
   int n;                                  //多边形顶点数 
   double x[MaX],y[MaX];        //顶点坐标 
}poly; 

int zd[100000][2],znum;      //跖对的集合和跖对的数量 


/*------------辅助函数-----------*/ 
double dist(int a,int b,int c) 
{ 
   double vx1,vx2,vy1,vy2; 
   vx1=poly.x[b]-poly.x[a]; vy1=poly.y[b]-poly.y[a]; 
   vx2=poly.x[c]-poly.x[a]; vy2=poly.y[c]-poly.y[a]; 
   return fabs(vx1*vy2 - vy1*vx2); 
} 


/*-------------求凸多边形直径的函数-------------*/ 
double DIAMETER() 
{ 
   znum=0; 
   int i,j,k=1; 
   double m,tmp; 
   while(dist(poly.n-1,0,k+1) > dist(poly.n-1,0,k)+eps) 
      k++; 
   i=0; j=k; 
   while(i<=k && j<poly.n) 
   { 
      zd[znum][0]=i; zd[znum++][1]=j; 
      while(dist(i,i+1,j+1)>dist(i,i+1,j)-eps && j<poly.n-1) 
      { 
         zd[znum][0]=i; zd[znum++][1]=j; 
         j++; 
      } 
      i++; 
   } 
   m=-1; 
   for(i=0;i<znum;i++) 
   { 
      tmp =(poly.x[zd[i][0]]-poly.x[zd[i][1]]) * (poly.x[zd[i][0]]-poly.x[zd[i][1]]); 
      tmp+=(poly.y[zd[i][0]]-poly.y[zd[i][1]]) * (poly.y[zd[i][0]]-poly.y[zd[i][1]]); 
      if(m<tmp) m=tmp; 
   } 
   return sqrt(m); 
} 
