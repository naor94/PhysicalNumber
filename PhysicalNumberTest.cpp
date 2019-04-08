/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  bool flag = false;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber z(100, Unit::CM);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    PhysicalNumber y(6, Unit::SEC);
    PhysicalNumber p(1, Unit::TON);
    PhysicalNumber q(30, Unit::KG);
    PhysicalNumber r(30, Unit::G);

    PhysicalNumber a1(2, Unit::KM);
    PhysicalNumber b1(300, Unit::M);
    PhysicalNumber c1(100, Unit::CM);
    PhysicalNumber d1(2, Unit::HOUR);
    PhysicalNumber e1(30, Unit::MIN);
    PhysicalNumber f1(6, Unit::SEC);
    PhysicalNumber g1(1, Unit::TON);
    PhysicalNumber h1(30, Unit::KG);
    PhysicalNumber i1(30, Unit::G);

    testcase
    //simple output check
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(z, "100[cm]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(y, "6[sec]")
    .CHECK_OUTPUT(p, "1[ton]")
    .CHECK_OUTPUT(q, "30[kg]")
    .CHECK_OUTPUT(r, "30[g]")

      // lengh test - in the 'famely'
    .setname("onars operators Compatible dimensions - length check:")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(b+z, "301[m]")
    .CHECK_OUTPUT(z+a, "230100[cm]")
    .CHECK_OUTPUT((b-=b), "0[m]")
    .CHECK_OUTPUT(a-b, "2.3[km]")
    .CHECK_OUTPUT(-b, "0[m]")
    .CHECK_OUTPUT(-a, "-2.3[km]")
    .CHECK_OUTPUT(+b, "0[m]")
    .CHECK_OUTPUT(+a, "2.3[km]")

    // mass test - in the 'famely'

     .setname("Compatible dimensions - mass check: ")
     .CHECK_OUTPUT(p+q, "1.03[ton]")
     .CHECK_OUTPUT(p+r, "1.00003[ton]")
     .CHECK_OUTPUT(q+p, "1030[kg]")
     .CHECK_OUTPUT(r+q, "30030[g]")
     .CHECK_OUTPUT(r-r, "0[g]")
     .CHECK_OUTPUT((r+=q), "30030[g]")
     .CHECK_OUTPUT((q+=p), "1030[kg]")
     .CHECK_OUTPUT((r-=r), "0[g]")
     .CHECK_OUTPUT(-r, "0[g]")
     .CHECK_OUTPUT(+r, "0[g]")
     .CHECK_OUTPUT(-q, "-1030[kg]")
     .CHECK_OUTPUT(+q, "1030[kg]")

     // time test - in the 'famely'

     .setname("Compatible dimensions - time check: ")
     .CHECK_OUTPUT(c+d, "2.5[hour]")
     .CHECK_OUTPUT(c+y, "2.00167[hour]")
     .CHECK_OUTPUT((c+=c), "4[hour]")
     .CHECK_OUTPUT(d+c, "270[min]")
     .CHECK_OUTPUT(d+y, "30.1[min]")
     .CHECK_OUTPUT(y+c, "14406[sec]")
     .CHECK_OUTPUT((d+=y), "30.1[min]")
     .CHECK_OUTPUT(d-d, "0[min]")
     .CHECK_OUTPUT((d-=d), "0[min]")
     .CHECK_OUTPUT(+d, "0[min]")
     .CHECK_OUTPUT(-d, "0[min]")
     .CHECK_OUTPUT(+y, "6[sec]")

     .setname("boolean operators: \n")
     .setname("Compatible dimensions - length check: ")
     .CHECK_EQUAL(b>a, false)
     .CHECK_EQUAL(a>b, true)
     .CHECK_EQUAL((a<=a), true)
     .CHECK_EQUAL(b<z, false)
     .CHECK_EQUAL((z>=a), false)

     .setname("Compatible dimensions - mass check: ")
    .CHECK_EQUAL(p>q, true)
    .CHECK_EQUAL(p<r, false)
    .CHECK_EQUAL(q==p, false)
    .CHECK_EQUAL(r<=q, true)
    .CHECK_EQUAL(r==r, true)
    .CHECK_EQUAL(r!=r, false)
    .CHECK_EQUAL(r>=q, false)
    .CHECK_EQUAL(q>p, false)

    .setname("Compatible dimensions - time check: ")
    .CHECK_EQUAL(c>d, true)
    .CHECK_EQUAL(c<y, false)
    .CHECK_EQUAL(c==c, true)
    .CHECK_EQUAL(d>=c, false)
    .CHECK_EQUAL(d>=y, true)
    .CHECK_EQUAL(d!=y, true)
    .CHECK_EQUAL(y<=c, true)
    .CHECK_EQUAL(c<=y, false)

    .setname("\n")
    .setname("Incompatible dimensions - length to others")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(flag=a<c)
    .CHECK_THROWS(flag=b>c)
    .CHECK_THROWS(flag=a==c)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)
    .CHECK_THROWS(a+p)
    .CHECK_THROWS(z+r)
    .CHECK_THROWS(flag=z<r)
    //
    .setname("Incompatible dimensions - time to others")
    .CHECK_THROWS(c+a)
    .CHECK_THROWS(c+b)
    .CHECK_THROWS(flag=c<a)
    .CHECK_THROWS(flag=c>b)
    .CHECK_THROWS(flag=c==a)
    .CHECK_THROWS(y+r)
    .CHECK_THROWS(d+b)
    .CHECK_THROWS(b+q)
    .CHECK_THROWS(y+z)
    .CHECK_THROWS(flag=y<z)
    //
    .setname("Incompatible dimensions - mass to others")
    .CHECK_THROWS(p+c)
    .CHECK_THROWS(p+a)
    .CHECK_THROWS(flag=p<c)
    .CHECK_THROWS(flag=p>a)
    .CHECK_THROWS(flag=p==c)
    .CHECK_THROWS(q+d)
    .CHECK_THROWS(q+y)
    .CHECK_THROWS(r+d)
    .CHECK_THROWS(r+z)
    .CHECK_THROWS(p+c)
    .CHECK_THROWS(flag=p>c)

    .setname("plus and minus by 1 all dimensions")
    .CHECK_OUTPUT(a1++, "2[km]")
    .CHECK_OUTPUT(a1, "3[km]")
    .CHECK_OUTPUT(--a1, "2[km]")
    .CHECK_OUTPUT(b1--, "300[m]")
    .CHECK_OUTPUT(b1, "299[m]")
    .CHECK_OUTPUT(--b1, "298[m]")
    .CHECK_OUTPUT(c1++, "100[cm]")
    .CHECK_OUTPUT(c1--, "101[cm]")
    .CHECK_OUTPUT(++c1, "101[cm]")
    .CHECK_OUTPUT(d1++, "2[hour]")
    .CHECK_OUTPUT(--d1, "2[hour]")
    .CHECK_OUTPUT(d1--, "2[hour]")
    .CHECK_OUTPUT(++e1, "31[min]")
    .CHECK_OUTPUT(--e1, "30[min]")
    .CHECK_OUTPUT(e1--, "30[min]")
    .CHECK_OUTPUT(f1++, "6[sec]")
    .CHECK_OUTPUT(f1, "7[sec]")
    .CHECK_OUTPUT(++f1, "8[sec]")
    .CHECK_OUTPUT(g1++, "1[ton]")
    .CHECK_OUTPUT(g1--, "2[ton]")
    .CHECK_OUTPUT(h1++, "30[kg]")
    .CHECK_OUTPUT(h1--, "31[kg]")
    .CHECK_OUTPUT(++h1, "31[kg]")
    .CHECK_OUTPUT(--i1, "29[g]")
    .CHECK_OUTPUT(i1++, "29[g]")
    .CHECK_OUTPUT(i1--, "30[g]")


    .setname("\n Basic input")
    .CHECK_OK(istringstream("700[kg]") >> q)
    .CHECK_OUTPUT(q, "700[kg]")
    .CHECK_OUTPUT((q += PhysicalNumber(1, Unit::TON)), "1700[kg]")
    .CHECK_THROWS(istringstream("seven[kg]") >> q)

    .CHECK_OK(istringstream("1[min]") >> e1)
    .CHECK_OUTPUT(e1, "1[min]")
    .CHECK_THROWS(istringstream("4[kaubanga]") >> e1)

    .CHECK_OK(istringstream("1[m]") >> b)
    .CHECK_OUTPUT(e1, "1[m]")
    .CHECK_THROWS(istringstream("4[garusis]") >> b)

      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
