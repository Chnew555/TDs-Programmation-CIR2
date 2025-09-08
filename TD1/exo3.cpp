#include <stdio.h>
#include <ctype.h>

char minuscule(char c) {
    return tolower(c); // convertit en minuscule si possible
}

int main() {
    char c;
    printf("Entrez un caractère : ");
    scanf(" %c", &c);

    printf("En minuscule : %c\n", minuscule(c));
    return 0;
}
