//============================================================================
// Name        : Suduko_Solver.cpp
// Author      : Harry
//============================================================================

#include "Data_suduko.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


#define Size 9
#define sqrSize 3

#define inTerminal

using namespace std;

typedef struct{
	int grid[Size][Size];// [x][y]
	bool gridNumberLocked[Size][Size];//use to determine if number is locked
}sudoku;

void printSudoku(sudoku sudokuToPrint){

	cout << "\n";
	for(int y=0;y<Size;y++){
		if( (y % sqrSize) ==0){
			cout << "+++++++++++++++++++++++++++\n";
		}
		for(int x=0;x<Size;x++){
			if( (x % sqrSize) ==0){
				cout << " +";
			}
			cout <<  " ";
			cout<<sudokuToPrint.grid[x][y];
		}
		cout << " +\n";
	}
	cout << "+++++++++++++++++++++++++++\n\n";
}

/*
int writeOutSudoku(sudoku sudokuToWrite){
	ofstream sudokuOut ("sudokuOut.txt");
	if(!sudokuOut.is_open()){
		cout<<"No sudokuOut file";
		return 1;
	}else{
		cout<<"\nsudokuOut file accessed\n";
	}

	for(int y=0;y<Size;y++){
		for(int x=0;x<Size;x++){
			sudokuOut << sudokuToWrite.grid[x][y];
		}
		sudokuOut << '\n';
	}
	sudokuOut.close();
	return 0;
}*/

/*int readInSudoku(sudoku* sudokuToRead){
	ifstream  sudokuIn ("sudokuIn.txt");
	string tempFileRead;

	if(!sudokuIn.is_open()){
		cout<<"No sudokuIn file";
		return 1;
	}else{
		cout<<"\nsudokuIn file accessed\n\n";
	}

	for(int y=0;y<Size;y++){
		sudokuIn >> tempFileRead;
		for(int x=0;x<Size;x++){
			sudokuToRead->grid[x][y]=tempFileRead[x]-48;
			if(sudokuToRead->grid[x][y] != 0){
				sudokuToRead->gridNumberLocked[x][y]=1;
			}else{
				sudokuToRead->gridNumberLocked[x][y]=0;
			}
		}
	}
	sudokuIn.close();
	return 0;
}*/

void readInSudokuData(sudoku* sudokuToRead, string data){
	string tempFileRead;
	istringstream iss(data);
	for(int y=0;y<Size;y++){
		iss >> tempFileRead;
		for(int x=0;x<Size;x++){
			sudokuToRead->grid[x][y]=tempFileRead[x]-48;
			if(sudokuToRead->grid[x][y] != 0){
				sudokuToRead->gridNumberLocked[x][y]=1;
			}else{
				sudokuToRead->gridNumberLocked[x][y]=0;
			}
		}
	}
}

bool checkRow(sudoku sudokuToCheck, int y,int* rowErrX){
	bool check[Size]={0,0,0,0,0,0,0,0,0};
	for(int counterRow=0;counterRow<Size;counterRow++){
		if( sudokuToCheck.grid[counterRow][y] !=0){
			if( check[sudokuToCheck.grid[counterRow][y]-1]==1 ){
				*rowErrX=counterRow;
				return 0;
			}else{
				check[sudokuToCheck.grid[counterRow][y]-1]=1;
			}
		}
	}
	return 1;
}

bool checkColumn(sudoku sudokuToCheck, int x, int* columnErrY){
	bool check[Size]={0,0,0,0,0,0,0,0,0};
	for(int counterColumn=0;counterColumn<Size;counterColumn++){
		if( sudokuToCheck.grid[x][counterColumn] !=0){
			if( check[sudokuToCheck.grid[x][counterColumn]-1]==1 ){
				*columnErrY=counterColumn;
				return 0;
			}else{
				check[sudokuToCheck.grid[x][counterColumn]-1]=1;
			}
		}
	}
	return 1;
}

