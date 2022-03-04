#include <iostream>
#include <cstring>
#include "utils.h"
const int MAX=1000;

/**********************************************************/
/*                                                        */
/* this program will read in every line of input.txt and  */
/* put each line into its own cstring.  The cleanLines()  */
/* function will deallocate all strings                   */
/*                                                        */
/* compile: c++ fileReader.cpp utils.cpp                  */
/*                                                        */
/**********************************************************/
struct Coord{
	int fromX_;
	int fromY_;
	int toX_;
	int toY_;
};
int main(int argc, char* argv[]){
	char* data[MAX];
	int numData=readLines("day05input.txt",data,MAX);
	Coord lines[MAX];
	for(int i=0;i<numData;i++){
		sscanf(data[i],"%d,%d -> %d,%d", &lines[i].fromX_,
				&lines[i].fromY_,&lines[i].toX_,&lines[i].toY_);
	}
	int map[1000][1000]={0};
	int smaller;
	int bigger;
	int vsmaller;
	int vbigger;
	for(int i=0;i<numData;i++){
		if(lines[i].fromX_==lines[i].toX_){
			//vertical, changing Ys
			if(lines[i].fromY_ < lines[i].toY_){
				smaller =lines[i].fromY_;
				bigger=lines[i].toY_;
			}
			else{
				smaller =lines[i].toY_;
				bigger=lines[i].fromY_;
			}
			for(int j=smaller;j<=bigger;j++){
				map[lines[i].fromX_][j]++;
			}
		}
		else if(lines[i].fromY_==lines[i].toY_){
			//horizontal, changing X's
			if(lines[i].fromX_ < lines[i].toX_){
				smaller =lines[i].fromX_;
				bigger=lines[i].toX_;
			}
			else{
				smaller =lines[i].toX_;
				bigger=lines[i].fromX_;
			}
			for(int j=smaller;j<=bigger;j++){
				map[j][lines[i].fromY_]++;
			}
		}
		else if((lines[i].fromX_ < lines[i].toX_ && lines[i].fromY_<lines[i].toY_) ||
				  (lines[i].fromX_ > lines[i].toX_ && lines[i].fromY_>lines[i].toY_)){
			  //top left to bottom right or bottomright to top left
			if(lines[i].fromY_ < lines[i].toY_){
				vsmaller =lines[i].fromY_;
				smaller =lines[i].fromX_;
				vbigger=lines[i].toY_;
				bigger=lines[i].toX_;
			}
			else{
				vsmaller =lines[i].toY_;
				vbigger=lines[i].fromY_;
				smaller =lines[i].toX_;
				bigger=lines[i].fromX_;
			}
			for(int i=smaller,j=vsmaller;i<=bigger;i++,j++){
				map[i][j]++;
			}
		}
		else{
			//top right to bottom left or bottom left to top right
			if(lines[i].fromY_ < lines[i].toY_){
				vsmaller =lines[i].fromY_;
				vbigger=lines[i].toY_;
				smaller =lines[i].toX_;
				bigger=lines[i].fromX_;
			}
			else{
				vsmaller =lines[i].toY_;
				vbigger=lines[i].fromY_;
				smaller =lines[i].fromX_;
				bigger=lines[i].toX_;
			}
			for(int i=smaller, j=vbigger;i<=bigger;i++,j--){
				map[i][j]++;
			}

		}
	}

	int numBad=0;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			std::cout<< map[j][i];
			if(map[i][j]>1){
				numBad++;
			}
		}
		std::cout << std::endl;
	}
	std::cout << numBad << std::endl;
	cleanLines(data,numData);
}