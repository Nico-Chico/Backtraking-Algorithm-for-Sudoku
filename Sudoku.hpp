#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <math.h>

/*#include<cstdlib>*/

using namespace std;

class Sudoku {
private:
	int* grid;			// Sudoku board. It is dealed as two dimensional but actually is one dimensional array in order to get better performance. 
	int size;
	// Returns a unassigned location by the parameters
	const bool findUnassignedLocation(int &row, int &col);
	// Check if the number already exists in the row: 
	bool checkRow(int row, int num);
	// Check if the number already exists in the column: 
	bool checkCol(int col, int num);
	// Check if the number already exists in the box(subgrid): 
	bool checkBox(int row, int col, int num);
public:
	Sudoku(const int& size);
	~Sudoku();
	// I overload operator << for the sudoku class. So you can show the sudoku board only doing: "cout << sudoku_instance << endl;"
	friend ostream& operator<<(ostream&, const Sudoku&);
	// Read initial status of the grid from the line "id" of "fileName" file. //It is supposed a size of 9
	void readFromFile(const string& fileName, int id);
	// Read initial status from file in matrix format;
	void readFromFileMatrix(const string& fileName);
 	// Use Backtracking Algorithm to solve the Sudoku;	
 	bool solveSudoku_Backtraking();
 	// Clear the screen and show the updated grid.
 	const void showUpdate();
};

Sudoku::Sudoku(const int& size) {
	this->size = size;
	grid = new int[size*size];
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			grid[(i*size) + j] = 0;
}

Sudoku::~Sudoku() { delete[] grid;}

ostream& operator<<(ostream &strm, const Sudoku& s) {
	for(int i=0; i<s.size; i++) {
		for(int j=0; j<s.size; j++) {
			strm << " "<< s.grid[(i*s.size) + j];
//			strm << setw(2) << setfill('0') << " "<< s.grid[(i*s.size) + j];
		}
		strm << "\n";
	}
  return strm;
}

void Sudoku::readFromFile(const string& fileName, int id) {
    ifstream file(fileName);
    string line = "";
	for(int i=0; i<=id; i++)
		getline(file, line);		// We got the line we want.
		
	//Splitting the line by ';' and saving tokens; 
	string delimiter = ";";
	size_t pos = 0;
	vector<string> tokens;
	while ((pos = line.find(delimiter)) != string::npos) {
    	tokens.push_back(line.substr(0, pos));
    	line.erase(0, pos + delimiter.length());
	}
	id = stoi(tokens[0]);
	int difficulty = stoi(tokens[1]);
	string& data = tokens[2];	
	for(int i=0; i<size*size; i++) {	// load initial status
		data[i] == '.' ? grid[i] = 0 : (grid[i] = data[i] - '0');	// if it's '.' set 0, else set the char translate to int;
	}	
	
	cout <<"Initial status loaded from file: '"<<fileName<<"' | id: "<<id<<" | difficulty: "<<difficulty<< endl;
}

void Sudoku::readFromFileMatrix(const string& fileName) {
    ifstream file(fileName);
    string line = "";
    int i=0;
	while(getline(file, line)) {
		string delimiter = " ";
		size_t pos = 0;
		string token;
		while ((pos = line.find(delimiter)) != string::npos) {
			token = line.substr(0, pos);
			grid[i] = stoi(token);
			line.erase(0, pos + delimiter.length());
			i++;
		}
	}
}

bool Sudoku::checkRow(int row, int num) {
	for(int col=0; col<size; col++)
		if(grid[row*size + col] == num)
			return false;
	return true;
}

bool Sudoku::checkCol(int col, int num) {
	for(int row=0; row<size; row++)
		if(grid[row*size + col] == num)
			return false;
	return true;
}

bool Sudoku::checkBox(int row, int col, int num) {
	int boxSize = sqrt(size);
	int startRow = row - row%boxSize;
	int startCol = col - col%boxSize;
	for(int row=0; row<boxSize; row++)
		for(int col=0; col<boxSize; col++)
			if(grid[(row+startRow)*size + col+startCol] == num)
				return false;
	return true;
}

const bool Sudoku::findUnassignedLocation(int &row, int &col) {
	for(row = 0; row<size; row++)
		for(col = 0; col<size; col++)
			if(grid[row*size + col] == 0)
				return true;
	return false;
}

bool Sudoku::solveSudoku_Backtraking() {
	int row, col;
	
	if(!findUnassignedLocation(row, col))
		return true; // Solved
	
//	cout <<"Computing row:"<<row<<", col:"<<col<<endl;
	for(int num = 1; num<=size; num++)	{
 		if(checkRow(row, num) && checkCol(col, num) && checkBox(row, col, num)) { // if the numer is safe in that position.
			grid[row*size + col] = num;
//			showUpdate();
			if(solveSudoku_Backtraking())
				return true;
			grid[row*size + col] = 0; 	// Set as unassigned
//			showUpdate();
		 }	
	}
	return false;
}

const void Sudoku::showUpdate() { 
	system("clear");
	cout << endl;
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			cout << " "<< grid[(i*size) + j];
		}
		cout << "\n";
	}
//	usleep(10000);
}

