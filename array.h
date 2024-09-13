#ifndef TARRAY_H
#define TARRAY_H
#include "number.h"
#include "iostream"
using namespace std;

enum ESortMode
{
    ESortModeUp,
    ESortModeDown,
};

class TArray
{
    ESortMode sortMode;
public:


    TArray();
    friend ostream& operator<< (ostream&, TArray&);

    number sko, average;
    int aver();

    number *arr;
    unsigned int len;

    void setSortMode(ESortMode);
    void sortArr();
    void changeItem(int, number);
};

#endif // TARRAY_H
