#ifndef ARRAYADT_HPP_
#define ARRAYADT_HPP_
class ArrayADT
{
private:
    int *arr;
    int size;
    int length;

public:
    ArrayADT();
    ArrayADT(int size);
    ArrayADT(const ArrayADT &other);
    int& operator[] (int index);
     void Display();
    int GetLength();
    int GetSize();
    void Append(int x);
    ~ArrayADT();
};
#endif