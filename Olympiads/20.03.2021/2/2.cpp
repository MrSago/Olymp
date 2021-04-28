
#include <bits/stdc++.h>

using namespace std;

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");

    double p, k, m, q, n;
    fscanf(fin, "%lf%lf%lf%lf%lf", &p, &k, &m, &q, &n);
    fclose(fin);

    int count_bag = 0;
    if (q > p) {
        count_bag = (int)(q / p);
        q -= count_bag * p;
    }

    if (count_bag) {
        fprintf(fout, "%.1lf\n", count_bag * min(n + p * k, m));
    } else {
        fprintf(fout, "%.1lf\n", n + q * k);
    }

    fclose(fout);
    return 0;
}

