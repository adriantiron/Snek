
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
          setfillstyle(SOLID_FILL , BLUE);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , LIGHTGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , DARKGRAY);
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
          setfillstyle(SOLID_FILL , BLUE);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , LIGHTGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
}

void botHeadSprite(int x , int y)
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
          setfillstyle(SOLID_FILL , RED);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , BLACK);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
}

void botBodySprite(int x , int y)
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
          setfillstyle(SOLID_FILL , RED);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , BLACK);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
      else if(a[i][j]==0)
      {
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x+i,y+j,x+i+1,y+j+1);
      }
}


void fruitSprite(int x , int y , int z , bool b)
{
     int i , j , a[10][10]={
      0 , 0 , 3 , 3 , 0 , 2 , 2 , 2 , 0 , 0 ,
      0 , 0 , 0 , 3 , 2 , 2 , 0 , 0 , 0 , 0 ,
      0 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 0 ,
      1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
      1 , 1 , 1 , 4 , 1 , 1 , 1 , 1 , 1 , 1 ,
      1 , 1 , 4 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
      1 , 1 , 4 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
      1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
      0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,
      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,
      };
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(a[i][j]==1 && b == false)
            {
                setfillstyle(SOLID_FILL, RED);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==1  && b == true)
            {
                setfillstyle(SOLID_FILL, YELLOW);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==2)
            {
                setfillstyle(SOLID_FILL, BROWN);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==3 && b == false)
            {
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==3 && b == true)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==4 && b == false)
            {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==4 && b == true)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==1)
            {
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==2)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
}

void speedSprite(int x , int y , int z)
{
      int i , j , a[10][10]={
      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,
      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,
      0 , 0 , 1 , 1 , 0 , 0 , 1 , 1 , 0 , 0 ,
      0 , 1 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 0 ,
      1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 ,
      1 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 1 ,
      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,
      0 , 0 , 1 , 1 , 0 , 0 , 1 , 1 , 0 , 0 ,
      0 , 1 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 0 ,
      1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 ,
      };
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(a[i][j]==1)
            {
                setfillstyle(SOLID_FILL, YELLOW);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==1)
            {
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==2)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
}

void slowSprite(int x , int y , int z)
{
    int i , j , a[10][10]={
      1 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 1 ,
      2 , 1 , 2 , 0 , 0 , 0 , 0 , 2 , 1 , 2 ,
      0 , 2 , 1 , 2 , 0 , 0 , 2 , 1 , 2 , 0 ,
      0 , 0 , 2 , 1 , 2 , 2 , 1 , 2 , 0 , 0 ,
      2 , 0 , 0 , 2 , 1 , 1 , 2 , 0 , 0 , 2 ,
      1 , 2 , 0 , 0 , 2 , 2 , 0 , 0 , 2 , 1 ,
      2 , 1 , 2 , 0 , 0 , 0 , 0 , 2 , 1 , 2 ,
      0 , 2 , 1 , 2 , 0 , 0 , 2 , 1 , 2 , 0 ,
      0 , 0 , 2 , 1 , 2 , 2 , 1 , 2 , 0 , 0 ,
      0 , 0 , 0 , 2 , 1 , 1 , 2 , 0 , 0 , 0 ,
      };
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(a[i][j]==1)
            {
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==2)
            {
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==1)
            {
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==2)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
}


