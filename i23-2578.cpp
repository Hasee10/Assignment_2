/*
Muhammad Haseeb Arshad
23i-2578
DS-A
Assignment # 2
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
using namespace std;

struct Node 
{
    char data;
    Node* up;//upper node 
    Node* down;//lower node
    Node* left;//left node
    Node* right;//right node

    Node()
    {
         data = 0;
         up = nullptr;
         down = nullptr;
         left = nullptr;
         right = nullptr;
    }

    Node(char ch)
    {
         data = ch;
         up = nullptr;
         down = nullptr;
         left = nullptr;
         right = nullptr;
    }
};



int main()
{

    return 0;
}