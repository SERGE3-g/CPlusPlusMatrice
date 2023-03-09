//
// Created by guea on 09/03/23.
//

#include <iostream>
#include <random>
using namespace std;

int main()
{
    int righe = 9;
    int colonne = 9;

    int matrice[righe][colonne];

    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = rand() % 10;

        }
    }
    // stampo 0 sulle diagonali

    for (int i = 0; i < righe ; i++){
        matrice[i][i] = 0;
        matrice[i][8-i] = 0;
    }


    cout << "    ";
    for (int i = 0; i < colonne; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int trattini = colonne * 2 + 4;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < righe; i++)
    {

        cout << i << "|  ";

        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j] << " ";
        }

        cout << endl;
    }

}



