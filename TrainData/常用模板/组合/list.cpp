ICPC2002 模块库
maintained by WishingBone
Last Update @ October 23
release

几何\
  多边形
  浮点函数
  几何公式
  面积
  球面
  三点共圆
  三维几何
  凸包(graham)					O(nlogn)
  网格(pick)
  整数函数
  注意
结构\
  并查集					O(1)-O(logn)
  并查集扩展(friend_enemy)			O(1)-O(logn)
  堆(binary)					O(logn)
  堆(mapped)					O(logn)
  线段树
  子段和					O(logn)
  子阵和					O(logm*logn)
其他\
  大数(整数类封装)
  大数说明
  分数
  矩阵
  线性方程组(gauss)
  日期
数论\
  阶乘最后非零位
  模线性方程(组)
  质数表
  质数随机判定(miller_rabin)
  最大公约数最小公倍数
图论_NP搜索\
  最大独立集
  最大团
  最小支配集
  最小支配集(方案)
图论_P算法\
  欧拉回路(邻接阵形式)				O(n^2)
  拓扑排序(邻接阵形式)				O(n^2)
  无向图关键边(dfs邻接阵形式)			O(n^2)
  无向图关键点(dfs邻接阵形式)			O(n^2)
  无向图块(bfs邻接阵形式)			O(n^2)
  无向图连通分支(bfs邻接阵形式)			O(n^2)
  无向图连通分支(dfs邻接阵形式)			O(n^2)
  有向图强连通分支(bfs邻接阵形式)		O(n^2)
  有向图强连通分支(dfs邻接阵形式)		O(n^2)
  有向图最小点基(邻接阵形式)			O(n^2)
图论_匹配\
  二分图完备匹配(hungary邻接表形式)		O(m*e)
  二分图完备匹配(hungary邻接阵形式)		O(m*m*n)
  二分图完备匹配(hungary正向表形式)		O(m*e)
  二分图最大匹配(hungary邻接表形式)		O(m*e)
  二分图最大匹配(hungary邻接阵形式)		O(m*m*n)
  二分图最大匹配(hungary正向表形式)		O(m*e)
  一般图最大匹配(邻接表形式)			O(n*e)
  一般图最大匹配(邻接阵形式)			O(n^3)
  一般图最大匹配(正向表形式)			O(n*e)
图论_网络流\
  最大流(邻接阵形式)
图论_最短路径\
  最短路径(单源bellman_ford邻接表形式)  	O(n*m)
  最短路径(单源bellman_ford邻接阵形式)		O(n^3)
  最短路径(单源dijkstra邻接阵形式)		O(n^2)
  最短路径(单源dijkstra_bfs邻接表形式)		O(m)
  最短路径(单源dijkstra_bfs正向表形式)		O(m)
  最短路径(单源dijkstra+binary_heap邻接表形式)	O(mlogm)
  最短路径(单源dijkstra+binary_heap正向表形式)	O(mlogm)
  最短路径(单源dijkstra+mapped_heap邻接表形式)	O(mlogn)
  最短路径(单源dijkstra+mapped_heap正向表形式)	O(mlogn)
  最短路径(多源floyd_warshall邻接阵形式)	O(n^3)
图论_支撑树\
  最小生成树(kruskal邻接表形式)			O(mlogm)
  最小生成树(kruskal正向表形式)			O(mlogm)
  最小生成树(prim邻接阵形式)			O(n^2)
  最小生成树(prim+binary_heap邻接表形式)	O(mlogm)
  最小生成树(prim+binary_heap正向表形式)	O(mlogm)
  最小生成树(prim+mapped_heap邻接表形式) 	O(mlogn)
  最小生成树(prim+mapped_heap正向表形式) 	O(mlogn)
  最小树形图(邻接阵形式)                        O(n^3)
应用\
  joseph模拟					O(n)
  N皇后构造解
  布尔母函数
  幻方构造
  模式匹配(kmp)					O(m+n)
  逆序对数					O(nlogn)
  最长子序列					O(nlogn)
  最大子串匹配					O(m*n)
  最大子段和					O(n)
  最大子阵和					O(n^3)
组合\
  排列组合生成
  生成gray码
  置换(polya)
  字典序全排列
  字典序组合
  组合公式
