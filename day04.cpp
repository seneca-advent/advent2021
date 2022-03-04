#include <iostream>
#include <cstring>
#include <cstdlib>
#include "utils.h"
const int MAX=1000;

class Board{
	struct Coord{
		int row_;
		int col_;
		bool isSet_;
		Coord(){
			isSet_=false;
		}
		void set(int row, int col){
			row_=row;
			col_=col;
			isSet_=true;
		}
	};
	bool board_[5][5]; //board[r][c];
	Coord lookUp_[100];
	int boardValues_[5][5];
	int numSetInRow_[5];
	int numSetInCol_[5];
	bool isWin_;
public:
	Board(char* boardData[]){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				board_[i][j]=false;
			}
		}
		int rowValues[5];
		for(int i=0;i<5;i++){
			sscanf(boardData[i],"%d %d %d %d %d",&rowValues[0],&rowValues[1], 
										&rowValues[2],&rowValues[3],&rowValues[4]);
			for(int j=0;j<5;j++){
				lookUp_[rowValues[j]].set(i,j);
				boardValues_[i][j]=rowValues[j];
			}									
		}
		for(int i=0;i<5;i++){
			numSetInCol_[i]=0;
			numSetInRow_[i]=0;
		}
		isWin_=false;
	}
	bool mark(int bingo){
		Coord curr=lookUp_[bingo];
		bool rc=false;
		if(curr.isSet_==true){
			board_[curr.row_][curr.col_]=true;
			numSetInRow_[curr.row_]++;
			numSetInCol_[curr.col_]++;
			if(numSetInCol_[curr.col_] == 5 || numSetInRow_[curr.row_]==5){
				isWin_=true;
			}
			rc=true;
		}
		return rc;
	}
	//returns true if we have a win, false otherwise
	bool checkWin()const{
		return isWin_;
	}

	int getScore() const{
		int score=0;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(board_[i][j]==false){
					score+=boardValues_[i][j];
				}
			}
		}
		return score;
	}
};

/**********************************************************/
/*                                                        */
/* this program will read in every line of input.txt and  */
/* put each line into its own cstring.  The cleanLines()  */
/* function will deallocate all strings                   */
/*                                                        */
/* compile: c++ fileReader.cpp utils.cpp                  */
/*                                                        */
/**********************************************************/
int main(int argc, char* argv[]){
	char* data[MAX];
	int numData=readLines("day04input.txt",data,MAX);
	int bingoNumbers[100];
	int numBingoValues;
	char* value=strtok(data[0],",\n");
	numBingoValues=0;
	while(value){
		bingoNumbers[numBingoValues++]=atoi(value);
		value=strtok(NULL,",\n");
	}


	int curr=2;
	int numBoards=(numData-1)/6;
	Board* boards[100];
	for(int i=0;i<numBoards;i++){
		boards[i]=new Board(data+curr);
		curr=curr+6;
	}
	bool done=false;
	for(int i=0;!done && i<numBingoValues;i++){
		for(int j=0;!done && j<numBoards;j++){
			if(boards[j]->mark(bingoNumbers[i]) && boards[j]->checkWin()){
				std::cout << "Winner:" << std::endl;
				std::cout << boards[j]->getScore() << std::endl;
				std::cout << bingoNumbers[i] <<std::endl;
				std::cout << boards[j]->getScore() * bingoNumbers[i] << std::endl;
				done=true;
			}
		}
	}
	for(int i=0;i<numBoards;i++){
		delete boards[i];
	}
	cleanLines(data,numData);
}