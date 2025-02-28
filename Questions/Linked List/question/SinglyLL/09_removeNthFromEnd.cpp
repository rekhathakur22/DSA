#include <iostream>
using namespace std;

class Solution
{
public:
  ListNode *removeNthFromEnd_bruteForce(ListNode *head, int n)
  {
    if (head == nullptr)
    {
      return nullptr; // Edge case: empty list
    }

    // Count the total number of nodes
    ListNode *temp = head;
    int nodeCount = 0;
    while (temp != nullptr)
    {
      nodeCount++;
      temp = temp->next;
    }

    // Calculate the position of the node to delete
    int delNode = nodeCount - n;

    // If the node to delete is the head
    if (delNode == 0)
    {
      ListNode *newHead = head->next;
      delete head;
      return newHead;
    }

    // Traverse to the node before the one to delete
    temp = head;
    for (int i = 0; i < delNode - 1; i++)
    {
      temp = temp->next;
    }

    // Delete the node
    ListNode *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;

    /*
    tc:O(len + (len-n)) worst case: 2N
    - where N is number of nodes in linked list
    sc:O(1)
    */
  }

  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    // Initialize two pointers, slow and fast, both starting at the head of the list
    ListNode *slow = head;
    ListNode *fast = head;

    // Traverse the list using the fast pointer
    while (fast->next != NULL)
    {
      // If n is not zero, move only the fast pointer ahead
      if (n)
      {
        fast = fast->next;
        n--; // Decrement n to keep track of the distance between slow and fast
      }
      else
      {
        // Once n is zero, move both slow and fast pointers ahead
        fast = fast->next;
        slow = slow->next;
      }
    }

    // After the loop, if n is still not zero, it means the node to delete is the head
    if (n)
    {
      // Update the head to the next node
      head = head->next;
      // Delete the original head node to free memory
      delete slow;
      // Return the new head
      return head;
    }

    // If the node to delete is not the head, locate the node to delete
    ListNode *NodeToDelete = slow->next;
    // Update the next pointer of the slow node to skip the node to delete
    slow->next = slow->next->next;
    // Delete the node to free memory
    delete NodeToDelete;

    // Return the head of the modified list
    return head;

    /*
    tc:O(n)
    - where n is length of linked list
    sc:O(1)
    */
  }
};