/*  追赶法解周期性方程
    周期性方程定义：| a1 b1 c1 ...               |   |   | =  x1
                    |    a2 b2 c2 ...            |   |   | =  x2
                    |       ...                  | * | X | =  ...
                    | cn-1 ...         an-1 bn-1 |   |   | =  xn-1
                    | bn   cn                an  |   |   | =  xn
    输入：a[],b[],c[],x[]
    输出：求解结果X在x[]中
*/

void run()
{
	c[0] /= b[0]; a[0] /= b[0]; x[0] /= b[0];
	for (int i = 1; i < N - 1; i ++) {
		double temp = b[i] - a[i] * c[i - 1];
		c[i] /= temp;
		x[i] = (x[i] - a[i] * x[i - 1]) / temp;
		a[i] = -a[i] * a[i - 1] / temp;
	}
	a[N - 2] = -a[N - 2] - c[N - 2];
	for (int i = N - 3; i >= 0; i --) {
		a[i] = -a[i] - c[i] * a[i + 1];
		x[i] -= c[i] * x[i + 1];
	}
	x[N - 1] -= (c[N - 1] * x[0] + a[N - 1] * x[N - 2]);
	x[N - 1] /= (c[N - 1] * a[0] + a[N - 1] * a[N - 2] + b[N - 1]);
	for (int i = N - 2; i >= 0; i --)
		x[i] += a[i] * x[N - 1];
}
