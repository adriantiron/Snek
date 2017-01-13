#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <stdio.h>
#include <fstream>
#include "sprites.h"


using namespace std;


bool gameOver , quitted=false , existsSpecial=false , playerStarted = false;
bool speedInUse = false , slowInUse = false , boostInUse = false , halfInUse = false;
const int height = 40;
const int width = 40;
int headX, headY, fruitX, fruitY, score , speedX , speedY , boostX , boostY , slowX , slowY , lhalfX , lhalfY ;
int botHeadX, botHeadY , botNTail , botTailX[100] , botTailY[100] , botScore;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir , botDir;
int nTail, tailX[100], tailY[100];
int trin=1 , scoreAdd , movSpeed;
unsigned int highScore;
time_t startTime;


//Prototypes:
void menu();
void multiplayer();
void help();
void powersMenu();
void game_score();
void game_reset();
void spawnFruit();
void spawnSpecial();
void spawnSpeed();
void spawnSlow();
void spawnBoost();
void spawnHalf();
int botColision(eDirection);




void hideCmd()
{
    HWND hide_cmd;
    AllocConsole();
    hide_cmd = FindWindowA("ConsoleWindowClass" , NULL);
    ShowWindow(hide_cmd,0);
}

void dataBoard()
{
    game_score();
    settextstyle(8 , HORIZ_DIR , 1);

    char arr[50];
    sprintf(arr, "%d", highScore);
    outtextxy(460 , 120 , "KING:");
    outtextxy(520 , 120 , arr);
    outtextxy(460 , 200 , "EXIT  - Q");
    outtextxy(460 , 240 , "PAUSE - P");
    outtextxy(460 , 280 , "RESUME - O");
}

void multiDataBoard()
{
    settextstyle(8 , HORIZ_DIR , 1);
    char arr1[10] , arr2[10];
    sprintf(arr1, "%d", score);
    outtextxy(460 , 80 , "BLUE:");
    outtextxy(520 , 80 , arr1);
    sprintf(arr2, "%d", botScore);
    outtextxy(460 , 120 , "RED:");
    outtextxy(520 , 120 , arr2);
    outtextxy(460 , 200 , "EXIT  - Q");
    outtextxy(460 , 240 , "PAUSE - P");
    outtextxy(460 , 280 , "RESUME - O");
}


void Setup()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height/ 2;
    srand(time(NULL));
    fruitX = rand() % (width-4) + 3;
    fruitY = rand() % (height-4) + 3;
    score = 0;
    scoreAdd = 10;
    existsSpecial = speedInUse = slowInUse = boostInUse = halfInUse = false;
    speedX = speedY = slowX = slowY = boostX = boostY = lhalfX = lhalfY = 0;
    movSpeed = 80;
}

void multiSetup()
{
    gameOver = false;
    dir = STOP;
    botDir = STOP;
    headX = width / 4;
    headY = height/ 4;
    botHeadX = (width / 4) * 3;
    botHeadY = (height/ 4) * 3;
    srand(time(NULL));
    fruitX = rand() % (width-4) + 3;
    fruitY = rand() % (height-4) + 3;
    score = 0;
    botScore = 0;
    scoreAdd = 10;
    existsSpecial = true;
    speedX = speedY = slowX = slowY = boostX = boostY = lhalfX = lhalfY = 0;
    movSpeed = 80;
}

