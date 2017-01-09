#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <stdio.h>

using namespace std;

bool gameOver , quitted=false , existsSpecial=false;
const int height = 40;
const int width = 40;
int headX, headY, fruitX, fruitY, score , speedX , speedY , boostX , boostY , slowX , sloY , lhalfX , lhalfY ;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir;
int nTail, tailX[100], tailY[100];
int trin=1 , scoreAdd=1;



//Prototypes:
void menu();
void multiplayer();
void help();
void highscores();
void game_score();
void game_reset();
void spawnSpeed();
void spawnSlow();
void spawnBoost();
void spawnHalf();

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


void fruitSprite(int x , int y)
{
     int i , j , a[10][10]={
      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
      0 , 0 , 0 , 2 , 2 , 2 , 2 , 0 , 0 , 0 ,
      0 , 0 , 2 , 2 , 3 , 3 , 2 , 2 , 0 , 0 ,
      0 , 2 , 2 , 3 , 2 , 2 , 3 , 2 , 0 , 0 ,
      0 , 2 , 3 , 2 , 1 , 1 , 2 , 3 , 2 , 0 ,
      0 , 2 , 3 , 2 , 1 , 1 , 2 , 3 , 2 , 0 ,
      0 , 2 , 2 , 3 , 2 , 2 , 3 , 2 , 0 , 0 ,
      0 , 0 , 2 , 2 , 3 , 3 , 2 , 2 , 0 , 0 ,
      0 , 0 , 0 , 2 , 2 , 2 , 2 , 0 , 0 , 0 ,
      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
      };
      for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        if(a[i][j]==1)
      {
          setfillstyle(SOLID_FILL , GREEN);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , RED);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==3)
      {
          setfillstyle(SOLID_FILL , LIGHTRED);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , LIGHTGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
}

void speedSprite(int x , int y)
{

}

void slowSprite(int x , int y)
{

}

void boostSprite(int x , int y)
{

}

void halfSprite(int x , int y)a
{

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

void dataBoard()
{
    setfillstyle(SOLID_FILL ,BLACK);
    bar(440,60,610,280);
    game_score();
    settextstyle(8 , HORIZ_DIR , 1);
    outtextxy(460 , 120 , "KING:");
    setfillstyle(SOLID_FILL ,WHITE);
    bar(430,160,620,180);
    outtextxy(460 , 200 , "EXIT  - Q");
    outtextxy(460 , 240 , "PUASE - P");
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
    scoreAdd = 1;
}

void Draw()
{
    char wallChar = 'w';
    char snekHead = 'h';
    char fruitChar = 'f';

    ClearScreen( 0, 0 );   // system("cls");
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
            }
            else if (i == fruitY && j == fruitX)
            {
                fruitSprite((i+2)*10,(j+2)*10);
                cout<<fruitChar;
            }
            else if(i == speedY && j == speedX)
                speedSprite((i+2)*10,(j+2)*10);


            else
            {
                bool tailDisplayed = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        bodySprite((i+2)*10,(j+2)*10);
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

        if(GetAsyncKeyState('A'))
        {
            if (dir != DOWN)
                dir = UP;
        }
        else if(GetAsyncKeyState('W'))
        {
            if (dir != RIGHT)
                dir = LEFT;
        }
        else if(GetAsyncKeyState('D'))
        {
            if (dir != UP)
                dir = DOWN;
        }
        else if(GetAsyncKeyState('S'))
        {
            if (dir != LEFT)
                dir = RIGHT;
        }
        else if(GetAsyncKeyState('Q'))
        {
             gameOver = true;
             game_reset();
        }
}
void spawnFruit()
{
    bool fruitIsOnTail = true;
    while (fruitIsOnTail)
        {
            fruitIsOnTail = false;
            for (int i=0; i<nTail; i++)
                if (tailX[i] == fruitX && tailY[i] == fruitY)
                {
                    fruitX = rand() % (width-4) + 2;
                    fruitY = rand() % (height-4) + 2;
                    fruitIsOnTail = true;
                }
        }
        bool fruitIsOnHead = true;
        while (fruitIsOnHead)
        {
            fruitIsOnHead = false;
                if (headX == fruitX && headY == fruitY)
                {
                    fruitX = rand() % (width-4) + 2;
                    fruitY = rand() % (height-4) + 2;
                    fruitIsOnHead = true;
                }
        }
}

void spawnSpecial()
{
   unsigned spec;
   if(existsSpecial==false)
   {
       spec = rand() % 4 + 1;
       if(spec==1) spawnSpeed();
       else if(spec==2) spawnSlow();
       else if(spec==3) spawnHalf();
       else spawnBoost();
       existsSpecial = true;
   }

}

void spawnSpeed()
{

}

void spawnSlow()
{

}

void spawnBoost()
{

}

void spawnHalf()
{

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
        score += scoreAdd;
        fruitX = rand() % (width-4) + 3;
        fruitY = rand() % (height-4) + 3;

        spawnFruit();
        nTail++;
    }

    spawnSpecial();

}


void game_reset()
{
    nTail = 0;
}


void game_window()
{
    initwindow(630 , 460 , "SNEK");
}

void game_score()
{
    settextstyle(8 , HORIZ_DIR , 2);
    char arr[50];
    sprintf(arr , "SCORE:%d " , score);
    setcolor(LIGHTGREEN);
    outtextxy(460 , 80 , arr);
}

void singleplayer()
{
    system("color 3");
    ShowConsoleCursor();
    Setup();
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        dataBoard();
        Sleep(100);
    }
    Sleep(2000);
    menu();
}

void menu()
{
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    trin=1;
    setfillstyle(SOLID_FILL , BLACK);
    bar(100,60,530,400);
    setfillstyle(SOLID_FILL , LIGHTGREEN);
    setcolor(LIGHTGREEN);
    settextstyle(8 , HORIZ_DIR , 4);
    outtextxy(170 , 80 , "SINGLEPLAYER");
    outtextxy(170 ,170 , "MULTIPLAYER");
    outtextxy(170 ,260 , "HELP");
    outtextxy(170 ,350 , "QUIT");
    while(quitted!=true)
    {
             if(GetAsyncKeyState('W') && trin>1) trin--;
             else if(GetAsyncKeyState('S') && trin<4) trin++;
             else if(GetAsyncKeyState(VK_RETURN))
             {
                 if(trin==1) singleplayer();
                 if(trin==4) quitted = true;
             }
             setfillstyle(SOLID_FILL ,BLACK);
             bar(140,60,160,400);
             setfillstyle(SOLID_FILL , LIGHTGREEN);
             bar(140,trin*90,160,trin*90+10);
             Sleep(100);

    }
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
    game_window();
    bar(0,0,630,460);
    setfillstyle(SOLID_FILL , LIGHTGREEN);
    settextstyle(8 , HORIZ_DIR , 10);
    outtextxy(200 ,160 , "T&T");
    floodfill(202 ,190 , WHITE);
    floodfill(320 ,240 , WHITE);
    Sleep(3000);
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    menu();
    return 0;
}
