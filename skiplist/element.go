/**
 * @author: baowj
 * @time: 2022/4/12 15:15:33
 */
package skiplist

type Key interface {

	// compare
	// k1 > k2 int > 0
	// k1 == k2 int = 1
	// k1 < k2 int < 0
	compare(k1, k2 Key) int
}

type Value interface {
	Set(value Value)
	New() Value
}

type MyValue struct {
	Data int
}

type MyKey struct {
	Data int
}

func (mv *MyValue) Set(value Value) {
	mv.Data = value.(*MyValue).Data
}

func (mv *MyValue) New() Value {
	dst := new(MyValue)
	return dst
}

func (MyKey) compare(k1, k2 Key) int {
	if k1 == nil && k2 == nil {
		return 0
	}
	if k1 == nil {
		return -1
	}
	if k2 == nil {
		return 1
	}
	return k1.(MyKey).Data - k2.(MyKey).Data
}
