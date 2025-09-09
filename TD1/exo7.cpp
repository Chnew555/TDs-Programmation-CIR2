#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int tab[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) tab[i] = rand() % 100;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }

    printf("Tableau trié : ");
    for (int i = 0; i < N; i++) printf("%d ", tab[i]);
    printf("\n");

    return 0;
}
