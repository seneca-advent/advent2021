#include <iostream>
#include <cstring>
#include <cstdlib>
#include "utils.h"
const int MAX=3000;

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
	int depth[MAX];
	int numData=readLines("day01input.txt",data,MAX);
	for(int i=0;i<numData;i++){
		depth[i]=atoi(data[i]);
		std::cout << depth[i] << std::endl;
	}
	int numIncrease=0;
	for(int i=1;i<numData;i++){
		if(depth[i] > depth[i-1]){
			numIncrease++;
		}
	}
	std::cout << numIncrease << std::endl;
	cleanLines(data,numData);
}