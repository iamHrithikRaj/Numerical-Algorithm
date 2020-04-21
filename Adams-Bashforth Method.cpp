/*Adams-Bashforth Method*/
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<conio.h>
using namespace std;
void main( )
{
    float *x, *y, *f;
float h;
int i,size,row;
clrscr();
cout <<"enter the size";
cin>>size;
x=new float[size+1];
y=new float[size+1];
f=new float[size+1];
for (i=0;i<size;i++)
{
cout<<"enter the value for x["<<i<<"]";
cin>>x[i];
cout<<"enter the value for y["<<i<<"]";
cin>>y[i];
}
h=x[1]-x[0];
// calculating values [f]
for(i=0;i<4;i++)
{
f[i]=pow(x[i],2)*(1.0+y[i]);
}
cout<<"\nvalues for (x) (y) and (f) are\n";
row=16;
for(i=0;i<4;i++)
{
gotoxy(2,row);cout<<"x=";gotoxy(6,row);cout<<x[i];gotoxy(13,ro
w);cout<<"y"<<i-3;gotoxy(16,row);cout<<"=";gotoxy(18,row);cout
<<y[i];gotoxy(28,row);cout<<"f"<<i-3;gotoxy(32,row);cout<<"=";
gotoxy(35,row);cout<<f[i];
row++;
}
//using predicator
y[size]=y[size-1]+((h/24)*((55*f[size-1])–(59*f[size-
2])+(37*f[size-
3])-(9*f[size-4])));
x[size]=1.4;
f[size]=pow(x[size],2)*(1.0+y[size]);
gotoxy(2,row);cout<<"x=";
gotoxy(6,row);cout<<x[size];gotoxy(13,row);cout<<"y1";
gotoxy(16,row);cout<<"="; gotoxy(18,row);cout<<y[size
];gotoxy(28,row);cout<<"f1";gotoxy(32,row);cout<<"=";
gotoxy(35,row);cout<<f[size];
}