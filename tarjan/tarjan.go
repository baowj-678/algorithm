/**
 * @author: baowj
 * @time: 2022/7/31 16:36:15
 */
package tarjan

import (
	"fmt"
)

func dfs(table [][]int, dfn []int, low []int, stack []int, x int, n *int) {
	*n += 1
	tmpN := *n
	dfn[x] = tmpN
	min := tmpN
	stack = append(stack, x)
	for _, y := range table[x] {
		// not visited
		if dfn[y] == -1 {
			dfs(table, dfn, low, stack, y, n)
		}
		// update low
		if min > low[y] {
			min = low[y]
		}
	}

	if tmpN == min {
		i := len(stack) - 1
		for ; i >= 0; i-- {
			if low[stack[i]] < min {
				break
			}
		}
		var output []int
		if i == 0 && low[stack[0]] >= min {
			output = stack
			stack = []int{}
		} else {
			output = stack[i+1:]
			stack = stack[:i]
		}
		fmt.Print(output)
	}
	low[x] = min
}

// table为邻接表
func tarjan(table [][]int) {
	dfn := make([]int, len(table))
	low := make([]int, len(table))
	// init, -1 for not visited
	for i := 0; i < len(table); i++ {
		dfn[i] = -1
		low[i] = -1
	}
	stack := []int{}
	n := 1
	for i := 0; i < len(table); i++ {
		dfs(table, dfn, low, stack, i, &n)
	}
}
