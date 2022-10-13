#include "ArrayADT.hpp"
#include <iostream>
ArrayADT::ArrayADT()
{
    this->arr = new int[1];
    if (this->arr)
    {
        this->size = 1;
        this->length = 0;
    }
}
ArrayADT::ArrayADT(int size)
{
    this->arr = new int[size];
    if (this->arr)
    {
        this->length = 0;
        this->size = size;
    }
}
ArrayADT::ArrayADT(const ArrayADT &other)
{
    this->size = other.size;
    this->length = other.length;
    this->arr = new int[other.size];

    for (int i = 0; i < other.size; i++)
    {
        this->arr[i] = other.arr[i];
    }
}
int& ArrayADT::operator[] (int index)
{
    if (index < 0 || index >= length){
        throw std::out_of_range ("out of range");
    }
    return arr[index];
}
ArrayADT::~ArrayADT()
{
    delete[] arr;
}

void ArrayADT::Display(){
    for(int i=0;i<length;i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
}
int ArrayADT::GetLength()
{
    return length;
}
int ArrayADT::GetSize()
{
    return size;
}

void ArrayADT::Append(int x)
{
    // if we reach capacity double the size;
    if (size == length)
    {
        // allocate a new buffer 2* size
        int NewSize = 2 * size;
        int *Buffer = new int[NewSize];
        // copy things into the buffer
        for (int i = 0; i < length; i++)
        {
            Buffer[i] = arr[i];
        }
        // free the old memory
        delete[] arr;
        // update our array adt with new size and new array
        size = NewSize;
        arr = Buffer;
        // remove buffer
        Buffer = nullptr;
        delete Buffer;
    }
    arr[length] = x;
    length++;
}
