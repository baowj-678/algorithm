/**
 * @author: baowj
 * @time: 2022/4/12 12:33:05
 */
package skiplist

import "math/rand"

const MaxLevel int = 16
const P float32 = 0.5

type SkipNode struct {
	value   *Value
	key     Key
	forward []*SkipNode
}

type SkipList struct {
	head  *SkipNode
	len   int
	level int
}

func (*SkipNode) compare(node1, node2 *SkipNode) int {
	return node1.key.compare(node1.key, node2.key)
}

// NewNode Create new SkipNode
func NewNode(value *Value, key Key, level int) *SkipNode {
	return &SkipNode{
		value:   value,
		key:     key,
		forward: make([]*SkipNode, level),
	}
}

// New Create new SkipList
func New() *SkipList {
	return &SkipList{
		head: &SkipNode{
			nil,
			nil,
			make([]*SkipNode, MaxLevel),
		},
		level: 0,
		len:   0,
	}
}

// randomLevel get level
func randomLevel() int {
	level := 1
	for rand.Float32() < P && level < MaxLevel {
		level++
	}
	return level
}

func (sl *SkipList) Insert(key Key, value Value) {
	myValue := value.New()
	myValue.Set(value)
	sl.insert(key, &myValue)
}

func (sl *SkipList) insert(key Key, value *Value) *SkipNode {
	update := make([]*SkipNode, MaxLevel)
	tmpNode := sl.head
	for l := sl.level - 1; l >= 0; l-- {
		for tmpNode.forward[l] != nil {
			if key.compare(key, tmpNode.forward[l].key) > 0 {
				tmpNode = tmpNode.forward[l]
			} else if key.compare(key, tmpNode.forward[l].key) == 0 {
				(*tmpNode.forward[l].value).Set(*value)
				return tmpNode.forward[l]
			} else {
				break
			}
		}
		update[l] = tmpNode
	}
	tmpNode = tmpNode.forward[0]
	// if tmpNode is the one, just change the value point to the new value.
	if tmpNode != nil && key.compare(tmpNode.key, key) == 0 {
		tmpNode.value = value
		return tmpNode
	}
	// get random level.
	level := randomLevel()
	// make sure the new level is one bigger than the old level at most.
	if level > sl.level {
		level = sl.level + 1
		update[sl.level] = sl.head
		sl.level = level
	}
	// create new SkipNode
	newNode := NewNode(value, key, level)
	for i := 0; i < level; i++ {
		newNode.forward[i] = update[i].forward[i]
		update[i].forward[i] = newNode
	}
	return newNode
}

func (sl *SkipList) Search(key Key) Value {
	tmpNode := sl.head
	for l := sl.level - 1; l >= 0; l-- {
		for tmpNode.forward[l] != nil {
			if key.compare(key, tmpNode.forward[l].key) > 0 {
				tmpNode = tmpNode.forward[l]
			} else if key.compare(key, tmpNode.forward[l].key) == 0 {
				return *tmpNode.forward[l].value
			} else {
				break
			}
		}
	}
	return nil
}

func (sl *SkipList) Delete(key Key) {
	tmpNode := sl.head
	for l := sl.level - 1; l >= 0; l-- {
		for tmpNode.forward[l] != nil {
			if key.compare(key, tmpNode.forward[l].key) > 0 {
				tmpNode = tmpNode.forward[l]
			} else if key.compare(key, tmpNode.forward[l].key) == 0 {
				tmpNode.forward[l] = tmpNode.forward[l].forward[l]
				break
			} else {
				break
			}
		}
	}
	return
}
