#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "algorithm.h"
#include <functional>

namespace udtl {
    template <typename T, typename T2, typename Compare = std::less<T>>
    class priority_queue {
    public:
        // Constructor
        priority_queue() {}

        // Push element into the priority queue
        void push(const T& value) {
            container.push_back(value);
            siftUp(container.size() - 1);
        }

        // Check if the priority queue is empty
        bool empty() const {
            return container.empty();
        }

        // Access the top element of the priority queue
        const T& top() const {
            return container.front();
        }

        // Remove the top element from the priority queue
        void pop() {
            if (empty())
                return;

            container[0] = container.back();
            container.pop_back();
            siftDown(0);
        }

    private:
        udtl::vector<T> container; // Underlying container
        Compare compare;          // Comparison function object

        // Sift up the element at index i
        void siftUp(int i) {
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (compare(container[i], container[parent]))
                    break;
                std::swap(container[i], container[parent]);
                i = parent;
            }
        }

        // Sift down the element at index i
        void siftDown(int i) {
            int size = container.size();
            while (i < size) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int largest = i;

                if (left < size && compare(container[left], container[largest]))
                    largest = left;

                if (right < size && compare(container[right], container[largest]))
                    largest = right;

                if (largest == i)
                    break;

                std::swap(container[i], container[largest]);
                i = largest;
            }
        }
    };
}

#endif
