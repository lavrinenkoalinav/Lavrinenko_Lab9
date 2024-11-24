#include <iostream>
#include <stdexcept>
#include <Windows.h>
using namespace std;

struct Fraction {
    int numerator;
    int denominator; 

    Fraction(int num, int den) {
        if (den == 0) {
            throw std::invalid_argument("Знаменник не може бути нулем.");
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    int findGCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a); 
    }

    void simplify() {
        int gcdValue = findGCD(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    Fraction add(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction subtract(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction multiply(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Ділення на нуль.");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);   
    SetConsoleOutputCP(1251);

    try {
        Fraction f1(3, 4); 
        Fraction f2(5, 6); 

        std::cout << "Перший дріб: ";
        f1.print();
        std::cout << "Другий дріб: ";
        f2.print();

        Fraction result = f1.add(f2);
        std::cout << "Додавання: ";
        result.print();

        result = f1.subtract(f2);
        std::cout << "Віднімання: ";
        result.print();

        result = f1.multiply(f2);
        std::cout << "Множення: ";
        result.print();

        result = f1.divide(f2);
        std::cout << "Ділення: ";
        result.print();
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
