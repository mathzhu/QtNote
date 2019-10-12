#include "cplusplus.h"


CPlusPlus::CPlusPlus()
{
    errmsg({"hello", "world"});
}

void CPlusPlus::msg(...){

}
void CPlusPlus::errmsg(initializer_list<string> l1){
    for(auto begin = l1.begin(); begin != l1.end(); ++begin)
       cout  << *begin << endl;
}
