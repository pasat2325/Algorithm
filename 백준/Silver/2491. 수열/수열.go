/*
투포인터

left : 증가 또는 감소 구간이 시작되는 위치
right : +1 인덱스 씩 증가하며 새로운 인덱스의 증가 또는 감소를 판별

항상 구간의 상태는 증가 또는 감소 둘 중 하나만 존재함

구간의 상태가 증가일 때 -> isIncr = true
구간의 상태가 감소일 때 -> isIncr = false

right - 1 값과 비교하여 right 가 더 크면 inIncr = true
right - 1 값과 비교하여 right 가 더 작으면 inIncr = false

isIncr 이 반전되는 경우 (구간의 상태가 바뀌는 경우) 현재 right 값과 일치하는 값이 나올 때 까지 left 포인터를 이동시킴 (+1)
구간의 길이를 기록 중인 tempLength를 answer와 비교한다. answer = max(answer, tempLength)

그 외의 경우 tempLength++

최악의 경우 -> 매  right 이동마다 구간의 상태가 바뀌는 경우 -> left를 매번 이동시켜야 함. 즉 right 이동 한번 당 left 이동 한번이 발생하므로 2 * 100,000
*/

package main

import (
	"bufio"
	"fmt"
	"os"
)
func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i])
	}

	var isIncr bool = false
	var left, right int = 0, 0
	var tempLength, answer int = 1, 0

	for i := 1; i < n; i++ {
		right = i
		if arr[right - 1] < arr[right] {
			if(!isIncr){
				isIncr = true
				answer = max(answer, tempLength)
				for {
					if arr[left] == arr[right - 1] {
						break
					}
					left++
				}
				tempLength = right - left + 1
			} else {
				tempLength++
			}
		} else if arr[right - 1] > arr[right] {
			if(isIncr){
				isIncr = false
				answer = max(answer, tempLength)
				for {
					if arr[left] == arr[right - 1] {
						break
					}
					left++
				}
				tempLength = right - left + 1
			} else {
				tempLength++
			}
		} else {
			tempLength++
		}
	}
	answer = max(answer, tempLength)
	if n == 1 {
		answer = 1
	}
	fmt.Fprintln(out, answer)
}