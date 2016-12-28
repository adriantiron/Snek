#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 40;
int headX, headY, fruitX, fruitY, score;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir;
int nTail, tailX[100], tailY[100];


void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    // Get handle of the standard output
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Handle == NULL)
    {
        cout<<endl;

    }

    // Set screen buffer size to that specified in coord
    if(!SetConsoleScreenBufferSize(Handle, coord))
    {
        cout<<endl;

    }

    // Set the window size to that specified in Rect
    if(!SetConsoleWindowInfo(Handle, TRUE, &Rect))
    {
        cout<<endl;

    }

}

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
    SetWindow(42,24);
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
    char wallChar = 219;
    char snekHead = 232;
    char fruitChar = 42;

    ClearScreen( 0, 0 );   // system("cls");

    for (int i=0; i<width+2; i++)
        cout<<wallChar;
    cout<<endl;

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {

            if (j == 0)
                cout<<wallChar;

            if (i == headY && j == headX)
                cout<<snekHead;
            else if (i == fruitY && j == fruitX)
                cout<<fruitChar;
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
                cout<<wallChar;
        }

        cout<<endl;
    }


    for (int i=0; i<width+2; i++)
        cout<<wallChar;

    cout<<endl;
    cout << "                Score:" << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {

        case 'w':
        {
            if (dir != DOWN)
                dir = UP;
            break;
        }
        case 'a':
        {
            if (dir != RIGHT)
                dir = LEFT;
            break;
        }
        case 's':
        {
            if (dir != UP)
                dir = DOWN;
            break;
        }
        case 'd':
        {
            if (dir != LEFT)
                dir = RIGHT;
            break;
        }

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
    {
        Sleep(46);
        headY--;
        break;
    }
    case LEFT:
    {
        headX--;
        break;
    }
    case DOWN:
    {
        Sleep(46);
        headY++;
        break;
    }
    case RIGHT:
    {
        headX++;
        break;
    }
    default:
        break;
    }

    if ( headX >= width || headX < 0 || headY >= height || headY < 0)
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

    cout<<endl<<"         Better luck next time!"<<endl;
    Sleep(1000);
    return 0;
}
