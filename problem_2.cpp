//
// Created by Germain Jones on 19/05/2023.
//

#include <vector>
#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        long long number1 = 0;
        long long number2 = 0;
        long long number3;
        int i = 0;
        int j = 0;
        int overflow = 0;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode head = ListNode();
        ListNode *l3 = &head;

        while (ptr1 != nullptr) {
            i += 1;
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr) {
            j += 1;
            ptr2 = ptr2->next;
        }

        int array1[i];
        int array2[j];
        ptr1 = l1;
        ptr2 = l2;

        for (int k = i; 0 < k; --k) {
            array1[k - 1] = ptr1->val;
            ptr1 = ptr1->next;
        }

        for (int k = j; 0 < k; --k) {
            array2[k - 1] = ptr2->val;
            ptr2 = ptr2->next;
        }

        for (auto item: array1) {
            std::cout << item;
        }
        std::cout << "\n";

        for (auto item: array2) {
            std::cout << item;
        }

        int add;
        ListNode* prev = nullptr;
        ListNode* temp;
        if (i == j) {
            for (int index = 0; index < i; index++) {
                add = array1[i] + array2[j] + overflow;
                temp = new ListNode(add % 10);
                overflow = add / 10;
                temp->next = prev;
                prev = temp;
            }

            if (overflow != 0){
                temp = new ListNode(overflow);
                temp->next = prev;
                prev = temp;
            }

        } else if (i < j) {
            for (int index = 0; index < i; index++) {
                add = array1[i] + array2[j] + overflow;
                temp = new ListNode(add % 10);
                overflow = add / 10;
                temp->next = prev;
                prev = temp;
            }

        }
        l3->next = prev;
        return nullptr;
    }
};

int main() {
    Solution solution;
    ListNode a = ListNode(2);
    ListNode b = ListNode(2, &a);


    ListNode c = ListNode(1);
    ListNode e = ListNode(2, &c);

    ListNode *d = solution.addTwoNumbers(&b, &e);
    std::cout << d->val;
    return 0;
}