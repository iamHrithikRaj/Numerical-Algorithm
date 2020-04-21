/* Trapezoidal rule.*/
#include <iostream>
#include <iomanip>
using namespace std;
float y(float x){
    return 1/(1+x*x);
}
int main(){
    float x0,xn,h,s;
    int i,n;
    cout << "Enter x0,xn,no. of subintervals" << endl;
    cin >> x0 >> xn >> n;
    cout << fixed;
    h = (xn-x0)/n;
    s = y(x0)+y(xn);
    for (i=1;i<=n-1;i++)
        s += 2*y(x0+i*h);
    cout << "Value of integral is"
        << setw(6) << setprecision(4)
        << (h/2)*s << endl;
    return 0;
}