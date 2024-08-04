#include "fraction.h"
#include <numeric> // Include the numeric header for std::gcd

namespace cs10b_fraction {

    // Default constructor
    Fraction::Fraction() : numerator(0), denominator(1) {}

    // Constructors
    Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            denominator = 1;
        }
        simplify();
    }

    Fraction::Fraction(int wholeNumber) : numerator(wholeNumber), denominator(1) {}

    // Operator overloads for integer and Fraction operations
    Fraction operator + (int num, const Fraction& frac) {
        return Fraction(num) + frac;
    }

    Fraction operator -(int num, const Fraction& frac) {
        return Fraction(num) - frac;
    }

    Fraction operator *(int num, const Fraction& frac) {
        return Fraction(num) * frac;
    }

    Fraction operator /(int num, const Fraction& frac) {
        return Fraction(num) / frac;
    }


    // Overloaded operators
    std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        if (fraction.denominator == 1) {
            out << fraction.numerator;
        } else if (fraction.numerator < fraction.denominator) {
            out << fraction.numerator << '/' << fraction.denominator;
        } else {
            int wholePart = fraction.numerator / fraction.denominator;
            int remainder = fraction.numerator % fraction.denominator;
            out << wholePart << '+' << remainder << '/' << fraction.denominator;
        }
        return out;
    }

    bool operator<(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator) < (right.numerator * left.denominator);
    }

    bool operator<=(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator) <= (right.numerator * left.denominator);
    }

    bool operator>(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator) > (right.numerator * left.denominator);
    }

    bool operator>=(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator) >= (right.numerator * left.denominator);
    }

    bool operator==(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator) == (right.numerator * left.denominator);
    }

    bool operator!=(const Fraction& left, const Fraction& right) {
        return (left.numerator * right.denominator) != (right.numerator * left.denominator);
    }

    // Arithmetic operators
    Fraction Fraction::operator+(const Fraction& other) const {
        Fraction result(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
        result.simplify();
        return result;
    }

    Fraction Fraction::operator-(const Fraction& other) const {
        Fraction result(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
        result.simplify();
        return result;
    }

    Fraction Fraction::operator*(const Fraction& other) const {
        Fraction result(numerator * other.numerator, denominator * other.denominator);
        result.simplify();
        return result;
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        Fraction result(numerator * other.denominator, denominator * other.numerator);
        result.simplify();
        return result;
    }

    Fraction& Fraction::operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    Fraction& Fraction::operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    Fraction& Fraction::operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    Fraction& Fraction::operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    Fraction& Fraction::operator++() {
        *this += 1;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        *this += 1;
        return temp;
    }

    Fraction& Fraction::operator--() {
        *this -= 1;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        *this -= 1;
        return temp;
    }
std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char slash;
    int whole = 0;
    int numerator = 0;
    int denominator = 1;

    // Peek to see if the next character is a digit or a minus sign (for negative numbers)
    if (isdigit(in.peek()) || in.peek() == '-') {
        // Read the whole part if present
        in >> whole;

        // Check if the next character is a plus sign indicating a mixed fraction
        if (in.peek() == '+') {
            in.ignore(); // Ignore the plus sign
            in >> numerator >> slash >> denominator;
            numerator += whole * denominator; // Add the whole part to the numerator
        } else if (in.peek() == '/') {
            // If no whole part, directly read numerator and denominator
            in.ignore(); // Ignore the slash
            in >> numerator >> slash >> denominator;
        } else {
            // If no slash, it's a whole number
            numerator = whole;
        }
    } else {
        // If the next character is not a digit or minus sign, it's not a valid fraction
        // Set fraction to 0
        fraction.numerator = 0;
        fraction.denominator = 1;
        return in;
    }

    // Update the fraction
    fraction.numerator = numerator;
    fraction.denominator = denominator;
    fraction.simplify(); // Simplify the fraction after reading
    return in;
}



   void Fraction::simplify() {
    // Handle negative fractions
    if (denominator < 0) {
        // Ensure denominator is positive
        numerator *= -1;
        denominator *= -1;
    }
    
    // Find the greatest common divisor (GCD) using Euclid's algorithm
    int a = std::abs(numerator);
    int b = std::abs(denominator);
    int gcd_val = 1;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd_val = a;
    
    // Reduce the fraction using GCD
    numerator /= gcd_val;
    denominator /= gcd_val;
}
 


  

} // namespace cs10b_fraction
