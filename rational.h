#include <ostream>
#include <istream>

class RationalFrac final {
    public:
        RationalFrac(int denominatior = 0, int numerator = 1);

        int get_numerator();
        int get_denominator();
        void simplify();
        static int GCD(int a, int b);

        RationalFrac operator+(const RationalFrac& other) const;
        RationalFrac operator-(const RationalFrac& other) const;
        RationalFrac operator*(const RationalFrac& other) const;
        RationalFrac operator/(const RationalFrac& other) const;
        
        RationalFrac& operator+=(const RationalFrac& other);    
        RationalFrac& operator-=(const RationalFrac& other);    

        RationalFrac& operator++();
        RationalFrac operator++(int);
        RationalFrac& operator--();
        RationalFrac operator--(int);

        bool operator<(const RationalFrac &frac) const;
        bool operator>(const RationalFrac &frac) const;
        bool operator==(const RationalFrac &frac) const;
        bool operator<=(const RationalFrac &frac) const;
        bool operator>=(const RationalFrac &frac) const;
        bool operator!=(const RationalFrac &frac) const;

        friend std::ostream& operator<<(std::ostream& os, const RationalFrac& frac);
        friend std::istream& operator>>(std::istream& is, RationalFrac& frac);

    private:
        int denom_, numer_;

};

