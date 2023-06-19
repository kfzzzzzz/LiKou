#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

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