bool checkSmallGrid(sudoku sudokuToCheck, int x,int y,int* smallGridErrX,int* smallGridErrY){
	bool check[Size]={0,0,0,0,0,0,0,0,0};
	int yConst=y/sqrSize;
	int xConst=x/sqrSize;
	yConst *=sqrSize;
	xConst *=sqrSize;
	for(int smally=yConst;smally<sqrSize+yConst;smally++){
		for(int smallx=xConst;smallx<sqrSize+xConst;smallx++){
			if( sudokuToCheck.grid[smallx][smally] !=0){
				if( check[sudokuToCheck.grid[smallx][smally]-1]==1 ){
					*smallGridErrX=smallx;
					*smallGridErrY=smally;
					return 0;
				}else{
					check[sudokuToCheck.grid[smallx][smally]-1]=1;
				}
			}
		}
	}
	return 1;
}

int solveSudoku(sudoku &sudokuProcessing,int &processingCounter){
	int rowErrX,columnErrY,smallGridErrX,smallGridErrY;
	bool row=1,column=1,smallGrid=1;
	row=1;column=1;smallGrid=1;
		for(int y=0;y<Size;y++){
			for(int x=0;x<Size;x++){
				if(sudokuProcessing.gridNumberLocked[x][y]==0){
					do{
						if(sudokuProcessing.grid[x][y] >= Size){
							sudokuProcessing.grid[x][y]=0;
							do{
								if(sudokuProcessing.grid[x][y]>= Size && sudokuProcessing.gridNumberLocked[x][y]==0){sudokuProcessing.grid[x][y]=0;}
								if(x==0 && y==0){
									cout<<"\n\nProgram sent to x=0 y=0, therefore there is no solution\n";
									exit(2);
								}
								if(x==0){
									x=Size-1;
									y--;
								}else{
									x--;
								}
							}while(sudokuProcessing.gridNumberLocked[x][y]!=0 || sudokuProcessing.grid[x][y]>= Size);
						}
						if(sudokuProcessing.grid[x][y] < Size ){
							sudokuProcessing.grid[x][y]++;
						}
						row=checkRow(sudokuProcessing,y,&rowErrX);
						column=checkColumn(sudokuProcessing,x,&columnErrY);
						smallGrid=checkSmallGrid(sudokuProcessing,x,y,&smallGridErrX,&smallGridErrY);
						processingCounter++;
					}while(!(row && column && smallGrid));
				}
			}
		}
		return 0;
}

int main() {
	sudoku sudokuProcessing;
	int rowErrX,columnErrY,smallGridErrX,smallGridErrY,processingCounter=0;

#ifndef inTerminal
	char userInput;
#endif
/*	if( readInSudoku(&sudokuProcessing) == 1){
#ifndef inTerminal
	cout<<"press any key and enter to exit\n";
	cin>>userInput;
	cout<<"Exiting\n";
#endif
		return 1;
	}*/

	readInSudokuData(&sudokuProcessing, getData() );

	cout<<"\nInputted Sudoku:\n";
	printSudoku(sudokuProcessing);
	for(int y=0;y<Size;y++){
		for(int x=0;x<Size;x++){
			if((checkRow(sudokuProcessing,y,&rowErrX) && checkColumn(sudokuProcessing,x,&columnErrY) && checkSmallGrid(sudokuProcessing,x,y,&smallGridErrX,&smallGridErrY))==0){
				cout<<"\n\nInput Sodoku contains errors and cannot be solved\n";
#ifndef inTerminal
	cout<<"press any key and enter to exit\n";
	cin>>userInput;
	cout<<"Exiting\n";
#endif
				exit(3);
			}
		}
	}

	solveSudoku(sudokuProcessing,processingCounter);
	cout<<"Solved Sudoku:\n";
	printSudoku(sudokuProcessing);
	cout<<"Processing Counter: "<<processingCounter<<endl;
	/*if( writeOutSudoku(sudokuProcessing) ){
#ifndef inTerminal
	cout<<"press any key and enter to exit\n";
	cin>>userInput;
	cout<<"Exiting\n";
#endif
		return 1;
	}*/
#ifndef inTerminal
	cout<<"press any key and enter to exit\n";
	cin>>userInput;
	cout<<"Exiting\n";
#endif
	return 0;
}
