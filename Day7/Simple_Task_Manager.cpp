#include <iostream>
#include <string>
using namespace std;

struct Task {
    int id;
    string name;
    Task* next;
    Task(int tid, string tname) {
        id = tid;
        name = tname;
        next = NULL;
    }
};

class TaskManager {
private:
    Task* head;
public:
    TaskManager() { head = NULL; }

    // Add at end (new task)
    void addTask(int id, string name) {
        Task* newTask = new Task(id, name);
        if (head == NULL) {
            head = newTask;
            return;
        }
        Task* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newTask;
    }

    // Insert at priority position (1 = highest priority)
    void insertTaskAt(int pos, int id, string name) {
        Task* newTask = new Task(id, name);
        if (pos == 1) {
            newTask->next = head;
            head = newTask;
            return;
        }
        Task* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            delete newTask;
            return;
        }
        newTask->next = temp->next;
        temp->next = newTask;
    }

    // Delete task by ID
    void deleteTask(int id) {
        if (head == NULL) return;

        if (head->id == id) {
            Task* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Task* temp = head;
        while (temp->next != NULL && temp->next->id != id) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Task not found!" << endl;
            return;
        }
        Task* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search task by ID
    bool searchTask(int id) {
        Task* temp = head;
        while (temp != NULL) {
            if (temp->id == id) return true;
            temp = temp->next;
        }
        return false;
    }

    // Print all tasks
    void printTasks() {
        Task* temp = head;
        if (temp == NULL) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << "Task List: " << endl;
        while (temp != NULL) {
            cout << "ID: " << temp->id << ", Task: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TaskManager tm;

    // Add tasks
    tm.addTask(101, "Complete assignment");
    tm.addTask(102, "Prepare for exam");
    tm.addTask(103, "Buy groceries");

    cout << "Initial tasks:" << endl;
    tm.printTasks();

    // Insert priority task at position 2
    tm.insertTaskAt(2, 104, "Urgent meeting");
    cout << "\nAfter inserting urgent task:" << endl;
    tm.printTasks();

    // Delete completed task
    tm.deleteTask(102);
    cout << "\nAfter deleting task 102:" << endl;
    tm.printTasks();

    // Search
    cout << "\nSearching for task 103: " 
         << (tm.searchTask(103) ? "Found" : "Not Found") << endl;
    cout << "Searching for task 200: " 
         << (tm.searchTask(200) ? "Found" : "Not Found") << endl;

    return 0;
}
