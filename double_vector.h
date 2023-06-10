#include<vector>

class DoubleVector
{
private:
    int m_capacity;
    int m_size;
    int m_head;
    int m_tail;
    std::vector<int> m_list;

public:
    DoubleVector();
    DoubleVector(int capacity);
    ~DoubleVector();

    void push_back(int n);
    void push_front(int n);

    int pop_back();
    int pop_front();

    void right_shift(int n);
    void left_shift(int n);

    void alloc_left();
    void alloc_right();

    void remove(int idx);
    void removeAll();

    int size();
    bool empty();
    void print();
    void printReverse();

    int at(int idx);

    bool equals(DoubleVector& lst);
};
