#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int rows = 10;
const int columns = 10;
int matrix[rows][columns];
char grid[10][10];

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

void getboard(){
int boardwidth;
int boardheight;
  cin>>boardwidth;
  cin>>boardheight;
  return;
}

// bool gridMaker(){
//     for(int i = 0; i < 10; i++) {  
//     std::cout <<  i + 1 << "";
//     for(int j = 0; j < 10; j++){
//       std::cout <<" | ";
//     }
//     std::cout << std::endl;
//   }
//   std::string board[10][10] = {
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," ",""," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "},
//       {" "," "," "," "," "," "," "," "," "," "}
//     };

// }

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
