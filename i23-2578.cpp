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

struct Ps 
{
    Node* n;//pointer to store the position of the player
    Ps()
    {
        n = nullptr;
    }
};


class Grid 
{
   private:
    Node *key;//key node
    Node *door;//door node
    int rows;
    int cols;
    int result;//player score
    int rem_moves;//remnaining moves stored
    int ind_1;//undo moves limit stored here
    int prev_ind;//prev move index stored here

    bool ke_stat;//check to see if i caught the key
    Ps mov_revs[20];
    Node *head;//head represents the top most node of the grid
    Node *pl_mo;
    Node *bb;

   public:
    Grid()
    {
      rows = 0;
      cols = 0;
      head = nullptr;
      ke_stat = false;
      result = 0;
      prev_ind = 0;
    }

    Grid(int r, int c, int num)
    {
        rows = r;
        cols = c;
        head = nullptr;
        ke_stat = false;
        result = 0;
        prev_ind = 0;
        make_grid();
    }


    void make_grid() 
    {
       int num = 0;  
       Node* pre_1 = nullptr;
       Node* pre_2 = nullptr;
       int n = rows;
       int q = cols;
       char b = '#';
       char c = '.';
       int p = n - 1;
       int l = q - 1;

       for (int i = 0; i < n; i++) 
       {
         Node* curr_node = nullptr;
         int nut;
         pre_2 = nullptr;
         int nut_2;
         for (int j = 0; j < q; j++) 
         {
            Node *NN;
            if (i == num || j == num || i == p || j == l)
            {
               NN = new Node(b);
            }
            else
            {
               NN = new Node(c);
            }
                

            if (j == num) 
            {
               curr_node = NN;
            } 
            else 
            {
               int t = 0;
               pre_2->right = NN;
               NN->left = pre_2;
            }


            if (i > num) 
            {
                int fp = 0;
                NN->up = pre_1;
                pre_1->down = NN;
                pre_1 = pre_1->right;
                int fp_2 = 0;
            }
            pre_2 = NN;
         }
         pre_1 = curr_node;
            
         if (i == num) 
         {
            head = curr_node;
         }
       }
    }

    void random_elements() 
    {
        srand(time(0));
        char a = 'P';
        char b = '.'; 
        char c = 'B';
        char d = 'C';
        int num = 5;

        door = rand_func();
        door->data = b;

        pl_mo = rand_func();
        pl_mo->data = a;
        key = rand_func();
        key->data = b;
    
        bb = rand_func();
        bb->data = c;

        for (int i = 0; i < num; i++) 
        {
            Node *t = rand_func();
            t->data = d;
        }
    }


};   

int main()
{
    char u = 'u';
    char u_2 = 'q';
    int r;
    int c;
    int num = 0;
    int m;
    cout << "   _____ _            _   _                                          " << endl;
    cout << "  |_   _| |__   ___  | | | |_ __  ___  ___  ___ _ __                 " << endl;
    cout << "    | | | '_ \\ / _ \\ | | | | '_ \\/ __|/ _ \\/ _ \\ '_ \\              " << endl;
    cout << "    | | | | | |  __/ | |_| | | | \\__ \\  __/  __/ | | |              " << endl;
    cout << "    |_| |_| |_|\\___|  \\___/|_| |_|___/\\___|\\___|_| |_|          _   " << endl;
    cout << "    | | ___  _   _ _ __ _ __   ___ _   _   / _ \\ _   _  ___  ___| |_ " << endl;
    cout << " _  | |/ _ \\| | | | '__| '_ \\ / _ \\ | | | | | | | | | |/ _ \\/ __| __|" << endl;
    cout << "| |_| | (_) | |_| | |  | | | |  __/ |_| | | |_| | |_| |  __/\\__ \\ |_ " << endl;
    cout << " \\___/ \\___/ \\__,_|_|  |_| |_|\\___|\\__, |  \\__\\_\\\\__,_|\\___||___/\\__|" << endl;
    cout << "                                   |___/                             " << endl;
    
    cout << "Now you are Tasked with Selecting the LEVEL of the GAME" << endl;
    cout << "CHOOSE from the following " << endl;
    cout << " ---> 1. EASY-LEVEL " << endl;
    cout << " ---> 2. MEDIUM-LEVEL " << endl;
    cout << " ---> 3. HARD-LEVEL " << endl;
    cout << endl;
    cin >> num;
    cout << endl;

    if (num == 1)
    {
        r = 10;
        c = 10;
    }
    else if (num == 2)
    {
        r = 15;
        c = 15;
    }
    else if (num == 3)
    {
        r = 20;
        c = 20;
    }

    initscr();//terminal setup for the game interface
    cbreak();//direct output no enter required
    noecho();//text appearance hidden
    curs_set(0);//here the cursor is hidden
    keypad(stdscr, TRUE);//special keys like arrow keys are processed here


    return 0;
}