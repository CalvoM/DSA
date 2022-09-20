#include "heap.hpp"

int main(int argc, char **argv) {
  BHeap heap(HeapType::min);
  heap.AddElement(3);
  heap.Print();
  heap.AddElement(1);
  heap.Print();
  heap.AddElement(7);
  heap.Print();
  heap.AddElement(2);
  heap.Print();
  heap.AddElement(9);
  heap.Print();
  heap.Delete();
  heap.Print();
  heap.Delete();
  heap.Print();
}