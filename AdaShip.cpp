#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
using namespace std;


// I have added a one for the while lopp so that it print 10 columns and numbers
const int rows = 11;
const int columns = 11;
//define array
int matrix[rows][columns];//The 2D matrix that it being used as the board 
int computer[rows][columns];//The 2D matrix that is beeing used by the computer
int lifePointCarrier = 0;//------------
int lifePointBattleship = 0;        //|
int lifePointDestoyer = 0;          //|varibles used to  store the life point for each boat on the userboard  
int lifePointSubmarine = 0;         //|
int lifePointPatrolBoat = 0;//---------

int lifePointCarrierAI = 0;//------------
int lifePointBattleshipAI = 0;        //|
int lifePointDestoyerAI = 0;          //|varibles used to  store the life point for each boat on the computer board 
int lifePointSubmarineAI = 0;         //|
int lifePointPatrolBoatAI = 0;//---------
int userScore = 0;//Used to keep score for the user 
int aiScore = 0;//Used to keep score for the computer 
string quiterGame;//varible used to quit the game
char grid[11][11];
string name;//Store the name of the boats from the ini file 
string funds;//Store the size of the boats from the ini file 
int supplies, turns;
std::vector<int> x;//vector used to store the size of the boat
std::vector<string> shipName;//vector used to store the name of the boat
std::vector<std::string> output_vector;//vector used to store the size of the board


//function used to get the size of the board
void getBoardSize(){
  std::ifstream input_file;
    input_file.open("adaship_config.ini");//Gets the file and open it 
    std::string line;
    while (getline(input_file, line))
    {
        std::istringstream ss_line(line);
        while(ss_line){
            std::string element;
            ss_line >> element;
            output_vector.push_back(element);//used to  push the data into the vector
        }
    }
    for (int i = 0; i < output_vector.size(); i++) {
        std::cout << output_vector.at(i) << ' '<<"\n";
    }
    std::cout <<"Simone: " <<output_vector[1]<<"\n";
    std::cout<<"Simone: " <<output_vector[3]<<"\n";
    int result = std::stoi(output_vector[1]);
    cout<<result<<"\n";
    int resullt = std::stoi(output_vector[3]);
    cout<<resullt<<"\n";
}

void readConfig(){
  std::ifstream file("adaship_config.ini");//Gets the file and open it 
  std::string line;
  while (std::getline(file, line)) {
    stringstream ss(line);
    file >> name;//pushes the data into the varibles 
    file >> funds;//pushes the data into the varibles
    file >> supplies;//pushes the data into the varibles
    x.push_back(supplies);//used to  push the data into the vector
    shipName.push_back(funds);//used to  push the data into the vector

  } 
}


int colref_index(std::string coord) {
//convert 'column reference' (A[a] = 0, B[b] = 2, .. Z[a] = 25, AA[aa], AB[bb]..ZZ[zz] = 701) to an index (0..701)
//returns valid index (0..701), any negative values represent invalid column references i.e., not A[a]..ZZ[zz]
if(coord.length() == 1) {//deal with single letter value (A = 0, B = 2 .. Z = 25)
return toupper(int(coord[0])) - 65; // 65 represents ASCII 'A' 'A' - 65 = 0
} else if(coord.length() == 2) {//deal with pair values (AA = 26, BA = 52, CA = 78 .. ZZ = 701)
return ((toupper(int(coord[1])) - 65) + (toupper(int(coord[0])) - 64) * 26); // -64 to get base 1 thus avoiding 0 * n = 0 issue
}
return -1; //no match
}

std::string index_colref(int idx) {
//convert index to 'column reference'; valid range 0 to 702 (ZZ)
//invalid indexes return and empty string
std::string coords = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string reference = ""; //set default return

if(idx >= 0 && idx <= ((26*26)+26)) { //check in valid range
int x = idx/26; //check range; 0 if A..Z
if(x == 0) {
reference = coords[idx]; //return reference
} else {
idx = idx - (x * 26); //update index
reference = coords[(x-1)]; //add initial column ref; A..Z
reference += coords[idx]; //add secondary column ref; AA..ZZ
}
}
return reference;
}

//This function is used to show the board of the user   
void Show()
{
  char i; 
	std::cout << "\t";
	for (i = 'A'; i <= 'J'; i++)//for loop that output the letters for the x axis
  cout << i <<"\t"; 
	std::cout << "\n";
	for ( int row = 1; row < 11; ++row){//for loop that output the numbers for the y axis
    std::cout << row<< "\t";
    for (int column = 1; column < 11; ++column){
    {
      cout << matrix[row][column] << "\t";
    }
  }
		cout << endl;
	}
}

