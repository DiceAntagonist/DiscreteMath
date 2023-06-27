#include <iostream>
#include <cmath>

using namespace std;

int evaluatePolynomial(int n) {
    
    int coefficients[] = {4, 2, 9};
    int degree = sizeof(coefficients) / sizeof(coefficients[0]);

    int result = 0;
    for (int i = 0; i < degree; i++) {
        result += coefficients[i] * pow(n, degree - 1 - i);
    }

    return result;
}

int main() {
    int n = 5;
    int polynomialValue = evaluatePolynomial(n);

    cout << "The value of the polynomial function for n = " << n << " is: " << polynomialValue << endl;

    return 0;
}
