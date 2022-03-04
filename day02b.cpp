#include <iostream>
#include <cstring>
#include <cstdio>
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
int main(int argc, char* argv[]){
	char* data[MAX];
	int numData=readLines("day02input.txt",data,MAX);
	char command[8];
	int amount;
	int horizontal =0 ;
	int vertical =0;
	int aim = 0;
	for(int i=0;i<numData;i++){
		sscanf(data[i],"%s %d\n",command,&amount);
		if(strcmp(command,"up")==0){
			aim = aim - amount;
		}
		else if(strcmp(command, "down")==0){
			aim = aim + amount;
		}
		else{
			horizontal = horizontal + amount;
			vertical = vertical + aim * amount;
		}
	}
	std::cout << "vertical: " << vertical <<  std::endl;
	std::cout << "horizontal: " << horizontal <<  std::endl;
	std::cout << "result: " << vertical * horizontal << std::endl;
	cleanLines(data,numData);
}