//|This function us used to show the computr board to the user 
void ShowComputerBoard()
{
  char i; 
	std::cout << "\t";
	for (i = 'A'; i <= 'J'; i++)//for loop that output the letters for the x axis
  cout << i <<"\t"; 
	std::cout << "\n";
	for ( int row = 1; row < 11; ++row)//for loop that output the numbers for the y axis
	{
    std::cout << row<< "\t";
    for (int column = 1; column < 11; ++column){
      {
        cout << computer[row][column] << "\t";
		  }
    }
    cout << endl;
	} 
}

void setupUserBoard(){
	   int pointerOne;//pointer for the baots to  be rendered 
	   string pointertwo;//pointer for the baots to be rendered 
     int amountOfBoats=0;//Amount of boats in the game
     int boatIndexName=0;//The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;//Varibel used to  render boats into the matrix 
     int decisionVF;//Varible that allows user to decide if they want to render the boat vertically or horizontally
    while(amountOfBoats<5){
      int boatSize=x[amountOfBoats];//Get the size of the boat by using the index using the amount of times that the while loop has run.
      std::cout<<"Your setting up boat "<<shipName[boatIndexName]<<" and it takes up "<<boatSize<<" spaces"<<"\n";//tells the user what boat it is and what size the boat is 
      cout<<"Please press 1 for vertical or 2 for horizontal: ";cin>>decisionVF;//Ask whats the user what way the boat has to  be placed 
      while(!cin || decisionVF > 2 || decisionVF < 1){//Validation loop for the decisionVF
       cout << "Please re-input your choose(1 or 2): ";
       cin.clear();
       cin.ignore();
       cin >> decisionVF;
       }
     cout<<"Insert row number: ";cin>>pointerOne;//Get the Y axis coordinate from the user 
     //validation loop 
     while(!cin || pointerOne > 10 || pointerOne < 1){
       cout << "Please re-input your row number(1-10): ";
       cin.clear();
       cin.ignore();
       cin >> pointerOne;//Askes the user gain for input 
       }
     cout<<"Insert column letter: ";cin>>pointertwo;//Get the X axis coordinate from the user 
     //validation loop 
     int validator = 0;
     while(validator < 1){
       if(pointertwo == "A" || pointertwo == "B" || pointertwo == "C" || pointertwo == "D" || pointertwo == "E" || pointertwo == "F" || pointertwo == "G" || pointertwo == "H" || pointertwo == "I" || pointertwo == "J"){
         validator++;
       }else{
         cout<<"Please re-input your column letter(A-J): ";
         cin.clear();
         cin.ignore();
         cin >> pointertwo;//Askes the user gain for input 
       }
     }
     //coonverts the letter into numbers for the coordinates 
     int idx = colref_index(pointertwo);
	   std::string colref = index_colref(idx);
     //if statement for positioning the boats vertically or horizontally 
     if(decisionVF==1){
      int s=pointerOne;
      //while lopp used to render the boats onto matrix. The while loop run until it matches the size of the boats 
        while(amountLoop < boatSize) {
        matrix[s][idx+1]=boatSize;//Vertical 
        amountLoop++;
        s++;//increments the the coordinates 
        }
     }else{
       int s=idx+1;
       //while lopp used to render the boats onto matrix. The while loop run until it matches the size of the boats
        while(amountLoop < boatSize) {
        matrix[pointerOne][s]=boatSize;//horizontal
        amountLoop++;
        s++;//increments the the coordinates
      }
    }
    amountOfBoats++;
    boatIndexName++;
    amountLoop= 0;
    Show();
  }
}//Done renaming variables 

//function used to populate the computer matrix/2D array 
void masterBoatSetUp(){
     int amountOfAiBoats=0;
     int nameOfAiBoats=0;
     int amountLoop=0;
     srand((unsigned) time(NULL));//Random seed 
    while(amountOfAiBoats<5){
     int boatSize=x[amountOfAiBoats];
     int pointerOfAiBoat = (rand() % 7) + 1;//Generates random numbers for y-axis
     int pointerOfAiBoat2 = (rand() % 7) + 1;//Generates random number for x-axis 
     int decisionVF = (rand() % 2) +1;//Generates random number between 1-2 for the vertical or hozontal placement 
    //if statement for positioning the boats vertically or horizontally 
    if(decisionVF==1){
      int s=pointerOfAiBoat;
      //while lopp used to render the boats onto computer matrix. The while loop run until it matches the size of the boats
        while(amountLoop < boatSize) {
        computer[s][pointerOfAiBoat]=boatSize;//Vertical 
        amountLoop++;
        s++;
        }
     }else{
       int s=pointerOfAiBoat;
       //while lopp used to render the boats onto computer matrix. The while loop run until it matches the size of the boats
        while(amountLoop < boatSize) {
        computer[pointerOfAiBoat][s]=boatSize;//horizontal
        amountLoop++;
        s++;
      }
    }
    amountOfAiBoats++;
    nameOfAiBoats++;
    amountLoop=0;
  }
}//Done renaming variables 

