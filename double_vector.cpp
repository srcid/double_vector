#include<iostream>
#include<algorithm>
#include<stdexcept>

#include"double_vector.h"

using namespace std;

DoubleVector::DoubleVector(): m_capacity(16), m_size(0)
{
    m_head = m_capacity / 2;
    m_tail = m_head + 1;
    m_list = vector<int>(m_capacity, 0);
}

DoubleVector::DoubleVector(int capacity) : m_capacity(capacity), m_size(0)
{
    m_head = capacity / 2;
    m_tail = m_head + 1;
    m_list = vector<int>(capacity, 0);
}

DoubleVector::~DoubleVector()
{
}

void DoubleVector::right_shift(int n) {
    rotate(m_list.rbegin(), m_list.rbegin() + n, m_list.rend());
    m_head += n;
    m_tail += n;

    return;
}

void DoubleVector::left_shift(int n) {
    rotate(m_list.begin(), m_list.begin() + n, m_list.end());
    m_head -= n;
    m_tail -= n;

    return;
}

int DoubleVector::pop_back() 
{
    if (m_size == 0) {
        throw runtime_error("The list is empty");
    }

    int ans = m_list[m_tail - 1];
    m_tail--;
    m_size--;

    return ans;
}

int DoubleVector::pop_front() 
{
    if (m_size == 0) {
        throw runtime_error("The list is empty");
    }

    int ans = m_list[m_head + 1];
    m_head++;
    m_size--;

    return ans;
}

void DoubleVector::alloc_left() 
{
    m_list.insert(m_list.begin(), m_capacity, 0);
    left_shift(m_capacity / 2);
    m_head += m_capacity;
    m_tail += m_capacity;
    m_capacity *= 2;
}

void DoubleVector::alloc_right()
{
    m_list.insert(m_list.end(), m_capacity, 0);
    right_shift(m_capacity / 2);
    m_capacity *= 2;
}

void DoubleVector::push_back(int n) 
{
    if (m_tail == m_capacity) {
        if (m_head == -1) { 
           alloc_right();
        } else { 
            int
                free_slots_in_left_side = m_head,
                delta = free_slots_in_left_side / 2 + 1;

                left_shift(delta);
        }
    }

    m_list[m_tail] = n;
    m_tail++;
    m_size++;
    
    return;
}

void DoubleVector::push_front(int n) 
{
    if (m_head == -1) {
        if (m_tail == m_capacity) { 
            alloc_left();
        } else { 
            int
                free_slots_in_right_side = m_capacity - m_tail,
                delta = free_slots_in_right_side / 2 + 1;
            right_shift(delta);
        }
    }

    m_list[m_head] = n;
    m_head--;
    m_size++;

    return;
}

void DoubleVector::remove(int idx)
{
    const int real_idx = m_head + idx + 1;
    rotate(m_list.begin() + real_idx, m_list.begin() + real_idx + 1, m_list.end());
    m_tail -= 1;
}

void DoubleVector::removeAll()
{
    m_head = m_capacity / 2;
    m_tail = m_head + 1;
    m_size = 0;
}

int DoubleVector::size()
{
    return m_size;
}

bool DoubleVector::empty()
{
    return m_size == 0;
}

void DoubleVector::print()
{
    for (auto i = m_list.begin() + m_head + 1; i < m_list.begin() + m_tail; i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void DoubleVector::printReverse()
{
    for (auto i = m_list.rbegin() + (m_capacity - m_tail); i < m_list.rend() - m_head - 1; i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int DoubleVector::at(int idx)
{
    if (idx > m_size - 1) {
        throw out_of_range("Index don't exists.");
    }

    return m_list[m_head + idx + 1];
}

bool DoubleVector::equals(DoubleVector &lst)
{
    if (m_size != lst.size()) {
        return false;
    }

    for (int i=0; i < m_size; i++) {
        if (at(i) != lst.at(i)) {
            return false;
        }    
    } 
    
    return true;
}

void DoubleVector::concat(DoubleVector &lst)
{
    while (lst.size()) {
        push_back(lst.pop_front());
    }

    return;
}
