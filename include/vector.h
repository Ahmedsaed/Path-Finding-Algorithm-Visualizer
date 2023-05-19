#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class t>


class vector{
private:
    int* m_data;
    int m_size, m_capacity;
    void expand()
    {
        int *new_data = new int[m_capacity * 2];
        memcpy(new_data, m_data, m_size * sizeof(int));
        delete[] m_data;
        m_data = new_data;
        m_capacity *= 2;
    }
    
    void shrink()
    {
        int *new_data = new int[m_capacity / 2];
        memcpy(new_data, m_data, m_size * sizeof(int));
        delete[] m_data;
        m_data = new_data;
        m_capacity /= 2;
    }

public:
    vector()
    {
        m_size = 0;
        m_capacity = 4;
        m_data = new int[4];
    }

    void push_back(int x)
    {
        if(m_size == m_capacity)
            expand();
        m_data[m_size++] = x;
    }
    void pop_back()
    {
        m_size--;
        if(m_size*2 < m_capacity && m_capacity>4)
            shrink();
    }
    int size()
    {
        return m_size;
    }
    bool empty ()
    {
        if(m_size==0)
            return true;
        return false;
    }

    int& operator[](int index)
    {
        return m_data[index];
    }
};


#include "vector.tpp"

#endif