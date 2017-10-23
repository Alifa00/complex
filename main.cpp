#include <iostream>
using namespace std;
struct complex_t {
    float real;
    float imag;
};
complex_t add(complex_t rhs, complex_t lhs) {
    complex_t result;
    result.real = rhs.real + lhs.real;
    result.imag = rhs.imag + lhs.imag;
    return result;
}
complex_t sub(complex_t rhs, complex_t lhs) {
    complex_t result;
    result.real = rhs.real - lhs.real;
    result.imag = rhs.imag - lhs.imag;
    return result;
}
complex_t mul(complex_t rhs, complex_t lhs) {
    complex_t result;
    result.real = rhs.real * lhs.real - rhs.imag * lhs.imag;
    result.imag = rhs.imag * lhs.real + rhs.real * lhs.imag;
    return result;
}
complex_t div(complex_t rhs, complex_t lhs) {
    complex_t result;
    result.real = (rhs.real * lhs.real + rhs.imag * lhs.imag) / (lhs.real * lhs.real + lhs.imag * lhs.imag);
    result.imag = (rhs.imag * lhs.real - rhs.real * lhs.imag) / (lhs.real * lhs.real + lhs.imag * lhs.imag);
    return result;
}
std::istream & read(std::istream & stream, complex_t & complex) {
    char fun1, fun2, fun3;
    float real;
    float imag;
    if (stream >> fun1 && fun1 == '(' && stream >> real && stream >> fun2 && fun2 == ',' && stream >> imag && stream >> fun3 && fun3 == ')') {
        complex.real = real;
        complex.imag = imag;
    } else {
        stream.setstate(std::ios::failbit);
    }
    return stream;
}
std::ostream & write(std::ostream & stream, complex_t complex) {
    stream << "(" << complex.real << "," << complex.imag << ")";
    return stream;
}
int main() {
    char op;
    complex_t complex1, complex2;
    if (read(cin, complex1) && (cin >> op) && read(cin, complex2)) {
        switch (op) {
            case '+':
                write(cout, add(complex1, complex2));
                break;
            case '-':
                write(cout, sub(complex1, complex2));
                break;
            case '*':
                write(cout, mul(complex1, complex2));
                break;
            case '/':
                write(cout, div(complex1, complex2));
                break;
            default:
                cout << "\nAn error has occured while reading input data";
                break;
        }
    } else {
        cout << "\nAn error has occured while reading input data";
    }
    return 0;
}
