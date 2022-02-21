#include <iostream>
#include <string>
#include "a1-global.cc"

int main(){
    //test (a)
    Date d1(2020,1,24,11,3);
    Date d2(2020,1,23,11,3);
    testDate(d1, d2, false);

    //test (b)
    d1.setDate(2020,1,24,0,3);
    d2.setDate(2020,1,24,4,3);
    testDate(d1, d2, false);

    //test (c)
    d1.setDate(2020,1,24,12,1);
    d2.setDate(2020,1,24,13,3);
    testDate(d1, d2, false);

    //test (d)
    d1.setDate(2020,1,24,12,2);
    d2.setDate(2020,1,24,13,1);
    testDate(d1, d2, true);

    //test(e)
    d1.setDate(2020,1,24,13,1);
    testDate(d1, d2, true);
    cout<<endl;
    
    Library l1 = Library();
    populate(l1);
    testReservations(l1);
    
    //uncomment below to see all objects present in the library
    //l1.print();
    return 0;
}
