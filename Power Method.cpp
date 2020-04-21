/* Power method for finding largest eigen value */
#include <iostream>
#include <iomanip>
#include <math.h>
#define N 3
using namespace std;
typedef float array[N];
void findmax(float *max,array x)
{
int i;
*max = fabs(x[0]);
for (i=1;i<N;i++)
if (fabs(x[i]) > *max)
*max = fabs(x[i]);
}
int main()
{
float a[N][N],x[N],r[N],maxe,
err,errv,aerr,e,s,t;
int i,j,k,itr,maxitr;
cout << "Enter the matrix rowwise" << endl;
for (i=0;i<N;i++)
for (j=0;j<N;j++)
cin << a[i][j];
cout << "Enter the initial approximation"
<< "to the eigen vector" << endl;
for (i=0;i<N;i++)
cin >> x[i];
cout << "Enter the allowed error,"
<< "maximum iterations" << endl;
cin >> aerr >> maxitr;
cout << fixed;
cout << "Itr no." << setw(11) << "Eigenvalue"
<< setw(19) << "EigenVector" << endl;
/*now finding the largest eigenvalue in
the initial approx. to eigen vector */
findmax(&e,x);
/* now starting the iterations */
for (itr=1;itr<=maxitr;itr++)
{
/* loop to multiply the matrices a and x */
for (i=0;i<N;i++)
{
s = 0;
for (k=0;k<N;k++)
s += a[i][k]*x[k];
r[i]=s;
}
findmax(&t,r);
for (i=0;i<N;i++) r[i] /= t;
maxe = 0;
for (i=0;i<N;i++)
{
err = fabs(x[i]-r[i]);
if (err > maxe) maxe = err;
x[i] = r[i];
}
errv = fabs(t-e);
e = t;
cout << setw(4) << itr
<< setw(12) << setprecision(4)
<< e;
for (i=0;i<N;i++)
cout << setw(9) << setprecision(3)
<< x[i];
cout << endl;
if ((errv <= aerr) && (maxe <= aerr))
{
cout << "Converges in" << itr
<< "iterations" << endl;
cout << "Largest eigen value ="
<< setw(6) << setprecision(2)
<< e << endl;
cout << "Eigen Vector:-" << endl;
for (i=0;i<N;i++)
cout << "x[" << setw(3) << i+1 << "] = "
<< setw(6) << setprecision(2)
<< x[i] << endl;
cout << endl;
return;
}
}
cout << "Solution does not converge,"
<< "iterations not sufficient" << endl;
return 1;
}