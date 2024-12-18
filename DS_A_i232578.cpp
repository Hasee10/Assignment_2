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
    int prev_mov;

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
      prev_mov = 0;
    }

    Grid(int r, int c, int num)
    {
        rows = r;
        cols = c;
        head = nullptr;
        ke_stat = false;
        result = 0;
        prev_ind = 0;
        prev_mov = -1;
        make_grid();
        random_elements();
        level(num);
    }

    void level(int num) 
    {
        int magn = 0;
        int s = 0;
        int p = 0;

        s = node_dist(pl_mo, key);
        p = node_dist(key, door);
        magn = s + p;
        
        if(num == 1) 
        {
            rem_moves = magn + 6;
            ind_1 = 6;
        }
        
        else if(num == 2) 
        {
            rem_moves = magn + 2;
            ind_1 = 4;
        }
        
        else if(num == 3) 
        {
            rem_moves = magn;
            ind_1 = 1;
        }
        
        else 
        {
            rem_moves = magn + 6;
            ind_1 = 6;
        }
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
    
    int node_dist(Node *n1, Node *n2) 
    {
        int a;//xcoordinates
        int b;
        int c;//y coordinates
        int d;
        int sum = 0;
        xy_cord(n1, a, c);
        xy_cord(n2, b, d);
        sum = abs(a - b) + abs(c - d);
        return sum;
    }

    void pl_move(int dir) 
    {
        int num = 1;
        int num_2 = 0;
        char n = '#';
        char n_2 = '.';
        char n_3 = 'K';
        char n_4 = 'D';
        char n_5 = 'C';
        char n_6 = 'P';
        if ((prev_mov == KEY_UP && dir == KEY_DOWN)) 
        {
            mvprintw(num, num_2, "Cant Move Back");
            return;
        }
        else if(prev_mov == KEY_DOWN && dir == KEY_UP)
        {
            mvprintw(num, num_2, "Cant Move Back");
            return;
        }
        else if(prev_mov == KEY_LEFT && dir == KEY_RIGHT)
        {
            mvprintw(num, num_2, "Cant Move Back");
            return;
        }
        else if(prev_mov == KEY_RIGHT && dir == KEY_LEFT)
        {
            mvprintw(num, num_2, "Cant Move Back");
            return;
        }
  

        if (rem_moves <= num_2) 
        {
            mvprintw(num, num_2, "GAME FINISH. No more moves left");
            refresh();
            getch();
            endwin();
            exit(0);
        }
        int dis = 0;
        dis = node_dist(pl_mo, key);

        Node* NN = pl_mo;
        if(dir == KEY_UP)
        {
            NN = pl_mo->up;
        }
        else if(dir == KEY_DOWN)
        {
            NN = pl_mo->down;
        }
        else if(dir == KEY_LEFT)
        {
            NN = pl_mo->left;
        }
        else if(dir == KEY_RIGHT) 
        {
            NN = pl_mo->right;
        }

        if(NN && NN->data != n) 
        {
           if (NN == bb) 
           {
              k_d_show();
              mvprintw(num, num_2, "BOMB BLAST. YOU LOST");
              refresh();
              getch();
              endwin();
              exit(0);
          }

          if (prev_ind < ind_1) 
          {
              int fp = 0;
              mov_revs[prev_ind].n = pl_mo;
              prev_ind = prev_ind + 1;
          } 
          
          else 
          {
              int l = ind_1 - 1;
              for (int i = 0; i < l; i++) 
              {
                 mov_revs[i] = mov_revs[i + 1];
              }
              mov_revs[l].n = pl_mo;
          }

          pl_mo->data = n_2;
          pl_mo = NN;

          if (pl_mo == key) 
          {
              pl_mo->data = n_3;
              ke_stat = true;
              mvprintw(num + 1, num_2, "KEY FOUND.");
          }

          if (pl_mo == door) 
          {
              pl_mo->data = n_4;
              if (ke_stat) 
              {
                 result = result + rem_moves;
                 mvprintw(num + 1, num_2, "GAME WON. DOOR UNLOCKED. Final SCORE -->  %d", result);
                 refresh();
                 getch();
                 endwin();
                 exit(0);
              } 
              else 
              {
                 int fp = num + 1;
                 mvprintw(fp, num_2, "FIND KEY. DOOR LOCKED");
              }
           }

           if (pl_mo->data == n_5) 
           {
              result = result + 2;
              ind_1 = ind_1 + 1; 
              mvprintw(num, num_2, "COIN COLLECTED. SCORE --> %d", result);
           }
           pl_mo->data = n_6;
           rem_moves = rem_moves - 1;
           prev_mov = dir;

           int dis_2 = 0;
           dis_2 = node_dist(pl_mo, key);
           if(dis_2 < dis)
           {
              mvprintw(num + 2, num_2, "Drawing closer ");
           }

           else if(dis_2 > dis)
           {
              mvprintw(num + 2, num_2, "Moving away ");
           }

           curr_scen();
           grid_making();
        } 
        
        else 
        {
            mvprintw(num, num_2, "YOU SMACKEEED THE WAAALL!");
        }
    }

    Node* rand_func() 
    {
        char d = '.';
        int a;
        int b;
        Node* nod = head;
        int num = 0;
        int num_2 = 0;
        do 
        {
            a = rand() % (rows - 2);
            num = a + 1;
            
            b = rand() % (cols - 2);
            num_2 = b + 1;
            
            nod = nod_gain(num, num_2);
        } while (nod->data != d);
        return nod;
    }

    void grid_making() 
    {
        int num = rows;
        Node *n_1 = head;// pointed to the head node that is the node on top left
        for (int i = 0; i < num; i++) 
        {
            int num_2 = cols;
            Node *t = n_1;
            for (int j = 0; j < num_2; j++)// grid printed after the string line
            {
                int lm = i + 2;
                int km = j * 2;
                mvprintw(lm, km, "%c ", t->data);//specific row and column where the data will be printed
                int num_9;
                t = t->right;// pointer moved to next node in the row under consideration
            }
            int fp = 0;
            n_1 = n_1->down;// now the node points to the next row node
        }
        refresh();// updated grid is shown
    }

    void mov_rev() 
    {
        char c = '.';
        char c_2 = 'P';
        int num = 0;
        int num_2 = 2;
        if (prev_ind > num) 
        {
            prev_ind = prev_ind - 1;//if undo moves are there the index is decremented by one moving the index to the last recorded move
            Node *pr_node = mov_revs[prev_ind].n;//retrieves the node relating to the previous node

            pl_mo->data = c;
            pl_mo = pr_node;
            pl_mo->data = c_2;

            rem_moves++;
            ind_1--;
            curr_scen();//shows the pl_mos changed position
            grid_making();//the pl_mos position is updated with the new coordinates
        } 
        
        else 
        {
            mvprintw(num_2, num, "NONE UNDOS TO DO");
        }
    }

     void xy_cord(Node *newN , int &var_1, int &var_2)//reference variables that store the x and y variables of the pont we need to find 
    {
        int n;
        Node* nn_1 = head;//points at the top left corner of the grid
        int n_2;
        var_1 = 0;//row index as zero
        while (nn_1 && nn_1 != newN) 
        {
            int n_3; 
            Node *nn_2 = nn_1;
            int n_4;
            var_2 = 0;//column index as zero
            while (nn_2 && nn_2 != newN) //traverses through the columns of the grid by using the right pointer
            {
                int n_7;
                nn_2 = nn_2->right;
                var_2++;
                int n_8;
            }//when node is found in this row the loop exits

            if (nn_2 == newN)
            {
                int n_9;
                break;//here i check if the temporary node points at the new node
            }
            int n_5;
            nn_1 = nn_1->down;
            int n_1;
            var_1++;
        }
    }

    Node* nod_gain(int a, int b) 
    {
        Node* t = head;
        int num = a;
        int num_2 = b;
        for (int i = 0; i < num; i++) 
        {
            t = t->down;
        }
        
        for (int j = 0; j < num_2; j++) 
        {
            t = t->right;
        }
        return t;
    }

    void k_d_show() 
    {
        int fp = 0;
        key->data = 'K';//if the pl_mo node matches the key and the door then the position is updated here
        int fp_2 = 0;
        door->data = 'D';
    }

    void curr_scen() 
    {
        clear();//while displaying grid all previous grids are removed from the screen
        int magn = 0;
        if(ke_stat != true)
        {
            magn = node_dist(pl_mo, key);//if key is not picked up the distance from node to the key is calculated            
        }

        else
        {                        
            magn = node_dist(pl_mo, door);//if key is picked up the distance from node to door is calculated
        }
        int num = 0;
        mvprintw(num, num, "Remaining MOVES --> %d || Undo MOVES Remaining -->  %d || result --> %d || DISTANCE TO --> %s: %d", rem_moves, ind_1, result, ke_stat ? "door" : "key", magn);
    }

    void er_gr() 
    {
        int n;
        Node *t = head;
        int n_2;
        while(t) 
        {
            Node *nn = t;
            int n_3;
            Node *nn_2 = t->down;
            int n_4;
            while (nn) 
            {
                int n_5;
                Node *t_2 = nn->right;
                int n_6;
                delete nn; //here I traverse through the column of the current row and delete each of the nodes and then it is updated to point on the next node in the row
                nn = t_2;
                int n_7;
            }
            int n_2;
            t = nn_2;//after all the deletion the the loop updates t to point to the first node of the next row
        }
    }    

    ~Grid() 
    {
        er_gr();
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
    
    Grid grid(r, c, num);
    grid.curr_scen();
    grid.grid_making();

    while ((m = getch()) != u_2) 
    {
        if (m != u) 
        {
            grid.pl_move(m);            
        } 
        
        else 
        {
            grid.mov_rev();
        }
    }
    endwin();
    
    return 0;
}