# AdaShips
AdaShip is a two-player, turn based game of sea warfare.


# Summary and review of the problem, overall proposed solution:
AdaShip is a game that's played on a CLI(command-line interface). The game consists of a player vs a computer. The computer and the player take turns to input a coordinate into the terminal and try to guess if a boat was placed there. The game continues until the computer or the player has no more ships on the board. The player would be able to set up the boats on the board using the terminal, the terminal allows the player to input if they want the boat vertically or horizontally and where the player wants the boat to be rendered. The computer would randomly place the ship on the computer board and also use an AI to fire torpedoes to the player's board. The game prevents the user from inputting the wrong values.


My solution was to create two boards using 2D arrays. It would allow me to push the new values to the matrix easily and effectively. The program allows the user to input a coordinate and then render the boat in that position using a while loop. When the user inputs a value into the program it validates the input and it will ask for input again. I have a menu with instructions for the user. The program runs until a player or the computer has no more ships on the board or the player has quit the game.

# UML style diagram illustrating initial overall solution:

My UML represents how my code works and how they function are related to each other. As my code doesn't have classes 
I didn't use classes or separated the code into files. The UML is a way to visualize the way the code works and how data flows.

![alt text](https://github.com/simtor/AdaShips/blob/main/Screenshot%202021-03-24%20at%2012.01.33.png)

# Initial working plan, overall approach, development strategy and approach to quality:
My strategy was to divide and conquer as if I break down the problem into small components it would allow me to work more efficiently. I started to do some research and then build a small prototype and then made the prototype more efficient and robust.

I made a flowchart to help me visualize the program and what components I would need to create to meet the passing criteria. From the flowchart, I was able to see I would need two separate boards and small components such as placing the boats and firing the torpedoes.

![alt text](https://github.com/simtor/AdaShips/blob/main/flowchart-BattleshipWM.jpg)

My approach to quality was to make my family members use the program and test the robustness and usability. From that user testing, I kept improving the program making it more robust and making the menu more user friendly. The sessions help me understand the problems that a user would have when using the program as a developer my mind would automatically know what to do but see it from a user perspective help me with quality.


# Analysis and decomposition of the overall problem into key ‘epic’ style tasks:
I read the assignment and extracted the requirements I would need to do.
I made a requirement list and I followed that requirement list until I had a prototype.
I worked in an agile environment so I kept improving my solution every time, you can see this in my GitHub commits.

- First Set up boats for each player 
- Turns for each player shooting torpedoes 
- The game is won once a player has not boats left 
- Record the location of the boats and shot that was hit or miss
- The location is going to  be like 4A or 4F

####  -------------Boats----------------
    Carrier - Length 5
    Battleship - Length 4
    Destroyer - Length 3
    Submarine - Length 3
    Patrol Boat - Length 2

#### -----------(player v computer)----------
The real player set up the board first  and the computer should do it automatically
The AI should be able to fire torpedoes at the opponent 
We need to indicate if ships are sunk or not

####  ------------------------Pass Criteria--------------------
- Should be able to  read ‘adaship_config.ini’ and get this information:
Board: 10x10
Boat: Carrier, 5
Boat: Battleship, 4
Boat: Destroyer, 3
Boat: Submarine, 3
Boat: Patrol Boat, 2

- Set up an interface 
- Menu 
- Place the ships on the board 
- Indicate where the ship is
- function that detects if boats are in the same place 
- Support reset game and quit the game
- Continue button to  start the game after placements
- Place ships in random places with  strategies
- Turns should be done for player and computer 


# Initial object-oriented design ideas and plan of phased breakdown into smaller tasks:

If you look at my code you can see that I broke down the tasks into functions, as at the start of the development phase I decide to got with the stagy divide and conquer, at the start of the development phase, I started working on the board from my research the best option was to have a 2D array to store boats/ships.  After finding a method that allows me to create a matrix I move on to start looking for a way to populate the board with ships. I was lucky that I was using a matrix as it was simple to push items into the arrays by doing [x][y]=2. 

After getting comfortable with the matrix I was able to randomly populate the computer board with ships and random fire torpedos into the user board. 
As you can see above me I have a list of tasks which I used to track my development, this list helps me because I knew what I had to do and the research helped me a lot as well. 


# Reflection on key design challenges, innovations and how I solved them

Design challenges are that the board is made with numbers makes it harder to find other numbers, the board starts to hurt your eye after a bit, so if I had more time I would have to change the design of the board letter, this would help with usability fo the program.

There are still bugs in the code as sometimes the boats are over each other meaning that the score wouldn't work.  I would fix this problem by using another random engine generator and also moving the code from a function to the main. This problem was noticed too late to fix it properly. 

For innovation would introduce player vs player, also AI vs AI it would have been fun if I had more time to do them. 

Created by Simone Ram🐏
