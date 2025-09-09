#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 3, m = 4;
    int** tab = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) tab[i] = (int*)malloc(m * sizeof(int));
    srand(time(NULL));
    // Remplissage al�atoire
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab[i][j] = rand() % 100;
        }
    }
    for (int col = 0; col < m; col++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (tab[j][col] > tab[j + 1][col]) {
                    int tmp = tab[j][col];
                    tab[j][col] = tab[j + 1][col];
                    tab[j + 1][col] = tmp;
                }
            }
        }
    }
    printf("Tableau tri� colonne par colonne :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", tab[i][j]);
        }
        printf("\n");
    }
    // Lib�ration m�moire
    for (int i = 0; i < n; i++) free(tab[i]);
    free(tab);
    return 0;
}
