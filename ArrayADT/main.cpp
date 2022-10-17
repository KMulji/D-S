
#include <iostream>
#include "./ArrayADT.hpp"
#include <unistd.h>
int main()
{
    ArrayADT x = ArrayADT();
    x.Append(5);
    x.Append(7);
    x.Append(7);
    x.Append(8);
    x.Append(8);
    x.Append(10);
    x.Display();
    std::cout<<x.BinLeftMost(8)<<std::endl;

    
    
    
    return 0;
}