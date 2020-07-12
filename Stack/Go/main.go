package main

import (
	"fmt"
)

//StackData data type for stack-> Can be changed to whichever type
type StackData byte

//Stack models the stack Data structure
type Stack struct {
	mData []StackData
}

//Top Returns the top element in the stack
func (s *Stack) Top() StackData {
	return s.mData[len(s.mData)-1]
}

//Pop Removes the top element in the stack
func (s *Stack) Pop() StackData {
	var item StackData = s.mData[len(s.mData)-1]
	s.mData[len(s.mData)-1] = 0
	s.mData = s.mData[:len(s.mData)-1]
	return item
}

//Push adds element to stack top
func (s *Stack) Push(el StackData) {
	s.mData = append(s.mData, el)
}

//Isempty checks if the stack has not element
func (s *Stack) Isempty() bool {
	return len(s.mData) == 0
}

//Clear removes all elements from stack
func (s *Stack) Clear() {
	s.mData = nil
}

func main() {
	s := Stack{}
	s.Push(1)
	s.Push(2)
	s.Pop()
	fmt.Println(s.Top())
}
