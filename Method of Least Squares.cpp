/* Parabolic fit by least squares */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
float augm[3][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0}};
float t,a,b,c,x,y,xsq;
int i,j,k,n;
cout << "Enter the no. of pairs of"
<<"observed values:" << endl;
cin >> n;
cout << fixed;
augm [0] [0] = n;
for (i=0;i<n;i++)
{
cout << "Pair no. " << i+1 << endl;
cin >> x >> y;
xsq = x*x;
augm[0][1] += x;
augm[0][2] += xsq;
augm[1][2] += x*xsq;
augm[2][2] += xsq*xsq;
augm[0][3] += y;
augm[1][3] += x*y;
augm[2][3] += xsq*y;
}
augm[1][1] = augm[0][2];
augm[2][1] = augm[1][2];
augm[1][0] = augm[0][1];
augm[2][0] = augm[1][1];
cout << "The augmented matrix is:-" << endl;
for (i=0;i<3;i++)
{
for (j=0;j<4;j++)
cout << setw(9) << setprecision (4) << augm[i][j];
cout << endl;
}
/* Now solving for a,b,c
by Gauss Jordan Method */
for (j=0;j<3;j++)
for (i=0;i<3;i++)
if (i!=j)
{
t = augm[i][j]/augm[j][j];
for (k=0;k<4;k++)
augm[i][k] -= augm[j][k]*t;
}
a = augm[0][3]/augm[0][0];
b = augm[1][3]/augm[1][1];
c = augm[2][3]/augm[2][2];
cout << setprecision(4)
<< "a = " << setw(8) << a
<< "b = " << setw(8) << b
<< "c = " << setw(8) << c
<< endl;
return 0;
}