#ifndef ARRAYADT_HPP_
#define ARRAYADT_HPP_
class ArrayADT
{
private:
    int *arr;
    int size;
    int length;
    void Grow();
    void Shrink();
    void Swap(int *x, int *y);

public:
    ArrayADT();
    ArrayADT(int size);
    ArrayADT(const ArrayADT &other);
    int &operator[](int index);
    void Display();
    int GetLength();
    int GetSize();
    void Append(int x);
    void RightShift();
    void LeftShift();
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int x);
    int BinarySearch(int x);
    int BinLeftMost(int x);
    int BinRightMost(int x);
    ~ArrayADT();
};
#endif