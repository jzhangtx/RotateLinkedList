// RotateLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

int CountElementsAndMoveToTail(ListNode** pHead)
{
    if (*pHead == nullptr)
        return 0;

    int count = 1;
    while ((*pHead)->next != nullptr)
    {
        ++count;
        *pHead = (*pHead)->next;
    }

    return count;
}

ListNode* RotateListByK(ListNode* head, int k)
{
    if (head == nullptr)
        return head;

    ListNode* pLast = head;
    int count = CountElementsAndMoveToTail(&pLast);
    k = k % count;

    if (k != 0)
    {
        ListNode* pNode = GetNodeByIndex(head, count - k - 1);
        pLast->next = head;
        head = pNode->next;
        pNode->next = nullptr;
    }

    return head;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count < 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The number of nodes to rotate: ";
        int k = -1;
        std::cin >> k;

        pHead = RotateListByK(pHead, k);

        std::cout << "The list after rotated: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
