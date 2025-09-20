#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyDown(int i) {
        int size = heap.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        if (i == 0) return;
        int parent = (i - 1) / 2;
        if (heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax() {
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

            if (left < size && heap[i] < heap[left])
                return false;
            if (right < size && heap[i] < heap[right])
                return false;
        }
        return true;
    }

};

int main() {
    MaxHeap h;
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(5);
    h.insert(10);

    cout << "Max Heap: ";
    h.printHeap();

    cout << "Max Element: " << h.getMax() << endl;

    h.deleteMax();
    cout << "After deleting max: ";
    h.printHeap();
    cout << "Heap property check: " 
         << (h.check() ? "Valid Max Heap" : "Not a Max Heap") 
         << endl;
         

    return 0;
}
    
