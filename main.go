/**
 * @author: baowj
 * @time: 2022/4/12 16:43:48
 */
package main

import (
	"fmt"
	"skiplist/skiplist"
)

type TestInter interface {
	print()
	set(v int)
}

type TestStruct struct {
	Data int
}

func (ts *TestStruct) print() {
	fmt.Println(ts.Data)
}

func (ts *TestStruct) set(v int) {
	ts.Data = v
}

func printf(inter TestInter) {
	inter.print()
}

func setf(inter TestInter, v int) {
	inter.set(v)
	inter.print()
}

func main() {
	//testStruct := new(TestStruct)
	//testStruct.print()
	//printf(&testStruct)
	//
	//setf(&testStruct, 89)
	//testStruct.print()

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
