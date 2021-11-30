#include<stdlib.h>
#include<stdio.h>
#include<glut.h>
#include <math.h>
#include <iostream>
using std::cout;  
using std::cin;    
using std::endl; 

void endpoints()
{
	int x0,y0,xend,yend;
	cout << "enter values of P1: ";
	cout << "x0: ";
	cin >> x0;
	cout << "y0: ";
	cin >> y0;
	cout << "enter values of P2: ";
	cout << "xend: ";
	cin >> xend;
	cout << "yend: ";
	cin >> yend;
	cout << "p1(",x0,",",y0,")";
	cout << "p2(",xend,",",yend,")";
}
void Direct_use_of_line_equation()
{
	glClearColor(1,1,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glPointSize(5);
	int x,y;
	int dx,dy;
	float m;
	dx=xend-x0;
	dy=yend-y0;
	m=dy/dx;
	glBegin(GL_POINTS);
    glVertex2i(x0,y0);
	glEnd();
	if(m>0)
	{
		for(int i = x0;i<=xend;i++)
		{
			y=m*i;
			glBegin(GL_POINT);
			glVertex2i(i,y);
			glEnd();
		}
		
	}
	else
	{
		for(int i = y0;i<=yend;i++)
		{
			y=m*i;
			glBegin(GL_POINT);
			glVertex2i(i,y);
			glEnd();
		}
	
	}
	glEnd();
	glFlush();
}
void DDA()
{
	float dy,dx,length,x,y,Xin,Yin;
    dx=xend-x0;
    dy=yend-y0;
	if(abs(dx)> abs(dy))
	{
		length = abs(dx);
	}
	else
	{
		length = abs(dy);
	}
	Xin = dx/length;
    Yin = dy/length;
	x= x0;
	y=y0;
	glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
	glEnd();
	for (int i=1 ;i<=length;i++)
	{
		x= x + Xin;
        y= y + Yin;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}
	glFlush();
}
void Bresenham()
{
	int dx=xend-x0;
    int dy=yend-y0;
	int dx2=2*dx;
	int dy2=2*dy;
    int p0 = dy2 - dx;
    float x=x0,y=y0;
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    int p =p0;
    int k;
	for(k=0;k<dx;k++)
    {
        if(p<0)
		{
			x = x+1;
			glVertex2i(x,y);
		}
		else
        {
            x = x+1;
		    y = y+1;
            glVertex2i(x,y);
        }
	}
    glEnd();
    glFlush();	
}
void choose()
{
	string answer;
	cout << "Do you want to back to the menu? y/n: ";
	cin >> answer;
	if(answer == "y" || answer =="Y")
	{
		system("clear");
		start();
	}
	else if(answer=="n" || answer == "N")
	{
		//exit();
	}
	else
	{
		cout << "wrong answer!";
		system("clear");
		choose();
	}
}
void start()
{
	cout << "Enter the algorithm's number to start:- \n 1- Direct use of line equation\n 2- DDA \n 3- Bresenham \n your chose: ";
	int algorithm_number;
	
	cin >> algorithm_number;
	if(algorithm_number == 1)
	{
		Direct_use_of_line_equation();
		choose();
	}
	else if(algorithm_number == 2)
	{
		DDA();
		choose();
	}
	else if(algorithm_number == 3)
	{
		Bresenham();
		choose();
	}
	else
	{
		cout << "wrong input!\n try again";
		system("clear");
		start();
	}
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Draw point");
	gluOrtho2D(0,200,0,200);
	endpoints();
	glutDisplayFunc(start);
	glutMainLoop();


}