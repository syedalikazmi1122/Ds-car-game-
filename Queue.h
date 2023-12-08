//AyeshaShahid_2483_SE-B
//Ali Kazmi_22i2472_SE-B
//Saima Saleem_22i2498_SE-B
#pragma once
#include <iostream>
using namespace std;

class node_of_queue
{
public:
    int index_x_of_bonus;
    int index_y_of_bonus;
    node_of_queue* pointer_to_the_next;

    // Default constructor
    node_of_queue()
    {
        index_x_of_bonus = 0;
        index_y_of_bonus = 0;
        pointer_to_the_next = nullptr;
    }

    // Parameterized constructor
    node_of_queue(int x, int y)
    {
        index_x_of_bonus = x;
        index_y_of_bonus = y;
        pointer_to_the_next = nullptr;
    }
};

class Queue {
private:
    node_of_queue* front_pointer;
    node_of_queue* rear_pointer;

public:
    // Constructor
    Queue()
    {
        front_pointer = rear_pointer = nullptr;
    }

    // Destructor
    ~Queue()
    {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front_pointer == nullptr;
    }

    // Function to enqueue a node
    void enqueue(int x_index, int y_index)
    {
        node_of_queue* the_new_node = new node_of_queue(x_index, y_index);

        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            front_pointer = rear_pointer = the_new_node;
        }
        else {
            rear_pointer->pointer_to_the_next = the_new_node;
            rear_pointer = the_new_node;
        }
    }

    // Function to dequeue a node
    void dequeue()
    {
        // If the queue is empty, do nothing
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        node_of_queue* temp = front_pointer;
        front_pointer = front_pointer->pointer_to_the_next;
        delete temp;

        // If the queue becomes empty after dequeue, update rear to null
        if (front_pointer == nullptr) {
            rear_pointer = nullptr;
        }
    }

    // Function to display the elements in the queue
    void displayQueue()
    {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        node_of_queue* current = front_pointer;
        while (current != nullptr) {
            cout << "X-index " << current->index_x_of_bonus << ", Index y " << current->index_y_of_bonus << endl;
            current = current->pointer_to_the_next;
        }
    }
};

