#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

int n, tk[10];
double p[10], sump[10];
const int MAX_ITR = 10000000;

int random_draw() {
    double p = (double)rand() / RAND_MAX;
    int i;
    for (i = 0 ; i < n ; i++) {
        if (p < sump[i]) break;
    }
    return i;
}

int main() {
    freopen("collector.in","r",stdin);
    freopen("collector.out.bf","w",stdout);
    srand(time(NULL));
    while (scanf("%d",&n) != EOF) {
        double pre = .0;
        for (int i = 0 ; i < n ; i++) {
            scanf("%lf",&p[i]);
            sump[i] = pre + p[i];
            pre += p[i];
        }
        long long tot_step = 0;
        for (int itr = 0 ; itr < MAX_ITR ; ++itr) {
            /*
            if (itr % (MAX_ITR / 100) == 0) {
                printf("iter %d\n", itr);
            }
            */
            memset(tk, 0, sizeof(tk));
            int cnt = 0, step = 0;
            while (cnt < n) {
                ++step;
                int v = random_draw();
                // printf("v:%d\n",v);
                if (v < n && tk[v] == 0) {tk[v] = 1; ++cnt;}
            }
            tot_step += step;
        }
        printf("%.6lf\n",(double)tot_step / MAX_ITR);
    }
    return 0;
}
