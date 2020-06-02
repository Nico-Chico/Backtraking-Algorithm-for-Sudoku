#include <iostream>
#include "Sudoku.hpp"
#include <chrono>

using namespace std;

int main () { 

	// Time control variables:
	auto t1_g = std::chrono::high_resolution_clock::now();
	auto t2_g = std::chrono::high_resolution_clock::now();
	auto duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();
	
	system("clear");
	cout<<endl << " ===== Use of Backtracking Algorithm on Sudoku problems =====" << endl << endl;
	
	cout << "---------------------------------------" << endl;
	Sudoku sudoku9(9);
	int i = 1;
	cout << "Insert ID of Sudoku to solve: ";	
	cin >> i ;
	sudoku9.readFromFile("Sudoku9.csv", i);
	//Show initial status
	cout << sudoku9 << endl;
	sleep(1);
	t1_g = std::chrono::high_resolution_clock::now();
	if(sudoku9.solveSudoku_Backtraking())
		cout << "Solution found: \n" << sudoku9 <<endl;
	else
		cout << "No solution for that problem." <<endl;
    t2_g = std::chrono::high_resolution_clock::now();
    duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();
	cout << "Time in µs: "<<duration_g<<endl<<endl<<endl;
} 


