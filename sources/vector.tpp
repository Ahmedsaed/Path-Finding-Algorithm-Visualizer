#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "vector.h"


template <class t>
void  vector<t>::push_back(t x)
    {
        if(m_size == m_capacity)
            expand();
        m_data[m_size++] = x;
    }
template <class t>
void vector<t>::pop_back()
    {
        m_size--;
        if(m_size*2 < m_capacity && m_capacity>4)
            shrink();
    }
template <class t>
int vector<t>::size()
    {
        return m_size;
    }
template <class t>
bool vector<t>::empty ()
    {
        if(m_size==0)
            return true;
        return false;
    }



#endif