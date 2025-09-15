#include <iostream>
#include <iomanip> // Pour setw() et l'alignement
using namespace std;

int main() {
    cout << "Table de multiplication complete :" << endl;
    cout << "==================================" << endl << endl;
    cout << setw(4) << "x |";
    for (int i = 1; i <= 10; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    cout << "----+";
    for (int i = 1; i <= 10; i++) {
        cout << "----";
    }
    cout << endl;

    // Affichage de la table complète
    for (int i = 1; i <= 10; i++) {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= 10; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    return 0;
}