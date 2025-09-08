#include <stdio.h>
#include <math.h>  

int main() {
    double a, b, c;
    printf("Entrez a, b, c : ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("Pas de racines r�elles\n");
    }
    else if (delta == 0) {
        double x = -b / (2 * a);
        printf("Une racine r�elle : %.2f\n", x);
    }
    else {
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        printf("Deux racines r�elles : %.2f et %.2f\n", x1, x2);
    }
    return 0;
}
