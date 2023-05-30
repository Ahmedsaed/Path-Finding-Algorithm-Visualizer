#ifndef VECTOR_H
#define VECTOR_H

#include "main.h"

namespace udtl {
    /**
     * @file vector.tpp
     * @brief Implementation of a dynamic array data structure.
     *
     * This file contains the implementation of a vector class template in C++.
     * The vector class is a dynamic array data structure that can grow or shrink
     * in size as elements are added or removed.
     *
     * The implementation includes the following member functions:
     *   - A default constructor that initializes an empty vector with a capacity of 4.
     *   - A constructor that takes an initializer list of elements to initialize the vector.
     *   - A copy constructor that creates a new vector with the same elements as another vector.
     *   - A destructor that deallocates the memory used by the vector.
     *   - An assignment operator that copies the elements of another vector or an initializer list to this vector.
     *   - An operator[] overload that returns a reference to the element at a given index.
     *   - push_back and pop_back functions for adding and removing elements from the back of the vector.
     *   - size and empty functions for getting the current size and checking if the vector is empty.
     *   - front function for getting the first element in the vector.
     *   - clear function for removing all elements from the vector.
     *   - insert function for inserting an element at a given position.
     *   - back function for getting the last element in the vector.
     *
     * The implementation also includes two private member functions, expand and shrink, which increase or decrease the capacity of the vector as needed.
     *
     * @tparam T The type of elements stored in the vector.
     */
    template <class T>
    class vector{
    private:
        T* m_data;
        size_t m_size, m_capacity;
        void expand();
        void shrink();

    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;

        vector();
        ~vector();
        vector(const vector<T>& other);
        vector(const std::initializer_list<T>& initList);
        vector& operator=(const vector<T>& other);
        vector& operator=(const std::initializer_list<T>& initList);

        void push_back(T x);
        void pop_back();
        unsigned int size() const;
        bool empty() const;
        void insert(size_type pos, const T& value);
        void insert(T* pos, const T& value);

        reference front();  // Non-const version
        const_reference front() const;  // Const version
        reference back();
        const_reference back() const;

        T& operator[](int index);
        T& operator[](int index) const;

        T* begin() {
            return m_data;
        }

        // end() function
        T* end() {
            return m_data + m_size;
        }

        void clear();
    };


    #include "vector.tpp"
}

#endif
