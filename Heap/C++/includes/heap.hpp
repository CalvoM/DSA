#include <iostream>
#include <vector>
enum class HeapType { max, min };

class BHeap {
private:
  std::vector<int> heap;
  HeapType heapType;
  void maxCreateHeap();
  void minCreateHeap();

public:
  BHeap(HeapType heapType) { this->heapType = heapType; }
  int AddElement(int value);
  void Delete();
  void Print();
};

int BHeap::AddElement(int value) {
  this->heap.push_back(value);
  switch (this->heapType) {
    case HeapType::max:
        this->maxCreateHeap();
        break;
    case HeapType::min:
        this->minCreateHeap();
        break;
    default:
        break;
  }
  return this->heap.size() - 1;
}
void BHeap::Delete() {}
void BHeap::minCreateHeap() {
  int new_el_index = this->heap.size() - 1;
  int parent_index = 0;
  while (new_el_index > 0) {
    parent_index = (new_el_index + 1) / 2 - 1;
    if (this->heap[new_el_index] < this->heap[parent_index]) {
      int new_el = this->heap[new_el_index];
      this->heap[new_el_index] = this->heap[parent_index];
      this->heap[parent_index] = new_el;
      new_el_index = parent_index;
    } else {
      new_el_index -= 1;
    }
  }
}
void BHeap::maxCreateHeap() {
  int new_el_index = this->heap.size() - 1;
  int parent_index = 0;
  while (new_el_index > 0) {
    parent_index = (new_el_index + 1) / 2 - 1;
    if (this->heap[new_el_index] > this->heap[parent_index]) {
      int new_el = this->heap[new_el_index];
      this->heap[new_el_index] = this->heap[parent_index];
      this->heap[parent_index] = new_el;
      new_el_index = parent_index;
    } else {
      new_el_index -= 1;
    }
  }
}
void BHeap::Print() {
  for (int i : this->heap) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
