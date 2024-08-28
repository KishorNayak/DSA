#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        if (i && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void deleteMin() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
    }

    int extractMin() {
        if (heap.empty()) throw std::out_of_range("Heap is empty!");

        int minElement = heap.front();
        deleteMin();
        return minElement;
    }

    int getMin() const {
        if (heap.empty()) throw std::out_of_range("Heap is empty!");
        return heap.front();
    }

    void printHeap() const {
        for (int i : heap) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

