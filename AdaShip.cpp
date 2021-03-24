#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
using namespace std;



const int rows = 11;
const int columns = 11;


int matrix[rows][columns];
int computer[rows][columns];
char grid[11][11];

int maxships= 5;
int value=1;
string name;
string funds;
int supplies, turns;
std::vector<int> x;
std::vector<string> shipName;
std::vector<std::string> output_vector;

void getBoardSize(){
  std::ifstream input_file;
    input_file.open("adaship_config.ini");
    std::string line;
    while (getline(input_file, line))
    {
        std::istringstream ss_line(line);
        while(ss_line){
            std::string element;
            ss_line >> element;
            output_vector.push_back(element);
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
  std::ifstream file("adaship_config.ini");
  std::string line;
  while (std::getline(file, line)) {
    stringstream ss(line);
    // ss >> name >> supplies >> turns;
    file >> name;
    file >> funds;
    file >> supplies;
    std::cout <<line<< "\n";
    std::cout<<name<<"\n";
    std::cout<<funds<<"\n";
    std::cout<<supplies<<"\n";
    x.push_back(supplies);
    shipName.push_back(funds);

  } 
}
void Show()
{
  char i; 
	std::cout << "\t";
	for (i = 'A'; i <= 'J'; i++)
  cout << i <<"\t"; 
	std::cout << "\n";
	for ( int row = 1; row < 11; ++row)
	{
        std::cout << row<< "\t";
        for (int column = 1; column < 11; ++column)
        {
		    {
          cout << matrix[row][column] << "\t";
		    }
        }
		cout << endl;
	} 
}

void ShowComputerBoard()
{
  char i; 
	std::cout << "\t";
	for (i = 'A'; i <= 'J'; i++)
  cout << i <<"\t"; 
	std::cout << "\n";
	for ( int row = 1; row < 11; ++row)
	{
        std::cout << row<< "\t";
        for (int column = 1; column < 11; ++column)
        {
		    {
          cout << computer[row][column] << "\t";
		    }
        }
		cout << endl;
	} 
}

//Need to change name of the function and this is finished 
void carrier(){
	   int v1;
	   int v2;//turn them into strings for the coodinates 
     int v3=0;
     int v4=0;//turn them into strings for the coodinates 
     string v5;
     //The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     int decisionVF;
    while(v3<5){
      int boatSize=x[v3];
      std::cout<<"Your setting up boat "<<shipName[v4]<<" and it takes up "<<boatSize<<" spaces"<<"\n";
      cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
     cout<<"Insert row number: ";cin>>v1;
     while(!cin || v1 > 10 || v1 < 1){
       cout << "That was no integer! Please enter an integer: ";
       cin.clear();
       cin.ignore();
       cin >> v1;
       }
  	 cout<<"Insert column letter: ";cin>>v2;
     cout<<"Simone: ";cin>>v5;
     while(cin.fail()){
       cout << "That was no integer! Please enter an integer: ";
       cin.clear();
       cin.ignore();
       cin >> v5;
       }
     if(decisionVF==1){
      int s=v1;
      std::cout<<"\n"<<boatSize<<"\n";
        while(amountLoop < boatSize) {
          std::cout<<s<<v1<<"\n";
        matrix[s][v2]=1;//Vertical 
        amountLoop++;
        s++;
        }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
        while(amountLoop < boatSize) {
          std::cout<<v2<<s<<"\n";
        matrix[v1][s]=2;//horizontal
        amountLoop++;
        s++;
      }
    }
    v3++;
    v4++;
    amountLoop= 0;
    Show();
  }
//  int s=v1;//make the variable changeable with v1
}

void battleship(){
	   int v1;
	   int v2;//turn them into strings for the coodinates 
     int v3;
     int v4;//turn them into strings for the coodinates 
     int boatSize=x[1];//The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     int decisionVF;
    //  int s=v1;//make the variable changeable with v1
     cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
     cout<<"Insert row number: ";cin>>v2;
  	 cout<<"Insert column letter: ";cin>>v1;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<s<<v1<<"\n";
      matrix[s][v1]=1;
      amountLoop++;
      s++;
      }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<v2<<s<<"\n";
      matrix[v1][s]=2;
      amountLoop++;
      s++;
    }
  }
}
void destroyer(){
	   int v1;
	   int v2;//turn them into strings for the coodinates 
     int v3;
     int v4;//turn them into strings for the coodinates 
     int boatSize=x[2];//The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     int decisionVF;
    //  int s=v1;//make the variable changeable with v1
     cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
     cout<<"Insert row number: ";cin>>v2;
  	 cout<<"Insert column letter: ";cin>>v1;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<s<<v1<<"\n";
      matrix[s][v1]=1;
      amountLoop++;
      s++;
      }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<v2<<s<<"\n";
      matrix[v1][s]=2;
      amountLoop++;
      s++;
    }
  }
}
void submarine(){
	   int v1;
	   int v2;//turn them into strings for the coodinates 
     int v3;
     int v4;//turn them into strings for the coodinates 
     int boatSize=x[3];//The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     int decisionVF;
    //  int s=v1;//make the variable changeable with v1
     cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
     cout<<"Insert row number: ";cin>>v2;
  	 cout<<"Insert column letter: ";cin>>v1;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<s<<v1<<"\n";
      matrix[s][v1]=1;
      amountLoop++;
      s++;
      }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<v2<<s<<"\n";
      matrix[v1][s]=2;
      amountLoop++;
      s++;
    }
  }
}
void patrolBoat(){
	   int v1;
	   int v2;//turn them into strings for the coodinates 
     int v3;
     int v4;//turn them into strings for the coodinates 
     int boatSize=x[4];//The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     int decisionVF;
    //  int s=v1;//make the variable changeable with v1
     cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
     cout<<"Insert row number: ";cin>>v2;
  	 cout<<"Insert column letter: ";cin>>v1;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<s<<v1<<"\n";
      matrix[s][v1]=1;
      amountLoop++;
      s++;
      }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<v2<<s<<"\n";
      matrix[v1][s]=2;
      amountLoop++;
      s++;
    }
  }
}

void Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = 0;
		}//end for
	}//end for
}//end of clear


void SetShips()
{
	int s = 0;
	while (s < maxships)
	{
		int x = rand() % 10;
		int y = rand() % 10;
    std::cout<<x<<y<<"\n";
		if (computer[x][y] != 1)
		{
			s++;
			computer[x][y] = 1;
		}
	}
}


void masterBoatSetUp(){
	  //  int v1;
	  //  int v2;//turn them into strings for the coodinates
    //  srand((unsigned) time(0));
    //  int v1 = (rand() % 5) + 1;
    //  int v2 = (rand() % 5) + 1; 
     int v3=0;
     int v4=0;//turn them into strings for the coodinates 
     //The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     srand((unsigned) time(0));
    while(v3<5){
     int boatSize=x[v3];
     int v1 = (rand() % 7) + 1;
     int v2 = (rand() % 7) + 1;
     int decisionVF = (rand() % 2) +1;
      std::cout<<"Your setting up boat "<<shipName[v4]<<" and it takes up "<<boatSize<<" spaces"<<"\n";
    //   cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
    //  cout<<"Insert row number: ";cin>>v2;
  	//  cout<<"Insert column letter: ";cin>>v1;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
        while(amountLoop < boatSize) {
          std::cout<<s<<v1<<"\n";
        computer[s][v1]=1;//Vertical 
        amountLoop++;
        s++;
        }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
        while(amountLoop < boatSize) {
          std::cout<<v2<<s<<"\n";
        computer[v1][s]=2;//horizontal
        amountLoop++;
        s++;
      }
    }
    v3++;
    v4++;
    amountLoop=0;
  }
//  int s=v1;//make the variable changeable with v1
}

void deleteThisFunction(){
	  //  int v1;
	  //  int v2;//turn them into strings for the coodinates
    //  srand((unsigned) time(0));
    //  int v1 = (rand() % 5) + 1;
    //  int v2 = (rand() % 5) + 1; 
     int v3=0;
     int v4=0;//turn them into strings for the coodinates 
     //The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     srand((unsigned) time(0));
    while(v3<5){
     int boatSize=x[v3];
     int v1 = (rand() % 7) + 1;
     int v2 = (rand() % 7) + 1;
     int decisionVF = (rand() % 2) +1;
      std::cout<<"Your setting up boat "<<shipName[v4]<<" and it takes up "<<boatSize<<" spaces"<<"\n";
    //   cout<<"Would you like vertical or horizontal: ";cin>>decisionVF;
    //  cout<<"Insert row number: ";cin>>v2;
  	//  cout<<"Insert column letter: ";cin>>v1;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
        while(amountLoop < boatSize) {
          std::cout<<s<<v1<<"\n";
        matrix[s][v1]=1;//Vertical 
        amountLoop++;
        s++;
        }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
        while(amountLoop < boatSize) {
          std::cout<<v2<<s<<"\n";
        matrix[v1][s]=2;//horizontal
        amountLoop++;
        s++;
      }
    }
    v3++;
    v4++;
    amountLoop=0;
  }
//  int s=v1;//make the variable changeable with v1
}

