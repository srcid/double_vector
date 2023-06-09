#include<algorithm>

#include"double_vector.h"

using namespace std;


DoubleVector::DoubleVector(int capacity) : capacity(capacity), size(0)
{
    head = capacity / 2;
    tail = head + 1;
    list = vector<int>(capacity, 0);
}

DoubleVector::~DoubleVector()
{
}

void DoubleVector::right_shift(int n) {
    rotate(list.rbegin(), list.rbegin() + n, list.rend());
    head += n;
    tail += n;

    return;
}

void DoubleVector::left_shift(int n) {
    rotate(list.begin(), list.begin() + n, list.end());
    head -= n;
    tail -= n;

    return;
}