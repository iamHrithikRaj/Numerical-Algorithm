/* Laplace's Equation */
#include <iostream>
#include <iomanip>
#include <math.h>
#define SQR 4
typedef float array[SQR+1][SQR+1];
using namespace std;
void getrow(int i,array u){
    int j;
    cout << "Enter the values of u["
    << i << ",j], j=1, " << SQR << endl;
    for (j=1;j<=SQR;j++)
    cin >> u[i][j];
}
void getcol(int j,array u){
    int i;
    cout << "Enter the values of u[i," << j
        << "], i=2," << SQR-1 << endl;
    for (i=2;i<=SQR-1;i++)
        cin >> u[i][j];
}
void printarr(array u,int width,int precision){
    int i,j;
    for (i=1;i<=SQR;i++){
        for (j=1;j<=SQR;j++)
            cout << setw(width) << setprecision(precision)
                << u[i][j];
        cout << endl;
    }
}
int main (){
    array u;
    float maxerr,aerr,err,t;
    int i,j,itr,maxitr;
    for (i=1;i<=SQR;i++)
        for(j=1;j<=SQR;j++)
            u[i][j]=0;
    cout << "Enter the boundary conditions" << endl;
    getrow(1,u); getrow(SQR,u);
    getcol(1,u); getcol(SQR,u);
    cout << "Enter allowed error,"
        << "maximum iterations" << endl;
    cin >> aerr >> maxitr;
    cout << fixed;
    for (itr=1;itr<=maxitr;itr++){
        maxerr=0;
    for (i=2;i<=SQR-1;i++)
        for(j=2;j<=SQR-1;j++){
            t=(u[i-1][j]+u[i+1][j]+
                u[i][j+1]+u[i][j-1])/4;
            err=fabs(u[i][j]-t);
            if (err > maxerr)
                maxerr = err;
            u[i][j]=t;
        }
        cout << "Iteration no. " << itr << endl;
        printarr(u,9,2);
        if (maxerr <= aerr){
            cout << "After " << itr << " iterations"
                << endl
                << "The solution:-" << endl;
                printarr(u,8,1);
                return 0;
        }
    }
    cout << "Iterations not sufficient." << endl;
    return 1;
}