#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "vector.h"

template <class t>
vector<t>::vector()
{
    m_size = 0;
    m_capacity = 4;
    m_data = new t[4];
}

template <class t>
int& vector<t>::operator[](int index)
{
    return m_data[index];
}

template <class t>
void vector<t>::expand()
{
    t *new_data = new t[m_capacity * 2];
    memcpy(new_data, m_data, m_size * sizeof(t));
    delete[] m_data;
    m_data = new_data;
    m_capacity *= 2;
}

template <class t>
void vector<t>::shrink()
{
    t *new_data = new t[m_capacity / 2];
    memcpy(new_data, m_data, m_size * sizeof(t));
    delete[] m_data;
    m_data = new_data;
    m_capacity /= 2;
}

template <class t>
void vector<t>::push_back(t x)
{
    if (m_size == m_capacity)
        expand();
    m_data[m_size++] = x;
}
template <class t>
void vector<t>::pop_back()
{
    m_size--;
    if (m_size * 2 < m_capacity && m_capacity > 4)
        shrink();
}
template <class t>
int vector<t>::size()
{
    return m_size;
}
template <class t>
bool vector<t>::empty()
{
    if (m_size == 0)
        return true;
    return false;
}

#endif