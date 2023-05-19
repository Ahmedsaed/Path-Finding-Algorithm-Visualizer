#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class t>
class vector{
private:
    t* m_data;
    int m_size, m_capacity;
    void expand()
    {
        t *new_data = new t[m_capacity * 2];
        memcpy(new_data, m_data, m_size * sizeof(t));
        delete[] m_data;
        m_data = new_data;
        m_capacity *= 2;
    }
    
    void shrink()
    {
        t *new_data = new t[m_capacity / 2];
        memcpy(new_data, m_data, m_size * sizeof(t));
        delete[] m_data;
        m_data = new_data;
        m_capacity /= 2;
    }

public:
    vector()
    {
        m_size = 0;
        m_capacity = 4;
        m_data = new t[4];
    }

    void push_back(t x);  
    void pop_back();
    int size();
    bool empty ();
    

    int& operator[](int index)
    {
        return m_data[index];
    }
};


#include "vector.tpp"

#endif