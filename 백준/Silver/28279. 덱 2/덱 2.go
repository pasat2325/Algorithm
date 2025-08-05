package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()


	var q []int
	q = make([]int, int(1e6), int(1e6))

	var n, front, rear int
	fmt.Fscanln(reader, &n)
	front = 0
	rear = n - 1
	var count int = 0
	for i := 0; i < n; i++ {
		var o int
		var data int
		fmt.Fscan(reader, &o)
		switch o {
		case 1: // push_front
			fmt.Fscanln(reader, &data)
			front = (front - 1 + n) % n
			q[front] = data
			count += 1
		case 2: //push_back
			fmt.Fscanln(reader, &data)
			rear = (rear + 1) % n
			q[rear] = data
			count += 1
		case 3:
			if count == 0 {
				fmt.Fprintln(writer, -1)
			} else {
				fmt.Fprintln(writer, q[front])
				front = (front + 1) % n
				count -= 1
			}
		case 4:
			if count == 0 {
				fmt.Fprintln(writer, -1)
			} else {
				fmt.Fprintln(writer, q[rear])
				rear = (rear - 1 + n) % n
				count -= 1
			}
		case 5:
			fmt.Fprintln(writer, count)
		case 6:
			if count == 0 {
				fmt.Fprintln(writer, 1)
			} else {
				fmt.Fprintln(writer, 0)
			}
		case 7:
			if count == 0 {
				fmt.Fprintln(writer, -1)
			} else {
				fmt.Fprintln(writer, q[front])
			}
		case 8:
			if count == 0 {
				fmt.Fprintln(writer, -1)
			} else {
				fmt.Fprintln(writer, q[rear])
			}
		}
	}
}