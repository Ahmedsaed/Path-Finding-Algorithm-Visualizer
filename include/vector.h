#ifndef VECTOR_H
#define VECTOR_H

#include "main.h"

template <class t>
class vector{
private:
    t* m_data;
    int m_size, m_capacity;
    void expand();
    void shrink();

public:
    vector();

    void push_back(t x);  
    void pop_back();
    int size();
    bool empty ();
    

    int& operator[](int index);
};


#include "vector.tpp"

#endif