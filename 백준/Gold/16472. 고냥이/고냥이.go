package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
)

var s uint = 0 // state
var arr = make([]int, 26)

// 현재 가르키는 알파벳이 새로운 종류인지, 이미 등장한 종류인지 확인.
func isExists(c byte) bool{
	k := int(c - 'a')
	if s & (1 << k) == 0 {
		return false
	} else {
		return true
	}
}


func main(){
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	var str string

	fmt.Fscan(in, &n, &str)

	strlen := len(str)

	cnt, tempLength, ans := 0, 0, 0
	left, right := 0, 0

	for {
		if right == strlen{
			ans = max(tempLength - 1, ans)
			break
		}
		k := int(str[right] - 'a')
		arr[k]++

		if isExists(str[right]) {
			right++
			tempLength++
		} else {
			cnt = bits.OnesCount(s)
			if cnt + 1 > n {
				for {
					k := int(str[left] - 'a')
					left++
					arr[k]--
					//fmt.Fprintln(out, left - 1, arr[k])
					if arr[k] == 0 {
						s = s ^ (1 << k)
						break
					}
				}
			}
			tempLength = right - left + 1
			s = s | (1 << k)
			right++
		}

		ans = max(tempLength, ans)
	}
	fmt.Fprintln(out, ans)
}