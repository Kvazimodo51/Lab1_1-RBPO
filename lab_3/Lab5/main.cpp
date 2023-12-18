#include <iostream>
#include <complex>
#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
import Math;
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;
    cout << "1-экспоненциальная форма\n        2-алгебраическая: \n";
    cin >> choice;
    Complex userComplex;
    if (choice == 1) {
        double mod, arg;

        cout << "Введите модуль числа: ";
        cin >> mod;

        cout << "Введите аргумент числа: ";
        cin >> arg;

        userComplex = Complex::FromExponentialForm(mod, arg);
        cout <<  endl << userComplex << endl;
    }
    else if (choice == 2) {
        double re, im;

        cout << "Введите действительную часть числа: ";
        cin >> re;

        cout << "Введите мнимую часть числа: ";
        cin >> im;

        userComplex = Complex::FromAlgebraicForm(re, im);
        cout << endl << userComplex << endl;
    }
    int nominator, denominator;
    cout << "Введите рациональное число в форме числитель/знаменатель: ";
    char separator;
    cin >> nominator >> denominator;
    Rational userRational(nominator, denominator);
    cout << endl << userRational << endl;
    double userDouble;
    cout << "Введите реальное число: ";
    cin >> userDouble;
    cout << "f(" << userComplex << ") = " << func(userComplex) << endl;
    cout << "f(" << userRational << ") = " << func(userRational) << endl;
    cout << "f(" << userDouble << ") = " << func(userDouble) << endl;
    return 0;
}