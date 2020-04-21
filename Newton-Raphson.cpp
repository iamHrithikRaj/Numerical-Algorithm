/* Newton Raphson Method */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
float f(float x){
    return x*log10(x)-1.2;
}
float df(float x){
    return log10(x) + 0.43429;
}
int main(){
    int itr,maxitr;
    float h,x0,x1,aerr;
    cout << "Enter x0,allowed error,"
    << "maximum iterations" << endl;
    cin >> x0 >> aerr >> maxitr;
    cout << fixed;
    for (itr=1;itr<=maxitr;itr++){
        h = f(x0)/df(x0);
        x1 = x0-h;
        cout << "Iteration no." << setw(3) << itr
        << "X = " << setw(9) << setprecision(6)
        << x1 << endl;
        if (fabs(h) < aerr){
            cout << "After" << setw(3) << itr
            << "iterations, root = "
            << setw(8) << setprecision(6) << x1;
            return 0;
        }
        x0 = x1;
    }
    cout << "Iterations not sufficient,"
    << "solution does not converge" << endl;
    return 1;
}