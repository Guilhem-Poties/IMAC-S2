#include "fraction.hpp"
#include "utils.hpp"

Fraction operator+(Fraction f1, Fraction const& f2) {
    return simplify(f1+=f2);
};
Fraction operator+(Fraction f, int const& x) {
    return simplify(f+=x);
};

Fraction operator-(Fraction f1, Fraction const& f2) {
    return simplify(f1-=f2);
}
Fraction operator-(Fraction f, int const& x) {
    return simplify(f-=x);
};

Fraction operator*(Fraction f1, Fraction const& f2) {
    return simplify(f1*=f2);
}
Fraction operator*(Fraction f, int const& x) {
    return simplify(f*=x);
};

Fraction operator/(Fraction f1, Fraction const& f2) {
    return simplify(f1/=f2);
}
Fraction operator/(Fraction f, int const& x) {
    return simplify(f/=x);
};


bool operator==(Fraction const& f1, Fraction const& f2) {
    return (simplify(f1).numerator == simplify(f2).numerator && simplify(f1).denominator == simplify(f2).denominator);
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1==f2);
}


bool operator<(Fraction const& f1, Fraction const& f2) {
    return (f1.numerator / f1.denominator < f2.numerator / f2.denominator);
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return (f1 < f2 || f1 == f2);
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2 || f1 == f2);
}

Fraction::operator float() const {
    Fraction f = *this;
    return f.to_float();
}


std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

/*
Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator, f1.denominator * f2.denominator});
};

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator, f1.denominator * f2.denominator});
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({f1.numerator * f2.numerator, f1.denominator * f2.denominator});
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({f1.numerator * f2.denominator, f1.denominator * f2.numerator});
}
*/