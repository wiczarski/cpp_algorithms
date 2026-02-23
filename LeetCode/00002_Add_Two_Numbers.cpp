struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curNode1 = l1;
        ListNode* curNode2 = l2;

        int carry = 0;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (curNode1 || curNode2 || carry){
            int a = curNode1 ? curNode1->val : 0;
            int b = curNode2 ? curNode2->val : 0;

            int sum = a + b + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (curNode1) curNode1 = curNode1->next;
            if (curNode2) curNode2 = curNode2->next;

        }

        return dummy.next;

    }
};