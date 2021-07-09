package main

import (
	"errors"
	"fmt"
)

var ErrNoNodeInList = errors.New("ErrNoNodeInList")
var ErrIndexOutOfRange = errors.New("ErrIndexOutOfRange")

//Node node of linked-list
type Node struct {
	data int
	next *Node
}

//LinkedList Linked list
type LinkedList struct {
	head  *Node
	tail  *Node
	count int
}

//IsEmpty returns if list is empty
func (nl *LinkedList) IsEmpty() bool {
	return nl.head == nil
}

//AddToFront adds element to front of linked list
func (nl *LinkedList) AddToFront(el byte) (err error) {
	if nl.IsEmpty() {
		newNode := Node{data: int(el)}
		nl.head = &newNode
		nl.tail = &newNode
		nl.count += 1
		return
	}
	newHead := Node{data: int(el), next: nl.head}
	nl.head = &newHead
	nl.count += 1
	return
}

//Append adds element to end of linked list
func (nl *LinkedList) Append(el byte) (err error) {
	if nl.IsEmpty() {
		newNode := Node{data: int(el)}
		nl.head = &newNode
		nl.tail = &newNode
		nl.count += 1
		return
	}
	currNode := nl.head
	newNode := Node{data: int(el)}
	currNode.next = &newNode
	nl.tail = &newNode
	nl.count += 1
	return
}

//Insert adds element to linked list at index specified, the list is 0-indexed
func (nl *LinkedList) Insert(index int, el byte) (err error) {
	if index > nl.Length() || index < 0 {
		return ErrIndexOutOfRange
	}
	currIndex := 0
	currNode := nl.head
	for currIndex != index {
		currNode = currNode.next
		currIndex += 1
	}
	return
}

//Length returns the number of items in linked list
func (nl *LinkedList) Length() int {
	return nl.count
}

func (nl *LinkedList) PrintList() {
	if nl.IsEmpty() {
		return
	}
	currNode := nl.head
	for currNode != nil {
		fmt.Print(currNode.data)
		if currNode.next != nil {
			fmt.Print(" -> ")
		} else {
			fmt.Println()
		}
		currNode = currNode.next
	}

}
