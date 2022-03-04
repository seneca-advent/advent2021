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
bool isLower(int map[][MAP], int row,int col){
	int numHigher=0;
	int necessary=4;
	if(row==0){
		necessary--;
	}

}
int main(int argc, char* argv[]){
	char* data[MAX];
	int map[MAX][MAX];
	int numData=readLines("day09sample.txt",data,MAX);
	for(int i=0;i<numData;i++){
		std::cout << data[i] << std::endl;
	}
	int length=strlen(data[0]);
	for(int i=0;i<numData;i++){
		for(int j=0;j<length;j++){
			map[i][j]=data[i][j]-'0';
		}
	}
	int risk=0;
	for(int i=0;i<numData;i++){
		for(int j=0;j<length;j++){
		}
	}

	cleanLines(data,numData);
}