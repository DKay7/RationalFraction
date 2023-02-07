#include "rational.h"
#include <stdexcept>
#include <iostream>

//--------------------------------------------------------------------------------

RationalFrac::RationalFrac(int numer_, int denominatior) : denom_(denominatior), numer_(numer_) {
    
    if (denom_ == 0)
        throw std::overflow_error("Zero division error");
    
    simplify();
}

//--------------------------------------------------------------------------------

void RationalFrac::simplify() {

    int gcd = GCD(numer_, denom_);
    numer_ /= gcd;
    denom_ /= gcd;

    if (denom_ < 0) {
        numer_ *= -1;
        denom_ *= -1;
    }
}

//--------------------------------------------------------------------------------

int RationalFrac::GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a % b);
}

//--------------------------------------------------------------------------------

int RationalFrac::get_numerator() {
    return numer_;
}

//--------------------------------------------------------------------------------

int RationalFrac::get_denominator() {
    return denom_;
}

//--------------------------------------------------------------------------------

RationalFrac& RationalFrac::operator+=(const RationalFrac& other) {    
    *this = RationalFrac {
        numer_ * other.denom_ + other.numer_ * denom_, 
        denom_ * other.denom_
    };

    return *this;
}

//--------------------------------------------------------------------------------

RationalFrac& RationalFrac::operator-=(const RationalFrac& other) {    
    *this = RationalFrac {
        numer_ * other.denom_ - other.numer_ * denom_, 
        denom_ * other.denom_
    };

    return *this;
}

//--------------------------------------------------------------------------------

RationalFrac RationalFrac::operator+(const RationalFrac& other) const {    
    RationalFrac temp = *this;
    return temp += other; 
}

//--------------------------------------------------------------------------------

RationalFrac RationalFrac::operator-(const RationalFrac& other) const {    
    RationalFrac temp = *this;
    return temp -= other;
}

//--------------------------------------------------------------------------------

RationalFrac RationalFrac::operator*(const RationalFrac& other) const {    
    return RationalFrac {
        numer_ * other.numer_, 
        denom_ * other.denom_
    };
}

//--------------------------------------------------------------------------------

RationalFrac RationalFrac::operator/(const RationalFrac& other) const {    
    return RationalFrac {
        numer_ * other.denom_, 
        denom_ * other.numer_
    };
}

//--------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const RationalFrac& frac) {
    os << frac.numer_ << " / " << frac.denom_ << "\n";

    return os;
}

//--------------------------------------------------------------------------------

std::istream& operator>>(std::istream& is, RationalFrac& frac) {
    int numer, denom;
    char sep;

    is >> numer >> sep >> denom;

    if (sep != '/') {
        is.setstate(std::ios_base::failbit);
        return is;
    }

    frac = RationalFrac(numer, denom);
    return is;
}

//--------------------------------------------------------------------------------

bool RationalFrac::operator<(const RationalFrac &frac) const {
    return numer_ * frac.denom_ < frac.numer_ * denom_;
}

//--------------------------------------------------------------------------------

bool RationalFrac::operator>(const RationalFrac &frac) const {
    return numer_ * frac.denom_ > frac.numer_ * denom_;
}

//--------------------------------------------------------------------------------

bool RationalFrac::operator==(const RationalFrac &frac) const {
    return numer_ * frac.denom_ == frac.numer_ * denom_;
}

//--------------------------------------------------------------------------------

bool RationalFrac::operator<=(const RationalFrac &frac) const {
    return numer_ * frac.denom_ <= frac.numer_ * denom_;
}

//--------------------------------------------------------------------------------

bool RationalFrac::operator>=(const RationalFrac &frac) const {
    return numer_ * frac.denom_ >= frac.numer_ * denom_;
}

//--------------------------------------------------------------------------------

bool RationalFrac::operator!=(const RationalFrac &frac) const {
    return numer_ * frac.denom_ != frac.numer_ * denom_;
}

//--------------------------------------------------------------------------------

RationalFrac& RationalFrac::operator++() {
    return *this += RationalFrac(1, 1);
}

//--------------------------------------------------------------------------------

RationalFrac RationalFrac::operator++(int) {
    RationalFrac temp = *this;
    ++(*this);

    return temp;
}

//--------------------------------------------------------------------------------

RationalFrac& RationalFrac::operator--() {
    return *this -= RationalFrac(1, 1);
}

//--------------------------------------------------------------------------------

RationalFrac RationalFrac::operator--(int) {
    RationalFrac temp = *this;
    --(*this);

    return temp;
}

//--------------------------------------------------------------------------------
