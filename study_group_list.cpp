/*
 * Course: COEN 2220 - Programming 2
 * Name: [Julian A. Pagan Hernandez]
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [15/10/2026]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Define a Node with string groupCode, int meetingRoom, and Node *next.
    struct Node 
    {
        string groupCode;   // Store one group Code
        int meetingRoom;    // Store one meeting room number
        Node *next;         // Store the address of the next node 
    };

    // TODO (Part C): Declare a Node *head data member for the first node address.
    Node *head;

    // TODO (Part C): Declare an int groupCount data member for the number of stored groups.
    int groupCount;

public:
    // TODO (Part C): Write a constructor that creates an empty list and sets groupCount to zero.
    StudyGroupList()
    {
        head = nullptr; // A new list begins with no nodes.
        groupCount = 0; // Initialize groupCount to zero.
    }

    bool isEmpty() const
    {
        return head == nullptr; // No first node means the list is empty.
    }

    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write addGroup. It receives a group code and room number, adds one node at the end, and updates groupCount.
    void addGroup(const string& newGroupCode, int newMeetingRoom)
    {
        Node *newNode = new Node;
        newNode->groupCode = newGroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next !=nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
        groupCount++; // Update groupCount when a new group is added.   
    }
    // TODO (Part D): Write displayGroups as a const member function.
    void displayGroups() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Magic Group Code: " << currentNode->groupCode << ", Meeting Room: " << currentNode->meetingRoom << endl; 
            currentNode = currentNode->next;
        }
    }
    // TODO (Part D): Write size as a const member function that returns groupCount.
    int size() const
    {
        return groupCount;
    }

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudyGroupList object.
    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    // TODO (Part E): Display every stored group and print the result of size().
    // TODO (Part E): Search for one stored group code and one missing group code; print both bool results.

    return 0;
}