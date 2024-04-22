#include<iostream>
#include<ctime>
#include<math.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<string>
using namespace std;

void clearScreen()
{
    system("cls");
}


int main()
{
    cout << "------------------------------" << endl;
    cout << "|          C++ PACMAN        |" << endl;
    cout << "-----------------------------" << endl;
    cout << "|   CLASSIC ARCADE REVIVAL   |" << endl;
    cout << "-----------------------------" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "|       PRESS ENTER TO       |" << endl;
    cout << "|         START GAME         |" << endl;
    cout << "|                            |" << endl;
    cout << "|   Use W, A, S, D to move   |" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "------------------------------" << endl;
    string input;
    getline(cin, input);
    
    clearScreen;
    // Assigning the variables:
    char arr[15][15];
    int x, y, a = 2, b = 2, count = 0, score = 0;
    char move;
    srand(time(0));
    int gc1 = 12, gr1 = 10, gc2 = 3, gr2 = 9;
    char ghost1 = 'G';
    char ghost2 = 'G';
    char pacman = 'P';
    int ran = (rand() % 2 + 2);
    int gmove;

    // For Generating The Map
    for (x = 0; x < 15; x++)
    {
        for (y = 0; y < 15; y++)
        {
            if (x == 0 || x == 14)         // Maze Top and Bottom Rows
            {
                arr[x][y] = '#';
            }
            else if (y == 0 || y == 14)   // Maze Left Most and Right Most Column
            {
                arr[x][y] = '#';
            }
            else if (x == ran + 1)       // Random Obstakle Wall-1
            {
                arr[x][y] = '#';
                if (y == 4 || y == 9 || y == 13)
                    arr[x][y] = '.';  // Obstacle in green color
            }
            else if (x == ran + 3)       // Random Obstakle Wall-2
            {
                arr[x][y] = '#';
                if (y == 3 || y == 7 || y == 13)
                    arr[x][y] = '.';  // Obstacle in green color
            }
            else if (x == ran + 9)       // Random Obstakle Wall-3
            {
                arr[x][y] = '#';
                if (y == 4 || y == 9 || y == 13)
                    arr[x][y] = '.';  // Obstacle in green color
            }
            else
            {
                arr[x][y] = '.';          // Printing The Pallets
            }
            if (arr[x][y] == '.')
                count++;
        }
    }

    // For Printing the map
    arr[b][a] = pacman;
    cout << "\t\t\tScore: " << score << endl;
    for (x = 0; x < 15; x++)
    {
        for (y = 0; y < 15; y++)
        {
            if (x == gr1 && y == gc1)
                cout << "\033[1;34m" << ghost1 << " ";  // Blue Ghost
            else if (x == gr2 && y == gc2)
                cout << "\033[1;34m" << ghost2 << " ";  // Blue Ghost
            else if (arr[x][y] == '#')
                cout << "\033[1;32m" << arr[x][y] << " ";  // Green Wall
            else if (arr[x][y] == '.')
                cout << "\033[1;32m" << arr[x][y] << " ";  // Green Pallet
            else if (arr[x][y] == 'P')
                cout << "\033[1;31m" << arr[x][y] << " ";  // Red Pacman
        }
        cout << endl;
    }

    // For taking moves Infinite loop
    for (int m = 0; m == 0;)
    {
        cout << "\nEnter Move\t";
        if (score == count - 1)  // For ending game when all pallets are collected
        {
            cout << "Game over, You Win";
            cout << "\tYour Score: " << score << endl;
            break;
        }
        move = _getch();
        if (move == 's')
        {
            b++;
            if (b > 0)
            {
                arr[b - 1][a] = ' ';
                if (arr[b][a] == '#')
                    b--;
            }
        }
        else if (move == 'w')
        {
            b--;
            if (b >= 0)
            {
                arr[b + 1][a] = ' ';
                if (arr[b][a] == '#')
                    b++;
            }
        }
        else if (move == 'a')
        {
            a--;
            if (a >= 0)
            {
                arr[b][a + 1] = ' ';
                if (arr[b][a] == '#')
                {
                    a++;
                }
            }
        }
        else if (move == 'd')
        {
            a++;
            if (a >= 0)
            {
                arr[b][a - 1] = ' ';
                if (arr[b][a] == '#')
                {
                    a--;
                }
            }
        }

        if (arr[b][a] == '.')
        {
            score++;
        }

        // For Calculating Euclidean Distance
        float dis1 = sqrt(pow((b - (gr2 - 1)), 2) + (pow((a - gc2), 2)));
        float dis2 = sqrt(pow((b - (gr2 + 1)), 2) + (pow((a - gc2), 2)));
        float dis3 = sqrt(pow((b - gr2), 2) + (pow((a - (gc2 + 1)), 2)));
        float dis4 = sqrt(pow((b - gr2), 2) + (pow((a - (gc2 - 1)), 2)));

        // Moving Ghost chasing pacman
        if ((dis1 < dis2 && dis1 < dis3 && dis1 < dis4))
        {
            if (arr[gr2 - 1][gc2] != '#')
                gr2--;
        }
        else if ((dis2 < dis1 && dis2 < dis3 && dis2 < dis4))
        {
            if (arr[gr2 + 1][gc2] != '#')
                gr2++;
        }
        else if ((dis3 < dis1 && dis3 < dis2 && dis3 < dis4))
        {
            if (arr[gr2][gc2 + 1] != '#')
                gc2++;
        }
        else if ((dis4 < dis1 && dis4 < dis2 && dis4 < dis3))
        {
            if (arr[gr2][gc2 - 1] != '#')
                gc2--;
        }

        gmove = rand() % 4 + 1;
        if (gmove == 1)
        {
            if (arr[gr1 - 1][gc1] != '#')
                gr1--;
        }
        else if (gmove == 2)
        {
            if (arr[gr1 + 1][gc1] != '#')
                gr1++;
        }
        else if (gmove == 3)
        {
            if (arr[gr1][gc1 + 1] != '#')
                gc1++;
        }
        else if (gmove == 4)
        {
            if (arr[gr1][gc1 - 1] != '#')
                gc1--;
        }

        if ((b == gr1 && a == gc1) || (b == gr2 && a == gc2))  // Breaking loop when pacman gets caught by Ghost
        {
            cout << "Game over";
            cout << "\tYour Score: " << score << endl;
            break;
        }

        clearScreen();

        // Assigning the shapes for up/down/left/right to Pacman
        if (move == 's')
        {
            pacman = 'v';
            arr[b][a] = pacman;
        }
        else if (move == 'w')
        {
            pacman = '^';
            arr[b][a] = pacman;
        }
        else if (move == 'd')
        {
            pacman = '>';
            arr[b][a] = pacman;
        }
        else if (move == 'a')
        {
            pacman = '<';
            arr[b][a] = pacman;
        }
        else
        {
            cout << "Invalid Move";
        }

        cout << "\t\t\tScore: " << score << endl;

        // Printing The maze after a move
        for (x = 0; x < 15; x++)
        {
            for (y = 0; y < 15; y++)
            {
                if (x == gr1 && y == gc1)
                    cout << "\033[1;34m" << ghost1 << " ";  // Blue Ghost
                else if (x == gr2 && y == gc2)
                    cout << "\033[1;34m" << ghost2 << " ";  // Blue Ghost
                else if (arr[x][y] == '.')
                    cout << "\033[1;32m" << arr[x][y] << " ";  // Green Pallet
                else if (arr[x][y] == 'P')
                    cout << "\033[1;31m" << arr[x][y] << " ";  // Red Pacman
                else
                    cout << "\033[0m" << arr[x][y] << " ";  // Reset color for other characters
            }
            cout << endl;
        }
    }
    
    return 0;
}