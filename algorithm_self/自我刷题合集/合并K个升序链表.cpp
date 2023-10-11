
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKListsHelper(ListNode* l1, ListNode* l2)
    {
        if ((!l1) || (!l2)) return l1 ? l1 : l2;

        ListNode* head, pre_head;
        head = &pre_head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        //肯定是有一个已经到头了
        head->next = (l1 ? l1 : l2);
        return pre_head.next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            ans = mergeKListsHelper(ans, lists[i]);
        }
        return ans;
    }
};