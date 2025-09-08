#include <stdio.h>
#include <string.h>

int main() {
    char mot[50], affichage[50], lettre;
    int essais = 10, trouve = 0;

    printf("Entrez le mot secret : ");
    scanf("%s", mot);

    int n = strlen(mot);
    for (int i = 0; i < n; i++) affichage[i] = '_';
    affichage[n] = '\0';

    while (essais > 0 && !trouve) {
        printf("Mot : %s | Essais restants : %d\n", affichage, essais);
        printf("Proposez une lettre : ");
        scanf(" %c", &lettre);

        int bonne = 0;
        for (int i = 0; i < n; i++) {
            if (mot[i] == lettre) {
                affichage[i] = lettre;
                bonne = 1;
            }
        }
        if (!bonne) essais--;

        if (strcmp(mot, affichage) == 0) trouve = 1;
    }

    if (trouve) printf("Bravo ! Le mot était %s\n", mot);
    else printf("Perdu ! Le mot était %s\n", mot);

    return 0;
}
