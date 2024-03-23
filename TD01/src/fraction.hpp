#pragma once
#include <ostream>
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    Fraction& operator+=(Fraction const& f) {
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator = denominator * f.denominator;

        return *this;
    }
    Fraction& operator+=(int const& x) {
        numerator += x * denominator;

        return *this;
    }

    Fraction& operator-=(Fraction const& f) {
        numerator = numerator * f.denominator - f.numerator * denominator;
        denominator = denominator * f.denominator;

        return *this;
    }
    Fraction& operator-=(int const& x) {
        numerator -= x * denominator;

        return *this;
    }

    Fraction& operator*=(Fraction const& f) {
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;

        return *this;
    }
    Fraction& operator*=(int const& x) {
        numerator *= x;

        return *this;
    }

    Fraction& operator/=(Fraction const& f) {
        numerator = numerator * f.denominator;
        denominator = denominator * f.numerator;

        return *this;
    }
    Fraction& operator/=(int const& x) {
        denominator *= x;

        return *this;
    }


    float to_float() {
        return (float)numerator/(float)denominator;
    }

    operator float() const;
};


Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator+(Fraction f1, int const& x);

Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, int const& x);

Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, int const& x);

Fraction operator/(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, int const& x);


bool operator==(Fraction const& f1, Fraction const& f2);

bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);

bool operator<=(Fraction const& f1, Fraction const& f2);

bool operator>(Fraction const& f1, Fraction const& f2);

bool operator>=(Fraction const& f1, Fraction const& f2);


std::ostream& operator<<(std::ostream& os, Fraction const& f);