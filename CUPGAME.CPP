#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<fstream.h>

void *img;

int dif=0;

class cup
{
 public:
 int curpos,hold;
 cup(int a,int x)
 {
  hold=x;
  curpos=a;
 }
 cup(){}

}cu[3];


void shift(int a,int b,int c)
{int o=2+dif/3,h=200,ef=0,max,sw=0,sw1=1;

 for(int i=0;i<3;i++)
 {if(cu[i].curpos==a)cu[i].curpos=b;
  else if(cu[i].curpos==b)cu[i].curpos=a;
 }

a=a*100+50; b=b*100+50; c=c*100+50;
max=(b-a)/2;
setfillstyle(1,random(14));
floodfill(300,400,WHITE);

for(int x=a, y=b; x<=b; x+=o, y-=o)
{
 if(sw%o==0)
  {  if(x<a+(b-a)/2)
     ef++;
     else
     ef--;
  }
putimage(x ,h+ef ,img ,0 );
putimage(y ,h-ef ,img ,0 );
putimage(c ,h ,img ,0 );

}
delay( 30 );
sw++;
}

void init()
{
 for(int x=150;x<351;x+=100)
 putimage(x,100,img,0);

 int pos;
 for(int i=0;i<3;i++)
  if(cu[i].hold==1)pos=cu[i].curpos;
 pos=pos*100+50;


 setfillstyle(1,WHITE);
 pieslice(pos+25,250,0,360,10);

 delay(2000);

 for(int j=100;j<201;j++)
  for(x=150;x<351;x+=100)
   putimage(x,j,img,0);
}

void end()
{
 int pos;
 for(int i=0;i<3;i++)
  if(cu[i].hold==1)pos=cu[i].curpos;
 pos=pos*100+50;

 setfillstyle(1,WHITE);

 for(int j=200;j>100;j--)
  { pieslice(pos+25,250,0,360,10);
    for(int x=150;x<351;x+=100)
    putimage(x,j,img,0);
  }
}

void frame()
{
 rectangle( 110, 90, 450, 350);
 rectangle( 113, 92, 447, 348);
 }

void read()
{
 img=malloc(imagesize(88,88,142,167));
 ifstream im("cup.bmp",ios::in|ios::binary);
 im.read((char*)img,imagesize(88,88,142,167));
}

void ginit()
{int gd=0,gm;
initgraph(&gd,&gm,"..//BGI");
}

void game()
{int a,b,c,cou=0;
delay(1000);
while(cou<20+dif)
{ do
 {
  a=random(3)+1;
  b=random(3)+1;
  if((a==1||b==1)&&(b==2||a==2))
  c=3;
  if((a==1||b==1)&&(b==3||a==3))
  c=2;
  if((a==2||b==2)&&(b==3||a==3))
  c=1;
  }while(a>=b);
  shift(a,b,c);
  cou++;
}
}

int check()
{
 rep:
 char opt=getch();
 if(opt!='1'&&opt!='2'&&opt!='3')
 goto rep;
 else
 end();
 int pos;

 for(int i=0;i<3;i++)
  if(cu[i].hold==1)pos=cu[i].curpos;

 if(pos!=(opt-'1'+1))
 return 0;
 else
 {dif++;return 1;}
}

void assign()
{
 for(int i=0;i<3;i++)
 {
  cu[i].curpos=i+1;cu[i].hold=0;
 }
cu[1].hold=1;
}

void start()
{
int ch=1;
assign();
read();
frame();
while(ch)
{
 gotoxy(1,1);
 cout<<"SCORE:"<<dif;
 init();
 game();
 ch=check();
}
}

void main()
{
randomize();
ginit();
start();



gotoxy(32,25);
cout<<"GAME OVER";
getch();
}

