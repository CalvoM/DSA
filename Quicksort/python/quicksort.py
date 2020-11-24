
counter = 0


def partition(elements, start, end) -> int:
    global counter
    preMarker = start-1
    marker = start

    while marker < end:
        counter += 1
        if elements[end] >= elements[marker]:
            preMarker += 1
            elements[marker], elements[preMarker] = elements[preMarker], elements[marker]
        marker += 1
    elements[end], elements[preMarker+1] = elements[preMarker+1], elements[end]
    return preMarker+1


def quickSort(elements, start, end):
    if start < end:
        loc = partition(elements, start, end)
        quickSort(elements, start, loc-1)
        quickSort(elements, loc+1, end)


if __name__ == "__main__":
    numbers = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    print(numbers)
    quickSort(numbers, 0, len(numbers)-1)
    print(numbers, counter, len(numbers))
