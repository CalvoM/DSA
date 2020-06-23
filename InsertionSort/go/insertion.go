package main

import "fmt"

func insertionSort(arr []int) {
	fmt.Println(arr)
	for front := 1; front < len(arr); front++ {
		currentItem := arr[front]
		back := front - 1
		for back >= 0 && arr[back] > currentItem {
			arr[back+1] = arr[back]
			back--
		}
		arr[back+1] = currentItem
	}
	fmt.Println(arr)
}

func main() {
	insertionSort([]int{5, 2, 3, 6, 9, 1, 2, 0, 3, 10, 20, 11, 34, 12})
}
