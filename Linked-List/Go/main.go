package main

import "fmt"

func main() {
	list := LinkedList{}
	list.AddToFront(2)
	list.AddToFront(1)
	list.Append(3)
	list.Append(4)
	list.PrintList()
	fmt.Println(list.Length())
}
