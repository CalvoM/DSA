package main

import "fmt"

func partition(elements []int, start int, end int) int {
	marker := start
	right := end
	preMarker := start - 1
	for {
		if marker == end {
			break
		}
		if elements[marker] <= elements[right] {
			preMarker++
			elements[preMarker], elements[marker] = elements[marker], elements[preMarker]
		}
		marker++
	}
	elements[preMarker+1], elements[right] = elements[right], elements[preMarker+1]
	return preMarker + 1
}

func quickSort(elements []int, start int, end int) {
	if start < end {
		loc := partition(elements, start, end)
		quickSort(elements, start, loc-1)

		quickSort(elements, loc+1, end)

	}
}

func main() {
	elements := make([]int, 8)
	elements = []int{2, 8, 7, 1, 3, 5, 6, 4}
	quickSort(elements, 0, 7)
	fmt.Println(elements)
}
