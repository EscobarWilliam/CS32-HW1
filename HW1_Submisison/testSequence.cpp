//
//  testSequence.cpp
//  HW1
//
//  Created by William  Escobar on 4/17/23.
//
#define TESTNUM 1

// (If you know how to specify a value for TESTNUM at the time you invoke the
// compiler, using either a project setting in Visual C++ or Xcode or by
// defining the value on the command line, you could leave the #define line
// above commented out and instead set TESTNUM that other way.)

#ifndef TESTNUM  // In case you haven't already defined the name TESTNUM
#define TESTNUM 0
#endif

#if TESTNUM == 1

//for this test, make sure that ItemType is: std::string
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    s.insert(0, 10);
    s.insert(0, 20);
    assert(s.size() == 2);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}

#elif TESTNUM == 2

//for this test, make sure that ItemType is: unsigned long
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    s.insert(0, 10);
    s.insert(0, 20);
    assert(s.size() == 2);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}

#elif TESTNUM == 3

//for this test, make sure that ItemType is: std::string
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    //tests constructor, insert(), get(), and remove() functions
    Sequence s;
        s.insert(0, "a");
        s.insert(1, "b");
        s.insert(2, "e");
        s.insert(3, "b");
        s.insert(4, "c");
        assert(s.remove("b") == 2);
        assert(s.size() == 3);
        string x;
        assert(s.get(0, x)  &&  x == "a");
        assert(s.get(1, x)  &&  x == "e");
        assert(s.get(2, x)  &&  x == "c");
//*******************************************************
//    Test of the swap() function
    Sequence s1;
        s1.insert(0, "paratha");
        s1.insert(0, "focaccia");
    Sequence s2;
        s2.insert(0, "roti");
        s1.swap(s2);
        assert(s1.size() == 1  &&  s1.find("roti") == 0  &&  s2.size() == 2  &&
                    s2.find("focaccia") == 0  &&  s2.find("paratha") == 1);
//*******************************************************
    //tests the user input, and empty string "" is accepted
    Sequence r;
        r.insert(0, "dosa");
        r.insert(1, "pita");
        r.insert(2, "");
        r.insert(3, "matzo");
        assert(r.find("") == 2);
        r.remove("dosa");
        assert(r.size() == 3  &&  r.find("pita") == 0  &&  r.find("") == 1  &&
                    r.find("matzo") == 2);
    std::cout << "Passed all tests." << std::endl;
    return 0;
}

#else  // use original main.cpp
int main()
{
    return 0;
}
#endif
