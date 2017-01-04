#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <stdio.h>

using namespace std;

bool gameOver;
const int height = 40;
const int width = 40;
int headX, headY, fruitX, fruitY, score , uspeedX , uspeedY , boostX , boostY , dspeedX , dspeedY , lhalfX , lhalfY ;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir;
int nTail, tailX[100], tailY[100];

//Prototypes:
void menu();
void multiplayer();
void help();
void highscores();

//Sprites:
void headSprite(int x , int y)
{
      int i , j , a[10][10]={
      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,
      0 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 1 , 0 ,
      1 , 1 , 2 , 2 , 1 , 1 , 2 , 2 , 1 , 1 ,
      1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 ,
      1 , 2 , 1 , 2 , 2 , 2 , 2 , 1 , 2 , 1 ,
      1 , 2 , 1 , 2 , 2 , 2 , 2 , 1 , 2 , 1 ,
      1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 ,
      1 , 1 , 2 , 2 , 1 , 1 , 2 , 2 , 1 , 1 ,
      0 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 1 , 0 ,
      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,
      };
      for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        if(a[i][j]==1)
      {
          setfillstyle(SOLID_FILL , LIGHTGREEN);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , WHITE);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , LIGHTGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
}

void bodySprite(int x , int y)
{
     int i , j , a[10][10]={
      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,
      0 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 1 , 0 ,
      0 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 0 ,
      0 , 1 , 2 , 2 , 1 , 1 , 2 , 2 , 1 , 0 ,
      0 , 1 , 2 , 2 , 1 , 1 , 2 , 2 , 1 , 0 ,
      0 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 0 ,
      0 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 1 , 0 ,
      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,
      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
      };
      for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        if(a[i][j]==1)
      {
          setfillstyle(SOLID_FILL , LIGHTGREEN);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , WHITE);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , LIGHTGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
}



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
    SetWindow(50,50);
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
    char wallChar = 'w';
    char snekHead = 'h';
    char fruitChar = 'f';

    ClearScreen( 0, 0 );   // system("cls");
    setfillstyle(SOLID_FILL , BLACK);
    bar(0,0,10,10);
    setfillstyle(SOLID_FILL , LIGHTGREEN);
    bar(20 , 20 , 420 , 30);
    bar(20 , 30 , 30 , 420);
    bar(30 , 410 , 410 , 420);
    bar(410 , 30 , 420 , 420);
    for (int i=1; i<=height; i++)
    {
        for (int j=1; j<=width; j++)
        {
            if (i == headY && j == headX)
            {
                headSprite((i+2)*10,(j+2)*10);
               // setfillstyle(SOLID_FILL , LIGHTGREEN);
                //bar((i+2)*10 , (j+2)*10 , (i+2)*10+10 , (j+2)*10+10);
            }
            else if (i == fruitY && j == fruitX)
            {
                setfillstyle(SOLID_FILL , RED);
                bar((i+2)*10 , (j+2)*10 , (i+2)*10+10 , (j+2)*10+10);
                cout<<fruitChar;
            }

            else
            {
                bool tailDisplayed = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        bodySprite((i+2)*10,(j+2)*10);
                       // setfillstyle(SOLID_FILL , LIGHTGREEN);
                       // bar((i+2)*10 , (j+2)*10 , (i+2)*10+10 , (j+2)*10+10);
                        cout<<"b";
                        tailDisplayed = true;
                    }
                }
                if (!tailDisplayed && j<=width-2 && i<=height-2)
                    {
                        setfillstyle(SOLID_FILL , LIGHTGRAY);
                        bar((i+2)*10 , (j+2)*10 , (i+2)*10+10, (j+2)*10+10);
                        cout<<" ";
                    }

            }

            if (j == width)
                   cout<<wallChar;
        }

        cout<<endl;
    }


    for (int i=0; i<width; i++)
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

        case 'a':
        {
            if (dir != DOWN)
                dir = UP;
            break;
        }
        case 'w':
        {
            if (dir != RIGHT)
                dir = LEFT;
            break;
        }
        case 'd':
        {
            if (dir != UP)
                dir = DOWN;
            break;
        }
        case 's':
        {
            if (dir != LEFT)
                dir = RIGHT;
            break;
        }
        case 'q':
        {
             menu();
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

    if ( headX >= width-1 || headX < 1 || headY >= height-1 || headY < 1)
        gameOver = true;

    for (int i=0; i<nTail; i++)
        if (tailX[i] == headX && tailY[i] == headY)
            gameOver = true;

    if (headX == fruitX && headY == fruitY)
    {
        score += 10;
        fruitX = rand() % (width-4) + 3;
        fruitY = rand() % (height-4) + 3;
        bool fruitIsOnTail = true;

        while (fruitIsOnTail)
        {
            fruitIsOnTail = false;
            for (int i=0; i<nTail; i++)
                if (tailX[i] == fruitX && tailY[i] == fruitY)
                {
                    fruitX = rand() % (width-4) + 3;
                    fruitY = rand() % (height-4) + 3;
                    fruitIsOnTail = true;
                }
        }
        bool fruitIsOnHead = true;

        while (fruitIsOnHead)
        {
            fruitIsOnHead = false;
                if (headX == fruitX && headY == fruitY)
                {
                    fruitX = rand() % (width-4) + 3;
                    fruitY = rand() % (height-4) + 3;
                    fruitIsOnHead = true;
                }
        }
        nTail++;
    }

}

void game_window()
{
    initwindow(630 , 460 , "SNEK");
}

void game_score()
{
    char arr[50];
    sprintf(arr , "SCORE: %d " , score);
    setcolor(LIGHTCYAN);
    outtextxy(500 , 150 , arr);
}

void singleplayer()
{
    system("color 3");
    ShowConsoleCursor();
    Setup();
    game_window();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        game_score();
    }

    cout<<endl<<"         Better luck next time!"<<endl;
    Sleep(1000);
}

void menu()
{
    singleplayer();
}

void multiplayer()
{

}

void help()
{

}

void highscores()
{

}

int main()
{
    menu();
    return 0;
}
