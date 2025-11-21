package main

import (
	"bufio"
	"os"
	"slices"
	"strconv"
)

/*
------ Template start ------
*/

var (
	scanner = bufio.NewScanner(os.Stdin)
	out     = bufio.NewWriter(os.Stdout)
)

func ri() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func wi(n int) {
	out.WriteString(strconv.Itoa(n))
}

func wnl() {
	out.WriteByte('\n')
}

/*
====== Template end ======
*/

func main() {
	defer out.Flush()
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 1<<20), 1<<20)

}
