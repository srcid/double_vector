#include<iostream>
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

void DoubleVector::alloc_left() 
{
    list.insert(list.begin(), capacity, 0);
    left_shift(capacity / 2);
    head += capacity;
    tail += capacity;
    capacity *= 2;
}

void DoubleVector::alloc_right()
{
    list.insert(list.end(), capacity, 0);
    right_shift(capacity / 2);
    capacity *= 2;
}

void DoubleVector::push_back(int n) 
{
    if (tail == capacity) {
        if (head == -1) { 
           alloc_right();
        } else { 
            int
                free_slots_in_left_side = head,
                delta = free_slots_in_left_side / 2 + 1;

                left_shift(delta);
        }
    }

    list[tail] = n;
    tail++;
    size++;
    
    return;
}

void DoubleVector::push_front(int n) 
{
    if (head == -1) {
        if (tail == capacity) { 
            alloc_left();
        } else { 
            int
                free_slots_in_right_side = capacity - tail,
                delta = free_slots_in_right_side / 2 + 1;
            right_shift(delta);
        }
    }

    list[head] = n;
    head--;
    size++;

    return;
}

void DoubleVector::removeAll()
{
    head = capacity / 2;
    tail = head + 1;
    size = 0;
}

bool DoubleVector::empty()
{
    return size == 0;
}

void DoubleVector::print()
{
    for (auto i = list.begin() + head + 1; i < list.begin() + capacity / 2; i++) {
            cout << *i << " ";
    }
    for (auto i = list.begin() + capacity / 2; i < list.begin() + tail; i++) {
            cout << *i << " ";
    }
    cout << endl;
}

int DoubleVector::at(int idx)
{
    if (idx > size - 1) {
        return -1;
    }

    return list[head + idx + 1];
    
}
