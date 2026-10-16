/*
 * Course: COEN 2220 - Programming 2
 * Name: [Julian A. Pagan Hernandez]
 * Lab: Lab 9 - Linked Lists
 * Description: Guided example - a linked list of lost-item codes
 * Due date: [10/15/2026]
 */

#include <iostream>
#include <string>
using namespace std;

class LostItemList
{
private:
    struct Node
    {
        string itemCode; // Store one lost-item code.
        Node *next;      // Store the address of the next node.
    };

    Node *head;          // Store the first node address or nullptr.

public:
    LostItemList()
    {
        head = nullptr;  // A new list begins with no nodes.
    }

    bool isEmpty() const
    {
        return head == nullptr; // No first node means the list is empty.
    }

    // --- STEP B2: Add one item at the end ---
    
    void addItem(const string& newItemCode)
    {
        Node *newNode = new Node;
        newNode->itemCode = newItemCode;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }
    

    // --- STEP B3: Traverse and search the list ---
    
    void display() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Lost item: " << currentNode->itemCode << endl;
            currentNode = currentNode->next;
        }
    }

    bool contains(const string& targetItemCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->itemCode == targetItemCode)
            {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
    
};

int main()
{
    cout << boolalpha; // Print bool results as true or false.

    LostItemList lostItems;

    cout << "\n------------------------------\n" << endl;
    cout << "-> List starts empty: " << lostItems.isEmpty() << endl;
    cout << "\n------------------------------" << endl;
    // --- STEP B2: Add dummy lost-item codes ---
    
    lostItems.addItem("LF-104");
    lostItems.addItem("LF-215");
    lostItems.addItem("LF-330");

    cout << "\n-> List starts empty after additions: "
         << "-" << lostItems.isEmpty() << "\n" << endl;
    

    // --- STEP B3: Display and search stored codes ---
    
    lostItems.display();
    cout << "\n-------------------------------\n" << endl;
    cout << "Contains LF-215: " << lostItems.contains("LF-215") << endl;
    cout << "Contains LF-999: " << lostItems.contains("LF-999") << endl;
    cout << "\n------------------------------\n" << endl;
    cout << "-> Another Dummy Values\n" << endl;
    cout << "Contains LF-440: " << lostItems.contains("LF-440") << endl;
    cout << "Contains LF-104: " << lostItems.contains("LF-104") << endl;
    cout << "\n------------------------------\n" << endl;
    

    return 0;
}

/*
 * Analysis Answers
 *
 * B4 — Appending LF-330
 * When addItem("LF-330") reaches its final assignment, which node does head point to,
 * which node does currentNode point to, and what link is created? Explain why head does
 * not change in this case.
 * Answer:
 * - Head is pointing to LF-104, current node is pointing to LF-215.
 * - The link created is Lf-330, because the node 215 is no longer nullptr and start to point to the new node Lf-330.
 * - The head does not change because it only can change when the first node of the list changes.It cna only happen when the list is empty; the "if (head == nullptr)".
 * 
 *
 * B5 — Traversal and linear search
 * What traversal step do display and contains have in common? What is different about
 * the action each function performs at a node, and why may contains stop earlier?
 * Answer:
 * - Both functions starts with 'Node *currentNode = head;' and the go thru the list with a while loop cicle "while (currentNode != nullptr)"; going to the next node with "currentNode = currentNode->next;".
 * - The difference on the action of every node is that display prints 'itemCode' of each node, without any condition; it always going to visit all the nodes.
 * - The contains compare the 'itemCode' of the node with 'targetItemCode'. It does not print anything, it only decide if there is conscience. 
 * - Contains may stop earlier because its objective is to know if the code exists, not show every code. When it finds a code, it can return true and stop the search, without checking all the nodes. 
 * 
 */