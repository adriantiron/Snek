
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


void fruitSprite(int x , int y , int z)
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
            if(a[i][j]==1)
            {
                setfillstyle(SOLID_FILL, RED);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==2)
            {
                setfillstyle(SOLID_FILL, BROWN);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==3)
            {
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==4)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==1)
            {
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0 && z==2)
            {
                setfillstyle(SOLID_FILL, BLACK);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
}

void speedSprite(int x , int y)
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
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
            else if(a[i][j]==0)
            {
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(x+j,y+i,x+j+1,y+i+1);
            }
}

void slowSprite(int x , int y)
{

}

void boostSprite(int x , int y)
{

}

void halfSprite(int x , int y)
{

}


