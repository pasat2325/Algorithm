package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)
func main(){
	var in *bufio.Reader = bufio.NewReader(os.Stdin)
	var out *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n int
	fmt.Fscanln(in, &n)
	for i := 1; i <= n; i++ {
		line, _ := in.ReadString('\n')
		line = strings.TrimRight(line, "\r\n")
		fmt.Fprintf(out, "%d. %s\n", i, line)
	}

} 