#include<algorithm>
#include<stdexcept>

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

int DoubleVector::pop_back() 
{
    if (size == 0) {
        throw runtime_error("The list is empty");
    }

    int ans = list[tail - 1];
    tail--;
    size--;

    return ans;
}

int DoubleVector::pop_front() 
{
    if (size == 0) {
        throw runtime_error("The list is empty");
    }

    int ans = list[head + 1];
    head++;
    size--;

    return ans;
}
