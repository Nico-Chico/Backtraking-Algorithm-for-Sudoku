#include <iostream>
#include "Sudoku.hpp"
#include <chrono>

using namespace std;

int main () { 

	// Time control variables:
	auto t1_g = std::chrono::high_resolution_clock::now();
	auto t2_g = std::chrono::high_resolution_clock::now();
	auto duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();
	

	cout<<endl << " ===== Use of Backtracking Algorithm on Sudoku problems =====" << endl << endl;
	
	cout << "---------------------------------------" << endl;
	cout << "Sudoku 9x9 experiments" <<endl;
	Sudoku sudoku9(9);
	for(int i=1; i<=46; i++) {
		sudoku9.readFromFile("Sudoku9.csv", i);
		//Show initial status
		cout << sudoku9 << endl;
		t1_g = std::chrono::high_resolution_clock::now();
		if(sudoku9.solveSudoku_Backtraking())
			cout << "Solution found: \n" << sudoku9 <<endl;
		else
			cout << "No solution for that problem." <<endl;
        t2_g = std::chrono::high_resolution_clock::now();
        duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();
		cout << "Time in µs: "<<duration_g<<endl<<endl<<endl;
	}
	
	cout << "---------------------------------------" << endl;
	cout << "Sudoku 16x16 experiment" <<endl;
	Sudoku sudoku16(16);
	sudoku16.readFromFileMatrix("Sudoku16.csv");
	cout << "Initial status:" << endl;
	cout << sudoku16 << endl;
	t1_g = std::chrono::high_resolution_clock::now();
	if(sudoku16.solveSudoku_Backtraking())
		cout << "Solution found: \n" << sudoku16 <<endl;
	else
		cout << "No solution for that problem." <<endl;
    t2_g = std::chrono::high_resolution_clock::now();
    duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();
	cout << "Time in µs: "<<duration_g<<endl<<endl<<endl;


	cout << "---------------------------------------" << endl;
	cout << "Sudoku 25x25 experiment" <<endl;
	Sudoku sudoku25(25);
	sudoku25.readFromFileMatrix("Sudoku25.csv");
	cout << "Initial status:" << endl;
	cout << sudoku25 << endl;
	t1_g = std::chrono::high_resolution_clock::now();
	if(sudoku25.solveSudoku_Backtraking())
		cout << "Solution found: \n" << sudoku25 <<endl;
	else
		cout << "No solution for that problem." <<endl;
    t2_g = std::chrono::high_resolution_clock::now();
    duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();
	cout << "Time in µs: "<<duration_g<<endl<<endl<<endl;
} 


