//AyeshaShahid_2483_SE-B
//Ali Kazmi_22i2472_SE-B
//Saima Saleem_22i2498_SE-B
#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
//#include <unistd.h>
#include <chrono>
#include <climits>
#include<thread>
#include <list>
#include <windows.h> // Make sure this header is included to use SetConsoleTextAttribute
#include <ctime>
using namespace std;

class Node
{
public:
    class list
    {
    public:
        list* pointer_next_node;
        int value_at_node;
        int size;
        list()
        {
            pointer_next_node = nullptr;
            value_at_node = -1;
            size = 0;
        }
        int getsize()
        {
            list* temp = pointer_next_node;
            while (temp != nullptr)
            {
                size++;
                temp = temp->pointer_next_node;
            }
            return size;
        }
    } *the_adjacency_list;
    int current;
    int weight_of_the_edge;
    Node* next_node_pointer;
    Node()
    {
        weight_of_the_edge = 0;
        next_node_pointer = nullptr;
    }

    Node(int value, int weight)
    {
        weight_of_the_edge = weight;
        next_node_pointer = nullptr;
    }
};

class AutoQueue
{
private:
    list<pair<int, int>> elements;

public:
    bool empty()
    {
        return elements.empty();
    }

    void push(pair<int, int> element)
    {
        elements.push_back(element);
        elements.sort();
    }

    pair<int, int> top()
    {
        return elements.front();
    }

    void pop()
    {
        elements.pop_front();
    }
};

class AutoStack
{
private:
    list<int> elements;

public:
    void push(int element)
    {
        elements.push_front(element);
    }

    int top()
    {
        return elements.front();
    }

    void pop()
    {
        elements.pop_front();
    }

    bool empty()
    {
        return elements.empty();
    }
};

