<!-- THIS FILE IS ON MARKDOWN FORMAT. PLEASE READ IT ON GITLAB REPO: "https://gitlab.com/Nico_Chico/backtraking-algorithm-for-sudoku"
YOU CAN ALSO USE A PROPER .MD VISOR TO READ IT OR CONVERT TO PDF -->

# Backtraking Algorithm for Sudoku

*Laboratory 2, Introduction to Artificial Intelligence*

This is the second **laboratory work** of the **Introduction to Artificial Intelligence** 2020 course in the Computer Science program from **Politechnika Wrocławska** University.

The objective is getting familiar with Constraints Satisfaction Problems and Backtracking Algorithm. And test its performance solving the *Sudoku* problems. 

Use of Backtracking Algorithm to Solve Sudoku of N×N where N is a perfect square.

The project has been entirely developed in C++ language.

## How to compile the code

```bash
g++ -Wall -o SudokuSolver main.cpp
```

## To run the program
*In the project directory*
```bash
./SudokuSolver
```
## Project Structure
Basically, the code consists int the class Sudoku and main function.
Diferents sudoku problems are saved on the data files: `Sudoku9.csv` `Sudoku16.csv` & `Sudoku25.csv` 

### Class Sudoku:   `Sudoku.hpp`
This class is responsible of store and deal with the sudoku grid and the methods necessary to implement Backtracking.

### Main function :       `SudokuSolver.cpp`
Starts and checks the computation time by solving all the problems contained in
`Sudoku9.csv`	46 problems of 9×9, diferent difficulties
`Sudoku16.csv` 	1 problem of 16×16.
`Sudoku25.csv` 	1 problem of 25×25.

In addition to these the program can solve any N×N sudoku. Where N is a perfect square.
These problems can be initialized with all unassigned items, or from a file, as we do with the ones explained above.

However, as we will see in the experiments, from 25x25 the computation time of the algorithm scales very much and can last for days.

N can be changed on the `main.cpp`

## Experiment, analysis & conclusions:
*Work in progress*

---
 Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico) ⌨️
