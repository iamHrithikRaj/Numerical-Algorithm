#include <iostream>
#include <cmath>

// Function to compute f(x) = x^2 - 2
double f(double x) {
    return x * x * x + x  - 1 ;
}

// Function to compute f'(x) = 2x
double f_prime(double x) {
    return  3* x + 1 ;
}

int main() {
    // Initial values
    double x0 = 1.0; // initial guess
    double epsilon = 1e-6; // tolerance
    int maxIter = 100; // maximum number of iterations

    // Initialize variables
    double x = x0;
    double fx, f_prime_x, x_next;
    int iter = 0;

    // Newton Raphson method
    while (iter < maxIter) {
        // Compute f(x) and f'(x)
        fx = f(x);
        f_prime_x = f_prime(x);

        // Compute x_next
        x_next = x - fx / f_prime_x;

        // Print iteration details
        std::cout << "Iteration " << iter << ": x = " << x << ", f(x) = " << fx << ", f'(x) = " << f_prime_x << ", x_next = " << x_next << std::endl;

        // Check for convergence
        if (std::abs(x_next - x) < epsilon) {
            std::cout << "Converged! The root is approximately " << x_next << std::endl;
            break;
        }

        // Update x
        x = x_next;
        iter++;
    }

    return 0;
}