void Draw()
{
    setfillstyle(SOLID_FILL , BLUE);
    bar(20 , 20 , 420 , 30);
    bar(20 , 30 , 30 , 420);
    bar(30 , 410 , 410 , 420);
    bar(410 , 30 , 420 , 420);
    for (int i=1; i<=height; i++)
    {
        for (int j=1; j<=width; j++)
        {
            if (i == headY && j == headX)
                headSprite((i+2)*10,(j+2)*10);

            else if(i == botHeadY && j == botHeadX)
                botHeadSprite((i+2)*10,(j+2)*10);

            else if (i == fruitY && j == fruitX)
                fruitSprite((i+2)*10,(j+2)*10,1,boostInUse);

            else if(i == speedY && j == speedX)
                {
                    speedSprite((i+2)*10,(j+2)*10,1);

                    time_t endTime;
                    time (&endTime);
                    double elapsed_secs = difftime (endTime,startTime);

                    if (elapsed_secs > 11 && elapsed_secs < 13)
                        {
                            speedX = speedY = 0;
                            existsSpecial = false;
                            spawnSpecial();
                        }
                }
             else if(i == slowY && j == slowX)
                {
                    slowSprite((i+2)*10,(j+2)*10,1);

                    time_t endTime;
                    time (&endTime);
                    double elapsed_secs = difftime (endTime,startTime);
                    if (elapsed_secs > 8 && elapsed_secs < 10)
                        {
                            slowX = slowY = 0;
                            existsSpecial = false;
                            spawnSpecial();
                        }
                }
            else if(i == boostY && j == boostX)
                {
                    boostSprite((i+2)*10,(j+2)*10,1);

                    time_t endTime;
                    time (&endTime);
                    double elapsed_secs = difftime (endTime,startTime);
                    if (elapsed_secs > 8 && elapsed_secs < 10)
                        {
                            boostX = boostY = 0;
                            existsSpecial = false;
                            spawnSpecial();
                        }
                }
            else if(i == lhalfY && j == lhalfX)
                {
                    halfSprite((i+2)*10,(j+2)*10,1);

                    time_t endTime;
                    time (&endTime);
                    double elapsed_secs = difftime (endTime,startTime);
                    if (elapsed_secs > 8 && elapsed_secs < 10)
                        {
                            lhalfX = lhalfY = 0;
                            existsSpecial = false;
                            spawnSpecial();
                        }
                }
            else
            {
                bool tailDisplayed = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        bodySprite((i+2)*10,(j+2)*10);
                        bodySprite((i+2)*10,(j+2)*10);
                        tailDisplayed = true;
                    }
                }
                bool botTailDisplayed = false;
                for (int k = 0; k < botNTail; k++)
                {
                    if (botTailX[k] == j && botTailY[k] == i)
                    {
                        botBodySprite((i+2)*10,(j+2)*10);
                        botTailDisplayed = true;
                    }
                }

                if (!tailDisplayed && !botTailDisplayed && j<=width-2 && i<=height-2)
                    {
                        setfillstyle(SOLID_FILL , DARKGRAY);
                        bar((i+2)*10 , (j+2)*10 , (i+2)*10+10, (j+2)*10+10);
                    }
            }
        }
    }
}

void Input()
{

        if(GetAsyncKeyState('A'))
        {
            playerStarted = true;
            if (dir != DOWN)
                dir = UP;
        }
        else if(GetAsyncKeyState('W'))
        {
            playerStarted = true;
            if (dir != RIGHT)
                dir = LEFT;
        }
        else if(GetAsyncKeyState('D'))
        {
            playerStarted = true;
            if (dir != UP)
                dir = DOWN;
        }
        else if(GetAsyncKeyState('S'))
        {
            playerStarted = true;
            if (dir != LEFT)
                dir = RIGHT;
        }
        else if(GetAsyncKeyState('Q'))
        {
             gameOver = true;
             game_reset();
        }
        else if(GetAsyncKeyState('P'))
        {
               while (true)
               {
                   if (GetAsyncKeyState('O'))
                        break;
               }
        }

}

