#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "vector.h"

template <class T>
vector<T>::vector()
{
    m_size = 0;
    m_capacity = 4;
    m_data = new T[4];
}

template<typename T>
vector<T>::vector(const std::initializer_list<T>& initList) {
    m_size = 0;
    m_capacity = 4;
    m_data = new T[4];
    for (const auto& element : initList) {
        push_back(element);
    }
}

template<typename T>
vector<T>& vector<T>::operator=(const std::initializer_list<T>& initList) {
    clear();
    m_size = 0;
    m_capacity = 4;
    m_data = new T[4];
    for (const auto& element : initList) {
        push_back(element);
    }
    return *this;
}

template<typename T>
T& vector<T>::operator[](int index) {
    return m_data[index];
}

template <class T>
void vector<T>::expand()
{
    m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
    T *new_data = new T[m_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
}

template <class T>
void vector<T>::shrink()
{
    T *new_data = new T[m_capacity / 2];
    for (size_t i = 0; i < m_size; ++i) {
        new (new_data + i) T(m_data[i]);  // Copy constructor or assignment operator
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity /= 2;
}

template <class T>
void vector<T>::push_back(T x)
{
    if (m_size == m_capacity)
        expand();
    m_data[m_size++] = x;
}
template <class T>
void vector<T>::pop_back()
{
    m_size--;
    if (m_size * 2 < m_capacity && m_capacity > 4)
        shrink();
}
template <class T>
unsigned int vector<T>::size() const
{
    return m_size;
}
template <class T>
bool vector<T>::empty() const
{
    if (m_size == 0)
        return true;
    return false;
}

// Non-const version of front()
template<typename T>
typename vector<T>::reference vector<T>::front() {
    return *m_data;
}

// Const version of front()
template<typename T>
typename vector<T>::const_reference vector<T>::front() const {
    return *m_data;
}

template<typename T>
void vector<T>::clear() {
    m_size = 0;
}

template<typename T>
void vector<T>::insert(size_type pos, const T& value) {
    // Check if the vector is full and needs to be expanded
    if (m_size == m_capacity) {
        expand();
    }

    // Validate the position
    if (pos > m_size) {
        throw std::out_of_range("Invalid position for insertion");
    }

    // Shift elements to the right to make space for the new element
    for (size_type i = m_size; i > pos; --i) {
        m_data[i] = m_data[i - 1];
    }

    // Insert the new element at the specified position
    m_data[pos] = value;

    // Increment the size of the vector
    ++m_size;
}

template <class T>
void vector<T>::insert(T* pos, const T& value) {
    // Calculate the index from the pointer position
    size_type index = pos - m_data;

    // Call the existing insert function with the index
    insert(index, value);
}

#endif