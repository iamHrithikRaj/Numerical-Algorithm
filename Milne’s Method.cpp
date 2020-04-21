/*Milne predictor corrector*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float x[5],y[5],h;
float f(int i)
{
return x[i]-y[i]*y[i];
}
void corect()
{
    y[4] = y[2]+(h/3)*(f(2)+4*f(3)+f(4));
cout << setw(23) << ""
<< setprecision(4)
<< setw(8) << y[4]
<< setw(8) << f(4) << endl;
<< "",y[4],f(4)
}
int main()
{
float xr,aerr,yc;
int i;
cout << "Enter the values of x0,xr,h,"
<< "allowed error" << endl;
cin >> x[0] >> xr >> h >> aerr;
cout << "Enter the value of y[i], i=0, 3" << endl;
for (i=0;i<=3;i++) cin >> y[i];
cout << fixed;
for (i=1;i<=3;i++) x[i] = x[0]+i*h;
cout << setw(5) << "x" << setw(15) << "Predicted"
<< setw(17) << "Corrected" << endl;
cout << setw(11) << "y" << setw(10) << "f"
<< setw(7) << "y" << setw(10) << "f" << endl;
while (1)
{
if(x[3] = xr) return 0;
x[4] = x[3]+h;
y[4] = y[0]+
(4*h/3)*(2*(f(1)+f(3))-f(2));
cout << setw(6) << setprecision(2) << x[4]
<< setprecision(4)
<< setw(8) << y[4]
<< setw(8) << f(4) << endl;
corect(1);
while (1)
{
yc = y[4];
corect();
if(fabs(yc-y[4]) <= aerr) break;
}
for (i=0;i<=3;i++)
{
    x[i] = x[i+1];
y[i] = y[i+1];
}
}
}