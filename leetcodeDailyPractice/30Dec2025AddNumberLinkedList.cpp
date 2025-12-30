#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Solution class
class Solution {
public:
    Node* addTwoLists(Node* head1, Node* head2) {
        vector<int> a, b;

        // Store digits of first list
        while (head1) {
            a.push_back(head1->data);
            head1 = head1->next;
        }

        // Store digits of second list
        while (head2) {
            b.push_back(head2->data);
            head2 = head2->next;
        }

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        Node* result = NULL;

        // Add digits from back
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--];
            if (j >= 0) sum += b[j--];

            carry = sum / 10;
            int digit = sum % 10;

            Node* newNode = new Node(digit);
            newNode->next = result;
            result = newNode;
        }

        // Remove leading zeros
        while (result && result->data == 0 && result->next) {
            result = result->next;
        }

        return result;
    }
};

// Utility function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert node at end
Node* insert(Node* head, int data) {
    if (!head) return new Node(data);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
    return head;
}

// Main function
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // First number: 243
    head1 = insert(head1, 2);
    head1 = insert(head1, 4);
    head1 = insert(head1, 3);

    // Second number: 564
    head2 = insert(head2, 5);
    head2 = insert(head2, 6);
    head2 = insert(head2, 4);

    Solution obj;
    Node* result = obj.addTwoLists(head1, head2);

    cout << "Sum Linked List: ";
    printList(result);

    return 0;
}