void botBrain()
{
        if(botDir == STOP)
        {
          if(fruitX > botHeadX) botDir = RIGHT;
          else if (fruitX < botHeadX) botDir = LEFT;
          else if (fruitY < botHeadY) botDir = UP;
          else if (fruitY > botHeadY) botDir = DOWN;
        }
        if(fruitX > botHeadX && botDir != RIGHT)
        {
            if(botDir == UP)
            {
                if(botColision(RIGHT)==0) botDir = RIGHT;
            }
            else if(botDir == DOWN)
            {
                if(botColision(RIGHT)==0) botDir = RIGHT;
            }
            else if(botDir == LEFT)
            {
                if(botColision(UP)==0) botDir = UP;
                else if(botColision(DOWN)==0) botDir = DOWN;
            }
        }
        else if(fruitX < botHeadX && botDir != LEFT)
        {
            if(botDir == UP)
            {
                if(botColision(LEFT)==0) botDir = LEFT;
            }
            else if(botDir == DOWN)
            {
                if(botColision(LEFT)==0) botDir = LEFT;
            }
            else if(botDir == RIGHT)
            {
                if(botColision(UP)==0) botDir = UP;
                else if(botColision(DOWN)==0) botDir = DOWN;
            }
        }
        else if(fruitY > botHeadY && botDir != DOWN)
        {
            if(botDir == RIGHT)
            {
                if(botColision(DOWN)==0) botDir = DOWN;
            }
            else if(botDir == LEFT)
            {
                if(botColision(DOWN)==0) botDir = DOWN;
            }
            else if(botDir == UP)
            {
                if(botColision(LEFT)==0) botDir = LEFT;
                else if(botColision(RIGHT)==0) botDir = RIGHT;
            }
        }
        else if(fruitY < botHeadY && botDir != UP)
        {
            if(botDir == RIGHT)
            {
                if(botColision(UP)==0) botDir = UP;
            }
            else if(botDir == LEFT)
            {
                if(botColision(UP)==0) botDir = UP;
            }
            else if(botDir == DOWN)
            {
                if(botColision(LEFT)==0) botDir = LEFT;
                else if(botColision(RIGHT)==0) botDir = RIGHT;
            }
        }

}

int botColision(eDirection tempDir)
{
      if(tempDir == UP)
      {
          for (int i=0; i<nTail; i++) if(tailX[i] == botHeadX && tailY[i] == botHeadY - 1) return 1;
          for (int i=0; i<botNTail; i++) if(botTailX[i] == botHeadX && botTailY[i] == botHeadY - 1) return 2;
          if (botHeadX == headX && botHeadY - 1 == headY + 1) return 3;
          if (botHeadY - 1 >= height-1) return 4;
      }
      else if(tempDir == RIGHT)
      {
          for (int i=0; i<nTail; i++) if(tailX[i] == botHeadX + 1 && tailY[i] == botHeadY) return 1;
          for (int i=0; i<botNTail; i++) if(botTailX[i] == botHeadX + 1 && botTailY[i] == botHeadY) return 2;
          if (botHeadX + 1 == headX - 1 && botHeadY == headY) return 3;
          if (botHeadX + 1 >= width-1) return 4;
      }
      else if(tempDir == LEFT)
      {
          for (int i=0; i<nTail; i++) if(tailX[i] == botHeadX - 1 && tailY[i] == botHeadY) return 1;
          for (int i=0; i<botNTail; i++) if(botTailX[i] == botHeadX - 1 && botTailY[i] == botHeadY) return 2;
          if (botHeadX - 1 == headX + 1 && botHeadY == headY) return 3;
          if (botHeadX - 1 < 1) return 4;
      }
      if(tempDir == DOWN)
      {
          for (int i=0; i<nTail; i++) if(tailX[i] == botHeadX && tailY[i] == botHeadY + 1) return 1;
          for (int i=0; i<botNTail; i++) if(botTailX[i] == botHeadX && botTailY[i] == botHeadY + 1) return 2;
          if (botHeadX == headX && botHeadY + 1 == headY - 1) return 3;
          if (botHeadY + 1 < 1) return 4;
      }
      return 0;
}

