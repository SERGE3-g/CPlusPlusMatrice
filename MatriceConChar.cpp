//
// Created by guea on 09/03/23.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int rows = 20;
    int columns = 20;
    string words[] = {"ciao", "word", "apple", "barbabietole", "oshio" };
    char empty = ' ';


    int wordsLength = sizeof(words) / sizeof(words[0]);
    int contatore = 0;
    char matrix[rows][columns];

    // fill matrix with ' '
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = empty;
        }
    }

    for (int index = 0; index < wordsLength; index++)
    {
        if (index % 3 == 0)
        { // orizzontale
            if (words[index].length() > columns)
            {
                cout << "word " << words[index] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % rows; // row random
                int y = random() % (columns - words[index].length());

                while (matrix[x][y] != empty)
                {
                    x = random() % rows; // row random
                    y = random() % (columns - words[index].length());
                }

                for (int i = 0; i < words[index].length(); i++)// controllo se la cella è vuota
                {
                    if (matrix[x][y + i] != empty)
                    {
                        x = random() % rows; // row random
                        y = random() % (columns - words[index].length());
                        i = 0;
                    }
                }

                for (int i = 0; i < words[index].length(); i++)// fill the matrix with the word
                {
                    matrix[x][y + i] = words[index][i];
                    // cout << "index: " << index << " i: " << i << " x: " << x << " y: " << y << endl;
                    // cout << "matrix[" << x << "][" << y + i << "] = " << words[index][i] << endl;
                    // cout << "result: " << matrix[x][y + i] << endl;
                }
            }
        }
        else if (index % 3 == 1)
        { // verticale
            if (words[index].length() > rows)
            {
                cout << "word " << words[index] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length());
                int y = random() % columns;

                while (matrix[x][y] != empty)
                {
                    x = random() % (rows - words[index].length());
                    y = random() % columns;
                }

                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x + i][y] != empty)
                    {
                        x = random() % (rows - words[index].length());
                        y = random() % columns;
                        i = 0;
                    }
                }

                for (int i = 0; i < words[index].length(); i++)
                {
                    matrix[x + i][y] = words[index][i];
                    // cout << "index: " << index << " i: " << i << " x: " << x << " y: " << y << endl;
                    // cout << "matrix[" << x << "][" << y + i << "] = " << words[index][i] << endl;
                    // cout << "result: " << matrix[x][y + i] << endl;
                }
            }
        }
        else
        {
            // cout << "diagonale" << endl;
        }
    }


    // // fill the matrix with random char if empty
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < columns; j++)
    //     {
    //         if (matrix[i][j] == empty)
    //         {
    //             matrix[i][j] = random() % 25 + 97;
    //         }
    //     }
    // }

    cout << "devi trovare " << contatore << " parole" << endl;

    // stampo la matrice
    cout << "    ";
    for (int i = 0; i < columns; i++)
    {
        if(i < 10){
            cout << " " << i;
        }
        else{
            cout << " " << i;
        }

    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {

        if(i < 10){
            cout << "  " << i << " |";
        }
        else{
            cout << " " << i << " |";
        }

        for (int j = 0; j < columns; j++)// stampa la matrice
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}