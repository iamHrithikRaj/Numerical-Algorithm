/* derivatives using forward difference*/
#include<iostream>
#include<math.h>
#include<iomanip>
#include<conio.h>
using namespace std;
void main( )
{
float *x=NULL, *y=NULL,max;
float *tmp = NULL;
float xval,h,p,x0,y0,yval,sum;
int pos,i;
clrscr( );
cout<<"enter the no of comparisons";
cin>>max;
x=new float[max];
y=new float[max];
cout<<"enter the values in cv table for x and y";
for (i=0;i<max;i++)
{
cout<<"\n value for "<<i<<"x";
cin>>x[i];
cout<<"\n value for "<<i<<"y";
cin>>y[i];
}
cout<<"enter the value of x";
cin>>xval;
for(i=0;i<max;i++)
{
if(x[i]>=xval)
{
pos=i;
break;
}
}
x0=x[pos];
y0=y[pos];
cout<<"\nx0 is "<<x0<<"y0 is "<<y0<<"at"<<pos;
h=x[1]-x[0];
p=(xval-x0)/h;
if(pos<(max))
{
int i,l,j;
// calculating no of elements in array
l=max-pos;
tmp= new float [l* l];
cout<<"\n";
for(i=0;i<l;i++)
{
for(j=0;j<=l;j++)
{
tmp[i*l+j]=0;
}
cout<<"\n";
}
cout<<"\n size of new array" <<l<<"\n";
//copying values of y in array
for(i=0, j=pos;i<l;i++, j++)
{
tmp[i]=y[j];
}
cout<<"\n";
for(i=1;i<l;i++)
{
for(j=0; j<l-i; j++)
{
tmp[i*l+j]=tmp[(i-1)*l+(j+1)]-tmp[(i-1)*l+(j)];
}
}
cout<<"\nvalues are \n";
for(i=0;i<l;i++)
{ cout<<x[i+pos]<<"\t";
for(j=0; j<l; j++)
{
cout<<setprecision(3)<<tmp[j*l+i]<<"\t|";
}
cout<<"\n;
}
//appling newtons forward diffenation using first derivates
sum=0;
int k=1;
for(i=1;i<l;i++)
{
sum=sum+((1.0/i)*tmp[i*tmp[i*l+0]*k);
k=-k;
}
cout<<"\n\n first (dy/dx): "<<sum/h;
int v[]={0,0,1.0, 1.0, 11.0/12.0,5.0/6.0,137.0/180.0};
sum=0;
k=1;
for(i=2;i<l;i++)
{
sum=sum+(v[i]*tmp[i*l+0]*k);
k=–k;
}
cout<<"\n\n second (dy/dx): "<<sum/pow(h,2.0);
}