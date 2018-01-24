#include <dos.h>
#include <iostream>
#include <graphics.h>
  
  
      union REGS i,o;
      main()
           {
           int gd=DETECT,gm,maxx,maxy,x,y,button;
           initgraph(&gd,&gm,"c:\\turboc3\\bgi");
           maxx=getmaxx();
           maxy=getmaxy();
           rectangle(0,56,maxx,maxy);
           setviewport(1,57,maxx-1,maxy-1,1);
           gotoxy(26,1);
           printf("MouseDemostration program");
           if(initmouse()==0)
           {
           closegraph();
           restorecrtmode();
           printf("\n mouse driver not loaded");
           exit(1);
  
           }
           restrictmouseptr(1,57,maxx-1,maxy-1);
           showmouseptr();
           gotoxy(1,2);
           printf("Left button");
           gotoxy(15,2);
           printf("Right button");
           gotoxy(55,3);
           printf("press anaykey to exit");
           while(!kbhit())
           {
            getmousepos(&button,&x,&y);
            gotoxy(5,3);
            (button&1)==1?printf("down"):printf("up");
            gotoxy();
            (button&2)==2?printf("Down"):printf("Up");
            gotoxy(65,2);
            printf("X=%03d y=%03d",x,y );
           }
           return;
           }
           initmouse()
           {
           i.x.ax=0;
           int86(0x33,&i,&o);
           return(o.x.ax);
           }
           showmouseptr()
           {
            i.x.ax=1;
            int86(0x33,&i,&o);
            return;
           }
  
           restrictmouseptr(int x1,int y1,int x2,int y2)
           {
            i.x.ax=7;
            i.x.cx=x1;
            i.x.dx=x2;
            int86(0x33,&i,&o);
            i.x.ax=8;
            i.x.cx=y1;
            i.x.dx=y2;
            int86(0x33,&i,&o);
            return;
            }
            getmousepos(int *button,int *x,int *y)
            {
             i.x.ax=3;
             int86(0x33,&i,&o);
             *button=o.x.bx;
             *x=o.x.cx;
             *y=o.x.dx;
             return;
            }
