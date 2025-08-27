package main

import (
	"fmt"
	"slices"

	"golang.org/x/tour/tree"
)

func walk(t *tree.Tree, ch chan int) {
	if t.Left != nil {
		walk(t.Left, ch)
	}
	ch <- t.Value
	if t.Right != nil {
		walk(t.Right, ch)
	}
}

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int) {
	// We will implement DFS in-order
	if t == nil {
		return
	}
	walk(t.Left, ch)
	ch <- t.Value
	walk(t.Right, ch)
	close(ch)
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1 := make(chan int, 10)
	ch2 := make(chan int, 10)
	var t1Values []int
	var t2Values []int
	go Walk(t1, ch1)
	go Walk(t2, ch2)
	for v := range ch1 {
		t1Values = append(t1Values, v)
	}
	for v := range ch2 {
		t2Values = append(t2Values, v)
	}
	return slices.Equal(t1Values, t2Values)
}

func main() {
	t := tree.New(5)
	t2 := tree.New(5)
	fmt.Println("Are these two equal?")
	fmt.Println(t.String())
	fmt.Println(t2.String())
	fmt.Println(Same(t, t2))
}
