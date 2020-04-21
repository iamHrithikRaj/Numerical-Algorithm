/* Modified Euler's Method*/
#include<iostream>
#include<math.h>
#include<iomanip>
#include<conio.h>
using namespace std;
void main( )
{
clrscr ( );
int i,j;
float x,y,x1=0.0,y1=0.0,h,ms=0.0,flag=0,y2=0.0,t=0.0;
cout<<"\nenter the value of x";
cin>>x;
cout<<"enter the value of y";
cin>>y;
cout<<"enter the height";
cin>>h;
i=7;
j=2;
gotoxy(2,i);
cout<<"x";gotoxy(10,i);cout<<"x+y=y1";gotoxy(28,i);
cout<<"mean slope";gotoxy(45,i);cout<<"old y+.1(mean
slope)new y"; while(x1<x)
{
i++;
do
{
i++;
if(flag==0)
{
y1=x1+y;
gotoxy(2,i);cout<<x1;gotoxy(10,i);
cout<<y1;gotoxy(28,i);cout<<ms;
ms=y1;
y2=y+h*ms;
gotoxy(45,i);cout<<y2;
x1=x1+h;
flag=1;
}
else
{
ms=(y1+(x1+y2))/2.0;
t=y+h*ms;
if(y2==t)
{
y2=y+h*ms;
break;
}
gotoxy(2,i);cout<<x1;gotoxy(10,i);cout<<x1<<"+"<<x2;y2=y+h*ms;
gotoxy(28,i);cout<<ms;gotoxy(45,i);cout<<y2;
}
}while(1);
y=y2;
cout<<"\n";
flag=0;
}
getch( );
}