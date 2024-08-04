#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs10b_fraction {

    class Fraction {
    public:
        // Constructors
        Fraction();
        Fraction(int num, int denom);
        Fraction(int wholeNumber);

        // Overloaded operators
        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& in, Fraction& fraction);

        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);

        // Arithmetic operators
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        Fraction& operator+=(const Fraction& other);
        Fraction& operator-=(const Fraction& other);
        Fraction& operator*=(const Fraction& other);
        Fraction& operator/=(const Fraction& other);

        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);


        friend Fraction operator+(int num, const Fraction& frac);

    private:
        int numerator;
        int denominator;

        void simplify();
    };

} // namespace cs10b_fraction

#endif
