#include <iostream>
#include <vector>
#include <array>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

/**
 * Given head, the head of a linked list, determine if the linked list
 * a cycle in it. There is a cycle in a linked list if there is some node
 * in the list that can be reached again by continuously following the
 * next pointer. Internally, pos is used to denote the index of the node
 * that tail's next pointer is connected to.
 * Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list.
 * Otherwise, return false.
 *
 */
bool has_cycle(ListNode *head)
{
    ListNode *p1, *p2;
    p1 = p2 = head;
    while (p2 && p2->next) {
        // P1 moves one step when p2 moves every two steps,
        // thus p2 moves twice as far as p1.
        p1 = p1->next;
        p2 = p2->next->next;
        // If there is a ring, p2 will catch up with p1.
        if (p1 == p2)
            return true;
    }
    return false;
}

/**
 * 1 -> 2 -> 3 -> 4 -> 5
 * [(5, 1), (1, 2), (2, 3), (3, 4), (4, 5), (5, 6)]
 */
ListNode* create_list(int list[][2])
{
    ListNode *head, *p;
    head = p = new ListNode(0);
    for (int i = list[0][1]; i != 0; i = list[i][1]) {
        p->next = new ListNode(list[i][0]);
        p = p->next;
    }
    p = head;
    head = head->next;
    delete p;
    return head;
}

int main()
{
    int a[6][2] = {{5, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}};
    ListNode *head = create_list(a);
    assert(has_cycle(head) == false);
    head->next->next = head;
    assert(has_cycle(head) == true);
    delete head;
    return 0;
}
