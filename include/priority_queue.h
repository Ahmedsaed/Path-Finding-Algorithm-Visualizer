#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "algorithm.h"
#include <functional>

namespace udtl {
    /**
     * @file priority_queue.h
     * @brief Implementation of a priority queue data structure using a heap.
     *
     * This file contains the implementation of a priority queue class template in C++. The priority queue is implemented using a heap data structure, which allows for efficient insertion and removal of the highest priority element. The priority of elements is determined by a comparison function provided to the template, which defaults to std::less.
     *
     * The implementation includes the following member functions:
     *   - A default constructor that initializes an empty priority queue.
     *   - push function for adding an element to the priority queue.
     *   - pop function for removing the highest priority element from the priority queue.
     *   - top function for getting the highest priority element without removing it.
     *   - empty function for checking if the priority queue is empty.
     *
     * The template also includes two optional parameters:
     *   - Container: the type of container used to store the elements, which defaults to udtl::vector<T>.
     *   - Compare: the type of comparison function used to determine the priority of elements, which defaults to std::less<typename Container::value_type>.
     *
     * The implementation includes two private member functions, heapifyUp and heapifyDown, which maintain the heap property of the priority queue after insertion or removal of elements.
     *
     * @tparam TThe type of elements stored in the priority queue.
     * @tparam Container The type of container used to store the elements. Defaults to udtl::vector<T>.
     * @tparam Compare The type of comparison function used to determine the priority of elements. Defaults to std::less<typename Container::value_type>.
     */
    template<typename T, typename Container = udtl::vector<T>, typename Compare = std::less<typename Container::value_type>>
    class priority_queue {
    private:
        Container heap;
        Compare compare;

        void heapifyUp(int index) {
            while (index > 0) {
                int parentIndex = (index - 1) / 2;
                if (compare(heap[index], heap[parentIndex])) {
                    break;
                }
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
        }

        void heapifyDown(int index) {
            int size = heap.size();
            while (true) {
                int leftChildIndex = 2 * index + 1;
                int rightChildIndex = 2 * index + 2;
                int smallestIndex = index;

                if (leftChildIndex < size && compare(heap[leftChildIndex], heap[smallestIndex])) {
                    smallestIndex = leftChildIndex;
                }

                if (rightChildIndex < size && compare(heap[rightChildIndex], heap[smallestIndex])) {
                    smallestIndex = rightChildIndex;
                }

                if (smallestIndex == index) {
                    break;
                }

                std::swap(heap[index], heap[smallestIndex]);
                index = smallestIndex;
            }
        }

    public:
        bool empty() const {
            return heap.empty();
        }

        void push(const T& value) {
            heap.push_back(value);
            heapifyUp(heap.size() - 1);
        }

        void pop() {
            if (empty()) {
                return;
            }

            std::swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapifyDown(0);
        }

        const T& top() const {
            if (empty()) {
                throw std::out_of_range("Priority queue is empty.");
            }

            return heap[0];
        }
    };

    // Custom comparator for sorting in descending order
    template<typename T>
    struct DescendingComparator {
        bool operator()(const T& a, const T& b) const {
            return a > b;
        }
    };
}

#endif
