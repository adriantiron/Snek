#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool gameOver;
const int height = 25;
const int width = 75;
int headX, headY, fruitX, fruitY, score;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir;


void Setup()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height/ 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");

    for (int i=0; i<width; i++)
        cout<<"#";
    cout<<"\n";

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {

            if (j == 0 || j == width - 1)
                cout<<"#";
            else
            {
                if (i == headY && j == headX)
                    cout<<"O";
                else if (i == fruitY && j == fruitX)
                    cout<<"*";
                else
                    cout<<" ";


            }
        }

        cout<<"\n";

    }


    for (int i=0; i<width; i++)
        cout<<"#";

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

    }


}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(30);
    }


    return 0;
}
