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

	studyTime := make([]int, n)
	score := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &studyTime[i], &score[i])
	}

	var minRss uint64 = 1e12
	var aAns, bAns int

	for a := 1; a <= 100; a++ {
		for b := 1; b <= 100; b++ {
			var rss uint64 = 0
			for i := 0; i < n; i++ {
				x := studyTime[i]
				y := score[i]
				fx := a * x + b
				temp := y - fx
				rss += uint64(temp * temp)
			}
			if rss < minRss {
				minRss = rss
				aAns = a
				bAns = b
			}
		}
	}
	fmt.Fprintf(out, "%d %d\n", aAns, bAns )
}