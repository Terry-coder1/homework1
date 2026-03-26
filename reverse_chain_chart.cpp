#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

int main()
{
    int n;
    cin >> n; // 读取节点数量

    // 构建链表（头插法）
    Node *head = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        Node *newNode = new Node(num);
        newNode->next = head;
        head = newNode;
    }

    // 直接输出逆序结果（无需额外反转）
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
            cout << " ";
        current = current->next;
    }

    // 释放内存
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}