#ifndef CPLUSPLUS_H
#define CPLUSPLUS_H
#include <iostream>
using namespace std;
#include <string>
#include <initializer_list>

class CPlusPlus
{
public:
    CPlusPlus();
    void errmsg(initializer_list<string> l1);
    void msg(...);
};

#endif // CPLUSPLUS_H
