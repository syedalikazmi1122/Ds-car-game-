//AyeshaShahid_2483_SE-B
//Ali Kazmi_22i2472_SE-B
//Saima Saleem_22i2498_SE-B
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include "FileName.H"
#include<conio.h>
#include<string>
#include"Auto.h"
#include "Queue.h"
using namespace std;
int score = 0;
void displaying_the_leader_board()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    for (int P = 3; P == 3; P++)
    {

        SetConsoleTextAttribute(console_color, P);

        cout << "\t8 888888888o       ,o888888o.              .8.          8 888888888o.   8 888888888o.  " << endl;
        cout << "\t8 8888    `88.  . 8888     `88.           .888.         8 8888    `88.  8 8888    `^888. " << endl;
        cout << "\t8 8888     `88 ,8 8888       `8b         :88888.        8 8888     `88  8 8888        `88." << endl;
        cout << "\t8 8888     ,88 88 8888        `8b       . `88888.       8 8888     ,88  8 8888         `88" << endl;
        cout << "\t8 8888.   ,88' 88 8888         88      .8. `88888.      8 8888.   ,88'  8 8888          88" << endl;
        cout << "\t8 8888888888   88 8888         88     .8`8. `88888.     8 888888888P'   8 8888          88" << endl;
        cout << "\t8 8888    `88. 88 8888        ,8P    .8' `8. `88888.    8 8888`8b       8 8888         ,88" << endl;
        cout << "\t8 8888      88 `8 8888       ,8P    .8'   `8. `88888.   8 8888 `8b.     8 8888        ,88'" << endl;
        cout << "\t8 8888    ,88'  ` 8888     ,88'    .888888888. `88888.  8 8888   `8b.   8 8888    ,o88P' " << endl;
        cout << "\t8 888888888P       `8888888P'     .8'       `8. `88888. 8 8888     `88. 8 888888888P'  " << endl;
        cout << "\t==========================================================================================" << endl;
    }
    const   string resetColor = "\033[0m"; // Reset color to default
    const   string redColor = "\033[31m";  // Red
    const   string greenColor = "\033[32m";  // Green
    const   string yellowColor = "\033[33m";  // Yellow

    // Text to be printed
      string line1 = "  /|||_\\`.__";
      string line2 = " (   _    _ _\\ ";
      string line3 = "=`-(_)--(_)--'";

    // Calculate the width of the console
    int consoleWidth = 80; // Change this to the actual width of your console

    // Calculate the number of spaces needed to move the text to the right
    int padding = consoleWidth - line1.length();

    // Print the text with different colors and moved to the right
      cout <<   string(padding, ' ') << redColor << line1 << resetColor <<   endl;
      cout <<   string(padding, ' ') << greenColor << line2 << resetColor <<   endl;
      cout <<   string(padding, ' ') << yellowColor << line3 << resetColor <<   endl;

    SetConsoleTextAttribute(console_color, 7);
    node_of_tree* root = nullptr;
    ifstream leaderboardFile("leaderboard.txt");
    string name, score;

    while (leaderboardFile >> name >> score)
    {
        if (leaderboardFile.is_open())
        {
            root = insert_the_players_details(root, name, stoi(score));
        }
    }
    displaying_leaderboard(root);
}
int findPlayerScore(const string& playerName)
{
    ifstream leaderboardFile("leaderboard.txt");
    string name, score;

    while (leaderboardFile >> name >> score)
    {
        if (name == playerName)
        {
            return stoi(score);
        }
    }

    return 0;
}
void clearScreen()
{
    system("cls");
}
void welcome_function()
{
    cout << endl
        << endl;
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    for (int P = 6; P == 6; P++)
    {
        cout << endl
            << endl;
        SetConsoleTextAttribute(console_color, P);
        cout << "\t\t .d8888b.                        .d8888b.  " << endl;
        cout << "\t\td88P  Y88b                      d88P  Y88b           " << endl;
        cout << "\t\t888    888                      888    888                         " << endl;
        cout << "\t\t888         8888b.  888d888     888         8888b.  88888b.d88b.   .d88b.  " << endl;
        cout << "\t\t888             88b 888P        888  88888      88b 888 888  88b   d8P Y8b " << endl;
        cout << "\t\t888    888 .d888888 888         888    888 .d888888 888  888  888  8888888 " << endl;
        cout << "\t\tY88b  d88P  88  888 888         Y88b  d88P 888  888 888  888  888  Y8b.     " << endl;
        cout << "\t\t Y8888P     Y888888 888           Y8888P88  Y888888 888  888  888  Y88888 " << endl;
    }
    cout << endl;
    cout << endl;
    const   string resetColor = "\033[0m"; // Reset color to default
    const   string redColor = "\033[31m";  // Red
    const   string greenColor = "\033[32m";  // Green
    const   string yellowColor = "\033[33m";  // Yellow

    // Text to be printed
      string line1 = "  /|||_\\`.__";
      string line2 = " (   _    _ _\\ ";
      string line3 = "=`-(_)--(_)--'";

    // Calculate the width of the console
    int consoleWidth = 80; // Change this to the actual width of your console

    // Calculate the number of spaces needed to center the text
    int padding = (consoleWidth - line1.length()) / 2;

    // Print the text with different colors and centered
      cout <<   string(padding, ' ') << redColor << line1 << resetColor <<   endl;
      cout <<   string(padding, ' ') << greenColor << line2 << resetColor <<   endl;
      cout <<   string(padding, ' ') << yellowColor << line3 << resetColor <<   endl;

}
class node
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
    node* next_node_pointer;
    node()
    {
        weight_of_the_edge = 0;
        next_node_pointer = nullptr;
    }

    node(int value, int weight)
    {
        weight_of_the_edge = weight;
        next_node_pointer = nullptr;
    }
};
class graph
{
private:
    int vertex_node;
    node* the_adjacency_matrix[10][10];

public:
    graph(int vertex)
    {
        vertex_node = vertex;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                the_adjacency_matrix[i][j] = new node();
                the_adjacency_matrix[i][j]->current = i * vertex_node + j;
                the_adjacency_matrix[i][j]->the_adjacency_list = new node::list();
                the_adjacency_matrix[i][j]->weight_of_the_edge = 0;
                the_adjacency_matrix[i][j]->next_node_pointer = nullptr;
            }
        }
    }

    int get_vertex_node()
    {
        return vertex_node;
    }

    bool checking_if_edge_exist(int node1, int node2)
    {
        node* temporary_node = nullptr; // Initialize temporary_node to nullptr

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
            if (temporary_node != nullptr) {
                break; // If we found the node, no need to continue the loop
            }
        }
        for (node* current_node = temporary_node; current_node != nullptr; current_node = current_node->next_node_pointer)
        {
            node::list* temp_list = current_node->the_adjacency_list;
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
        // number of possible connect in upward direction
        if (i > 0)
        {
            number_of_possible_connections++;
        }
        // number of possible connect in downward direction
        if (i < vertex_node - 1)
        {
            number_of_possible_connections++;
        }
        // number of possible connect in left direction
        if (j > 0)
        {
            number_of_possible_connections++;
        }
        // number of possible connect in right direction
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
        // Connection in upward direction
        if (i > 0)
        {
            random_values[counter++] = the_adjacency_matrix[i - 1][j]->current;
        }
        // Connection in downward direction
        if (i < vertex_node - 1)
        {
            random_values[counter++] = the_adjacency_matrix[i + 1][j]->current;
        }
        // Connection in left direction
        if (j > 0)
        {
            random_values[counter++] = the_adjacency_matrix[i][j - 1]->current;
        }
        // Connection in right direction
        if (j < vertex_node - 1)
        {
            random_values[counter++] = the_adjacency_matrix[i][j + 1]->current;
        }
    }
    void adding_the_possible_connection(int i, int j, int* random_values, int counter, int weight)
    {
        int number_of_connections = 0;
        number_of_connections = rand() % 2;
        number_of_connections = min(number_of_connections, counter);

        bool selected[4];
        for (int k = 0; k < 4; k++)
        {
            selected[k] = false;
        }

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

            node::list* current_connection = the_adjacency_matrix[i][j]->the_adjacency_list;
            while (current_connection != nullptr && current_connection->value_at_node != random_values[index])
            {
                current_connection = current_connection->pointer_next_node;
            }
            if (current_connection == nullptr)
            {
                node::list* new_connection = new node::list();
                new_connection->value_at_node = random_values[index];
                new_connection->pointer_next_node = the_adjacency_matrix[i][j]->the_adjacency_list->pointer_next_node;
                the_adjacency_matrix[i][j]->the_adjacency_list->pointer_next_node = new_connection;
                current_connection = new_connection;
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
                node::list* new_connection = new node::list();
                new_connection->value_at_node = the_adjacency_matrix[i][j]->current;
                new_connection->pointer_next_node = the_adjacency_matrix[x][y]->the_adjacency_list->pointer_next_node;
                the_adjacency_matrix[x][y]->the_adjacency_list->pointer_next_node = new_connection;
                current_connection = new_connection;
            }
            the_adjacency_matrix[x][y]->weight_of_the_edge = weight;
        }
    }
    void generating_the_random_graph()
    {
        srand(time(0));
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

                for (int i = counter - 1; i > 0; i--)
                {
                    int j = rand() % (i + 1);
                    int temporary = rand_values[i];
                    rand_values[i] = rand_values[j];
                    rand_values[j] = temporary;
                }

                int final_random = 0;
                final_random = (rand() % (counter - min_connections + 1)) + min_connections;
                adding_the_possible_connection(i, j, rand_values, final_random, weight);
            }
        }
    }
    void displaying_the_adjacency_matrix()
    {
        for (int i = 0; i < vertex_node; i++)
        {
            for (int j = 0; j < vertex_node; j++)
            {
                cout << the_adjacency_matrix[i][j]->current << ": ";
                for (node::list* current_connection = the_adjacency_matrix[i][j]->the_adjacency_list->pointer_next_node; current_connection != nullptr; current_connection = current_connection->pointer_next_node)
                {
                    cout << current_connection->value_at_node << ",";
                }
                cout << endl;
            }
        }
    }
    void print_score_and_bonus(int previous_score)
    {
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int P = 6; P == 6; P++)
        {
            SetConsoleTextAttribute(console_color, P);
            cout << setw(20) << "Previous Score: " << previous_score << setw(22) << "Score: " << score;
            int bonus = score * 2.5;
        }
    }
    void printing_the_maze()
    {
        int index_of_the_neighbour, x_cordinate, y_cordinate;

        for (int i = 0; i < vertex_node; i++)
        {
            cout << "\t\t";
            for (int j = 0; j < vertex_node; j++)
            {
                node::list* the_current_connection = the_adjacency_matrix[i][j]->the_adjacency_list->pointer_next_node;
                bool connection_found = false;

                while (the_current_connection != nullptr)
                {
                    index_of_the_neighbour = the_current_connection->value_at_node;
                    x_cordinate = index_of_the_neighbour / vertex_node;
                    y_cordinate = index_of_the_neighbour % vertex_node;

                    if ((x_cordinate == i - 1 && y_cordinate == j) ||
                        (x_cordinate == i + 1 && y_cordinate == j) ||
                        (x_cordinate == i && y_cordinate == j - 1) ||
                        (x_cordinate == i && y_cordinate == j + 1))
                    {
                        connection_found = true;
                        break;
                    }

                    the_current_connection = the_current_connection->pointer_next_node;
                }

                if (connection_found)
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(
                        STD_OUTPUT_HANDLE);
                    for (int P = 3; P == 3; P++)
                    {
                        SetConsoleTextAttribute(console_color, P);
                        cout << " X "
                            << " ";
                    }
                }
                else
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(
                        STD_OUTPUT_HANDLE);
                    for (int P = 12; P == 12; P++)
                    {
                        SetConsoleTextAttribute(console_color, P);
                        cout << " * "
                            << " ";
                    }
                }
            }
            cout << endl;
        }
    }

    int visited_matrix[10][10];
    void initialize_visited_matrix()
    {
        for (int i = 0; i < vertex_node; i++)
        {
            for (int j = 0; j < vertex_node; j++)
            {
                visited_matrix[i][j] = 0;
                score = 0;
            }
        }
    }
    bool checking_if_the_node_exist(int i, int j)
    {
        return the_adjacency_matrix[i][j]->the_adjacency_list->getsize() > 0;
    }
    void car_moving_through_the_graph(int source1, int source2, int& dest1, int& dest2, string player_name)
    {
        Queue q;
        int number_of_bonuses = 0;
        system("CLS");
        int previous_score = findPlayerScore(player_name);

        print_score_and_bonus(previous_score);
        cout << endl
            << endl
            << endl;

        for (int i = 0; i < vertex_node; i++)
        {
            cout << "\t\t";
            for (int j = 0; j < vertex_node; j++)
            {
                HANDLE console_color;
                console_color = GetStdHandle(
                    STD_OUTPUT_HANDLE);
                for (int P = 5; P == 5; P++)
                {
                    SetConsoleTextAttribute(console_color, 7);
                    // Print top border
                    cout << "+-------";
                }
            }

            cout << "+" << endl;

            cout << "\t\t";
            for (int j = 0; j < vertex_node; j++)
            {
                for (int j = 0; j < vertex_node; j++)
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(
                        STD_OUTPUT_HANDLE);
                    for (int P = 5; P == 5; P++)
                    {
                        SetConsoleTextAttribute(console_color, 7);
                        // Print top border
                    }
                }
                // Print left border
                cout << "|  ";

                // Print cell content
                if (i == source1 && j == source2)
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    for (int P = 6; P == 6; P++)
                    {
                        SetConsoleTextAttribute(console_color, P);
                        cout << " C ";
                        visited_matrix[i][j] = 1;
                    }
                }
                else if (i == dest1 && j == dest2)
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    for (int P = 6; P == 6; P++)
                    {
                        SetConsoleTextAttribute(console_color, P);
                        cout << " D ";
                        visited_matrix[i][j] = 1;
                    }
                }
                else if (i != j && checking_if_edge_exist(i, j) && number_of_bonuses < 5)
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    for (int P = 2; P == 2; P++)
                    {
                        SetConsoleTextAttribute(console_color, P);
                        cout << " " << char(232) << " ";
                        visited_matrix[i][j] = 1;
                        q.enqueue(i, j);
                        number_of_bonuses++;
                    }
                }

                else if (checking_if_the_node_exist(i, j))
                {
                    if (visited_matrix[i][j] == 1)
                    {
                        HANDLE console_color;
                        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                        for (int P = 6; P == 6; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                            cout << " " << char(240) << " ";
                        }
                    }
                    else
                    {
                        HANDLE console_color;
                        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                        for (int P = 3; P == 3; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                            cout << " " << char(249) << " ";
                        }
                    }
                }
                else
                {
                    HANDLE console_color;
                    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    for (int P = 12; P == 12; P++)
                    {
                        SetConsoleTextAttribute(console_color, P);
                        cout << " " << char(254) << " ";
                        q.enqueue(i, j);
                    }
                }

                // Print right border
                cout << "  ";
            }
            for (int j = 0; j < vertex_node; j++)
            {
                HANDLE console_color;
                console_color = GetStdHandle(
                    STD_OUTPUT_HANDLE);
                for (int P = 5; P == 5; P++)
                {
                    SetConsoleTextAttribute(console_color, 7);
                    // Print top border
                }
            }
            cout << "|" << endl;
        }

        // Print bottom border
        cout << "\t\t";
        for (int j = 0; j < vertex_node; j++)
        {
            cout << "+-------";
        }
        cout << "+" << endl;
        cout << endl;
    }

    void move_up(char direction, int& source_1, int& source_2, int& dest1, int& dest2, string player_name)
    {
        if (source_1 - 1 >= 0 && the_adjacency_matrix[source_1 - 1][source_2]->the_adjacency_list->getsize() > 0)
        {
            source_1 = source_1 - 1;
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            visited_matrix[source_1][source_2] = 1;
            score += 2;
        }
        else
        {
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            score = max(0, score - 1);
        }
    }

    void move_down(char direction, int& source_1, int& source_2, int& dest1, int& dest2, string player_name)
    {
        if (source_1 + 1 < vertex_node && the_adjacency_matrix[source_1 + 1][source_2]->the_adjacency_list->getsize() > 0)
        {
            source_1 = source_1 + 1;
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            visited_matrix[source_1][source_2] = 1;
            score += 2;
        }
        else
        {
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            score = max(0, score - 2);
        }
    }

    void move_left(char direction, int& source_1, int& source_2, int& dest1, int& dest2, string player_name)
    {
        if (source_2 - 1 >= 0 && the_adjacency_matrix[source_1][source_2 - 1]->the_adjacency_list->getsize() > 0)
        {
            source_2 = source_2 - 1;
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            visited_matrix[source_1][source_2] = 1;
            score += 2;
        }
        else
        {
            score = max(0, score - 1);
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
        }
    }

    void move_right(char direction, int& source_1, int& source_2, int& dest1, int& dest2, string player_name)
    {
        if (source_2 + 1 < vertex_node && the_adjacency_matrix[source_1][source_2 + 1]->the_adjacency_list->getsize() > 0)
        {
            source_2 = source_2 + 1;
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            visited_matrix[source_1][source_2] = 1;
            score += 2;
        }
        else
        {
            score = max(0, score - 1);
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
        }
    }
    void fly_car(char direction, int& source_1, int& source_2, int& dest1, int& dest2, string player_name)
    {
        if (source_2 + 2 < vertex_node && the_adjacency_matrix[source_1][source_2 + 2]->the_adjacency_list->getsize() > 0)
        {
            source_2 = source_2 + 2;
            car_moving_through_the_graph(source_1, source_2, dest1, dest2, player_name);
            visited_matrix[source_1][source_2] = 1;
        }
    }
    bool depth_first_search(int source1, int source2, int dest1, int dest2)
    {
        // If the source is the same as the destination, we've found a path
        if (source1 == dest1 && source2 == dest2)
        {
            return true;
        }

        // Mark the source as visited
        visited_matrix[source1][source2] = true;

        // For each neighbor of the source
        for (node::list* current_connection = the_adjacency_matrix[source1][source2]->the_adjacency_list->pointer_next_node; current_connection != nullptr; current_connection = current_connection->pointer_next_node)
        {
            int neighbor1 = current_connection->value_at_node / vertex_node;
            int neighbor2 = current_connection->value_at_node % vertex_node;

            // If the neighbor is not visited, recursively call depth_first_search on the neighbor
            if (!visited_matrix[neighbor1][neighbor2])
            {
                if (depth_first_search(neighbor1, neighbor2, dest1, dest2))
                {
                    return true;
                }
            }
        }

        // If no path is found, return false
        return false;
    }

    bool if_the_path_exist_between_source_and_destination(int source1, int source2, int dest1, int dest2)
    {
        initialize_visited_matrix();
        // cout << "the path between source and destination is: \n"
        //      << endl;
        return depth_first_search(source1, source2, dest1, dest2);
    }
    void previous_score_of_the_player(string player_name)
    {
        int previous_score = 0;
        previous_score = findPlayerScore(player_name);
    }
};
void menu_of_the_game()
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int P = 5; P == 5; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << "                 .         .        " << endl;
        cout << "                ,8.       ,8.          8 8888888888   b.             8 8  8888      88 " << endl;
        cout << "               ,888.     ,888.         8 8888         888o.          8 8  8888      88 " << endl;
        cout << "              .`8888.   .`8888.        8 8888         Y88888o.       8 8  8888      88 " << endl;
        cout << "             ,8.`8888. ,8.`8888.       8 8888         .`Y888888o.    8 8  8888      88 " << endl;
        cout << "            ,8'8.`8888,8^8.`8888.      8 888888888888 8o. `Y888888o. 8 8  8888      88 " << endl;
        cout << "           ,8' `8.`8888' `8.`8888.     8 8888         8`Y8o. `Y88888o8 8  8888      88 " << endl;
        cout << "          ,8'   `8.`88'   `8.`8888.    8 8888         8   `Y8o. `Y8888 8  8888      88 " << endl;
        cout << "         ,8'     8.'     `8.`8888.   8 8888         8      `Y8o. `Y8 ` 8  8888     ,8P " << endl;
        cout << "        ,8'       `8        `8.`8888.  8 8888         8         Y8o.   8  8888    ,d8P  " << endl;
        cout << "       ,8'         `         `8.`8888. 8 888888888888 8            `Yo     `Y88888P'   " << endl;
        cout << "   ========================================================================================" << endl;
        cout << endl;
    }

    const   string resetColor = "\033[0m"; // Reset color to default
    const   string redColor = "\033[31m";  // Red
    const   string greenColor = "\033[32m";  // Green
    const   string yellowColor = "\033[33m";  // Yellow

    // Text to be printed
      string line1 = "  /|||_\\`.__";
      string line2 = " (   _    _ _\\ ";
      string line3 = "=`-(_)--(_)--'";
    int consoleWidth = 80; // Change this to the actual width of your console

    // Calculate the number of spaces needed to center the text
    int padding = (consoleWidth - line1.length()) / 2;

    // Print the text with different colors and centered
      cout <<   string(padding, ' ') << redColor << line1 << resetColor <<   endl;
      cout <<   string(padding, ' ') << greenColor << line2 << resetColor <<   endl;
      cout <<   string(padding, ' ') << yellowColor << line3 << resetColor <<   endl;
    cout << endl;
    for (int P = 6; P == 6; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << "\t\t\t\t += ==================== = +" << endl;
        cout << "\t\t\t\t |    1-    START          |" << endl;
        cout << "\t\t\t\t += ==================== = +" << endl;

    }
    for (int P = 3; P == 3; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << "\t\t\t\t += ==================== = +" << endl;
        cout << "\t\t\t\t |   2-  LeaderBoard       |" << endl;
        cout << "\t\t\t\t += ==================== = +" << endl;

    }
    for (int P = 5; P == 5; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << "\t\t\t\t += ==================== = +" << endl;
        cout << "\t\t\t\t |   3-   Auto Mode        |" << endl;
        cout << "\t\t\t\t += ==================== = +" << endl;

    }

    for (int P = 4; P == 4; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << "\t\t\t\t += ==================== = +" << endl;
        cout << "\t\t\t\t |   4-     Quit           |" << endl;
        cout << "\t\t\t\t += ==================== = +" << endl;

    }
}
void you_won_message( double elapsed_seconds)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int P = 3; P == 3; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << endl
            << endl
            << endl
            << endl
            << endl
            << endl
            << endl;

        cout << "\t\t\t\tdP  dP  dP  .d8888b.  88d888b. " << endl;
        cout << "\t\t\t\t88  88  88  88'  `88  88'  `88 " << endl;
        cout << "\t\t\t\t88.88b.88'  88.  .88  88    88 " << endl;
        cout << "\t\t\t\t8888P Y8P   `88888P'  dP    dP " << endl;
    }
    cout << "\n\t\t\t\tElapsed Time: " << elapsed_seconds << " seconds" << endl;
}
void you_lost_message()
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int P = 4; P == 4; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << endl
            << endl
            << endl
            << endl
            << endl
            << endl
            << endl;
        cout << "\t\t\t\tdP                      dP   " << endl;
        cout << "\t\t\t\t88                      88   " << endl;
        cout << "\t\t\t\t88  .d8888b.  .d8888b. d8888P " << endl;
        cout << "\t\t\t\t88  88'  `88  Y8ooooo.  88   " << endl;
        cout << "\t\t\t\t88  88.  .88       88   88   " << endl;
        cout << "\t\t\t\tdP  `88888P'  `88888P'  dP dP  " << endl;
    }
}
void write_score_to_file(string leaderboard_score, string name_of_the_player)
{
    ofstream leaderboard_score_file(leaderboard_score,   ios::app);

    if (!leaderboard_score_file.is_open())
    {
        cout << "Error opening the file: " << endl;
        return;
    }
    leaderboard_score_file << name_of_the_player << " " << score << endl;
    leaderboard_score_file.close();
}
void results(string player)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int P = 4; P == 4; P++)
    {
        SetConsoleTextAttribute(console_color, P);
        cout << "\t\t########  ########  ######  ##     ## ##       ########  ######  " << endl;
        cout << "\t\t##     ## ##       ##    ## ##     ## ##          ##    ##    ## " << endl;
        cout << "\t\t##     ## ##       ##       ##     ## ##          ##    ##       " << endl;
        cout << "\t\t########  ######    ######  ##     ## ##          ##     ######  " << endl;
        cout << "\t\t##   ##   ##             ## ##     ## ##          ##          ## " << endl;
        cout << "\t\t##    ##  ##       ##    ## ##     ## ##          ##    ##    ## " << endl;
        cout << "\t\t##     ## ########  ######   #######  ########    ##     ######  " << endl;
        cout << endl
            << endl
            << endl;
    }
    SetConsoleTextAttribute(console_color, 7);
    int bonus = 5;
    cout << "\t\t\t\t===========================" << endl;
    cout << "\t\t\t\t||  "
        << " Gold Bonus"
        << "  ||  " << bonus << "  ||" << endl;
    cout << "\t\t\t\t===========================" << endl;

    cout << "\t\t\t\t||  "
        << " Fuel Bonus"
        << "  ||  " << 5 << "   ||" << endl;
    cout << "\t\t\t\t===========================" << endl;
    cout << "\t\t\t\t||  "
        << " Power Up "
        << "   ||  " << 5 << "   ||" << endl;
    cout << "\t\t\t\t===========================" << endl;
    cout << "\t\t\t\t||  "
        << "  Score"
        << "      ||  " << score + bonus + 5 + 5 << "  ||" << endl;
    cout << "\t\t\t\t===========================" << endl;
    cout << endl
        << endl;
    write_score_to_file("leaderboard.txt", player);
}

