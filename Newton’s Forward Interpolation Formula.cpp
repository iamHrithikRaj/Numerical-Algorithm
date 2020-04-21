/* Newton's forward interpolation */
#include <iostream>
#include <iomanip>
#define MAXN 100
#define ORDER 4 
using namespace std;
int main()
{
float ax[MAXN+1],ay[MAXN+1],
diff[MAXN+1][ORDER+1],
nr=1.0,dr=1.0,x,p,h,yp;
int n,i,j,k;
cout << "Enter the value of n" << endl;
cin >> n;
cout << "Enter the values in form x,y" << endl;
for (i=0;i<=n;i++)
cin >> ax[i] >> ay[i];
cout << "Enter the values of x"
<< "for which value of y is wanted" << endl;
cin >> x;
cout << fixed;
h=ax[1]–ax[0];
/* now making the diff. table */
/* calculating the 1st order differences */
for (i=0;i<=n-1;i++)
diff[i][1] = ay[i+1]-ay[i];
/* calculating the second & higher order differences.*/
for (j=2;j<=ORDER;j++)
for (i=0;i<=n-j;i++)
diff [i][j] = diff[i+1][j-1]
-diff[i][j-1];
/* now finding x0 */
i=0;
while (!(ax[i] > x)) i++;
/* now ax[i] is x0 & ay[i] is y0 */
i--;
p = (x-ax[i])/h; yp=ay[i];
/* Now carrying out interpolation */
for (k=1;k<=ORDER;k++)
{
nr *= p-k+1; dr *=k;
yp += (nr/dr)*diff[i][k];
}
cout << "When x = "
<< setw(6) << setprecision(1)
<< x
<< " y = "
<< setw(6) << setprecision(2)
<< yp << endl;
return 0;
}