#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string nomFichier;
    cout << "Entrez le nom du fichier a analyser : ";
    cin >> nomFichier;

    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier '" << nomFichier << "'" << endl;
        return 1;
    }

    int nombreLignes = 0;
    int nombreMots = 0;
    int nombreLettres = 0;
    vector<int> occurrences(26, 0); 
    string ligne;

    while (getline(fichier, ligne)) {
        nombreLignes++;

        istringstream streamLigne(ligne);
        string mot;

        while (streamLigne >> mot) {
            nombreMots++;

            for (char c : mot) {
                if (isalpha(c)) {
                    nombreLettres++;
                    char lettre = tolower(c); // Converstion en minuscule
                    occurrences[lettre - 'a']++;
                }
            }
        }
    }

    fichier.close();

    // Affichage des résultats
    cout << "\n=== ANALYSE DU FICHIER ===" << endl;
    cout << "Nombre de lignes : " << nombreLignes << endl;
    cout << "Nombre de mots : " << nombreMots << endl;
    cout << "Nombre de lettres : " << nombreLettres << endl;

    cout << "\n=== OCCURRENCES DES LETTRES ===" << endl;
    for (int i = 0; i < 26; i++) {
        char lettre = 'a' + i;
        cout << lettre << " : " << occurrences[i] << "\t";

        // Affichage en 4 colonnes pour plus de lisibilité
        if ((i + 1) % 4 == 0) cout << endl;
    }
    cout << endl;

    return 0;
}