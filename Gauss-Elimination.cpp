/* Gauss elimination method */
#include <iostream>
#include <iomanip>
#include <math.h>
#define N 4
using namespace std;
int main(){
    float a[N][N+1],x[N],t,s;
    int i,j,k;
    cout << "Enter the elements of the"
            "augmented matrix rowwise" << endl;
    cout << fixed;
    for (i=0;i<N;i++)
        for (j=0;j<N+1;j++)
            cin >> a[i][j]);
    for (j=0;j<N-1;j++)
        for (i=j+1;i<N;i++){
            t = a[i][j]/a[j][j];
                for (k=0;k<N+1;k++)
                    a[i][k] -= a[j][k]*t;
        }
    /* now printing the
    upper triangular matrix */
    cout << "The upper triangular matrix"
            "is:-" << endl;
    for (i=0;i<N;i++){
        for (j=0;j<N+1;j++)
            cout << setw(8) << setprecision(4) << a[i][j];
            cout << endl;
    }
    /* now performing back substitution */
    for (i=N-1;i>=0;i--){
    s = 0;
        for (j=i+1;j<N;j++)
            s += a[i][j]*x[j];
            x[i] = (a[i][N]-s)/a[i][i];
    }
    /* now printing the results */
    cout << "The solution is:- " << endl;
    for (i=0;i<N;i++)
        cout << "x[" << setw(3) << i+1 << "] = "
        << setw(7) << setprecision(4) << x[i] << endl;
    return 0;
}