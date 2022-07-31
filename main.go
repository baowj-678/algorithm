/**
 * @author: baowj
 * @time: 2022/4/12 16:43:48
 */
package main

import (
	"fmt"
	"skiplist/skiplist"
)

func main() {
	sl := skiplist.New()
	var action int
	var key int
	var value int
	fmt.Println("Please with the format [action key value].")
	for {
		fmt.Scanln(&action, &key, &value)
		switch action {
		case 1:
			sl.Insert(skiplist.MyKey{Data: key}, &skiplist.MyValue{Data: value})
			fmt.Println("Success")
		case 2:
			ans := sl.Search(skiplist.MyKey{Data: key})
			fmt.Println("V:", ans)
		case 3:
			sl.Delete(skiplist.MyKey{Data: key})
			fmt.Println("Success")
		case 4:
			return
		}
	}
}
