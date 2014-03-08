#include <cstdio>
#include <cstdlib>
#include <cstring>

const int T = 20;
int a[20];
double p[20];

int main() {
    freopen("data.in","w",stdout);
    srand(0xbeef);
    int n;
    for (int ca = 0 ; ca < T ; ++ca) {
        if (ca < T / 2) n = 5;
        else if (ca < T - 2) n = 10;
        else n = 20;
        while (true) {
            int tot = 0;
            for (int i = 0 ; i < n ; i++) {
                a[i] = rand() % 100 + 1;
                tot += a[i];
            }
            tot += rand() % 100 + 1;
            double sump = .0;
            int flg = 1;
            for (int i = 0 ; i < n ; i++) {
                p[i] = (double)a[i] / tot;
                char tmp_buf[20];
                double tmp_p;
                sprintf(tmp_buf, "%.2lf", p[i]);
                sscanf(tmp_buf, "%lf", &tmp_p);
                if (tmp_p == 0.0) {flg = 0;}
                sump += tmp_p;
            }
            if (flg == 0) continue;
            if (sump <= 1.0) break;
        }
        printf("%d\n",n);
        for (int i = 0 ; i < n ; i++) {
            if (i) printf(" ");
            printf("%.2lf", p[i]);
        }
        printf("\n");
    }
    return 0;
}
