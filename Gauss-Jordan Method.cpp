/* Gauss jordan method */
#include <iostream>
#include <iomanip>
#define N 4
using namespace std;
int main(){
    float a[N][N+1],t;
    int i,j,k;
    cout << "Enter the elements of the"
        << "augmented matrix rowwise" << endl;
    for (i=0;i<N;i++)
        for (j=0;j<N+1;j++)
            cin >> a[i][j];
    /* now calculating the values
    of x1,x2,....,xN */
    cout << fixed;
    for (j=0;j<N;j++)
        for (i=0;i<N;i++)
            if (i!=j){
                t = a[i][j]/a[j][j];
                for(k=0;k<N+1;k++)
                    a[i][k] -= a[j][k]*t;
            }
    /* now printing the diagonal matrix */
    cout << "The diagonal matrix is:-" << endl;
    for (i=0;i<N;i++){
        for (j=0;j<N+1;j++)
            cout << setw(9) << setprecision(4) << a[i][j];
            cout << endl;
    }
    /* now printing the results */
    cout << "The solution is:- " << endl;
    for (i=0;i<N;i++)
        cout << "x[" << setw(3) << i+1 << "] ="
        << setw(7) << setprecision(4)
        << a[i][N]/a[i][i] << endl;
    return 0;
}