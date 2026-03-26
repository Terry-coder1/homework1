#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 反转链表函数
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// 创建链表（尾插法保持原始顺序）
ListNode *createList(int len)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int i = 0; i < len; i++)
    {
        int num;
        cin >> num;
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

// 两链表相加（低位在前格式）
ListNode *addLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *cur = &dummy;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }
    return dummy.next;
}

// 打印链表
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

// 释放链表内存
void freeList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    // 创建原始链表（高位在前）
    ListNode *num1 = createList(m);
    ListNode *num2 = createList(n);

    // 反转链表使低位在前
    ListNode *rev1 = reverseList(num1);
    ListNode *rev2 = reverseList(num2);

    // 相加得到结果（低位在前）
    ListNode *sumList = addLists(rev1, rev2);

    // 反转结果使高位在前
    ListNode *result = reverseList(sumList);

    // 输出最终结果
    printList(result);

    // 释放内存
    freeList(rev1);
    freeList(rev2);
    freeList(result);

    return 0;
}
