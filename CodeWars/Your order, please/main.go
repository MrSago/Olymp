/*
	author: MrS4g0
	created: 04.07.2024 17:39:46
	kata link: https://www.codewars.com/kata/55c45be3b2079eccff00010f/train/go
*/

package main

import (
	"fmt"
	"strings"
)

func Order(sentence string) string {
  var splitted = strings.Split(sentence, " ")
  var result = make([]string, len(splitted))

	for i := 0; i < len(splitted); i++ {
		for j := 0; j < len(splitted[i]); j++ {
			if splitted[i][j] >= '0' && splitted[i][j] <= '9' {
				result[splitted[i][j]-'0'-1] = splitted[i]
			}
		}
	}

	return strings.Join(result, " ")
}

func main() {
	fmt.Println(Order("is2 Thi1s T4est 3a"))
	fmt.Println(Order("4of Fo1r pe6ople g3ood th5e the2"))
}