void setUpCarrier(){
  srand((unsigned) time(0));
  int v1 = (rand() % 5) + 1;
  int v2 = (rand() % 5) + 1;
    // int v1= rand() % 5+1;
    // int v2= rand() % 5+1;//turn them into strings for the coodinates 
    int boatSize=x[0];//The amount of places so it will be 5,4,3,2 ;
    int amountLoop=0;
    int decisionVF;
    int s=v2;
    std::cout<<"\n"<<boatSize<<"\n";
    while(amountLoop < boatSize) {
      std::cout<<s<<v1<<"\n";
    computer[s][v1]=1;
    amountLoop++;
    s++;
  }
  return;
}
void setUpBattleship(){
  srand((unsigned) time(0));
  int superRandom = (rand() % 9) +1;
  int v1 = (rand() % superRandom) + 1;
  int v2 = (rand() % superRandom) + 1;
  
	  // int v1= rand() % 5+1;
	  // int v2= rand() % 5+1;//turn them into strings for the coodinates 
    int boatSize=x[1];//The amount of places so it will be 5,4,3,2 ;
    int amountLoop=0;
    int decisionVF;
    int s=v2;
    std::cout<<"\n"<<boatSize<<"\n";
    while(amountLoop < boatSize) {
      std::cout<<s<<v1<<"\n";
    computer[s][v1]=5;
    amountLoop++;
    s++;
    }
    return;
}
void setUpDestroyer(){
     srand((unsigned) time(0));
     int randomN = (rand() % 8) +1;
     int v1 = (rand() % randomN) + 1;
     int v2 = (rand() % randomN) + 1;
     int boatSize=x[2];//The amount of places so it will be 5,4,3,2 ;
     int amountLoop=0;
     int decisionVF = (rand() % 2) +1;;
    //  int s=v1;//make the variable changeable with v1
    std::cout<<decisionVF;
     if(decisionVF==1){
      int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<s<<v1<<"\n";
      computer[s][v1]=7;
      amountLoop++;
      s++;
      }
     }else{
       int s=v2;
      std::cout<<"\n"<<boatSize<<"\n";
      while(amountLoop < boatSize) {
        std::cout<<v2<<s<<"\n";
      computer[v1][s]=7;
      amountLoop++;
      s++;
    }
  }
}

bool Attack(int x, int y)
{
//   switch(computer[x][y] == !0) {
//   case x:
//     // code block
//     break;
//   case y:
//     // code block
//     break;
//   default:
//     // code block
// }
	if (computer[x][y] == 1 || computer[x][y] == 2)
	{
		computer[x][y]=5;
		return true;
	}
	return false;
}//end of Attack



//19/03/2021 17:13 Your need to  delete the functions and put name of the boat in there 
//need to finish set up of the boats 
//Need to creace AI to attck the users
//22:30 Need to make validation, vector for board size Transfer everything onto frankstain
//Finish the floawchart, make the readme file 
//

void computerbrain(){
   srand((unsigned) time(0));
   int aiNumber = (rand() % 9) + 1;
   int aiNumber2 = (rand() % 9) + 1;
  if (matrix[aiNumber][aiNumber2] == 1 || matrix[aiNumber][aiNumber2] == 2)
	{
		matrix[aiNumber][aiNumber2]=5;
    cout << "You sunk the battleship! :)" << endl;
    cout<<"Number 1 for random: "<<aiNumber<<" Number 2 for random: "<<aiNumber2;
		// return true;
	}
  cout<<"Number 1 for random: "<<aiNumber<<"\n";
  cout<<" Number 2 for random: "<<aiNumber2<<"\n";
  matrix[aiNumber][aiNumber2]=8;
  cout << "Sorry, no ship at that position!" << endl;
	// return false;

}

int main() 
{
    int pos1 = 0;
	  int pos2 = 0;
    int numberOfRuns=0;
    cout<<"AdaShip is a clone of the classic‘Battleship’game\n";
    cout<<"-----------------MENU-----------------\n";
    cout<<" 1.One player v computer game\n 2.Quit\n";
    readConfig();
    Show();
	  carrier();
    // deleteThisFunction();
    Show();
    cout<<"*****************setup finished******************"<<"\n";
    masterBoatSetUp();
    ShowComputerBoard();
    while(numberOfRuns < 5){
    cout << "Please input location(x, y): ";
		cin >> pos1;
    cout << "Please input location(x, y): "; 
    cin >> pos2;
		//begin if
		if (Attack(pos1, pos2) == true)
		{
			cout << "You sunk the battleship! :)" << endl;
            ShowComputerBoard();
		}
		else
		{
			cout << "Sorry, no ship at that position!" << endl;
            ShowComputerBoard();
		}//end
    computerbrain();
    cout<<"***************** USER BOARD ******************"<<"\n";
    Show();
    numberOfRuns++;
  }
  // getBoardSize();
  return 0;
}
//Created by Simone Ram
