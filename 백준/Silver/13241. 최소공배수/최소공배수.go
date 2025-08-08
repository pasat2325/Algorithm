package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var a,b int64
	fmt.Fscanln(in, &a, &b)
	g := gcd(a, b)
	result := a * b / g
	fmt.Fprintln(out,result)
}