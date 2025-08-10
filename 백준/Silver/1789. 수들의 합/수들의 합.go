package main

import (
	"bufio"
	"fmt"
	"os"
)
func main(){
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var S uint64
	fmt.Fscan(in,&S)
	var sum, i uint64 = 0, 1
	cnt := 0
	for {
		if sum >= S {
			break
		}
		sum += i
		cnt++
		i++
	}
	if sum == S {
		fmt.Fprint(out, cnt)
	} else {
		fmt.Fprint(out, cnt - 1)
	}
	
}