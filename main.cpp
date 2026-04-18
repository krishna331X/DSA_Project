#include <iostream>
#include "Task.h"

using namespace std;

class TodoList {
private:
    Node* head;
public:
    TodoList() : head(nullptr) {}

    void addTask(int id, string d, int p) {
        Task newTask(id, d, p);
        Node* newNode = new Node(newTask);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Task saved!" << endl;
    }
    void searchTask(string query) {
    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data.desc.find(query) != string::npos) {
            cout << "Found: [" << temp->data.id << "] " << temp->data.desc << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No task matches your search." << endl;
    }

    void show() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data.id << ": " << temp->data.desc << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TodoList list;
    list.addTask(1, "Website Design", 1);
    list.show();
    return 0;
}