class graph_auto
{
private:
    int vertex_node;
    Node* the_adjacency_matrix[10][10];

public:
    graph_auto(int vertex)
    {
        vertex_node = vertex;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                the_adjacency_matrix[i][j] = new Node();
                the_adjacency_matrix[i][j]->current = i * vertex_node + j;
                the_adjacency_matrix[i][j]->the_adjacency_list = new Node::list();
                the_adjacency_matrix[i][j]->weight_of_the_edge = 0;
                the_adjacency_matrix[i][j]->next_node_pointer = nullptr;
            }
        }
    }

    bool checking_if_edge_exist(int node1, int node2)
    {
        Node* temporary_node = nullptr;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (the_adjacency_matrix[i][j]->current == node1)
                {
                    temporary_node = the_adjacency_matrix[i][j];
                    break;
                }
            }
        }

        if (temporary_node == nullptr)
        {
            return false;
        }

        for (Node* current_node = temporary_node; current_node != nullptr; current_node = current_node->next_node_pointer)
        {
            Node::list* temp_list = current_node->the_adjacency_list;
            while (temp_list != nullptr)
            {
                if (temp_list->value_at_node == node2)
                {
                    return true;
                }
                temp_list = temp_list->pointer_next_node;
            }
        }
        return false;
    }

    int calculate_number_of_possible_connections(int i, int j)
    {
        int number_of_possible_connections = 0;

        if (i > 0)
        {
            number_of_possible_connections++;
        }

        if (i < vertex_node - 1)
        {
            number_of_possible_connections++;
        }

        if (j > 0)
        {
            number_of_possible_connections++;
        }

        if (j < vertex_node - 1)
        {
            number_of_possible_connections++;
        }
        return number_of_possible_connections;
    }

    int generate_connections(int minimum_connections, int maximum_connection, int number_of_possible_connections)
    {
        int connections = 0;
        do
        {
            connections = minimum_connections + rand() % (maximum_connection - minimum_connections + 1);
        } while (connections > number_of_possible_connections);
        return connections;
    }

    void generate_random_values(int i, int j, int* random_values, int& counter)
    {
        if (i > 0)
        {
            random_values[counter++] = the_adjacency_matrix[i - 1][j]->current;
        }

        if (i < vertex_node - 1)
        {
            random_values[counter++] = the_adjacency_matrix[i + 1][j]->current;
        }

        if (j > 0)
        {
            random_values[counter++] = the_adjacency_matrix[i][j - 1]->current;
        }

        if (j < vertex_node - 1)
        {
            random_values[counter++] = the_adjacency_matrix[i][j + 1]->current;
        }
    }

    void adding_the_possible_connection(int i, int j, int* random_values, int counter, int weight)
    {
        int number_of_connections = rand() % 2 + 2;
        number_of_connections = min(number_of_connections, counter);

        bool selected[4] = { false };

        for (int k = 0; k < number_of_connections; k++)
        {
            int index;
            do
            {
                index = rand() % counter;
            } while (selected[index]);

            selected[index] = true;

            if (random_values[index] < 0)
            {
                continue;
            }

            Node::list* current_connection = the_adjacency_matrix[i][j]->the_adjacency_list;
            while (current_connection != nullptr && current_connection->value_at_node != random_values[index])
            {
                current_connection = current_connection->pointer_next_node;
            }

            if (current_connection == nullptr)
            {
                Node::list* new_connection = new Node::list();
                new_connection->value_at_node = random_values[index];
                new_connection->pointer_next_node = the_adjacency_matrix[i][j]->the_adjacency_list->pointer_next_node;
                the_adjacency_matrix[i][j]->the_adjacency_list->pointer_next_node = new_connection;
            }

            the_adjacency_matrix[i][j]->weight_of_the_edge = weight;

            int x = random_values[index] / vertex_node;
            int y = random_values[index] % vertex_node;
            current_connection = the_adjacency_matrix[x][y]->the_adjacency_list;
            while (current_connection != nullptr && current_connection->value_at_node != the_adjacency_matrix[i][j]->current)
            {
                current_connection = current_connection->pointer_next_node;
            }

            if (current_connection == nullptr)
            {
                Node::list* new_connection = new Node::list();
                new_connection->value_at_node = the_adjacency_matrix[i][j]->current;
                new_connection->pointer_next_node = the_adjacency_matrix[x][y]->the_adjacency_list->pointer_next_node;
                the_adjacency_matrix[x][y]->the_adjacency_list->pointer_next_node = new_connection;
            }

            the_adjacency_matrix[x][y]->weight_of_the_edge = weight;
        }
    }

    void generating_the_random_graph()
    {
        srand(static_cast<unsigned>(time(0)));

        for (int i = 0; i < vertex_node; i++)
        {
            for (int j = 0; j < vertex_node; j++)
            {
                int max_connection = 4;
                int min_connections = 2;
                int possible_connections = calculate_number_of_possible_connections(i, j);
                int connections = generate_connections(min_connections, max_connection, possible_connections);
                int weight = rand() % 10;

                int counter = 0;
                int rand_values[4] = { -1, -1, -1, -1 };
                generate_random_values(i, j, rand_values, counter);

                for (int k = counter - 1; k > 0; k--)
                {
                    int l = rand() % (k + 1);
                    int temporary = rand_values[k];
                    rand_values[k] = rand_values[l];
                    rand_values[l] = temporary;
                }

                int final_random = (rand() % (counter - min_connections + 1)) + min_connections;
                adding_the_possible_connection(i, j, rand_values, final_random, weight);
            }
        }
    }

    void printing_the_maze(int source, int destination, int car_x, int car_y) {
        int index_of_the_neighbour, x_cordinate, y_cordinate;
        HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle

        for (int i = 0; i < vertex_node; i++) {
            cout << "\t\t\t";
            for (int j = 0; j < vertex_node; j++) {
                Node::list* the_current_connection = the_adjacency_matrix[i][j]->the_adjacency_list;
                bool connection_found = false;

                while (the_current_connection != nullptr) {
                    index_of_the_neighbour = the_current_connection->value_at_node;
                    x_cordinate = index_of_the_neighbour / vertex_node;
                    y_cordinate = index_of_the_neighbour % vertex_node;

                    if ((x_cordinate == i - 1 && y_cordinate == j) ||
                        (x_cordinate == i + 1 && y_cordinate == j) ||
                        (x_cordinate == i && y_cordinate == j - 1) ||
                        (x_cordinate == i && y_cordinate == j + 1)) {
                        connection_found = true;
                        break;
                    }

                    the_current_connection = the_current_connection->pointer_next_node;
                }

                // Set different colors for different items
                if (i == car_x && j == car_y) {
                    SetConsoleTextAttribute(console_color, 14); // Yellow for the car
                    cout << " C ";
                    SetConsoleTextAttribute(console_color, 7); // Reset to default color
                }
                else if (i * vertex_node + j == source) {
                    SetConsoleTextAttribute(console_color, 10); // Green for the source
                    cout << " S ";
                    SetConsoleTextAttribute(console_color, 7); // Reset to default color
                }
                else if (i * vertex_node + j == destination) {
                    SetConsoleTextAttribute(console_color, 12); // Red for the destination
                    cout << " D ";
                    SetConsoleTextAttribute(console_color, 7); // Reset to default color
                }
                else if (connection_found) {
                    SetConsoleTextAttribute(console_color, 3); // Cyan for path
                    cout << " X ";
                    SetConsoleTextAttribute(console_color, 7); // Reset to default color
                }
                else {
                    SetConsoleTextAttribute(console_color, 8); // Gray for no path
                    cout << " * ";
                    SetConsoleTextAttribute(console_color, 7); // Reset to default color
                }
            }
            cout << endl;
        }
    }


    void dijkstra(int source, int destination, AutoStack& shortest_path)
    {
        int dist[100];
        int prev[100];
        AutoQueue pq;

        for (int i = 0; i < vertex_node * vertex_node; i++)
        {
            dist[i] = INT_MAX;
            prev[i] = -1;
        }

        dist[source] = 0;
        pq.push({ 0, source });

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (int v = 0; v < vertex_node * vertex_node; v++)
            {
                if (checking_if_edge_exist(u, v) && dist[u] != INT_MAX && dist[u] + the_adjacency_matrix[u / vertex_node][u % vertex_node]->weight_of_the_edge < dist[v])
                {
                    dist[v] = dist[u] + the_adjacency_matrix[u / vertex_node][u % vertex_node]->weight_of_the_edge;
                    prev[v] = u;
                    pq.push({ dist[v], v });
                }
            }
        }

        // Build the shortest path
        for (int v = destination; v != -1; v = prev[v])
        {
            shortest_path.push(v);
        }
        move_car(shortest_path, source, destination);
    }

    // Add this method to graph_auto class
    void print_shortest_path(AutoStack& shortest_path, int source, int destination) {
        
        HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        AutoStack print_path = shortest_path;
        // Create a 2D array to represent the maze with the shortest path
        char maze[10][10];
        
        // Initialize the maze with no path characters
        for (int i = 0; i < vertex_node; i++) {
            for (int j = 0; j < vertex_node; j++) {
                maze[i][j] = '*'; // Initialize with no path
            }
        }

        // Mark the path on the maze
        while (!print_path.empty()) {
            int position = print_path.top();
            int x = position / vertex_node;
            int y = position % vertex_node;
            maze[x][y] = 'X'; // Mark the shortest path
            print_path.pop();
        }

        // Mark the source and destination
        maze[source / vertex_node][source % vertex_node] = 'S';
        maze[destination / vertex_node][destination % vertex_node] = 'D';

        // Print the maze with the shortest path
        for (int i = 0; i < vertex_node; i++) {
            for (int j = 0; j < vertex_node; j++) {
                if (maze[i][j] == 'X') {
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, 3); // Cyan for path
                }
                else {
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, 8); // Gray for no path
                }
                cout << " " << maze[i][j] << " ";
                SetConsoleTextAttribute(console_color, 7); // Reset to default color
            }
            cout << endl;
        }
    }

    // Modify this method in graph_auto class
    void move_car(AutoStack& shortest_path, int source, int destination)
    {
        HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle

        while (!shortest_path.empty()) {
            system("CLS");

            int current_position = shortest_path.top();
            shortest_path.pop();
            int car_x = current_position / vertex_node;
            int car_y = current_position % vertex_node;

            // Print the maze with the car at the current position
            for (int i = 0; i < vertex_node; ++i) {
                cout << "\t\t\t";
                for (int j = 0; j < vertex_node; ++j) {
                    // Set the color for the car's current position
                    if (i == car_x && j == car_y) {
                        SetConsoleTextAttribute(console_color, 14); // Yellow for the car
                        cout << " C ";
                    }
                    else if (i * vertex_node + j == source) {
                        SetConsoleTextAttribute(console_color, 10); // Green for the source
                        cout << " S ";
                    }
                    else if (i * vertex_node + j == destination) {
                        SetConsoleTextAttribute(console_color, 12); // Red for the destination
                        cout << " D ";
                    }
                    else {
                        // Check if the current position is part of the shortest path
                        bool is_path = false;
                        AutoStack temp_path = shortest_path;
                        while (!temp_path.empty()) {
                            int path_pos = temp_path.top();
                            temp_path.pop();
                            if (i == path_pos / vertex_node && j == path_pos % vertex_node) {
                                SetConsoleTextAttribute(console_color, 3); // Cyan for path
                                cout << " X ";
                                is_path = true;
                                break;
                            }
                        }

                        if (!is_path) {
                            SetConsoleTextAttribute(console_color, 8); // Grey for walls
                            cout << " * ";
                        }
                    }
                }
                cout << endl;
            }

            // Reset text color to default
            SetConsoleTextAttribute(console_color, 7);

            // Pause for a short time to animate the car's movement
               this_thread::sleep_for(   chrono::milliseconds(500));
        }

        // After the car has reached the destination, keep the final state for a while
           this_thread::sleep_for(   chrono::milliseconds(2000));
    }

    void moving_a_car()
    {
        int source_x, source_y, destination_x, destination_y;
        AutoStack shortest_path;

        cout << "Enter the x and y coordinates of the source node (space-separated): ";
        cin >> source_x >> source_y;

        cout << "Enter the x and y coordinates of the destination node (space-separated): ";
        cin >> destination_x >> destination_y;

        int source = source_x * vertex_node + source_y;
        int destination = destination_x * vertex_node + destination_y;

        dijkstra(source, destination, shortest_path);
    }
};