#include<iostream>
#include<conio.h>
#include<iomanp>
using namespace std;
void main()
{
int t[10],n,i,ts1=0,ts2=0;
float a,b,rs1=0,rs2=0,r[10],x1,y1,x2,y2;
clrscr();
cout<<"enter the no. of observations"<<endl;
cin>>n;
cout<<"enter the different values of t"<<endl;
for(i=1;i<=n;i++)
{
cin>>t[i];
}
cout<<"\nenter the corresponding values of r"<<endl;
for(i=1;i<=n;i++)
{
cin>>r[i];
}
for(i=1;i<=(n/2);i++)
{
ts1+=t[i];
rs1+=r[i];
}
for(i=((n/2)+1);i<=n;i++)
{
ts2+=t[i];
rs2+=r[i];
}
x1=ts1/(n/2);
y1=rs1/(n/2);
x2=ts2/(n/2);
y2=rs2/(n/2);
b=(y2-y1)/(x2-x1);
a=y1-(b*x1);
cout<<"the value of a&b comes out to be
"<<endl<<"a="<<setw(5)<<setprecision(3)<<a<<"\n"<<"b="<<
setw(5)<<setprecision(3)<<b;
getch();
}