#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    const int RIGHT = 0x4d;
    const int LEFT = 0x4b;
    const int UP = 0x48;
    const int DOWN = 0x50;
    const int ENTER = 0xd;
    int CursorY = 4;
    int bouton;

    void locate(int x, int y);
    /*BIBLIOTEQUE*/


    /*Fin BIBLIOTEQUE*/
    cout << "\t\t\t_________________________________________________________________" << endl;
    cout << "\t\t\t|\t\t\t\tMenu\t\t\t\t|" << endl;
    cout << "\t\t\t|_______________________________________________________________|" << endl;
    cout << "\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Afficher livres\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Afficher auteurs\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Saisir\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Suppression\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Rechercher\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Emprunter\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Rendre\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Noter\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|   Quitter\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t|_______________________________________________________________|" << endl;

    do {
        locate(25, CursorY);
        cout << "->";
        bouton = _getch();
        switch (bouton) {
        case UP:
            if (CursorY > 4) {
                locate(25, CursorY);
                cout << "  ";
                CursorY--;
            }
            break;
        case DOWN:
            CursorY;
            if (CursorY < 12) {
                locate(25, CursorY);
                cout << "  ";
                CursorY++;
            }
            break;
        default:
            break;
        }
    } while (bouton != ENTER);

        switch (CursorY) {
        case 4:
            system("cls");
            /*Procedure affichage livre*/
            break;
        case 5:
            /*Procedure affichage auteur*/
            break;
        case 6:
            /*Procedure saisie*/
            break;
        case 7:
            /*Procedure suppresion*/
            break;
        case 8:
            /*Procedure recherche*/
            break;
        case 9:
            /*Procedure d'emprunt*/
            break;
        case 10:
            /*Procedure de retour*/
            break;
        case 11:
            /*Procedure note livre*/
            break;
        case 12 : 
            break;
        default:
            break;
    }

}


void locate(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;

    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

/*void ZoomTextConsole(int fact)
{
    HANDLE hcsb = CreateFileA("CONOUT$", GENERIC_WRITE | GENERIC_READ, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
    GetCurrentConsoleFontEx(hcsb, FALSE, &cfi);
    cfi.dwFontSize.X *= fact;
    cfi.dwFontSize.Y *= fact;
    SetCurrentConsoleFontEx(hcsb, FALSE, &cfi);
    CloseHandle(hcsb);
}

int main()
{
    ZoomTextConsole(4);
    printf("plouf\n");
    system("pause");
}*/