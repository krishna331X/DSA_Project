#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

// --- LINKED LIST: Har appointment ek Node hai ---
struct Appointment {
    int id;
    string name;
    string service;
    Appointment* next;
    
    Appointment(int i, string n, string s) : id(i), name(n), service(s), next(nullptr) {}
};

class NailStudioSystem {
private:
    Appointment* head;         // Linked List for scheduled tasks
    queue<string> walkInQueue; // Queue for waiting area
    stack<string> logs;        // Stack for undo/history tracking

public:
    NailStudioSystem() : head(nullptr) {}

    // [LINKED LIST] - Adding new booking
    void bookAppointment(int id, string name, string service) {
        Appointment* newNode = new Appointment(id, name, service);
        if (!head) {
            head = newNode;
        } else {
            Appointment* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        logs.push("Booked: " + name);
        cout << "✅ Success: Appointment added for " << name << endl;
    }

    // [QUEUE] - Adding to waiting list
    void addWalkIn(string name) {
        walkInQueue.push(name);
        cout << "⌛ " << name << " is now in the waiting queue." << endl;
    }

    // [QUEUE] - Serving next person
    void serveNext() {
        if (!walkInQueue.empty()) {
            cout << "💅 Now serving from waitlist: " << walkInQueue.front() << endl;
            walkInQueue.pop();
        } else {
            cout << "📭 No one is in the waiting queue." << endl;
        }
    }

    // [STACK] - Undo last action
    void undoLastAction() {
        if (!logs.empty()) {
            cout << "⏪ Undoing: " << logs.top() << endl;
            logs.pop();
        } else {
            cout << "🚫 No actions to undo." << endl;
        }
    }

    // [SEARCHING] - Linear Search in Linked List
    void findCustomer(string name) {
        Appointment* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << "🔍 Found: " << name << " for " << temp->service << " (ID: " << temp->id << ")" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "❌ Customer not found." << endl;
    }

    void displayAll() {
        cout << "\n--- CURRENT APPOINTMENTS ---" << endl;
        Appointment* temp = head;
        while (temp) {
            cout << "[" << temp->id << "] " << temp->name << " -> " << temp->service << endl;
            temp = temp->next;
        }
        cout << "---------------------------\n" << endl;
    }
};

int main() {
    NailStudioSystem studio;
    
    cout << "--- GLOW & GLOSS PREMIUM SYSTEM ---" << endl;
    
    // Demonstrating Logic
    studio.bookAppointment(101, "Ananya", "Gel Extensions");
    studio.bookAppointment(102, "Riya", "Chrome Art");
    studio.addWalkIn("Sonal");
    studio.addWalkIn("Kavita");
    
    studio.displayAll();
    
    studio.findCustomer("Riya");
    studio.serveNext();
    studio.undoLastAction();

    return 0;
}