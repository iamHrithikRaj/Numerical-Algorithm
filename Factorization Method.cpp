/* Factorization method */
#include <iostream>
#include <iomanip>
#define N 3
using namespace std;
typedef float matrix[N][N];
matrix l,u,a;
float b[N],x[N],v[N];
void urow(int i){
    float s;
    int j,k;
    for (j=i;j<N;j++){
        s = 0;
        for (k=0;k<N-1;k++)
            s += u[k][j]*l[i][k];
            u[i][j] = a[i][j]-s;
    }
}
void lcol(int j){
    float s;
    int i,k;
    for (i=j+1;i<N;i++){
        s = 0;
        for (k=0;k<=j-1;k++)
            s += u[k][j]*l[i][k];
            l[i][j] = (a[i][j]-s)/u[j][j];
    }
}
void printmat(matrix x){
    int i,j;
    for (i=0;i<N;i++){
    for (j=0;j<N;j++)
        cout << setw(8) << setprecision(4) << x[i][j];
        cout << endl;
    }
}
int main(){
    int i,j,m;
    float s;
    cout << "Enter the elements of augmented"
    << " matrix rowwise" << endl;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++)
            cin >> a[i][j];
            cin >> b[i];
    }
    cout << fixed;
    /* now calculating the elements of l and u */
    for (i=0;i<N;i++)
        l[i][i] = 1.0;
    for (m=0;m<N;m++){
        urow(m);
        if (m < N-1) lcol(m);
    }
    /* now printing the elements of l and u */
    cout << setw(14) << "U" << endl; printmat(u);
    cout << setw(14) << "L" << endl; printmat(l);
    /* now solving LV=B
    by forward substitution */
    for (i=0;i<N;i++){
        s = 0;
        for (j=0;j<=i-1;j++)
            s += l[i][j]*v[j];
            v[i] = b[i]-s;
    }
    /* now solving UX=V
    by backward substitution */
    for (i=N-1;i>=0;i--){
        s = 0;
        for (j=i+1;j<N;j++)
            s += u[i][j]*x[j];
            x[i] = (v[i]-s)/u[i][i];
    }
    /* printing the results */
    cout << "The solution is:-" << endl;
    for (i=0;i<N;i++)
        cout << "x[" << setw(3) << i+1 << "] = "
        << setw(6) << setprecision(4)
        << x[i] << endl;
    return 0;
}