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
	
	alpha := make([]int, 26)
	
	var str string
	fmt.Fscanln(in, &str)
	slen := len(str)
	
	for i := 0; i < slen; i++ {
		alpha[int(str[i] - byte('A'))]++
	}

	switch slen {
	case 1:
		fmt.Fprintf(out, "%s", str)
	case 2:
		if str[0] == str[1] {
			fmt.Fprintf(out, "%s", str)
		} else {
			fmt.Fprintln(out, "I'm Sorry Hansoo")
		}
	default:
		var isP bool = true
		if slen % 2 == 0 {
			for _,i := range alpha {
				//fmt.Printf("%d ", i)
				if i > 0 && i % 2 != 0 {
					isP = false
				}
			}
			if isP {
	
				index := 0
				result := make([]byte, slen)
				for i, c := range alpha {
					if c > 0 {
						for j := 0; j < c / 2; j++ {
							result[index] = byte(i) + byte('A')
							result[slen - index - 1] = byte(i) + byte('A') 
							index++
						}
					}
				}
				fmt.Fprintln(out, string(result))
			} else {
				fmt.Fprintln(out, "I'm Sorry Hansoo")
			}
		} else {
			oddCount := 0
			oddIndex := -1
			for a,i := range alpha {
				if i > 0 && i % 2 != 0 {
					oddCount++
					oddIndex = a
				}
			}
			if oddCount > 1 {
				isP = false
			}
			if isP {
				index := 0
				result := make([]byte, slen)
				for i, c := range alpha {
					if c > 0 {
						if oddIndex == i {
							result[slen / 2] = byte(i) + byte('A')
						}
						for j := 0; j < c / 2; j++ {
							result[index] = byte(i) + byte('A')
							result[slen - index - 1] = byte(i) + byte('A') 
							index++
						}
					}
				}
				fmt.Fprintln(out, string(result))
			} else {
				fmt.Fprintln(out, "I'm Sorry Hansoo")
			}

		}
	}
}