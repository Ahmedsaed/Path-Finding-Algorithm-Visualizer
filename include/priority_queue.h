#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "algorithm.h"
#include <functional>

namespace udtl {
    template<typename T, typename Container = udtl::vector<T>, typename Compare = std::less<typename Container::value_type>>
    class priority_queue {
    private:
        Container heap;
        Compare compare;

        void heapifyUp(int index) {
            while (index > 0) {
                int parentIndex = (index - 1) / 2;
                if (!compare(heap[index], heap[parentIndex])) {
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
