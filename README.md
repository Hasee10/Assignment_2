# Assignment_2
Introduction
This is a text-based maze game developed using C++ and the ncurses library. The player navigates through a grid maze 
with the objective of finding a key and unlocking the door to win the game. The game offers multiple difficulty levels, 
each with different maze sizes and limited moves, adding to the challenge.

# Key Features and Game Mechanics
Multidimensional Linked List Grid: The maze is represented using a linked list of nodes, each connected to its neighboring nodes (up, down, left, right).
Player Movement: The player can navigate the grid using arrow keys (up, down, left, right).
Difficulty Levels:
Easy: 10x10 grid with additional moves.
Medium: 15x15 grid with a moderate number of moves.
Hard: 20x20 grid with a limited number of moves.

Game Elements:
Walls ('#'): Boundary nodes that block movement.
Key ('K'): The player must collect this before unlocking the door.
Door ('D'): Unlocks once the player collects the key.
Bomb ('B'): Stepping on this ends the game.
Coin ('C'): Collect to gain points and additional undo moves.
Undo Functionality: The player can undo their last move by pressing 'u'.
Win and Loss Conditions:
Win: Reach the door with the key in possession.
Loss: Run out of moves or step on a bomb.
Dynamic Output: The game provides feedback on player actions, such as finding the key, collecting a coin, or hitting a wall.

# How to Run the Game
Prerequisites
Make sure you have g++ installed for compiling C++ code.
Install ncurses library using the package manager:
sudo apt-get install libncurses5-dev libncursesw5-dev
On other systems, use the appropriate package manager (e.g., Homebrew for macOS).

# Running the Game
Execute the game using:
Game Controls
Arrow Keys: Move the player around the maze.
'u' Key: Undo the last move (if available).
'q' Key: Quit the game.

# Game Running Mechanics Screen shots
![image](https://github.com/user-attachments/assets/d0156ddb-9b60-480d-a0d3-8a5c7c87b452)

# Upon further changes {For Level # 1}
![image](https://github.com/user-attachments/assets/39456fc7-20ff-49ae-bf62-f69abfc755e5)
![image](https://github.com/user-attachments/assets/b94fe76d-42be-4476-8afe-c1e92f4a46b4)

Game Over
![image](https://github.com/user-attachments/assets/8a0984f1-43c5-4a8b-a757-5f02051fefda)

# Upon further changes {For Level # 2}
![image](https://github.com/user-attachments/assets/62b92cb7-4024-4de8-b7d7-75d92bfa0fb8)

Game Over
![image](https://github.com/user-attachments/assets/b7da81d7-2143-4121-b4b0-210953a099ed)

# Upon further changes {For Level # 3}



Assumptions and Special Configurations
Libraries: The game uses the ncurses library for terminal-based graphics and input handling. Ensure that it is correctly installed on your system.
Terminal Configuration: The game requires a terminal with ncurses support. Make sure your terminal supports special key inputs like arrow keys.
Initial Setup: The game initializes the terminal with special settings (noecho, cbreak, keypad) for a seamless gaming experience.







