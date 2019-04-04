#include <iostream>
#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;


PhysicalNumber::PhysicalNumber(double value, Unit u){
    this->val=value;
    this->type=u;
    
}
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p)const{
return *this;
}

PhysicalNumber& PhysicalNumber :: operator+=(const PhysicalNumber& p){
    return *this;
}
const PhysicalNumber PhysicalNumber:: operator+()const{
    return *this;
}
const PhysicalNumber PhysicalNumber:: operator-(const PhysicalNumber& p) const{
    return *this;
}
PhysicalNumber& PhysicalNumber:: operator-=(const PhysicalNumber& p){
    return *this;
}
const PhysicalNumber PhysicalNumber:: operator-()const{
    return *this;
}
bool ariel:: operator>(const PhysicalNumber& p1, const PhysicalNumber& p2){
    return true;
}
bool ariel:: operator<(const PhysicalNumber& p1, const PhysicalNumber& p2){
    return true;
 
}
 bool ariel::  operator>=(const PhysicalNumber& p1, const PhysicalNumber& p2){
     return false;
 }
 bool ariel::  operator<=(const PhysicalNumber& p1, const PhysicalNumber& p2){
     return false;
 }
 bool ariel::  operator!=(const PhysicalNumber& p1, const PhysicalNumber& p2){
     return true;
 }
 bool ariel:: operator==(const PhysicalNumber& p1, const PhysicalNumber& p2){
     return true;
 }
 PhysicalNumber& PhysicalNumber::  operator++(){
return *this;
 }
    //postfix
    const PhysicalNumber PhysicalNumber:: operator++(int x){
        return *this;

    }

    //prefix
    PhysicalNumber& PhysicalNumber:: operator--(){
        return *this;

    }
    //postfix
    const PhysicalNumber PhysicalNumber::  operator--(int x){
        return *this;

    }
    // i/o stream
     ostream& ariel::operator<<(ostream& os, const PhysicalNumber& p){
         return os;

    }
     istream& ariel:: operator>>(istream& is, PhysicalNumber& p){
         return is;

    }



// int main(){
//     PhysicalNumber p(5,Unit::KM);
//     cout<<p.type<<endl;
//     return 0;
// }