void botLogic()
{
    int botPrevX = botTailX[0];
    int botPrevY = botTailY[0];
    int botPrev2X, botPrev2Y;

    botTailX[0] = botHeadX;
    botTailY[0] = botHeadY;

    for (int i=1; i< botNTail; i++)
    {
        botPrev2X = botTailX[i];
        botPrev2Y = botTailY[i];

        botTailX[i] = botPrevX;
        botTailY[i] = botPrevY;

        botPrevX = botPrev2X;
        botPrevY = botPrev2Y;
    }

    switch (botDir)
    {
    case UP:
    {
        botHeadY--;
        break;
    }
    case LEFT:
    {
        botHeadX--;
        break;
    }
    case DOWN:
    {
        botHeadY++;
        break;
    }
    case RIGHT:
    {
        botHeadX++;
        break;
    }

    default:
        break;
    }

    if ( botHeadX >= width-1 || botHeadX < 1 || botHeadY >= height-1 || botHeadY < 1)
        gameOver = true;
    for (int i=0; i<nTail; i++)
        if(tailX[i] == botHeadX && tailY[i] == botHeadY) gameOver = true;;
    for (int i=0; i<botNTail; i++)
        if(botTailX[i] == botHeadX && botTailY[i] == botHeadY) gameOver = true;;
    if (botHeadX == headX && botHeadY  == headY) gameOver = true;
    for (int i=0; i<botNTail; i++)
        if (botTailX[i] == botHeadX && botTailY[i] == botHeadY)
            gameOver = true;

    if (botHeadX == fruitX && botHeadY == fruitY)
    {
        botScore += scoreAdd;

        spawnFruit();

        botNTail++;
    }
}

