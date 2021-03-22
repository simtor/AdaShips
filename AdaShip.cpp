#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string name;
string funds;
int supplies, turns;
std::vector<int> x;
std::vector<string> shipName; 

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

void getboard(){
int boardwidth;
int boardheight;
  cin>>boardwidth;
  cin>>boardheight;
  return;
}

bool gridMaker(){

  // const int array = 10;
  // int myArray[array] ;

  // int my2Darray [array][array];
  // for(size_t i=0; i < array; i++){
  //   for(size_t k=0; k<array; i++){
  //     my2Darray[i][k]=0;
  //   }
  // }

  // for(size_t i=0; i < array; i++){
  //   for(size_t k=0; k<array; i++){
  //     std::cout<< my2Darray[i][k]<< " ";
  //   }
  //   std::cout<<"\n";
  // }
    for(int i = 0; i < 10; i++) {  
    std::cout <<  i + 1 << "";
    for(int j = 0; j < 10; j++){
      std::cout <<" | ";
    }
    std::cout << std::endl;
  }
  std::string board[10][10] = {
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," ",""," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "},
      {" "," "," "," "," "," "," "," "," "," "}
    };

}

int main() 
{
    cout<<"AdaShip is a clone of the classic‘Battleship’game\n";
    cout<<"-----------------MENU-----------------\n";
    cout<<" 1.One player v computer game\n 2.Quit\n";
    string choose; 
    cin >> choose;
    readConfig();
    getboard();
    gridMaker();
  // const int array = 10;
  // int myArray[array];

  // int my2Darray [array][array];
  // for(size_t i=0; i < array; i++)
  // {
  //   for(size_t k=0; k<array; i++)
  //   {
  //     my2Darray[i][k]=0;
  //   }
  // }
  // for(size_t i=0; i < array; i++)
  // {
  //   for(size_t k=0; k<array; i++)
  //   {
  //     std::cout<< my2Darray[i][k]<< " ";
  //   }
  //   std::cout<<"\n";
  // }
  // system ("PAUSE");
  return 0;
}
//Created by Simone Ram
