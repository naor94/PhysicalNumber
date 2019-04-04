#include <iostream>
#include "Unit.h"

using namespace std;

namespace ariel{
    class PhysicalNumber;
}

class  ariel::PhysicalNumber{
    double val;
    Unit type;

    public:
    //constructor
    PhysicalNumber(double value, Unit u);

    //operators
    const PhysicalNumber operator+(const PhysicalNumber&) const;
    PhysicalNumber& operator+=(const PhysicalNumber&);
    //unary +
    const PhysicalNumber operator+()const;
    const PhysicalNumber operator-(const PhysicalNumber&) const;
    PhysicalNumber& operator-=(const PhysicalNumber&);
    //unary -
    const PhysicalNumber operator-()const;
    // 6 comparison operators
    friend bool operator>(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator<(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator>=(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator<=(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator!=(const PhysicalNumber&, const PhysicalNumber&);
    friend bool operator==(const PhysicalNumber&, const PhysicalNumber&);


    //prefix
    PhysicalNumber& operator++();
    //postfix
    const PhysicalNumber operator++(int);

    //prefix
    PhysicalNumber& operator--();
    //postfix
    const PhysicalNumber operator--(int);
    // i/o stream
    friend ostream& operator<<(ostream& os, const PhysicalNumber& p); 
    friend istream& operator>>(istream& is, PhysicalNumber& p);


    
};