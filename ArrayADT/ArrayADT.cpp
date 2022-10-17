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
int &ArrayADT::operator[](int index)
{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("out of range");
    }
    return arr[index];
}
ArrayADT::~ArrayADT()
{
    delete[] arr;
}
void ArrayADT::Grow()
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
void ArrayADT::Shrink()
{
    int *Buffer = new int[size / 2];
    size = size / 2;

    for (int i = 0; i < length; i++)
    {
        Buffer[i] = arr[i];
    }
    delete[] arr;
    arr = Buffer;
    Buffer = nullptr;
    delete Buffer;
}

void ArrayADT::Display()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
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
        Grow();
    }
    arr[length] = x;
    length++;
}
void ArrayADT::Insert(int index, int x)
{

    // 1 2 3 4 5 6 0
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("out of range");
        return;
    }

    Append(0);
    for (int i = length - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = x;
}
int ArrayADT::Delete(int index)
{
    if (size / 2 == length)
    {
        Shrink();
    }
    // 1 2 3 4 5 6 7 8 9
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("out of range");
        return -1;
    }
    int val = arr[index];
    for (int i = index; i < length - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    length--;
    return val;
}
int ArrayADT::LinearSearch(int x)
{

    for (int i = 0; i < length; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int ArrayADT::BinarySearch(int x)
{
    int lo = 0;
    int hi = length - 1;
    int mid = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        // should be on the right
        else if (x > arr[mid])
        {
            lo = mid + 1;
        }
        // should be on the left
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}
int ArrayADT::BinLeftMost(int x)
{
    int lo = 0;
    int hi = length - 1;
    int mid =0;
    int res=-1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == x)
        {
            res=mid;
            hi=mid-1;
        }
        // should be on the right
        else if (x > arr[mid])
        {
            lo = mid + 1;
        }
        // should be on the left
        else
        {
            hi = mid - 1;
        }
    }
    return res;
}
int ArrayADT::BinRightMost(int x)
{
    int lo = 0;
    int hi = length - 1;
    int mid =0;
    int res=-1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == x)
        {
            res=mid;
            lo=mid+1;
        }
        // should be on the right
        else if (x > arr[mid])
        {
            lo = mid + 1;
        }
        // should be on the left
        else
        {
            hi = mid - 1;
        }
    }
    return res;
}
void ArrayADT::Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void ArrayADT::RightShift()
{
    int end = arr[length - 1];
    // 1 2 3 4 5 6 7 8 9
    for (int i = length - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = end;
}
void ArrayADT::LeftShift()
{
    int start = arr[0];
    // 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < length - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = start;
}