void boostSprite(int x , int y , int z)
{

      int i , j , a[10][10]={
      1 , 1 , 0 , 1 , 1 , 0 , 1 , 1 , 1 , 1 ,
      1 , 1 , 0 , 1 , 1 , 0 , 2 , 2 , 2 , 1 ,
      2 , 1 , 0 , 1 , 2 , 0 , 0 , 0 , 0 , 1 ,
      0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 ,
      0 , 2 , 1 , 2 , 0 , 0 , 1 , 1 , 1 , 1 ,
      0 , 0 , 1 , 0 , 0 , 0 , 1 , 2 , 2 , 2 ,
      0 , 1 , 2 , 1 , 0 , 0 , 1 , 0 , 0 , 0 ,
      1 , 1 , 0 , 1 , 1 , 0 , 1 , 0 , 0 , 0 ,
      1 , 1 , 0 , 1 , 1 , 0 , 1 , 1 , 1 , 1 ,
      2 , 2 , 0 , 2 , 2 , 0 , 2 , 2 , 2 , 2 ,
      };
      for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        if(a[i][j]==1)
      {
          setfillstyle(SOLID_FILL , RED);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , LIGHTRED);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
      else if(a[i][j]==0 && z==1)
      {
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
      else if(a[i][j]==0 && z==2)
      {
          setfillstyle(SOLID_FILL , WHITE);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
}

void halfSprite(int x , int y , int z)
{
      int i , j , a[10][10]={
      0 , 0 , 0 , 0 , 2 , 1 , 0 , 0 , 0 , 0 ,
      0 , 2 , 1 , 0 , 1 , 2 , 0 , 2 , 1 , 0 ,
      0 , 1 , 2 , 1 , 0 , 0 , 2 , 1 , 2 , 0 ,
      0 , 0 , 1 , 2 , 1 , 2 , 1 , 2 , 0 , 0 ,
      2 , 1 , 0 , 1 , 2 , 1 , 2 , 0 , 2 , 1 ,
      1 , 2 , 0 , 2 , 1 , 2 , 1 , 0 , 1 , 2 ,
      0 , 0 , 2 , 1 , 2 , 1 , 2 , 1 , 0 , 0 ,
      0 , 2 , 1 , 2 , 0 , 0 , 1 , 2 , 1 , 0 ,
      0 , 1 , 2 , 0 , 2 , 1 , 0 , 1 , 2 , 0 ,
      0 , 0 , 0 , 0 , 1 , 2 , 0 , 0 , 0 , 0 ,
      };
      for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        if(a[i][j]==1)
      {
          setfillstyle(SOLID_FILL , BLUE);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
      else if(a[i][j]==2)
      {
          setfillstyle(SOLID_FILL , BLUE);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
      else if(a[i][j]==0 && z==1)
      {
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
      else if(a[i][j]==0 && z==2)
      {
          setfillstyle(SOLID_FILL , WHITE);
          bar(x+j,y+i,x+j+1,y+i+1);
      }
}

void menuSnakeSprite(int x , int y , int z)
{
        if(z==1)
        {
          setfillstyle(SOLID_FILL , LIGHTGRAY);
          bar(x,460-y,x+60,460-y-20);
          bar(x,460-y-20,x+61,460-y-26);
          bar(x,460-y-26,x+62,460-y-30);
          bar(x,460-y-30,x+63,460-y-33);
          bar(x,460-y-33,x+64,460-y-38);
          bar(x,460-y-38,x+65,460-y-40);
          bar(x,460-y-40,x+66,460-y-44);
          bar(x+1,460-y-44,x+67,460-y-46);
          bar(x+1,460-y-46,x+68,460-y-48);
          bar(x+2,460-y-48,x+68,460-y-53);
          bar(x+3,460-y-53,x+69,460-y-56);
          bar(x+4,460-y-56,x+70,460-y-60);
          bar(x+1,460-y-60,x+71,460-y-61);
          bar(x-9,460-y-61,x+73,460-y-62);
          bar(x-11,460-y-62,x+73,460-y-63);
          bar(x-13,460-y-63,x+74,460-y-64);
          bar(x-17,460-y-64,x+74,460-y-65);
          bar(x-18,460-y-65,x+75,460-y-67);
          bar(x-19,460-y-67,x+76,460-y-68);
          bar(x-20,460-y-68,x+77,460-y-73);
          bar(x-21,460-y-73,x+78,460-y-76);
          bar(x-21,460-y-76,x+79,460-y-83);
          bar(x-21,460-y-83,x+80,460-y-89);
          bar(x-21,460-y-89,x+81,460-y-101);
          bar(x-20,460-y-101,x+80,460-y-105);
          bar(x-19,460-y-105,x+79,460-y-107);
          bar(x-18,460-y-107,x+78,460-y-109);
          bar(x-17,460-y-109,x+77,460-y-111);
          bar(x-16,460-y-111,x+76,460-y-113);
          bar(x-15,460-y-113,x+75,460-y-115);
          bar(x-14,460-y-115,x+74,460-y-117);
          bar(x-13,460-y-117,x+73,460-y-118);
          bar(x-12,460-y-118,x+73,460-y-119);
          bar(x-11,460-y-119,x+72,460-y-120);
          bar(x-10,460-y-120,x+71,460-y-121);
          bar(x-9,460-y-121,x+70,460-y-122);
          bar(x-7,460-y-122,x+68,460-y-123);
          bar(x-5,460-y-123,x+65,460-y-124);
          bar(x-3,460-y-124,x+63,460-y-125);
          bar(x-1,460-y-125,x+61,460-y-126);
          setfillstyle(SOLID_FILL , BLUE);
          bar(x+1,460-y-126,x+55,460-y-127);
          bar(x+3,460-y-127,x+49,460-y-128);
          bar(x+6,460-y-128,x+46,460-y-129);
          bar(x,460-y-125,x+42,460-y-126);
          bar(x,460-y-124,x+38,460-y-125);
          bar(x,460-y-123,x+34,460-y-124);
          bar(x,460-y-122,x+30,460-y-123);
          bar(x,460-y-121,x+25,460-y-122);
          bar(x+1,460-y-120,x+21,460-y-121);
          bar(x+1,460-y-119,x+16,460-y-120);
          bar(x+2,460-y-118,x+11,460-y-119);
          bar(x+3,460-y-117,x+7,460-y-118);
          bar(x-18,460-y-107,x-17,460-y-108);
          bar(x+40,460-y-107,x+45,460-y-108);
          bar(x-19,460-y-106,x-17,460-y-107);
          bar(x+40,460-y-106,x+46,460-y-107);
          bar(x-19,460-y-105,x-17,460-y-106);
          bar(x+39,460-y-105,x+46,460-y-106);
          bar(x-20,460-y-104,x-17,460-y-105);
          bar(x+39,460-y-104,x+47,460-y-105);
          bar(x-21,460-y-101,x-17,460-y-104);
          bar(x+38,460-y-101,x+48,460-y-104);
          bar(x-22,460-y-97,x-16,460-y-101);
          bar(x+36,460-y-99,x+48,460-y-101);
          bar(x+35,460-y-97,x+48,460-y-99);
          bar(x-22,460-y-95,x-15,460-y-97);
          bar(x+33,460-y-95,x+48,460-y-97);
          bar(x-21,460-y-93,x-15,460-y-95);
          bar(x+32,460-y-93,x+46,460-y-95);
          bar(x-19,460-y-92,x-17,460-y-93);
          bar(x+30,460-y-92,x+45,460-y-93);
          bar(x+30,460-y-91,x+44,460-y-92);
          bar(x+31,460-y-90,x+41,460-y-91);
          bar(x+33,460-y-89,x+39,460-y-90);
          bar(x+2,460-y,x+21,460-y-20);
          bar(x+3,460-y-20,x+20,460-y-26);
          bar(x+3,460-y-26,x+19,460-y-30);
          bar(x+4,460-y-30,x+18,460-y-33);
          bar(x+5,460-y-33,x+17,460-y-38);
          bar(x+6,460-y-38,x+16,460-y-40);
          bar(x+7,460-y-40,x+15,460-y-44);
          bar(x+8,460-y-44,x+14,460-y-46);
          bar(x+9,460-y-46,x+13,460-y-48);
          bar(x+4,460-y,x+22,460-y-15);
          bar(x+4,460-y,x+23,460-y-10);
          bar(x+4,460-y,x+24,460-y-3);
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x+1,460-y-53,x+1,460-y-56);
          bar(x+4,460-y-56,x+4,460-y-60);
          bar(x+1,460-y-60,x+6,460-y-61);
          bar(x-9,460-y-61,x+12,460-y-62);
          bar(x-11,460-y-62,x+19,460-y-63);
          bar(x-13,460-y-63,x+26,460-y-64);
          bar(x+10,460-y-64,x+31,460-y-65);
          bar(x+18,460-y-65,x+35,460-y-66);
          bar(x+24,460-y-66,x+40,460-y-67);
          bar(x+26,460-y-67,x+43,460-y-68);
          bar(x+28,460-y-68,x+45,460-y-69);
          bar(x+32,460-y-69,x+47,460-y-70);
          bar(x+36,460-y-70,x+49,460-y-72);
          bar(x+40,460-y-72,x+51,460-y-74);
          bar(x+44,460-y-74,x+52,460-y-76);
          bar(x+46,460-y-76,x+52,460-y-78);
          bar(x+47,460-y-78,x+52,460-y-80);
          bar(x+48,460-y-80,x+52,460-y-81);
          bar(x+49,460-y-81,x+52,460-y-82);
        }
        else if(z==2)
        {
          setfillstyle(SOLID_FILL , DARKGRAY);
          bar(x,460-y,x+60,460-y-20);
          bar(x,460-y-20,x+61,460-y-26);
          bar(x,460-y-26,x+62,460-y-30);
          bar(x,460-y-30,x+63,460-y-33);
          bar(x,460-y-33,x+64,460-y-38);
          bar(x,460-y-38,x+65,460-y-40);
          bar(x,460-y-40,x+66,460-y-44);
          bar(x+1,460-y-44,x+67,460-y-46);
          bar(x+1,460-y-46,x+68,460-y-48);
          bar(x+2,460-y-48,x+68,460-y-53);
          bar(x+3,460-y-53,x+69,460-y-56);
          bar(x+4,460-y-56,x+70,460-y-60);
          bar(x+1,460-y-60,x+71,460-y-61);
          bar(x-9,460-y-61,x+73,460-y-62);
          bar(x-11,460-y-62,x+73,460-y-63);
          bar(x-13,460-y-63,x+74,460-y-64);
          bar(x-17,460-y-64,x+74,460-y-65);
          bar(x-18,460-y-65,x+75,460-y-67);
          bar(x-19,460-y-67,x+76,460-y-68);
          bar(x-20,460-y-68,x+77,460-y-73);
          bar(x-21,460-y-73,x+78,460-y-76);
          bar(x-21,460-y-76,x+79,460-y-83);
          bar(x-21,460-y-83,x+80,460-y-89);
          bar(x-21,460-y-89,x+81,460-y-101);
          bar(x-20,460-y-101,x+80,460-y-105);
          bar(x-19,460-y-105,x+79,460-y-107);
          bar(x-18,460-y-107,x+78,460-y-109);
          bar(x-17,460-y-109,x+77,460-y-111);
          bar(x-16,460-y-111,x+76,460-y-113);
          bar(x-15,460-y-113,x+75,460-y-115);
          bar(x-14,460-y-115,x+74,460-y-117);
          bar(x-13,460-y-117,x+73,460-y-118);
          bar(x-12,460-y-118,x+73,460-y-119);
          bar(x-11,460-y-119,x+72,460-y-120);
          bar(x-10,460-y-120,x+71,460-y-121);
          bar(x-9,460-y-121,x+70,460-y-122);
          bar(x-7,460-y-122,x+68,460-y-123);
          bar(x-5,460-y-123,x+65,460-y-124);
          bar(x-3,460-y-124,x+63,460-y-125);
          bar(x-1,460-y-125,x+61,460-y-126);
          setfillstyle(SOLID_FILL , RED);
          bar(x+1,460-y-126,x+55,460-y-127);
          bar(x+3,460-y-127,x+49,460-y-128);
          bar(x+6,460-y-128,x+46,460-y-129);
          bar(x,460-y-125,x+42,460-y-126);
          bar(x,460-y-124,x+38,460-y-125);
          bar(x,460-y-123,x+34,460-y-124);
          bar(x,460-y-122,x+30,460-y-123);
          bar(x,460-y-121,x+25,460-y-122);
          bar(x+1,460-y-120,x+21,460-y-121);
          bar(x+1,460-y-119,x+16,460-y-120);
          bar(x+2,460-y-118,x+11,460-y-119);
          bar(x+3,460-y-117,x+7,460-y-118);
          bar(x-18,460-y-107,x-17,460-y-108);
          bar(x+40,460-y-107,x+45,460-y-108);
          bar(x-19,460-y-106,x-17,460-y-107);
          bar(x+40,460-y-106,x+46,460-y-107);
          bar(x-19,460-y-105,x-17,460-y-106);
          bar(x+39,460-y-105,x+46,460-y-106);
          bar(x-20,460-y-104,x-17,460-y-105);
          bar(x+39,460-y-104,x+47,460-y-105);
          bar(x-21,460-y-101,x-17,460-y-104);
          bar(x+38,460-y-101,x+48,460-y-104);
          bar(x-22,460-y-97,x-16,460-y-101);
          bar(x+36,460-y-99,x+48,460-y-101);
          bar(x+35,460-y-97,x+48,460-y-99);
          bar(x-22,460-y-95,x-15,460-y-97);
          bar(x+33,460-y-95,x+48,460-y-97);
          bar(x-21,460-y-93,x-15,460-y-95);
          bar(x+32,460-y-93,x+46,460-y-95);
          bar(x-19,460-y-92,x-17,460-y-93);
          bar(x+30,460-y-92,x+45,460-y-93);
          bar(x+30,460-y-91,x+44,460-y-92);
          bar(x+31,460-y-90,x+41,460-y-91);
          bar(x+33,460-y-89,x+39,460-y-90);
          bar(x+2,460-y,x+21,460-y-20);
          bar(x+3,460-y-20,x+20,460-y-26);
          bar(x+3,460-y-26,x+19,460-y-30);
          bar(x+4,460-y-30,x+18,460-y-33);
          bar(x+5,460-y-33,x+17,460-y-38);
          bar(x+6,460-y-38,x+16,460-y-40);
          bar(x+7,460-y-40,x+15,460-y-44);
          bar(x+8,460-y-44,x+14,460-y-46);
          bar(x+9,460-y-46,x+13,460-y-48);
          bar(x+4,460-y,x+22,460-y-15);
          bar(x+4,460-y,x+23,460-y-10);
          bar(x+4,460-y,x+24,460-y-3);
          setfillstyle(SOLID_FILL , BLACK);
          bar(x+1,460-y-53,x+1,460-y-56);
          bar(x+4,460-y-56,x+4,460-y-60);
          bar(x+1,460-y-60,x+6,460-y-61);
          bar(x-9,460-y-61,x+12,460-y-62);
          bar(x-11,460-y-62,x+19,460-y-63);
          bar(x-13,460-y-63,x+26,460-y-64);
          bar(x+10,460-y-64,x+31,460-y-65);
          bar(x+18,460-y-65,x+35,460-y-66);
          bar(x+24,460-y-66,x+40,460-y-67);
          bar(x+26,460-y-67,x+43,460-y-68);
          bar(x+28,460-y-68,x+45,460-y-69);
          bar(x+32,460-y-69,x+47,460-y-70);
          bar(x+36,460-y-70,x+49,460-y-72);
          bar(x+40,460-y-72,x+51,460-y-74);
          bar(x+44,460-y-74,x+52,460-y-76);
          bar(x+46,460-y-76,x+52,460-y-78);
          bar(x+47,460-y-78,x+52,460-y-80);
          bar(x+48,460-y-80,x+52,460-y-81);
          bar(x+49,460-y-81,x+52,460-y-82);
        }

}


