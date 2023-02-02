#include <iostream>
#include <vector>
enum class HeapType { max, min };

class BHeap {
private:
  std::vector<int> heap;
  HeapType heapType;
  void maxCreateHeap();
  void minCreateHeap();
  void maxDeleteHeap();
  void minDeleteHeap();
  int heap_size;

public:
  BHeap(HeapType heapType) {
    this->heapType = heapType;
    this->heap_size = 0;
  }
  int AddElement(int value);
  int Delete();
  void Print();
  void Sort();
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
  this->heap_size++;
  return this->heap_size - 1;
}
void BHeap::minCreateHeap() {
  int new_el_index = this->heap_size - 1;
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
  int new_el_index = this->heap_size - 1;
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
int BHeap::Delete() {
  int del_el = this->heap[0];
  this->heap[0] = this->heap[this->heap_size - 1];
  this->heap[this->heap_size - 1] = del_el;
  this->heap_size--;
  switch (this->heapType) {
  case HeapType::max:
    this->maxDeleteHeap();
    break;
  case HeapType::min:
    this->minDeleteHeap();
    break;
  default:
    break;
  }
  return del_el;
}
void BHeap::minDeleteHeap() {
  int curr_index = 0;
  int heap_index = curr_index + 1;
  int lchild, rchild, temp;
  while(curr_index < (this->heap_size - 1)) {
    heap_index = curr_index + 1;
    lchild = heap_index * 2;
    rchild = lchild + 1;
    if(this->heap[rchild -1] < this->heap[lchild -1]){
      temp = this->heap[curr_index];
      this->heap[curr_index] = this->heap[rchild -1];
      this->heap[rchild - 1] = temp;
      curr_index = rchild -1;
    } else {
      temp = this->heap[curr_index];
      this->heap[curr_index] = this->heap[lchild -1];
      this->heap[lchild - 1] = temp;
      curr_index = lchild -1;
    }
  }
}
void BHeap::maxDeleteHeap() {
  int curr_index = 0;
  int heap_index = curr_index + 1;
  int lchild, rchild, temp;
  while(curr_index < (this->heap_size - 1)) {
    heap_index = curr_index + 1;
    lchild = heap_index * 2;
    rchild = lchild + 1;
    if(this->heap[rchild -1] > this->heap[lchild -1]){
      temp = this->heap[curr_index];
      this->heap[curr_index] = this->heap[rchild -1];
      this->heap[rchild - 1] = temp;
      curr_index = rchild -1;
    } else {
      temp = this->heap[curr_index];
      this->heap[curr_index] = this->heap[lchild -1];
      this->heap[lchild - 1] = temp;
      curr_index = lchild -1;
    }
  }

}
void BHeap::Print() {
  for (int i : this->heap) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
void BHeap::Sort() {
  for (int i = 0; i < this->heap.size(); i++) {
    this->Delete();
  }
}