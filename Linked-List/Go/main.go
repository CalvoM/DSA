package main

//Node node of linked-list
type Node struct {
	data int
	next *Node
}

//NodeList Linked list
type NodeList struct {
	head  *Node
	tail  *Node
	count int
}

//IsEmpty returns if list is empty
func (nl *NodeList) IsEmpty() bool {
	return nl.head == nil
}

//AddToFront adds element to front of linked list
func (nl *NodeList) AddToFront(el byte) {

}

//Append adds element to end of linked list
func (nl *NodeList) Append(el byte) {

}

//Insert adds element to linked list at index specified
func (nl *NodeList) Insert(index int, el byte) {

}

//Length returns the number of items in linked list
func (nl *NodeList) Length() int {
	return nl.count
}
func main() {

}
