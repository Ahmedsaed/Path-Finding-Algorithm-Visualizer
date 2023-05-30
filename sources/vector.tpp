#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "vector.h"

template <class T>
udtl::vector<T>::vector()
{
    m_size = 0;
    m_capacity = 4;
    m_data = new T[4];
}

template<typename T>
udtl::vector<T>::vector(const std::initializer_list<T>& initList) {
    m_size = 0;
    m_capacity = initList.size();
    m_data = new T[m_capacity];
    for (const auto& element : initList) {
        push_back(element);
    }
}

template<typename T>
udtl::vector<T>::vector(const vector<T>& other) : m_data(new T[other.m_size]), m_size(other.m_size) {
    // Copy the elements from the other vector
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }
}


template<typename T>
udtl::vector<T>::~vector() {
    delete[] m_data;
    m_data = nullptr;
}

template<typename T>
udtl::vector<T>& udtl::vector<T>::operator=(const std::initializer_list<T>& initList) {
    clear();
    m_size = 0;
    m_capacity = initList.size();
    m_data = new T[m_capacity];
    for (const auto& element : initList) {
        push_back(element);
    }
    return *this;
}

template<typename T>
udtl::vector<T>& udtl::vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        // Create a temporary copy of the other vector
        vector temp(other);

        // Swap the contents of this vector with the temporary vector
        std::swap(m_data, temp.m_data);
        std::swap(m_size, temp.m_size);
    }
    return *this;
}

template<typename T>
T& udtl::vector<T>::operator[](int index) {
    return m_data[index];
}

template<typename T>
T& udtl::vector<T>::operator[](int index) const {
    return m_data[index];
}

template <class T>
void udtl::vector<T>::expand()
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
void udtl::vector<T>::shrink()
{
    T *new_data = new T[m_capacity / 2];
    for (size_t i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity /= 2;
}

template <class T>
void udtl::vector<T>::push_back(T x)
{
    if (m_size == m_capacity)
        expand();
    m_data[m_size++] = x;
}

template <class T>
void udtl::vector<T>::pop_back()
{
    m_size--;
    if (m_size * 2 < m_capacity && m_capacity > 4)
        shrink();
}
template <class T>
unsigned int udtl::vector<T>::size() const
{
    return m_size;
}
template <class T>
bool udtl::vector<T>::empty() const
{
    if (m_size == 0)
        return true;
    return false;
}

// Non-const version of front()
template<typename T>
typename udtl::vector<T>::reference udtl::vector<T>::front() {
    return *m_data;
}

// Const version of front()
template<typename T>
typename udtl::vector<T>::const_reference udtl::vector<T>::front() const {
    return *m_data;
}

template<typename T>
void udtl::vector<T>::clear() {
    m_size = 0;
}

template<typename T>
void udtl::vector<T>::insert(size_type pos, const T& value) {
    if (m_size == m_capacity) {
        expand();
    }

    if (pos > m_size) {
        throw std::out_of_range("Invalid position for insertion");
    }

    for (size_type i = m_size; i > pos; --i) {
        m_data[i] = m_data[i - 1];
    }

    m_data[pos] = value;

    ++m_size;
}

template <class T>
void udtl::vector<T>::insert(T* pos, const T& value) {
    // Calculate the index from the pointer position
    size_type index = pos - m_data;

    // Call the existing insert function with the index
    insert(index, value);
}

template <typename T>
const typename udtl::vector<T>::value_type& udtl::vector<T>::back() const {
    if (m_size == 0) {
        throw std::runtime_error("Vector is empty");
    }
    return m_data[m_size - 1];
}

template <typename T>
typename udtl::vector<T>::value_type& udtl::vector<T>::back() {
    return const_cast<T&>(const_cast<const vector<T>*>(this)->back());
}

#endif
