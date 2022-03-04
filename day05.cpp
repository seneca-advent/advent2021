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
	int numData=readLines("day05sample.txt",data,MAX);
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
	}
	int numBad=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
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