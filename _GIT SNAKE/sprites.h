//Sprites:
void headSprite(int x, int y)
{
    int i, j, a[10][10]=
    {
        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
        0, 1, 1, 2, 2, 2, 2, 1, 1, 0,
        1, 1, 2, 2, 1, 1, 2, 2, 1, 1,
        1, 2, 2, 2, 2, 2, 2, 2, 2, 1,
        1, 2, 1, 2, 2, 2, 2, 1, 2, 1,
        1, 2, 1, 2, 2, 2, 2, 1, 2, 1,
        1, 2, 2, 2, 2, 2, 2, 2, 2, 1,
        1, 1, 2, 2, 1, 1, 2, 2, 1, 1,
        0, 1, 1, 2, 2, 2, 2, 1, 1, 0,
        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
    };
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(a[i][j]==1)
            {
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==2)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==0)
            {
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
}

void bodySprite(int x, int y)
{
    int i, j, a[10][10]=
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
        0, 1, 1, 2, 2, 2, 2, 1, 1, 0,
        0, 1, 2, 2, 2, 2, 2, 2, 1, 0,
        0, 1, 2, 2, 1, 1, 2, 2, 1, 0,
        0, 1, 2, 2, 1, 1, 2, 2, 1, 0,
        0, 1, 2, 2, 2, 2, 2, 2, 1, 0,
        0, 1, 1, 2, 2, 2, 2, 1, 1, 0,
        0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(a[i][j]==1)
            {
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==2)
            {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==0)
            {
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
}

void fruitSprite(int x, int y)
{
    int i, j, a[10][10]=
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 2, 2, 2, 2, 0, 0, 0,
        0, 0, 2, 2, 3, 3, 2, 2, 0, 0,
        0, 2, 2, 3, 2, 2, 3, 2, 0, 0,
        0, 2, 3, 2, 1, 1, 2, 3, 2, 0,
        0, 2, 3, 2, 1, 1, 2, 3, 2, 0,
        0, 2, 2, 3, 2, 2, 3, 2, 0, 0,
        0, 0, 2, 2, 3, 3, 2, 2, 0, 0,
        0, 0, 0, 2, 2, 2, 2, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            if(a[i][j]==1)
            {
                setfillstyle(SOLID_FILL, GREEN);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==2)
            {
                setfillstyle(SOLID_FILL, RED);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==3)
            {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
            else if(a[i][j]==0)
            {
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(x+i,y+j,x+i+1,y+j+1);
            }
}

