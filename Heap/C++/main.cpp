#include "heap.hpp"

int main(int argc, char **argv) {
  BHeap heap(HeapType::min);
  heap.AddElement(10);
  heap.AddElement(20);
  heap.AddElement(30);
  heap.AddElement(25);
  heap.AddElement(5);
  heap.AddElement(40);
  heap.AddElement(35);
  heap.Print();
  heap.Sort();
  heap.Print();
}