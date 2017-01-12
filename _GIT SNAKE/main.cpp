#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <stdio.h>
#include <fstream>
#include "sprites.h"


using namespace std;


bool gameOver , quitted=false , paused = false , existsSpecial=false;
bool speedInUse = false , slowInUse = false;
const int height = 40;
const int width = 40;
int headX, headY, fruitX, fruitY, score , speedX , speedY , boostX , boostY , slowX , slowY , lhalfX , lhalfY ;
enum eDirection { STOP, UP, DOWN, LEFT, RIGHT };
eDirection dir;
int nTail, tailX[100], tailY[100];
int trin=1 , scoreAdd=1 , movSpeed=80 ;
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




void hideCmd()
{
    HWND hide_cmd;
    AllocConsole();
    hide_cmd = FindWindowA("ConsoleWindowClass" , NULL);
    ShowWindow(hide_cmd,0);
}

void dataBoard()
{
    setfillstyle(SOLID_FILL ,BLACK);
    bar(440,60,610,320);
    game_score();
    settextstyle(8 , HORIZ_DIR , 1);

    char arr[50];
    sprintf(arr, "%d", highScore);

    outtextxy(460 , 120 , "KING:");
    outtextxy(520 , 120 , arr);
    setfillstyle(SOLID_FILL ,WHITE);
    bar(430,160,620,180);
    outtextxy(460 , 200 , "EXIT  - Q");
    outtextxy(460 , 240 , "PAUSE - P");
    outtextxy(460 , 280 , "RESUME - O");
}

void powersInit()
{
    speedX = rand() % (width-4) + 3;
    speedY = rand() % (height-4) + 3;
    slowX = rand() % (width-4) + 3;
    slowY = rand() % (height-4) + 3;
    lhalfX = rand() % (width-4) + 3;
    lhalfY = rand() % (height-4) + 3;
    boostX = rand() % (width-4) + 3;
    boostY = rand() % (height-4) + 3;
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

}

void Draw()
{
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
                headSprite((i+2)*10,(j+2)*10);

            else if (i == fruitY && j == fruitX)
                fruitSprite((i+2)*10,(j+2)*10,1);

            else if(i == speedY && j == speedX)
                {
                    speedSprite((i+2)*10,(j+2)*10);

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
                    slowSprite((i+2)*10,(j+2)*10);

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
            else
            {
                bool tailDisplayed = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        bodySprite((i+2)*10,(j+2)*10);
                        tailDisplayed = true;
                    }
                }
                if (!tailDisplayed && j<=width-2 && i<=height-2)
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
        else if(GetAsyncKeyState('P'))
            {
               while (true)
               {
                   if (GetAsyncKeyState('O'))
                        break;
               }


            }
}

void spawnFruit()
{
    fruitX = rand() % (width-4) + 3;
    fruitY = rand() % (height-4) + 3;

    bool isOnTail = true;
    bool isOnHead = true;

    while (isOnTail && isOnHead)
        {
            isOnTail = false;
            isOnHead = false;

            for (int i=0; i<nTail; i++)
                if (tailX[i] == speedX && tailY[i] == speedY)
                {
                    fruitX = rand() % (width-4) + 3;
                    fruitY = rand() % (height-4) + 3;
                    isOnTail = true;
                }


                if (headX == speedX && headY == speedY)
                {
                    fruitX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnHead = true;
                }

        }
}

void spawnSpecial()
{
   unsigned spec;
   if(existsSpecial==false)
   {
       spec = rand() % 2 + 1;
       if(spec==1) spawnSpeed();
       else if(spec==2) spawnSlow();
       //else if(spec==3) spawnHalf();
       //else spawnBoost();
       existsSpecial = true;
   }

}

void spawnSpeed()
{

    speedX = rand() % (width-4) + 3;
    speedY = rand() % (height-4) + 3;

    bool isOnTail = true;
    bool isOnHead = true;

    while (isOnTail && isOnHead)
        {
            isOnTail = false;
            isOnHead = false;

            for (int i=0; i<nTail; i++)
                if (tailX[i] == speedX && tailY[i] == speedY)
                {
                    speedX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnTail = true;
                }


                if (headX == speedX && headY == speedY)
                {
                    speedX = rand() % (width-4) + 3;
                    speedY = rand() % (height-4) + 3;
                    isOnHead = true;
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

    while (isOnTail && isOnHead)
        {
            isOnTail = false;
            isOnHead = false;

            for (int i=0; i<nTail; i++)
                if (tailX[i] == speedX && tailY[i] == speedY)
                {
                    slowX = rand() % (width-4) + 3;
                    slowY = rand() % (height-4) + 3;
                    isOnTail = true;
                }


                if (headX == speedX && headY == speedY)
                {
                    slowX = rand() % (width-4) + 3;
                    slowY = rand() % (height-4) + 3;
                    isOnHead = true;
                }

        }

    time(&startTime);
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
            movSpeed /= 4;
            speedX = speedY = 0;
         }
    else if (headX == slowX && headY == slowY)
         {
            existsSpecial = false;
            slowInUse = true;
            time (&startTime);
            movSpeed *= 2;
            slowX = slowY = 0;
         }

    if (speedInUse)
    {

        time_t endTime;
        time (&endTime);
        double elapsed_secs = difftime (endTime,startTime);

        if (elapsed_secs > 12 && elapsed_secs < 14)
        {
            speedInUse = false;
            movSpeed *= 4;
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
            movSpeed /= 2;
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
    game_reset();
    Setup();
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        update_HighScore();
        dataBoard();
        Sleep(movSpeed); //the SMALLER the movSpeed is the FASTER the snake will go
    }
    Sleep(200);
    setcolor(RED);
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(60, 165, "YOU DIED!");
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
    Sleep(400);
    while(quitted!=true)
    {
             if(GetAsyncKeyState('W') && trin>1) trin--;
             else if(GetAsyncKeyState('S') && trin<4) trin++;
             else if(GetAsyncKeyState('E'))
             {
                 if(trin==1) singleplayer();
                 if(trin==3) help();
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
    setfillstyle(SOLID_FILL ,WHITE);
    bar(0,0,630,460);
    setfillstyle(SOLID_FILL , BLACK);
    bar(100,60,530,400);
    setcolor(LIGHTGREEN);
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
    setfillstyle(SOLID_FILL , BLACK);
    bar(100,60,530,400);
    setcolor(LIGHTGREEN);
    settextstyle(8 , HORIZ_DIR , 1);
    outtextxy(110 , 80 , "            POWER-UPS");
    fruitSprite(110 , 125 , 2);
    outtextxy(130 , 120 , "- fruit");
    outtextxy(110 , 135 , "Gives one point when eaten and adds");
    outtextxy(110 , 150 , "one to the length of the snake.");
    outtextxy(130 , 170 , "- speed");
    outtextxy(110 , 185 , "Doubles the speed of the snake.");
    outtextxy(130 , 205 , "- slow");
    outtextxy(110 , 220 , "Halves the speed of the snake.");
    outtextxy(130 , 240 , "- cut");
    outtextxy(110 , 255 , "Halves the size of the snake.");
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

    return 0;
}
