package main

import "fmt"

//QueueData  data type of Queue-> change the type to whichever you want
type QueueData string

//Queue models the queue data structure
type Queue struct {
	mData []QueueData
}

//Enqueue add element(el) to queue
func (q *Queue) Enqueue(el QueueData) {
	q.mData = append(q.mData, el)
}

//Dequeue remove element from queue exit end
func (q *Queue) Dequeue() QueueData {
	var el QueueData = q.mData[0]
	q.mData = append(q.mData[:0], q.mData[1:]...)
	return el
}

//Clear clear the queue
func (q *Queue) Clear() {
	q.mData = nil
}

//isEmpty check if queue is empty
func (q *Queue) isEmpty() bool {
	return len(q.mData) == 0
}

func main() {
	que := Queue{}
	que.Enqueue("c")
	que.Enqueue("h")
	que.Enqueue("a")
	que.Enqueue("m")
	que.Enqueue("b")
	que.Enqueue("e")
	que.Enqueue("r")
	for que.isEmpty() == false {
		fmt.Println(que.Dequeue())
	}
}
