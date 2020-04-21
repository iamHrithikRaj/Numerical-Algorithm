/*Solution of parabolic equations by
Bendre Schmidt method*/
#include <iostream>
#include <iomanip>
#define XEND 8
#define TEND 5 
using namespace std;
float f(int x){
    return 4*x-(x*x)/2.0;
}
int main(){
    float u[XEND+1][TEND+1],h=1.0,k=0.125,
        csqr,alpha,ust,uet;
    int i,j;
    cout << "Enter the square of 'c'" << endl;
    cin >> csqr;
    alpha = (csqr*k)/(h*h);
    cout << "Enter the value of u[0,t]" << endl;
    cin >> ust;
    cout <<"Enter the value of u[" << XEND
        << ",t]" << endl;
    cin >> uet;
    cout << fixed;
    for (j=0;j<=TEND;j++)
        u[0][j]=u[XEND][j]=ust;
    for (i=1;i<=XEND-1;i++)
        u[i][0]=f(i);
    for (j=0;j<=TEND-1;j++)
        for (i=1;i<=XEND-1;i++)
            u[i][j+1]=
            alpha*u[i-1][j]
            +(1-2*alpha)*u[i][j]
            +alpha*u[i+1][j];
    cout << "The value of alpha is"
        << setw(4) << setprecision(2)
        << alpha << endl;
    cout << "The values of u[i,j] are:-"
        << endl;
    for (j=0;j<TEND;j++){
        for (i=0;i<=XEND;i++)
            cout << setw(7) << setprecision(4)
                << u[i][j];
        cout << endl;
    }
return 0;
}