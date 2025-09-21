#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyDown(int i) {
        int size = heap.size();
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        if (i == 0) return;
        int parent = (i - 1) / 2;
        if (heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMin() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    bool check() {
        int size = heap.size();
        for (int i = 0; i <= (size - 2) / 2; i++) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < size && heap[i] > heap[left])
                return false;
            if (right < size && heap[i] > heap[right])
                return false;
        }
        return true;
    }
};

int main() {
    MinHeap h;
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(5);
    h.insert(10);

    cout << "Min Heap: ";
    h.printHeap();

    cout << "Min Element: " << h.getMin() << endl;

    h.deleteMin();
    cout << "After deleting min: ";
    h.printHeap();

    cout << "Heap property check: "
         << (h.check() ? "Valid Min Heap" : "Not a Min Heap")
         << endl;

    return 0;
}
