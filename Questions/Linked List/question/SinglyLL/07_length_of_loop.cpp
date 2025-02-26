#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

// Definition of singly linked list
struct ListNode
{
  int data;
  ListNode *next;
  ListNode(int x) : data(x), next(NULL) {}
};

class Solution
{
public:
  int brute_force(ListNode *head)
  {
    map<ListNode *, int> visitedNodes;
    int cycleNodeCount = 0;
    ListNode *temp = head;

    while (temp != NULL)
    {
      // if node is visited previously
      if (visitedNodes.find(temp) != visitedNodes.end())
      {
        ListNode *startNode = temp;
        cycleNodeCount++;
        temp = temp->next;
        while (temp != startNode)
        {
          cycleNodeCount++;
          temp = temp->next;
        }
        break;
      }
      visitedNodes[temp] = 1;
      temp = temp->next;
    }

    return cycleNodeCount;

    /*
    tc: O(N *2 log N)  + O(N)
    -where N is for traversing the LL , log N for map operations , where N is number of nodes in LL
    -The inner loop does not make the complexity O(N²) because it runs only once per cycle detection, not for every node in the list. The worst-case scenario remains O(N log N) due to the map operations.
    sc:O(N)
    - extra space used for storing all nodes , and some constant space also used
    */
  }

  int better(ListNode *head)
  {
    map<ListNode *, int> visitedNode; // store node address and its index (1 based indexing)
    ListNode *temp = head;
    int count = 1; // length of LL
    while (temp != NULL)
    {
      if (visitedNode.find(temp) != visitedNode.end())
        return count - visitedNode[temp]; // lenght of cylce
      visitedNode[temp] = count;
      temp = temp->next;
      count++; // increasing the length after visiting the node
    }

    return 0;

    /*
    tc: O(N * 2 * log N)
    - N for traversing the complete linked list , log N for map operations
    sc:O(N)
    - uses N extra space , N is number of nodes in linked list
    */
  }

  int optimal(ListNode *head)
  {
    // initialising two pointers slow and fast both starting from head
    ListNode *slow = head;
    ListNode *fast = head;

    // counts the length of loop in linked list
    int count = 0;
    // traverse until not reaching the last node
    while (fast != NULL && fast->next != NULL)
    {
      // move pointer by one step
      slow = slow->next;
      // move pointer by two step
      fast = fast->next->next;
      // if cycle detected
      if (slow == fast)
      {
        count++;           // increase loop length
        slow = slow->next; // move slow or fast pointer  one step
        while (slow != fast)
        {
          count++;
          slow = slow->next;
        }

        break; // break the loop if length is counted
      }
    }
    return count;

    /*
    tc:O(N)
    -N for traversing the linked list
    sc:O(1)
    -not using any extra space rather then constant space
    */
  }
};

int main()
{
  // creating a linked list
  int n;
  cin >> n; // Number of nodes

  if (n == 0)
    return 0;

  ListNode *head = NULL;
  ListNode *tail = NULL;
  unordered_set<ListNode *> nodes;

  // Taking input for linked list
  for (int i = 0; i < n; ++i)
  {
    int value;
    cin >> value;
    ListNode *newNode = new ListNode(value);
    nodes.insert(newNode);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // creating a cycle for testing purpose (comment out if not needed)
  if (n > 1)
  {
    tail->next = head->next; // example: pointing last node to the second node
  }

  // creating the solution object and returning number of nodes in cyle if list contain cycle
  Solution ob;
  int nodeCount = ob.optimal(head);

  // output the result
  cout << (nodeCount ? "cycle detected and has nodes: " : "cycle not detected") << nodeCount << endl;

  // clean up the allocated nodes to avoid memory leak
  for (auto node : nodes)
  {
    delete node;
  }

  return 0;
}