//this bool is set to out true if the users torpedo hit or misses the ship 
bool Attack(int x, int y)
{
	if (computer[x][y] == 2){
		computer[x][y]=9;//Change the matrix if user hit the boat
    lifePointPatrolBoat++;
    userScore++;//increment score if user hit a boat 
    cout << "You hit the patrol Boat on the Enenies board" << endl;
    if(lifePointPatrolBoat == 2){//output if the user has suckd the ships 
      cout<<"Patrol board has sunked on the Enenies board"<<"\n";
    }
		return true;
	}else if(computer[x][y] == 3){
    computer[x][y]=9;//Change the matrix if user hit the boat
    lifePointSubmarine++;
    userScore++;//increment score if user hit a boat 
    cout << "You hit the Submarine on the Enenies board" << endl;
    if(lifePointSubmarine== 3){//output if the user has suckd the ships 
      cout<<"Submarine has sunked on the Enenies board"<<"\n";
    }
		return true;
  }else if(computer[x][y] == 3){
    computer[x][y]=9;//Change the matrix if user hit the boat
    lifePointDestoyer++;
    userScore++;//increment score if user hit a boat 
    cout << "You hit the Destoyer on the Enenies board" << endl;
    if(lifePointDestoyer == 3){//output if the user has suckd the ships 
      cout<<"Destroyer has sunked on the Enenies board"<<"\n";
    }
		return true;
  }else if(computer[x][y] == 4){
    computer[x][y]=9;//Change the matrix if user hit the boat
    lifePointBattleship++;
    userScore++;//increment score if user hit a boat 
    cout << "You hit  the battleship on the Enenies board" << endl;
    if(lifePointBattleship == 4){//output if the user has suckd the ships 
      cout<<"Battleship has sunked on the Enenies board"<<"\n";
    }
		return true;
  }else if(computer[x][y] == 5){
    computer[x][y]=9;//Change the matrix if user hit the boat
    lifePointCarrier++;
    userScore++;//increment score if user hit a boat 
    cout << "You hit the Carrier on the Enenies board" << endl;
    if(lifePointCarrier == 5){//output if the user has suckd the ships 
      cout<<"Carrier has sunked on the Enenies board"<<"\n";
    }
		return true;
  }else{
    computer[x][y]=8;//if the user miss the shot 
    cout << "Sorry, no ship at that position!" << endl;
	  return false;
  }
  
}//end of Attack


void computerbrain(){
   srand((unsigned) time(0));
   int aiNumber = (rand() % 9) + 1;//generates random numbers for the y-axis for the user board 
   int aiNumber2 = (rand() % 9) + 1;//generates random numbers for the x-axis for the user board 
  if (matrix[aiNumber][aiNumber2] == 2){
		matrix[aiNumber][aiNumber2]=9;//change the matrix from 2 to 9 mean hit 
    lifePointPatrolBoatAI++;
    aiScore++;//increment score if computer hit a boat 
    cout<<lifePointPatrolBoatAI;
    lifePointPatrolBoatAI++;
    cout << "The computer has hit your the patrol Boat! :)" << endl;
    if(lifePointPatrolBoatAI == 2){
      cout<<"The computer has sunked your Patrol board"<<"\n";
    }
		// return true;
	}else if(matrix[aiNumber][aiNumber2] == 3){
    matrix[aiNumber][aiNumber2]=9;//change the matrix from 3 to 9 mean hit 
    lifePointSubmarineAI++;
    aiScore++;//increment score if computer hit a boat 
    cout << "The computer has hit your the Submarine! :)" << endl;
    if(lifePointSubmarineAI== 3){
      cout<<"The computer has sunked your Submarine"<<"\n";
    }
		// return true;
  }else if(matrix[aiNumber][aiNumber2] == 3){
    matrix[aiNumber][aiNumber2]=9;//change the matrix from 3 to 9 mean hit 
    lifePointDestoyerAI++;
    aiScore++;//increment score if computer hit a boat 
    cout << "The computer has hit your the Destoyer! :)" << endl;
    if(lifePointDestoyerAI == 3){
      cout<<"The computer has sunked your Destroyer"<<"\n";
    }
		// return true;
  }else if(matrix[aiNumber][aiNumber2] == 4){
    matrix[aiNumber][aiNumber2]=9;//change the matrix from 4 to 9 mean hit 
    lifePointBattleshipAI++;
    aiScore++;//increment score if computer hit a boat 
    cout << "The computer has hit your the battleship! :)" << endl;
    if(lifePointBattleshipAI == 4){
      cout<<"The computer has sunked your Battleship"<<"\n";
    }
		// return true;
  }else if(matrix[aiNumber][aiNumber2] == 5){
    matrix[aiNumber][aiNumber2]=9;//change the matrix from 5 to 9 mean hit 
    lifePointCarrierAI++;
    aiScore++;//increment score if computer hit a boat 
    cout << "The computer has hit your the Carrier! :)" << endl;
    if(lifePointCarrierAI== 5){
      cout<<"The computer has sunked your Carrier"<<"\n";
    }
		// return true;
  }else{
    matrix[aiNumber][aiNumber2]=8;//if the computer miss the shot 
    cout << "The computer has missed, no ship at that position!" << endl;
	  // return false;
  }
}


