#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr){};
};

/**
 * Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null. There is a cycle in a linked
 * list if there is some node in the list that can be reached again
 * by continuously following the next pointer. Internally, pos is
 * used to denote the index of the node that tail's next pointer is
 * connected to. Note that pos is not passed as a parameter. Notice
 * that you should not modify the linked list.
 */

/**
 * Use hash table. If there is a cycle, node p must be in
 * table.
 * Time  complexity: O(n)
 * Space complexity: O(n)
 */
ListNode *detect_cycle_1(ListNode *head)
{
    unordered_set<ListNode *> s;
    ListNode *p = head;
    while (p) {
        if (s.count(p))
            return p;
        s.insert(p);
    }
    return nullptr;
}

/**
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *                |----|----|
 * Given p1 and p2, p2 moves two steps whenever p1 moves one step.
 * If there is a cycle, p1 and p2 can meet in the cycle.
 * Assuming p2 moved s + kn + m steps, and p1 moved s + qn + m steps
 * Given equation s + kn + m = 2 * (s + qn + m)
 * So, s + m = (k - 2q)n = pn (p > 0)
 * Based on location which val is 4, if p1 continues move s steps
 * from meeting point, it will reach 4 again, and if another pointer
 * moves s steps from 1, it alse will reach 4, so they will meet at
 * 4.
 */

ListNode *detect_cycle_2(ListNode *head)
{
    ListNode *p1, *p2;
    p1 = p2 = head;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
            break;
    }
    if (!p2 || !p2->next)
        return nullptr;
    p1 = head;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
