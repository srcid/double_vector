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
