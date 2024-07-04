/*
	author: MrS4g0
	created: 04.07.2024 17:33:01
	kata link: https://www.codewars.com/kata/515de9ae9dcfc28eb6000001/train/go
*/

package main

import (
	"fmt"
)

func Solution(str string) []string {
	if len(str) % 2 != 0 {
		str += "_"
	}

	var result []string
	for i := 0; i < len(str); i += 2 {
		result = append(result, str[i:i+2])
	}

	return result
}

func main() {
	fmt.Println(Solution("abc"))
	fmt.Println(Solution("abcdef"))
}
