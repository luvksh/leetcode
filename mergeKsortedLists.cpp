//https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 struct Comparator {
     bool operator()(ListNode *i, ListNode *j)
     {
         return i->val > j->val;
     }
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = NULL;
        ListNode* curr ;
        priority_queue<ListNode*, vector<ListNode*>, Comparator> minHeap;
        for(ListNode* node:lists)
        {
            if(node!= NULL)
                minHeap.push(node);
        }
        if(!minHeap.empty())
        {
            root = minHeap.top();
            minHeap.pop();
            if(root->next != NULL)
            {
                minHeap.push(root->next);
            }
        }
        curr = root;
        while(!minHeap.empty())
        {
            curr->next = minHeap.top();
            minHeap.pop();
            curr = curr->next;
            if(curr->next != NULL)
            {
                minHeap.push(curr->next);
            }
        }
        return root;
    }
};