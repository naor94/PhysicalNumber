#include <iostream>
#include "PhysicalNumber.h"
using namespace ariel;
using namespace std;

//constructor
PhysicalNumber::PhysicalNumber(double value, Unit u){
    this->val=value;
    this->type=u;
 }

//convertor
const double PhysicalNumber:: typeConvertor(const PhysicalNumber& p) const{
    switch (type) // cases by units
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
        if(p.type==Unit::MIN) return p.val/60;
        if(p.type==Unit::SEC) return p.val/3600;
        break;

        case Unit::MIN:
        if(p.type==Unit::HOUR) return 60*p.val;
        if(p.type==Unit::MIN) return 1*p.val;
        if(p.type==Unit::SEC) return p.val/60;
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
//  compare between dimentionss
    const bool PhysicalNumber::isSameDeminsion(const PhysicalNumber& p ) const{
        if((this->type==Unit::KM||this->type==Unit::M||this->type==Unit::CM)
        &&(p.type==Unit::KM||p.type==Unit::M||p.type==Unit::CM))return true;
        else if((this->type==Unit::HOUR||this->type==Unit::MIN||this->type==Unit::SEC)
        &&(p.type==Unit::HOUR||p.type==Unit::MIN||p.type==Unit::SEC))return true;
        else if((this->type==Unit::TON||this->type==Unit::KG||this->type==Unit::G)
        &&(p.type==Unit::TON||p.type==Unit::KG||p.type==Unit::G)) return true;
        else return false;
    }


// operator +
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p)const{
if(!isSameDeminsion(p)){ //dimention check	
   throw "not same dimention";
}
else{
    double con=typeConvertor(p);
    return PhysicalNumber(this->val+con,this->type);
    }
   
}

// operator +=
PhysicalNumber& PhysicalNumber :: operator+=(const PhysicalNumber& p){
   if(!isSameDeminsion(p)){ //dimention check
   throw "not same dimention";
   }
   else{
    double con=typeConvertor(p);
    this->val+=con;

   }
   return *this;

}

// onar +
const PhysicalNumber PhysicalNumber:: operator+()const{
    return *this;
}

// operator -
const PhysicalNumber PhysicalNumber:: operator-(const PhysicalNumber& p) const{
if(!isSameDeminsion(p)){ //dimention check
   throw "not same dimention";
}
else{
    double con=typeConvertor(p);
    return PhysicalNumber(this->val-con,this->type);
}
   
}

//operator -=
PhysicalNumber& PhysicalNumber:: operator-=(const PhysicalNumber& p){
 if(!isSameDeminsion(p)){ // dimention check
   throw "not same dimention";
   }
   else{
    double con=typeConvertor(p);
    this->val-=con;

   }
   return *this;

}

//onar -
const PhysicalNumber PhysicalNumber:: operator-()const{
    if(this->val==0){
        return *this;
    }
    else return PhysicalNumber(this->val*-1,this->type);
}
// operator >
bool ariel:: operator>(const PhysicalNumber& p1, const PhysicalNumber& p2){
 if(!p1.isSameDeminsion(p2)){ //dimention check
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);
    return (p1.val>con);
   }

}
// operator <
bool ariel:: operator<(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){ // //dimention check
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);
    return (p1.val<con);
   }

} 

//operator >=
 bool ariel::  operator>=(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){ //dimention check
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);

    return (p1.val>=con);
   }

} 

// operator <=
 bool ariel::  operator<=(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){//dimention check
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);

    return (p1.val<=con);
   }

} 
// operator !=
 bool ariel::  operator!=(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);

    return (p1.val!=con);
   }

} 
 //operator ==
 bool ariel:: operator==(const PhysicalNumber& p1, const PhysicalNumber& p2){
if(!p1.isSameDeminsion(p2)){
   throw "not same dimention";
   }
   else{
    double con=p1.typeConvertor(p2);
    
    return (p1.val==con);
   }
 }
 //prefix ++
 PhysicalNumber& PhysicalNumber::  operator++(){
     this->val++;
     return *this;
 }
    //postfix ++
    const PhysicalNumber PhysicalNumber:: operator++(int x){
        PhysicalNumber copy= *this;
        this->val++;
        return copy;
    }

    //prefix --
    PhysicalNumber& PhysicalNumber:: operator--(){
        this->val--; 
        return *this;

    }
    //postfix --
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
// output
    istream& ariel:: operator>>(istream& is, PhysicalNumber& p){

    string ans;
    double new_val;
    is>>ans;
    bool error = false;
    int firstClose = ans.find("[");
    int secondClose= ans.find("]");
    if(firstClose<=0||secondClose<0||secondClose!=ans.length()-1) error = true;
   
    if (error) auto errorState = is.rdstate();
    else {
          try {
             new_val = stod(ans.substr(0,firstClose));
	  }
	  catch (exception &e) { 
		  auto errorState = is.rdstate();
		  return is;
	  }
          string new_Unit=ans.substr(firstClose+1,secondClose-firstClose-1);	
          if(new_Unit.compare("cm")== 0 || new_Unit.compare("CM")== 0) {
		  p.type = Unit::CM;
		  p.val=new_val;  
	  }
          else if (new_Unit.compare("m")== 0 || new_Unit.compare("M")== 0) {
		 p.type= Unit::M;
		  p.val=new_val;  
	  }
          else if (new_Unit.compare("km")== 0 || new_Unit.compare("KM")== 0) {
		  p.type = Unit::KM;
		  p.val=new_val;  
	  }
          else if (new_Unit.compare("sec")== 0 || new_Unit.compare("SEC")== 0) {
		  p.type = Unit::SEC;
		  p.val=new_val;
	  }
          else if (new_Unit.compare("min")== 0 || new_Unit.compare("MIN")== 0) {
		  p.type = Unit::MIN;
		  p.val=new_val;
	  }
          else if (new_Unit.compare("hour")== 0 || new_Unit.compare("HOUR")== 0) {
		  p.type = Unit::HOUR;
		  p.val=new_val;
	  }
          else if (new_Unit.compare("g")== 0 || new_Unit.compare("G")== 0) {
		  p.type= Unit::G;
		  p.val=new_val;
	  }
          else if (new_Unit.compare("kg")== 0 || new_Unit.compare("KG")== 0) {
		  p.type = Unit::KG;
		  p.val=new_val;
	  }
          else if (new_Unit.compare("ton")== 0 || new_Unit.compare("TON")== 0) {
		  p.type = Unit::TON;
		  p.val=new_val;
	  }
          else  auto errorState = is.rdstate();
    }  
    return is;
  }
	    




	     
	     
	     
	     
	     


