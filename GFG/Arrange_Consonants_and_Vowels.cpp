//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data)
{
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node *arrangeCV(Node *head)
    {
        Node *chead = head;
        Node *dummy = new Node('a');
        Node *dcur = dummy;
        while (chead->data == 'a' || chead->data == 'e' || chead->data == 'i' || chead->data == 'o' || chead->data == 'u')
        {
            dcur->next = chead;
            dcur = dcur->next;
            chead = chead->next;
        }

        Node *prev = chead;
        Node *cur = chead->next;

        while (cur != NULL)
        {
            if (cur->data == 'a' || cur->data == 'e' || cur->data == 'i' || cur->data == 'o' || cur->data == 'u')
            {
                dcur->next = cur;
                dcur = dcur->next;
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        dcur->next = chead;

        return dummy->next;
    }
};

//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--)
        {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends