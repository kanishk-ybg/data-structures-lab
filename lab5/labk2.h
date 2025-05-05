#ifndef RRHEADER_H
#define RRHEADER_H

#include <stdio.h>
#include <stdlib.h>

class Node {
    int time;
    Node* next;
    friend class CircularQueue; // Allow CircularQueue to access private members
};

class CircularQueue {
    Node* tail;
    int quantum;

public:
    CircularQueue(int q) {
        quantum = q;
        tail = NULL;
    }

    int insertProcess(int);
    void execute();
};

#endif