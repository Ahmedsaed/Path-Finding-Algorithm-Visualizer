#ifndef PAIR_H
#define PAIR_H

#include "main.h"

    /**
     * @file pair.h
     * @brief Implementation of a simple pair class template in C++.
     *
     * This file contains the header for a simple pair class template in C++,
     * which is used to store two elements of potentially different types together.
     *
     * The implementation includes a class template, `pair`, which has two public
     * data members, `first` and `second`, that store the two elements of the pair.
     * The types of these elements are specified using the template parameters `t1`
     * and `t2`, respectively.
     *
     * This class template is often used to simplify the handling of related data, such as
     * coordinates, key-value pairs, or other pairs of values.
     *
     * @tparam t1 The type of the first element stored in the pair.
     * @tparam t2 The type of the second element stored in the pair.
     */
template <typename t1, typename t2>
class pair{
public:
    t1 first;
    t2 second;
};

#endif
