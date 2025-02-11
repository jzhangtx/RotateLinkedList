package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) (*ListNode, *ListNode) {
	if len(v) == 0 {
		return nil, nil
	}

	if len(v) == 1 {
		pNode := &ListNode{v[0], nil}
		return pNode, pNode
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead, pCur
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
	}
	if pNode.next != nil {
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func GetNodeByIndex(head *ListNode, index int) *ListNode {
	for i := 0; i < index; i++ {
		head = head.next
	}

	return head
}

func CountListMoveToTail(head *ListNode) (int, *ListNode) {
	count := 1
	for ; head.next != nil; head = head.next {
		count++
	}

	return count, head
}

func RotateListByK(head *ListNode, k int) *ListNode {
	count, pTail := CountListMoveToTail(head)
	k = k % count

	if k != 0 {
		pNode := GetNodeByIndex(head, count-k-1)
		pTail.next = head
		head = pNode.next
		pNode.next = nil
	}

	return head
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the list: ")
		pHead, _ := GetListFromArray(vec)

		fmt.Print("Please enter number k (to rotate): ")
		var k int
		fmt.Scan(&k)
		pHead = RotateListByK(pHead, k)

		fmt.Print("The rotated list: ")
		pHead.Print()
	}
}
