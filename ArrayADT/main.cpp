
#include <iostream>
#include "./ArrayADT.hpp"

int main()
{
    ArrayADT x =  ArrayADT();
    for(int i=0;i<10;i++)
    {
        x.Append(i+1);
    }
    for(int i=0;i<10;i++)
    {
        std::cout<<x[i]<<std::endl;
    }
    std::cout<<x[10]<<std::endl;
    
    return 0;
}