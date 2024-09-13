#include "array.h"
#include "number.h"
#include <iostream>
#include <cmath>

TArray::TArray()
{
    sortMode = ESortModeUp;
    arr = new number[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = 0;
    }

}

ostream& operator<< (ostream& os, TArray& array)
{
    os << "{" << array.arr[0];
    for (int i = 1; i < array.len; i++)
    {
        os << " " <<array.arr[i];
    }
    os << "}" << endl;
    return os;
}

int TArray::aver()
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    average = sum/len;


    double temp = 0;
    for (int i = 0; i < len; i++)
    {
        temp += pow((arr[i] - average),2);
    }
    sko = pow((temp/(len-1)),0.5);

}

void TArray::setSortMode(ESortMode m)
{
    sortMode = m;
}

void TArray::sortArr()
{
    number temp;
    if (sortMode == ESortModeUp)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len;j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len;j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

void TArray::changeItem(int index, number item)
{
    arr[index] = item;
}

