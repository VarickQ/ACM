#include <cstdio>
#include <cstdlib>
#include <cmath>

const int AC = 0;
const int WA = 1;

const double eps = 1e-4;

void report(int v, const char *str) {
    printf("%s\n", str);
    exit(v);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s std_out user_out\n", argv[0]);
        return 1;
    }
    FILE *fout = fopen(argv[1], "r");
    FILE *fuser = fopen(argv[2], "r");
    double std, usr;
    while (fscanf(fout, "%lf", &std) != EOF) {
        if (fscanf(fuser, "%lf", &usr) != 1) {
            report(WA, "Missing output");
        }
        if (fabs(std-usr) > eps) {
            report(WA, "Wrong Output");
        }
    }
    fclose(fuser);
    fclose(fout);
    report(AC, "Accepted");
    return 0;
}
