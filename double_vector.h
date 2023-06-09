#include<vector>

class DoubleVector
{
private:
    int capacity;
    int size;
    int head;
    int tail;
    std::vector<int> list;

public:
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

    void removeAll();

    bool empty();
};