int main()
{
    int userAttackAi = 0;//User inputs Y-axis 
	  string userAttackAi2;//User inputs X-axis 
    int numberOfRuns=0;//variabel used for while loop 
    //menu 
    cout<<"AdaShip is a clone of the classic‘Battleship’game\n";
    cout<<"-----------------MENU-----------------\n";
    cout<<" One player v computer game"<<"\n";
    cout<<"how to play:"<<"\n";
    cout<<"Please set up your board first:"<<"\n";
    cout<<"To set up your board first you need to think if you want the boat to be vertical or horizontal by pressing 1 or 2"<<"\n";
    cout<<"Then you need to decide a point where you want the boat to be rendered by pressing a number for a row and a letter for a column"<<"\n";
    readConfig();
    Show();
    setupUserBoard();//asking user  for set up there boat on the baord 
    cout<<"If your torpedo missed the board will show number 8 but if the torpedo has hit a boat it will show number 9"<<"\n"; 
    cout<<"***************** This is the board that your playing with the computer************"<<"\n";
    Show();//showung them the the  board 
    cout<<"***************** This is the enemies board ************"<<"\n";
    masterBoatSetUp();
    ShowComputerBoard();
    while(numberOfRuns < 17){//game starts 
    cout << "Please input insert row number: ";
		cin >>userAttackAi;
    while(!cin || userAttackAi > 10 || userAttackAi < 1){//while loop used to validate the input 
       cout << "Please re-input your row number(1-10): ";
       cin.clear();
       cin.ignore();
       cin >> userAttackAi;
       }
    cout << "Please input insert column letter: "; 
    cin >> userAttackAi2;
    int validator = 0;
     while(validator < 1){//while loop used to validate the input 
       if(userAttackAi2 == "A" || userAttackAi2 == "B" || userAttackAi2 == "C" || userAttackAi2 == "D" || userAttackAi2 == "E" || userAttackAi2 == "F" || userAttackAi2 == "G" || userAttackAi2 == "H" || userAttackAi2 == "I" || userAttackAi2 == "J"){
         validator++;
       }else{
         cout<<"Please re-input your column letter(A-J):";
         cin.clear();
         cin.ignore();
         cin >> userAttackAi2;
       }
     } 
    int idx = colref_index(userAttackAi2);
	  std::string colref = index_colref(idx);//converts letter to numbers 
		if (Attack(userAttackAi, idx+1) == true)
		{
      cout<<"***************** ENEMY BOARD ******************"<<"\n";
      ShowComputerBoard();
		}
		else
		{
      cout<<"***************** ENEMY BOARD ******************"<<"\n";
      ShowComputerBoard();
		}
    computerbrain();
    cout<<"***************** YOUR BOARD ******************"<<"\n";
    Show();
    //Decide if user or compouter has won the game
    if(userScore == 16){
    cout<<"Congratulations you won the Game :)"<<"\n";
      cout<<"your scorescore: "<<userScore<<"\n";
      Show();
      cout<<"Computer score: "<<aiScore<<"\n";
      ShowComputerBoard();
    return 0;
  }else if(aiScore == 16){
    cout<<"Sorry you lost the game :("<<"\n";
    cout<<"Computer score: "<<aiScore<<"\n";
    ShowComputerBoard();
    cout<<"your score: "<<userScore<<"\n";
    Show();
    return 0;
  }else{//allows user to  quit the game;
    cout<<"Would you like to quit the game? Press Q to quit or any button to keep playing: "<<"\n";
    cin>>quiterGame;
    if(quiterGame == "Q" || quiterGame == "q"){
      cout<<"Computer score: "<<aiScore<<"\n";
      ShowComputerBoard();
      cout<<"your score: "<<userScore<<"\n";
      Show();
         return 0;
       }else{
         
       }
  }
    numberOfRuns++;
  }
  return 0;
}//end of code 


