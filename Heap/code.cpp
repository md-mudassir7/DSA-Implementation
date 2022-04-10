#include<bits/stdc++.h>
using namespace std;
class Heap{
private:
    int* arr;
    int n;
    int capacity;
public:
    Heap(int size = 100){
        arr = new int[size];
        capacity = size;
        n = 0;
    }
    void insert(int value){
        n++;
        arr[n-1] = value;
        heapifyAfterInsert(n-1);
    }
    void deleteRoot(){
        int x = arr[n-1];
        arr[0] = x;
        n-=1;
        heapifyAfterDelete(0);
    }
    void heapifyAfterInsert(int i){
        // Find parent
        int parent = (i - 1) / 2;
    
        if (arr[parent] > 0) {
            // For Max-Heap
            // If current node is greater than its parent
            // Swap both of them and call heapify again
            // for the parent
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
    
                // Recursively heapify the parent node
                heapifyAfterInsert(parent);
            }
        }
    }
    void heapifyAfterDelete(int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
    
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
    
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
    
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
    
            // Recursively heapify the affected sub-tree
            heapifyAfterDelete(largest);
        }
    }
    void printArray()
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main(){
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.printArray();
    h.deleteRoot();
    h.printArray();
    return 0;
}