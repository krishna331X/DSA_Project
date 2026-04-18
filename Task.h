#ifndef TASK_H
#define TASK_H
#include <string>
#include <iostream>

using namespace std;

struct Task {
    int id;
    string desc;
    int priority;
    bool isDone;

    Task(int i, string d, int p) : id(i), desc(d), priority(p), isDone(false) {}
};

struct Node {
    Task data;
    Node* next;
    Node(Task t) : data(t), next(nullptr) {}
};
#endif