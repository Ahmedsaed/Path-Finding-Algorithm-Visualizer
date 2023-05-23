#ifndef VECTOR_H
#define VECTOR_H

#include "main.h"

namespace udtl {
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
        vector(const std::initializer_list<T>& initList);
        vector& operator=(const std::initializer_list<T>& initList);

        void push_back(T x);  
        void pop_back();
        unsigned int size() const;
        bool empty() const;
        void insert(size_type pos, const T& value);
        void insert(T* pos, const T& value);
        
        reference front();  // Non-const version
        const_reference front() const;  // Const version
        
        T& operator[](int index);


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