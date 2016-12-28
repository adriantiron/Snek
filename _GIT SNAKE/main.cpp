#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 50;
int headX, headY, fruitX, fruitY, score;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir;
int nTail, tailX[100], tailY[100];


void ClearScreen(int x, int y)
{
    COORD p = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void ShowConsoleCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out,&cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(out,&cursorInfo);
}

void Setup()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height/ 2;
    srand(time(NULL));
    while (fruitX != headX && fruitY != headY)
    {
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    score = 0;
}

void Draw()
{
    ClearScreen( 0, 0 );   // system("cls");

    for (int i=0; i<width+2; i++)
        cout<<"#";
    cout<<"\n";

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {

            if (j == 0)
                cout<<"#";

            if (i == headY && j == headX)
                cout<<"O";
            else if (i == fruitY && j == fruitX)
                cout<<"*";
            else
            {
                bool tailDisplayed = false;

                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        tailDisplayed = true;
                    }
                }
                if (!tailDisplayed)
                    cout<<" ";

            }



            if (j == width - 1)
                cout<<"#";
        }

        cout<<endl;
    }


    for (int i=0; i<width+2; i++)
        cout<<"#";

    cout<<endl;
    cout<<"SCORE: "<<score;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        }

    }

}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = headX;
    tailY[0] = headY;

    for (int i=1; i< nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case UP:
        headY--;
        break;

    case LEFT:
        headX--;
        break;

    case DOWN:
        headY++;
        break;

    case RIGHT:
        headX++;
        break;

    default:
        break;
    }

    if ( headX >= width || headX <= 0 || headY >= height || headY < 0)
        gameOver = true;

    for (int i=0; i<nTail; i++)
        if (tailX[i] == headX && tailY[i] == headY)
            gameOver = true;

    if (headX == fruitX && headY == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }



}

int main()
{
    ShowConsoleCursor();
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(55);
    }

    return 0;
}
