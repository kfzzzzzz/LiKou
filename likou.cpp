#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // 剑指 Offer 25. 合并两个排序的链表
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *prevHead = new ListNode(-1);
        ListNode *curr = prevHead;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 != NULL ? l1 : l2;
        return prevHead->next;
    }

    // 剑指 Offer 03. 数组中重复的数字
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, bool> umap;
        for (int num : nums)
        {
            if (umap[num] == true)
                return num;
            umap[num] = true;
        };
        return -1;
    }
};

// 剑指 Offer 09. 用两个栈实现队列
class CQueue
{
public:
    stack<int> inStack, outStack;

    CQueue() {}

    void appendTail(int value)
    {
        inStack.push(value);
    }

    int deleteHead()
    {
        if (outStack.empty())
        {
            if (!inStack.empty())
            {
                while (!inStack.empty())
                {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
                int tempValue = outStack.top();
                outStack.pop();
                return tempValue;
            }
            else
            {
                return -1;
            }
        }
        int tempValue = outStack.top();
        outStack.pop();
        return tempValue;
    }
};

class unityFunc
{
public:
    ListNode *createListNode(vector<int> &a)
    {
        ListNode *prevHead = new ListNode(-1);
        ListNode *curr = prevHead;
        for (int i = 0; i < a.size(); i++)
        {
            curr->next = new ListNode(a[i]);
            curr = curr->next;
        }
        return prevHead->next;
    };

    void printListNode(ListNode *head)
    {
        cout << "ListNode:";
        while (head != nullptr)
        {
            cout << head->val << ",";
            head = head->next;
        }
        cout << endl;
        return;
    };
};

int main()
{
    vector<int> a1 = {1, 2, 3, 4, 5, 7, 10};
    vector<int> a2 = {1, 5, 6, 9};
    unityFunc unityFunc;
    Solution solution;
    ListNode *l1 = unityFunc.createListNode(a1);
    ListNode *l2 = unityFunc.createListNode(a2);
    ListNode *result = solution.mergeTwoLists(l1, l2);
    unityFunc.printListNode(result);
    return 0;
}