void spawnFruit()
{
    fruitX = rand() % (width-4) + 3;
    fruitY = rand() % (height-4) + 3;
    bool isOnTail = true;
    bool isOnHead = true;
    while (isOnTail || isOnHead)
        {
            isOnTail = false;
            isOnHead = false;
            if (headX == speedX && headY == speedY)
                {
                    fruitX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnHead = true;
                }

            for (int i=0; i<nTail; i++)
                while (tailX[i] == speedX && tailY[i] == speedY)
                {
                    fruitX = rand() % (width-4) + 3;
                    fruitY = rand() % (height-4) + 3;
                    isOnTail = true;
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

    speedX = rand() % (width-4) + 3;
    speedY = rand() % (height-4) + 3;

    bool isOnTail = true;
    bool isOnHead = true;
    bool isOnFruit = true;

    while (isOnTail || isOnHead)
        {
            isOnTail = false;
            isOnHead = false;
            isOnFruit = false;

            if (fruitX == speedX && fruitY == speedY)
                {
                    speedX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            if (headX == speedX && headY == speedY)
                {
                    speedX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            for (int i=0; i<nTail; i++)
                if (tailX[i] == speedX && tailY[i] == speedY)
                {
                    speedX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnTail = true;
                }
        }

    time(&startTime);
}

void spawnSlow()
{
    slowX = rand() % (width-4) + 3;
    slowY = rand() % (height-4) + 3;

    bool isOnTail = true;
    bool isOnHead = true;
    bool isOnFruit = true;

    while (isOnTail || isOnHead)
        {
            isOnTail = false;
            isOnHead = false;
            isOnFruit = false;
            if (fruitX == speedX && fruitY == speedY)
                {
                    slowX = rand() % (width-4) + 3;
                    slowY = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            if (headX == speedX && headY == speedY)
                {
                    slowX = rand() % (width-4) + 3;
                    slowY = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            for (int i=0; i<nTail; i++)
                if (tailX[i] == speedX && tailY[i] == speedY)
                {
                    slowX = rand() % (width-4) + 3;
                    slowY = rand() % (height-4) + 3;
                    isOnTail = true;
                }
        }

    time(&startTime);
}

void spawnBoost()
{
    boostX = rand() % (width-4) + 3;
    boostY = rand() % (height-4) + 3;

    bool isOnTail = true;
    bool isOnHead = true;
    bool isOnFruit = true;

    while (isOnTail || isOnHead)
        {
            isOnTail = false;
            isOnHead = false;
            isOnFruit = false;

             if (fruitX== boostX && fruitY == boostY)
                {
                    boostX  = rand() % (width-4) + 3;
                    boostY  = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            if (headX == boostX && headY == boostY)
                {
                    boostX  = rand() % (width-4) + 3;
                    boostY  = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            for (int i=0; i<nTail; i++)
                if (tailX[i] == boostX && tailY[i] == boostY)
                {
                    boostX  = rand() % (width-4) + 3;
                    boostY = rand() % (height-4) + 3;
                    isOnTail = true;
                }
        }

    time(&startTime);
}

void spawnHalf()
{
    lhalfX = rand() % (width-4) + 3;
    lhalfY = rand() % (height-4) + 3;

    bool isOnTail = true;
    bool isOnHead = true;
    bool isOnFruit = true;

    while (isOnTail || isOnHead)
        {
            isOnTail = false;
            isOnHead = false;
            isOnFruit = false;

            if (fruitX == lhalfX && fruitY == lhalfY)
                {
                    lhalfX = rand() % (width-4) + 3;
                    lhalfY = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            if (headX == lhalfX && headY == lhalfY)
                {
                    lhalfX = rand() % (width-4) + 3;
                    lhalfY = rand() % (height-4) + 3;
                    isOnHead = true;
                }
            for (int i=0; i<nTail; i++)
                if (tailX[i] == lhalfX && tailY[i] == lhalfY)
                {
                    lhalfX = rand() % (width-4) + 3;
                    lhalfY = rand() % (height-4) + 3;
                    isOnTail = true;
                }
        }

    time(&startTime);
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
    for (int i=0; i<botNTail; i++)
        if (botTailX[i] == headX && botTailY[i] == headY)
            gameOver = true;


    if (headX == fruitX && headY == fruitY)
    {
        score += scoreAdd;

        spawnFruit();

        nTail++;

        if (score == 10)
        {
            spawnSpecial();
        }
    }

    else if (headX == speedX && headY == speedY)
         {
            existsSpecial = false;
            speedInUse = true;
            time (&startTime);
            movSpeed = 20;
            speedX = speedY = 0;
         }
    else if (headX == slowX && headY == slowY)
         {
            existsSpecial = false;
            slowInUse = true;
            time (&startTime);
            movSpeed = 160;
            slowX = slowY = 0;
         }
    else if (headX == boostX && headY == boostY)
         {
            existsSpecial = false;
            boostInUse = true;
            time (&startTime);
            scoreAdd = 20;
            boostX = boostY = 0;
         }
    else if (headX == lhalfX && headY == lhalfY)
         {
            existsSpecial = false;
            halfInUse = true;
            time (&startTime);
            if(nTail == 1) game_reset();
            else
            {
                for(int i=nTail/2;i<nTail;i++)
                    tailX[i]=tailY[i]=0;
                nTail/=2;
            }
            lhalfX = lhalfY = 0;
         }

    if (speedInUse)
    {

        time_t endTime;
        time (&endTime);
        double elapsed_secs = difftime (endTime,startTime);

        if (elapsed_secs > 12 && elapsed_secs < 14)
        {
            speedInUse = false;
            movSpeed = 80;
            spawnSpecial();
        }
    }
    else if (slowInUse)
    {

        time_t endTime;
        time (&endTime);
        double elapsed_secs = difftime (endTime,startTime);

        if (elapsed_secs > 8 && elapsed_secs < 10)
        {
            slowInUse = false;
            movSpeed = 80;
            spawnSpecial();
        }
    }
    else if (boostInUse)
    {

        time_t endTime;
        time (&endTime);
        double elapsed_secs = difftime (endTime,startTime);

        if (elapsed_secs > 18 && elapsed_secs < 20)
        {
            boostInUse = false;
            scoreAdd = 10;
            spawnSpecial();
        }
    }
     else if (halfInUse)
    {

        time_t endTime;
        time (&endTime);
        double elapsed_secs = difftime (endTime,startTime);
        if (elapsed_secs > 8 && elapsed_secs < 10)
        {
            halfInUse = false;
            spawnSpecial();
        }
    }
}

void update_HighScore()
{
    if (score > highScore) highScore = score;
}

void game_reset()
{
    for (int i=0; i<nTail; i++)
        tailX[i] = tailY[i] = 0;
    for (int i=0; i<botNTail; i++)
        botTailX[i] = botTailY[i] = 0;
    nTail = botNTail = 0;
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
    setbkcolor(WHITE);
    setcolor(BLUE);
    outtextxy(460 , 80 , arr);
}

void singleplayer()
{
    game_reset();
    Setup();
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    menuSnakeSprite(485,0,1);
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        dataBoard();
        Sleep(movSpeed);
    }
    Sleep(200);
    setbkcolor(DARKGRAY);
    setcolor(RED);
    settextstyle(4, HORIZ_DIR, 5);
    int mes = rand() % 100 + 1;
    if(mes>=1 && mes<=49)
       outtextxy(60, 165, "YOU DIED!");
    else if(mes>=50 && mes<=92)
       outtextxy(80, 165, "WASTED");
    else
    {
         setfillstyle(SOLID_FILL ,BLUE);
         bar(0,0,630,460);
         setcolor(BLUE);
         setbkcolor(LIGHTGRAY);
         settextstyle(4, HORIZ_DIR, 1);
         outtextxy(260, 100, "Windows");
         setcolor(WHITE);
         setbkcolor(BLUE);
         outtextxy(30, 160, "An error has occurred. To continue:");
         outtextxy(30, 200, "Press Enter to return to Windows, or");
         outtextxy(30, 240, "Press CTRL+ALT+DEL to restart your ");
         outtextxy(30, 260, "computer. If you do this, you will lose any");
         outtextxy(30, 280, "unsaved information in all open applicatons.");
         outtextxy(30, 320, "Error 0E  016F  BFF9B3D4");
         outtextxy(120, 360, "Press any key to continue _");
    }
    Sleep(2000);
    menu();
}

void menu()
{
    update_HighScore();
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    trin=1;
    setfillstyle(SOLID_FILL , BLUE);
    setbkcolor(WHITE);
    setcolor(BLUE);
    settextstyle(BOLD_FONT , HORIZ_DIR , 4);
    outtextxy(170 , 80 , "SINGLEPLAYER");
    outtextxy(170 ,170 , "MULTIPLAYER");
    outtextxy(170 ,260 , "HELP");
    outtextxy(170 ,350 , "QUIT");
    Sleep(400);
    botHeadX = botHeadY = 0;
    speedInUse = slowInUse = boostInUse = halfInUse = false;
    while(quitted!=true)
    {

             if(GetAsyncKeyState('W') && trin>1) trin--;
             else if(GetAsyncKeyState('S') && trin<4) trin++;
             else if(GetAsyncKeyState('E'))
             {
                 if(trin==1) singleplayer();
                 if(trin==2) multiplayer();
                 if(trin==3) help();
                 if(trin==4) quitted = true;
             }
             setfillstyle(SOLID_FILL ,WHITE);
             bar(140,60,160,400);
             setfillstyle(SOLID_FILL , BLUE);
             bar(140,trin*90,160,trin*90+10);
             Sleep(100);

    }
}

void multiplayer()
{
    playerStarted = false;
    game_reset();
    multiSetup();
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    menuSnakeSprite(455,0,1);
    menuSnakeSprite(530,0,2);
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        if(playerStarted)
        {
            botBrain();
            botLogic();
        }
        multiDataBoard();
        Sleep(movSpeed);
    }
    Sleep(200);
    setbkcolor(DARKGRAY);
    setcolor(RED);
    settextstyle(4, HORIZ_DIR, 5);
    int mes = rand() % 100 + 1;
    if(mes>=1 && mes<=49)
       outtextxy(60, 165, "YOU DIED!");
    else if(mes>=50 && mes<=90)
       outtextxy(80, 165, "WASTED");
    else
    {
         setfillstyle(SOLID_FILL ,BLUE);
         bar(0,0,630,460);
         setcolor(BLUE);
         setbkcolor(LIGHTGRAY);
         settextstyle(4, HORIZ_DIR, 1);
         outtextxy(260, 100, "Windows");
         setcolor(WHITE);
         setbkcolor(BLUE);
         outtextxy(30, 160, "An error has occurred. To continue:");
         outtextxy(30, 200, "Press Enter to return to Windows, or");
         outtextxy(30, 240, "Press CTRL+ALT+DEL to restart your ");
         outtextxy(30, 260, "computer. If you do this, you will lose any");
         outtextxy(30, 280, "unsaved information in all open applicatons.");
         outtextxy(30, 320, "Error 0E  016F  BFF9B3D4");
         outtextxy(120, 360, "Press any key to continue _");
    }

    Sleep(2000);
    menu();
}

void help()
{
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    setbkcolor(WHITE);
    setcolor(BLUE);
    settextstyle(8 , HORIZ_DIR , 2);
    outtextxy(110 , 80 , "Use W-A-S-D to move in the menu ");
    outtextxy(110 , 100 , "and in the game.Press E to select.");
    outtextxy(110 , 140 , "Use Q to quit the match , and P");
    outtextxy(110 , 160 , "to pause it.");
    outtextxy(110 , 200 , "King represents the highscore.");
    outtextxy(110 , 240 , "In multiplayer you will compete");
    outtextxy(110 , 260 , "against a computer controlled");
    outtextxy(110 , 280 , "snake that will try to win.");
    outtextxy(110 , 320 , "E - info on the power-ups");
    outtextxy(110 , 360 , "Q - go back to the menu");
    bool inHelp = true;
    Sleep(400);
    while(inHelp)
    {
        if(GetAsyncKeyState('Q'))
        {
            inHelp = false;
            menu();
        }
        if(GetAsyncKeyState('E'))
        {
            inHelp = false;
            powersMenu();
        }
    }

}

void powersMenu()
{
    bool inPowerMenu = true;
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    setbkcolor(WHITE);
    setcolor(BLUE);
    settextstyle(8 , HORIZ_DIR , 1);
    outtextxy(110 , 80 , "            POWER-UPS");
    fruitSprite(110 , 125 , 2 , false);
    outtextxy(130 , 120 , "- fruit");
    outtextxy(110 , 135 , "Gives one point when eaten and adds");
    outtextxy(110 , 150 , "one to the length of the snake.");
    speedSprite(110 , 175 , 2);
    outtextxy(130 , 170 , "- speed");
    outtextxy(110 , 185 , "Doubles the speed of the snake.");
    slowSprite(110 ,210 , 2);
    outtextxy(130 , 205 , "- slow");
    outtextxy(110 , 220 , "Halves the speed of the snake.");
    halfSprite(110 , 245 , 2);
    outtextxy(130 , 240 , "- cut");
    outtextxy(110 , 255 , "Halves the size of the snake.");
    boostSprite(110 , 280 , 2);
    outtextxy(130 , 275 , "- boost");
    outtextxy(110 , 290 , "Doubles the points you get when eating");
    outtextxy(110 , 305 , "a fruit.");
    outtextxy(110 , 360 , "Q - go back to the help page");
    Sleep(400);
    while(inPowerMenu)
    {
        if(GetAsyncKeyState('Q'))
        {
            inPowerMenu = false;
            help();
        }
    }
}


int main()
{
    // hideCmd();
    game_window();
    bar(0,0,630,460);
    setfillstyle(SOLID_FILL , LIGHTBLUE);
    settextstyle(8 , HORIZ_DIR , 10);
    outtextxy(200 ,160 , "T&T");
    floodfill(202 ,190 , WHITE);
    floodfill(320 ,240 , WHITE);
    Sleep(3000);
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);

    ifstream fin("highscore.txt");
    fin.seekg(0);
    fin>>highScore;
    fin.close();

    menu();

    ofstream fout("highscore.txt");
    if (score>highScore)
        highScore = score;
    fout<<highScore;
    fout.close();


    system("exit");

    exit(0);
}
