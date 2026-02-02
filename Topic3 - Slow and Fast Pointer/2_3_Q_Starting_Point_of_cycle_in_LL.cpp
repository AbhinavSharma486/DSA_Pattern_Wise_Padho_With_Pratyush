// * Question :- Linked List Cycle II
// & Link :- https://leetcode.com/problems/linked-list-cycle-ii/description/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// Function to detect cycle and return starting node of cycle
Node *detectCycle(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }

  Node *slow = head;
  Node *fast = head;

  // step 1 : detect if cycle exists
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      break;
    }
  }

  // no cycle
  if (fast == NULL || fast->next == NULL)
  {
    return NULL;
  }

  // step 2 : find starting node of cycle
  slow = head;

  while (slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }

  return (slow == NULL) ? NULL : slow;
}

int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  n5->next = n3; // cycle created

  Node *cycleStart = detectCycle(n1);

  if (cycleStart)
  {
    cout << "Cycle starts at node with data: " << cycleStart->data << endl;
  }
  else
  {
    cout << "No cycle detected" << endl;
  }

  return 0;
}








// * Question :- 876. Middle of the Linked list
// & Link :- https://leetcode.com/problems/middle-of-the-linked-list/description/?source=submission-ac

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// Function to detect cycle and return starting node of cycle
Node *middleNode(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Node *middle_Node = middleNode(n1);

  if (middle_Node)
  {
    cout << "Middle Node is : " << middle_Node->data << endl;
  }
  else
  {
    cout << "No cycle detected" << endl;
  }

  return 0;
}
