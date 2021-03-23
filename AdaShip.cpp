#include<iostream>
using namespace std; 

const int rows = 10;
const int elements = 10;
const char isHit = 'H';
// const int value=1;

//num of total ships

//define array
int matrix[rows][elements];
char grid[10][10];
int maxships= 5;
int value=1;

// void printGrid() {
// 	// print the current grid
// 	cout << endl;
// 	for (int x = 0; x<10; x++) {
// 		for (int y = 0; y<10; y++) {
// 			cout << setw(2) << grid[x][y];
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }//end of printGrid
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

void createGrid() {
	// create a blank grid   
	for (int x = 1; x<10; x++) {
		for (int y = 1; y<10; y++) {
			grid[x][y] = '0';
		}
	}
}//end of createGrid

// void Show()
// {
// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < elements; j++)
// 		{
// 			cout << matrix[i][j] << " ";
// 		}//end for
// 		cout << endl;
// 	}//end for
// }//end of show

void Show()
{
	// for (int row = 0; row <20; ++row)
	// {
	// 	for (int column = 0; column < 20; ++column)
	// 	{
	// 		// matrix[row][column] = value * value;
	// 		value++;
	// 	}// end for (column=0; column<10; column++)
	// } //end for (row=0; row<10; row++)

	std::cout << "↓COL/ROW→ \t";
	for (int column = 1; column < 10; ++column)
	std::cout << column<< "\t";
	std::cout << "\n";
	for ( int row = 1; row < 10; ++row)
	{
        std::cout << row<< "\t\t";
        for (int column = 1; column < 10; ++column)
        {
           // std::cout << column + 1 << "\t";
		    {
            
			/*if (column!= 0) cout << column << "\t" << */cout << matrix[row][column] << "\t";
		    }//end for (column=0; column<10; column++)
        }
		cout << endl;
	} //end for (row=0; row<10; row++)
}
void SetShips()
{
	int s = 0;
	while (s < maxships)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if (matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}//end if
	}//end while
}//end of SetShips

void printGrid() {
	// print the current grid
	cout << endl;
	for (int x = 0; x<10; x++) {
		for (int y = 0; y<10; y++) {
			cout << grid[x][y];
		}
		cout << endl;
	}
	cout << endl;
}//end of printGrid

bool Attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}//end if
	return false;
}//end of Attack

void update(){
	int r;
	int z;
	//  int v1 = rand() % 100;0
	//  int v2 = rand() % 100;
	 int v1;
	 int v2;
	 int idx = colref_index("B");
	std::string colref = index_colref(idx);
	std::cout << "\nindex value: " << idx;
	std::cout << "\ncolumn reference: " << colref;
	std::cout << "\n";
	 std::cout<<v1<<"\n";
	 std::cout<<v2<<"\n";   
    //  v1 >> matrix[0][0];
	// for(int i=0; i<2; i++){
	//getline(cin, matrix[v1][v2]);
  	cout<<"Insert element1: ";cin>>v1;
	cout<<"Insert element2: ";cin>>v2;
	//   cin>>v2;
	
  	matrix[v1][v2]= 1;//fix this
	// }
	// std::cin >> matrix[v1][v2];
	// matrix[r][z] = rand();
}
int main()
{
    // printGrid();
    // createGrid();
	update();
    Show();

	// SetShips();

	
    // cout<<matrix[3][3];
}

//Created by Simone Ram
