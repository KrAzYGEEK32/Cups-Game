#include<graphics.h>
#include<conio.h>
#include<malloc.h>
#include<fstream.h>


void main()
{
int gd=0,gm,col=14;
initgraph(&gd,&gm,"");
setcolor(col);
setfillstyle(1,col);
line(100,100,93,150);
line(130,100,137,150);
ellipse(115,150,180,360,22,12);
ellipse(115,100,181,359,16,7);
floodfill(115,150,col);
setcolor(RED);
ellipse(115,100,0,360,15,6);
setfillstyle(1,RED);
floodfill(115,100,RED);

setcolor(col);
setfillstyle(1,col);
line(100,100,93,150);
line(130,100,137,150);
ellipse(115,150,180,360,22,12);
ellipse(115,100,181,359,16,7);
floodfill(115,150,col);
setcolor(RED);
ellipse(115,100,0,360,15,6);
setfillstyle(1,RED);
floodfill(115,100,RED);


void *img=malloc(imagesize(88,88,142,167));
getimage(88,88,142,167,img);
ofstream f("cup.bmp",ios::out|ios::binary);
f.write((char*)img,imagesize(88,88,142,167));
f.close();
getch();
}