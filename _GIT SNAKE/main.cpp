#include <iostream>
#include <windows.h>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 40;
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

}

void Input()
{

}

void Logic()
{

}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(60);
    }


    return 0;
}
