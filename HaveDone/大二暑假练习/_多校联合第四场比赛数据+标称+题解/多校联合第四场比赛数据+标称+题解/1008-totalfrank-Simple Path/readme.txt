标程中求解割点与双联通使用了递归，由于数据规模较大，并且手动出了一条链的数据。在windows上会爆栈，代码是在linux上测试的。
如果HDOJ上会爆栈的话，可以考虑将makedata中n = 80000, m = 79999, q = 3000这组数据改成n = 60000, m = n - 1, q = 3000后生成数据再测试。调整到不会爆栈的最大规模即可。