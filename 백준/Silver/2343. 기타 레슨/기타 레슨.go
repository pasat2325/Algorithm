package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var in *bufio.Reader = bufio.NewReader(os.Stdin)
	var out *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n,m int
	fmt.Fscanln(in, &n, &m)

	arr := make([]int, n)
	prev := 0
	maxx := 0
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(in, &x)
		arr[i] = prev + x
		prev = arr[i]
		if (x > maxx) {
			maxx = x
		}
	}

	var l, r, mid, cnt, ans  int 
	l = maxx
	r = arr[n - 1]
	//fmt.Println(l, r)

	for {
		cnt = 1
		if (l > r) {
			break 
		}
		mid = (l + r) / 2
		
		psum := 0 
		for i := 0; i < n; i++ {
			curr := arr[i] - psum
			
			if curr > mid {
				cnt++
				psum = arr[i - 1]
			} 
		}
		if cnt > m {
			l = mid + 1
		} else {
			r = mid - 1
			ans = mid

		}
	}
	fmt.Fprintln(out, ans)
}