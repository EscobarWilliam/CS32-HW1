
//
//  testnewSequence.cpp
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

#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Sequence a(1000);   // a can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
    ItemType v = 10;
    //Sequence t(-1);    //tests that we can't make a sequnce of an negative size

        // No failures inserting 5 items into b
    for (int k = 0; k < 5; k++)
        assert(b.insert(v) != -1);

        // Failure if we try to insert a sixth item into b
    assert(b.insert(v) == -1);

           // When two Sequences' contents are swapped, their capacities are
           // swapped as well:
    a.swap(b);
    assert(a.insert(v) == -1  &&  b.insert(v) != -1);

    //tests constructor, insert(), get(), and remove() functions
    Sequence s;
        s.insert(0, 1);
        s.insert(1, 2);
        s.insert(2, 5);
        s.insert(3, 2);
        s.insert(4, 3);
        assert(s.remove(2) == 2);
        assert(s.size() == 3);
        unsigned long x;
        assert(s.get(0, x)  &&  x == 1);
        assert(s.get(1, x)  &&  x == 5);
        assert(s.get(2, x)  &&  x == 3);
//*******************************************************
    //Test of the swap() function
    Sequence s1;
        s1.insert(0, 100);
        s1.insert(0, 90);
    Sequence s2;
        s2.insert(0, 110);
        s1.swap(s2);
        assert(s1.size() == 1  &&  s1.find(110) == 0  &&  s2.size() == 2  &&
                    s2.find(90) == 0  &&  s2.find(100) == 1);
//*******************************************************
    //For this test make sure: ItemType = unsigned long
    //This tests if ItemType was used with "using" statement
    Sequence r;
    assert(r.empty());
    assert(r.find(42) == -1);
    assert(r.insert(42) == 0);
    assert(r.size() == 1  &&  r.find(42) == 0);
    cout << "Passed all tests" << endl;


    return 0;
}

#elif TESTNUM == 2

#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    //tests the user input, and empty string "" is accepted
    Sequence s;
    s.insert(0, "dosa");
    s.insert(1, "pita");
    s.insert(2, "");
    s.insert(3, "matzo");
    assert(s.find("") == 2);
    s.remove("dosa");
    assert(s.size() == 3  &&  s.find("pita") == 0  &&  s.find("") == 1  &&
           s.find("matzo") == 2);
    //*******************************************************
    //For this test make sure: ItemType = std::string;
    Sequence s1;
    assert(s1.empty());
    assert(s1.find("laobing") == -1);
    assert(s1.insert("laobing") == 0);
    assert(s1.size() == 1  &&  s1.find("laobing") == 0);
    //s1.dump();
    cout << "Passed all tests" << endl;
    return 0;
}

#elif TESTNUM == 3

//For this test make sure: ItemType = std::string
#include "newSequence.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    s.insert(0, "lavash");
    s.insert(0, "tortilla");
    assert(s.size() == 2);
    ItemType x = "injera";
    assert(s.get(0, x) && x == "tortilla");
    assert(s.get(1, x) && x == "lavash");
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}

#elif TESTNUM == 4

//For this test make sure: ItemType = unsigned long
#include "newSequence.h"
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

#else
int main()
{
    return 0;
}
#endif

