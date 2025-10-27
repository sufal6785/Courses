//
// Created by User on 8/14/2025.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

