#include <iostream>
#include <iomanip> // Pour setw() et l'alignement
using namespace std;

int main() {
    int nombre;

    // Demander à l'utilisateur un chiffre entre 1 et 9
    do {
        cout << "Entrez un chiffre entre 1 et 9 : ";
        cin >> nombre;

        if (nombre < 1 || nombre > 9) {
            cout << "Erreur : le chiffre doit etre entre 1 et 9." << endl;
        }
    } while (nombre < 1 || nombre > 9);

    // Afficher la table de multiplication
    cout << "\nTable de multiplication de " << nombre << " :" << endl;
    cout << "----------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << nombre << " x " << setw(2) << i << " = " << setw(2) << nombre * i << endl;
    }

    return 0;
}
