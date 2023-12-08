
//AyeshaShahid_2483_SE-B
//Ali Kazmi_22i2472_SE-B
//Saima Saleem_22i2498_SE-B
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class node_of_tree
{
public:
    string name_of_the_player;
    int score_of_the_player;
    node_of_tree* left_child;
    node_of_tree* right_child;

    node_of_tree()
    {
        name_of_the_player = "";
        score_of_the_player = 0;
        left_child = nullptr;
        right_child = nullptr;
    }

    node_of_tree(string name, int score)
    {
        name_of_the_player = name;
        score_of_the_player = score;
        left_child = nullptr;
        right_child = nullptr;
    }
};

node_of_tree* insert_the_players_details(node_of_tree* root, string name, int score)
{
    if (root == nullptr)
    {
        return new node_of_tree(name, score);
    }
    else
    {
        if (score > root->score_of_the_player)
        {
            root->left_child = insert_the_players_details(root->left_child, name, score);
        }
        else
        {
            root->right_child = insert_the_players_details(root->right_child, name, score);
        }
    }
    return root;
}

void writing_the_leader_board_in_file(node_of_tree* root, ostream& leaderboard_in_file)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        writing_the_leader_board_in_file(root->left_child, leaderboard_in_file);
        leaderboard_in_file << root->name_of_the_player << " " << root->score_of_the_player << endl;
        writing_the_leader_board_in_file(root->right_child, leaderboard_in_file);
    }
}

void displaying_leaderboard(node_of_tree* root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        displaying_leaderboard(root->left_child);
        cout << "\n\n\t\t\t\t\t" << root->name_of_the_player << "\t" << root->score_of_the_player << endl;
        displaying_leaderboard(root->right_child);
    }
}

void searching_in_file(string name, ifstream& leaderboard_file)
{
    if (!leaderboard_file.is_open())
    {
        cout << "Error in opening file." << endl;
        return;
    }

    string player_name;
    int player_score;
    bool player_found = false;

    while (leaderboard_file >> player_name >> player_score)
    {
        if (player_name == name)
        {
            cout << "Player found: " << player_name << ", Latest Score: " << player_score << endl;
            player_found = true;
            break;
        }
    }

    if (!player_found)
    {
        cout << "Player not found: " << name << endl;
    }
}


