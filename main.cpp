#include <QCoreApplication>
#include <iostream>     // Pour cout et hex
#include <iomanip>      // Pour setfill et setw
#include <windows.h>    // Pour GetStdHandle et SetConsoleTextAttribute

using namespace std;    // Pour éviter de répéter std::

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Permet de récupérer un pointeur sur la console
    HANDLE	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Affiche les 256 combinaisons de couleurs avec leur valeur en HEXA
    for(int i = 0; i < 256; i++) {
        SetConsoleTextAttribute(hConsole, i);
        // setw(2) impose des nombres sur 2 chiffres
        // setfill('0') ajoute des 0 à gauche des nombres < 2 chiffres
        cout << " 0x" << hex << setfill('0') << setw(2) << i << " ";

        // Faire un saut de ligne toutes les 16 valeurs
        if((i & 0x0F)==0x0F) cout << endl;
    }

    return a.exec();
}
