#include <iostream>
#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;


PhysicalNumber::PhysicalNumber(double value, Unit u){
    this->val=value;
    this->type=u;
    
}

const double PhysicalNumber:: typeConvertor(const PhysicalNumber& p) const{
    switch (type)
    {
        case Unit::KM:
        if(p.type==Unit::KM)return 1*p.val;
        if(p.type==Unit::M) return 0.001*p.val;
        if(p.type==Unit::CM) return 0.00001*p.val;
        break;

        case Unit::M:
        if(p.type==Unit::KM) return 1000*p.val;
        if(p.type==Unit::M) return 1*p.val;
        if(p.type==Unit::CM) return 0.01*p.val;
        break;

        case Unit::CM:
        if(p.type==Unit::KM) return 100000*p.val;
        if(p.type==Unit::M) return 100*p.val;
        if(p.type==Unit::CM) return 1*p.val;
        break;

        case Unit::HOUR:
        if(p.type==Unit::HOUR) return 1*p.val;
        if(p.type==Unit::MIN) return 0.016666666666667 *p.val;
        if(p.type==Unit::SEC) return 0.00027777777777778*p.val;
        break;

        case Unit::MIN:
        if(p.type==Unit::HOUR) return 60*p.val;
        if(p.type==Unit::MIN) return 1*p.val;
        if(p.type==Unit::SEC) return 0.016666666666667 *p.val;
        break;

        case Unit::SEC:
        if(p.type==Unit::HOUR) return 3600*p.val;
        if(p.type==Unit::MIN) return 60*p.val;
        if(p.type==Unit::SEC) return 1 *p.val;
        break;

        case Unit::TON:
        if(p.type==Unit::TON) return 1*p.val;
        if(p.type==Unit::KG) return 0.001*p.val;
        if(p.type==Unit::G) return 0.000001 *p.val;
        break;

        case Unit::KG:
        if(p.type==Unit::TON) return 1000*p.val;
        if(p.type==Unit::KG) return 1*p.val;
        if(p.type==Unit::G) return 0.001 *p.val;
        break;

        case Unit::G:
        if(p.type==Unit::TON) return 1000000*p.val;
        if(p.type==Unit::KG) return 1000*p.val;
        if(p.type==Unit::G) return 1 *p.val;
        break;



    
        default:
            break;
    }

}

    const bool PhysicalNumber::isSameDeminsion(const PhysicalNumber& p ) const{
        if((this->type==Unit::KM||this->type==Unit::M||this->type==Unit::CM)
        &&(p.type==Unit::KM||p.type==Unit::M||p.type==Unit::CM))return true;
        else if((this->type==Unit::HOUR||this->type==Unit::MIN||this->type==Unit::SEC)
        &&(p.type==Unit::HOUR||p.type==Unit::MIN||p.type==Unit::SEC))return true;
        else if((this->type==Unit::TON||this->type==Unit::KG||this->type==Unit::G)
        &&(p.type==Unit::TON||p.type==Unit::KG||p.type==Unit::G)) return true;
        else return false;
    }



const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p)const{
if(!isSameDeminsion(p)){
   throw "not same dimention";
}
else{
    double con=typeConvertor(p);
    return PhysicalNumber(this->val+con,this->type);
    }
   
}

PhysicalNumber& PhysicalNumber :: operator+=(const PhysicalNumber& p){
   if(!isSameDeminsion(p)){
   throw "not same dimention";
   }
   else{
    double con=typeConvertor(p);
    this->val+=con;

   }
   return *this;

}
const PhysicalNumber PhysicalNumber:: operator+()const{
    return *this;
}
const PhysicalNumber PhysicalNumber:: operator-(const PhysicalNumber& p) const{
if(!isSameDeminsion(p)){
   throw "not same dimention";
}
else{
    double con=typeConvertor(p);
    return PhysicalNumber(this->val-con,this->type);
}
   
}



PhysicalNumber& PhysicalNumber:: operator-=(const PhysicalNumber& p){
 if(!isSameDeminsion(p)){
   throw "not same dimention";
   }
   else{
    double con=typeConvertor(p);
    this->val-=con;

   }
   return *this;

}
const PhysicalNumber PhysicalNumber:: operator-()const{
    if(this->val==0){
        return *this;
    }
    else return PhysicalNumber(this->val*-1,this->type);
}
bool ariel:: operator>(const PhysicalNumber& p1, const PhysicalNumber& p2){
 if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);
    return (p1.val>con);
   }

}
bool ariel:: operator<(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);
    return (p1.val<con);
   }

} 

 bool ariel::  operator>=(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);

    return (p1.val>=con);
   }

} 
 bool ariel::  operator<=(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);

    return (p1.val<=con);
   }

} 

 bool ariel::  operator!=(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);

    return (p1.val!=con);
   }

} 
 
 bool ariel:: operator==(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);
    
    return (p1.val==con);
   }
 }
 //prefix
 PhysicalNumber& PhysicalNumber::  operator++(){
     this->val++;
     return *this;
 }
    //postfix
    const PhysicalNumber PhysicalNumber:: operator++(int x){
        PhysicalNumber copy= *this;
        this->val++;
        return copy;
    }

    //prefix
    PhysicalNumber& PhysicalNumber:: operator--(){
        this->val--; 
        return *this;

    }
    //postfix
    const PhysicalNumber PhysicalNumber::  operator--(int x){
        PhysicalNumber copy= *this;
        this->val--;
        return copy;

    }
    // i/o stream
     ostream& ariel::operator<<(ostream& os, const PhysicalNumber& p){
         switch (p.type)
         {
             case Unit::KM:
                 os<<p.val<<"[km]";
                 return os;
                 break;
             case Unit::M:
                 os<<p.val<<"[m]";
                 return os;
                 break;
              case Unit::CM:
                 os<<p.val<<"[cm]";
                 return os;
                 break;
            case Unit::TON:
                 os<<p.val<<"[ton]";
                 return os;
                 break;
            case Unit::KG:
                 os<<p.val<<"[kg]";
                 return os;
                 break;
            case Unit::G:
                 os<<p.val<<"[g]";
                 return os;
                 break;
            case Unit::HOUR:
                 os<<p.val<<"[hour]";
                 return os;
                 break;
            case Unit::MIN:
                 os<<p.val<<"[min]";
                 return os;
                 break;
            case Unit::SEC:
                 os<<p.val<<"[sec]";
                 return os;
                 break;
         }
         
         return os;

    }
     istream& ariel:: operator>>(istream& is, PhysicalNumber& p){

        //  char tmp1;
        //  char tmp2;
        //  is>>p.val>>tmp1>>p.type>>tmp2;

         return is;

    }



// int main(){
  
//     PhysicalNumber x(1,Unit::KG);
//     PhysicalNumber y(2000,Unit::G);
//     bool z=(y>x);
//     if(z==true){
//         cout<<"true"<<endl;
//     }
//     else{
//         cout<<"false"<<endl;
//     }

   


//  }

