#pragma once

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();

    Fraction& operator+=(Fraction const& f) {
        numerator += f.numerator;
        denominator += f.denominator;
        return *this;
    }
};

Fraction operator+(Fraction f1, Fraction const& f2);