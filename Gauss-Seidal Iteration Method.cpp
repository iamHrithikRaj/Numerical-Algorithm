/* Gauss Seidal method */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define N 3 
int main()
{
float a[N][N+1],x[N],aerr,maxerr, t,s,err;
int i,j,itr,maxitr;
/* first initializing the array x */
for (i=0;i<N;i++) x[i]=0;
cout << "Enter the elements of the"
<< "augmented matrix rowwise" << endl;
for (i=0;i<N;i++)
for (j=0;j<N+1;j++)
cin >> a[i][j];
cout << "Enter the allowed error,"
<< "maximum iterations" << endl;
cin >> aerr >> maxitr;
cout << fixed;
cout << "Iteration" << setw(6) << "x[1]"
<< setw(11) << "x[2]"
<< setw(11) << "x[3]" << endl;
for (itr=1;itr<=maxitr;itr++)
{
maxerr = 0;
for (i=0;i<N;i++)
{
s = 0;
for (j=0;j<N;j++)
if (j!=i) s += a[i][j]*x[j];
t = (a[i][N]-s)/a[i][i];
err = fabs(x[i]-t);
if (err >> maxerr) maxerr = err;
x[i] = t;
}
cout << setw(5) << itr;
for (i=0;i<N;i++)
cout << setw(11) << setprecision(4) << x[i];
cout << endl;
if (maxerr << aerr)
{
cout << "Converges in" << setw(3) << itr
<< "iterations" << endl;
for (i=0;i<N;i++)
cout << "x[" << setw(3) << i+1 << "] = "
<< setw(7) << setprecision(4) << x[i]
<< endl;
return 0;
}
}
cout << "Solution does not converge,"
<< "iterations not sufficient" << endl;
return 1;
}