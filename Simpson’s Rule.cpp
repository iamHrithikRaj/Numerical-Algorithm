/* Simpson's rule */
#include <iostream>
#include <iomanip>
using namespace std;
float y(float x){
    return 1/(1+x*x);
}
int main(){
    float x0,xn,h,s;
    int i,n;
    cout << "Enter x0,xn, no.of subintervals"
        << endl;
    cin >> x0 >> xn >> n;
    cout << fixed;
    h = (xn-x0)/n;
    s = y(x0)+y(xn)+4*y(x0+h);
    for (i=3;i<=n-1;i+=2)
        s += 4*y(x0+i*h)+2*y(x0+(i-1)*h);
    cout << "Value of integral is"
        << setw(6) << setprecision(4)
        << (h/3)*s << endl;
    return 0;
}