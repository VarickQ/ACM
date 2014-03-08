#include <cstdio>
#include <cstdlib>
#include <cstring>

const int AC = 0;
const int WA = 1;
const int MAXN = 160;
int mp[MAXN][MAXN];
int tk[MAXN], ans[MAXN];
char buf[128];

void report(int v, const char *str) {
    printf("%s\n", str);
    exit(v);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s std_input user_output\n");
        return -1;
    }
    FILE *fin = fopen(argv[1], "r");
    FILE *fuser = fopen(argv[2], "r");
    if (!fin || !fuser) {
        printf("Fail to open files\n");
        return -1;
    }
    int n, m, ca = 0;
    while (fscanf(fin, "%d%d", &n, &m) != EOF) {
        // printf("Case %d:\n", ++ca);
        memset(mp, 0, sizeof(mp));
        while (m--) {
            int t1, t2;
            fscanf(fin,"%d%d",&t1,&t2);
            --t1; --t2;
            mp[t1][t2] = mp[t2][t1] = 1;
        }
        memset(tk, 0, sizeof(tk));
        for (int i = 0 ; i < n ; i++) {
            fscanf(fuser, "%d", &ans[i]);
            --ans[i];
            if (ans[i] < 0 || ans[i] >= n || tk[ans[i]])
                report(WA, "Not a valid permutation.");
            tk[ans[i]] = 1;
        }
        for (int i = 0 ; i < n ; i++) {
            if (mp[ans[i]][ans[(i+1)%n]] == 0) {
                sprintf(buf, "Edge (%d,%d) does not exist.", ans[i]+1, ans[(i+1)%n]+1);
                report(WA, buf);
            }
        }
    }
    fclose(fuser);
    fclose(fin);
    report(AC, "Accepted");
    return 0;
}
