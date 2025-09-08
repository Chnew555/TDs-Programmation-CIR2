#include <stdio.h>

// Version for
int fact_for(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

// Version while
int fact_while(int n) {
    int res = 1, i = 1;
    while (i <= n) {
        res *= i;
        i++;
    }
    return res;
}

// Version récursive
int fact_rec(int n) {
    if (n == 0) return 1;    // Cas terminal
    return n * fact_rec(n - 1);
}

int main() {
    int n;
    printf("Entrez n : ");
    scanf("%d", &n);

    printf("Factorielle avec for : %d\n", fact_for(n));
    printf("Factorielle avec while : %d\n", fact_while(n));
    printf("Factorielle recursive : %d\n", fact_rec(n));

    return 0;
}
