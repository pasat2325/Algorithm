package main

import (
    "fmt"
    "math/big"
)

func main(){
    var aStr, bStr string
    fmt.Scan(&aStr, &bStr)

    a,_ := new(big.Float).SetString(aStr)
    b,_ := new(big.Float).SetString(bStr)

    prec := uint(1999)
    a.SetPrec(prec)
    b.SetPrec(prec)
    
    result := new(big.Float).SetPrec(prec).Quo(a,b)
    fmt.Printf("%.1100f\n", result)
}