int main()
{
    graph myGraph(10);
    string name_of_players;
    string opt;
    int source_1 = 0;
    int source_2 = 0;
    int destination_1 = 9;
    int destination_2 = 9;
    int number_of_moves = 0;
    node_of_tree* root = nullptr;
    clearScreen();
    welcome_function();
    cout << endl;
    cout << endl;
    int option = 0;
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 7);
    cout << "\t\t\tEnter Player's name: ";
    getline(cin, name_of_players);
    clearScreen();
    menu_of_the_game();

    SetConsoleTextAttribute(console_color, 7);
    cout << "\t\t\t\tEnter Option:";
    cin >> option;
    if (option == 2)
    {
        clearScreen();
        displaying_the_leader_board();
        cout << "Press 1 To get back to menu." << endl;
        cin >> opt;
        if (opt == "1" || opt == "1")
        {
            menu_of_the_game();
            SetConsoleTextAttribute(console_color, 7);
            cout << "\t\t\t\tEnter Option:";
            cin >> option;
            if (option == 1)
            {
                cout << "TO START:" << endl;
                system("pause");
                clearScreen();
                auto start_time =   chrono::steady_clock::now();
                if (!myGraph.if_the_path_exist_between_source_and_destination(source_1, source_2, destination_1, destination_2))
                {
                    myGraph.generating_the_random_graph();
                    myGraph.printing_the_maze();
                }
                myGraph.car_moving_through_the_graph(0, 0, destination_1, destination_2, name_of_players);

                char direction;
                while (true)
                {
                    SetConsoleTextAttribute(console_color, 7);
                    //	cout << "Enter the 
                    // directions:\n1- w for Up.\t2- s for Down. \t3- a for Left.\t4- d for Right.\n";
                    direction = _getch();
                    if (source_1 == destination_1 && source_2 == destination_2 || direction == 'e')
                    {
                        clearScreen();
                        auto end_time =   chrono::steady_clock::now();
                        chrono::duration<double> elapsed_seconds = end_time - start_time;
                        you_won_message(elapsed_seconds.count());
                        system("pause");
                        clearScreen();
                        results(name_of_players);
                        HANDLE console_color;
                        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(console_color, 7);
                        break;
                    }
                    if (number_of_moves > 0 && score == 0)
                    {
                        clearScreen();
                        you_lost_message();
                        HANDLE console_color;
                        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(console_color, 7);
                        break;
                    }
                    if (direction == 'q')
                    {
                        string opt;
                        cout << "Do you want to quit the game?" << endl;
                        cin >> opt;
                        if (opt == "y" || opt == "Yes" || opt == "Y" || opt == "yes")
                        {
                            break;
                        }
                    }

                    switch (direction)
                    {
                    case 'w':
                    {
                        myGraph.move_up(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                        HANDLE console_color;
                        console_color = GetStdHandle(
                            STD_OUTPUT_HANDLE);
                        for (int P = 6; P == 6; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                        }
                        number_of_moves++;
                        break;
                    }
                    case 's':
                    {
                        myGraph.move_down(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                        HANDLE console_color;
                        console_color = GetStdHandle(
                            STD_OUTPUT_HANDLE);
                        for (int P = 6; P == 6; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                        }
                        number_of_moves++;
                        break;
                    }
                    case 'a':
                    {
                        myGraph.move_left(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                        HANDLE console_color;
                        console_color = GetStdHandle(
                            STD_OUTPUT_HANDLE);
                        for (int P = 6; P == 6; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                        }
                        number_of_moves++;
                        break;
                    }
                    case 'd':
                    {
                        myGraph.move_right(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                        HANDLE console_color;
                        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                        for (int P = 6; P == 6; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                        }
                        number_of_moves++;
                        break;
                    }
                    case 'z':
                    {
                        myGraph.fly_car(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                        HANDLE console_color;
                        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                        for (int P = 6; P == 6; P++)
                        {
                            SetConsoleTextAttribute(console_color, P);
                        }
                        number_of_moves++;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid direction. Try again.\n";
                        break;
                    }
                    }
                    HANDLE console_color;
                    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, 7);

                }
            }
        }
    }
    else if (option == 1)
    {
        auto start_time =   chrono::steady_clock::now();
        cout << "TO START:" << endl;
        system("pause");
        clearScreen();

        if (!myGraph.if_the_path_exist_between_source_and_destination(source_1, source_2, destination_1, destination_2))
        {
            myGraph.generating_the_random_graph();
            myGraph.printing_the_maze();
        }
        myGraph.car_moving_through_the_graph(0, 0, destination_1, destination_2, name_of_players);

        char direction;
        while (true)
        {
            SetConsoleTextAttribute(console_color, 7);
            cout << "Enter the directions:\n1- w for Up.\t2- s for Down. \t3- a for Left.\t4- d for Right.\n";
            direction = _getch();
            if (source_1 == destination_1 && source_2 == destination_2 || direction == 'e')
            {
                clearScreen();
                auto end_time =   chrono::steady_clock::now();
                  chrono::duration<double> elapsed_seconds = end_time - start_time;

                you_won_message(elapsed_seconds.count());
                system("pause");
                clearScreen();
                results(name_of_players);
                HANDLE console_color;
                console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console_color, 7);
                break;
            }
            if (number_of_moves > 0 && score == 0)
            {
                clearScreen();
                you_lost_message();
                HANDLE console_color;
                console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console_color, 7);
                break;
            }
            if (direction == 'q')
            {
                string opt;
                cout << "Do you want to quit the game?" << endl;
                cin >> opt;
                if (opt == "y" || opt == "Yes" || opt == "Y" || opt == "yes")
                {
                    break;
                }
            }

            switch (direction)
            {
            case 'w':
            {
                myGraph.move_up(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                HANDLE console_color;
                console_color = GetStdHandle(
                    STD_OUTPUT_HANDLE);
                for (int P = 6; P == 6; P++)
                {
                    SetConsoleTextAttribute(console_color, P);
                }
                number_of_moves++;
                break;
            }
            case 's':
            {
                myGraph.move_down(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                HANDLE console_color;
                console_color = GetStdHandle(
                    STD_OUTPUT_HANDLE);
                for (int P = 6; P == 6; P++)
                {
                    SetConsoleTextAttribute(console_color, P);
                }
                number_of_moves++;
                break;
            }
            case 'a':
            {
                myGraph.move_left(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                HANDLE console_color;
                console_color = GetStdHandle(
                    STD_OUTPUT_HANDLE);
                for (int P = 6; P == 6; P++)
                {
                    SetConsoleTextAttribute(console_color, P);
                }
                number_of_moves++;
                break;
            }
            case 'd':
            {
                myGraph.move_right(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                HANDLE console_color;
                console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                for (int P = 6; P == 6; P++)
                {
                    SetConsoleTextAttribute(console_color, P);
                }
                number_of_moves++;
                break;
            }
            case 'z':
            {
                myGraph.fly_car(direction, source_1, source_2, destination_1, destination_2, name_of_players);
                HANDLE console_color;
                console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                for (int P = 6; P == 6; P++)
                {
                    SetConsoleTextAttribute(console_color, P);
                }
                number_of_moves++;
                break;
            }
            case' ':
            {
                while (true) {
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    CONSOLE_SCREEN_BUFFER_INFO csbi;
                    GetConsoleScreenBufferInfo(console_color, &csbi);
                    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

                    for (int P = 6; P == 6; P++) {
                        SetConsoleTextAttribute(console_color, P);

                        // Calculate the number of lines needed to center the text vertically
                        int linesAbove = (consoleHeight - 4) / 2;
                        int linesBelow = consoleHeight - 4 - linesAbove;

                        // Print lines above the centered text
                          cout << "\t\t\t\t + = ==================== = +" <<   endl;
                          cout << "\t\t\t\t |    Press Esc to Resume   |" <<   endl;
                          cout << "\t\t\t\t + = ==================== = +" <<   endl;

                        // Print lines below the centered text
                    }

                    while (true) {
                        direction = _getch(); // Use _getch() to get a key press

                        if (direction == 27) { // Check if the key is the Esc key (ASCII code 27)
                            break; // Exit the inner loop when Esc is pressed
                        }
                    }
                    break;
                }
                break;
            }
            default:
            {
                cout << "Invalid direction. Try again.\n";
                break;
            }
            }
            HANDLE console_color;
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color, 7);
            // cout << "Enter the directions:\n1- u for Up.\t2- d for Down. \t3- l for Left.\t4- r for Right.\n";
        }
    }
    else if (option == 3)
    {
        int vertex_node = 10;
        graph_auto g(vertex_node);
        g.generating_the_random_graph();
        g.moving_a_car();
        return 0;
    }
    else if (option == 4)
    {
        cout << "Exiting..." << endl;
        exit(0);
    }
    return 0;
}