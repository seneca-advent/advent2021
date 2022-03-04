#include <iostream>
#include <cstring>
#include "utils.h"
const int MAX=1000;


int main(int argc, char* argv[]){
	char* data[MAX];
	int numData=readLines("day03input.txt",data,MAX);
	int width=strlen(data[0]);
	int numZero;
	int numOne;
	unsigned int gamma=0;
	unsigned int epsilon=0;
	for(int i=0;i<width;i++){
		numZero=0;
		numOne=0;
		for(int j=0;j<numData;j++){
			if(data[j][i]=='0'){
				numZero++;
			}
			else{
				numOne++;
			}
		}
		gamma = gamma << 1;
		epsilon = epsilon << 1;

		if(numOne > numZero){
			//gamma is 1, epsilon is 0
			gamma = gamma | 1;
		}
		else{
			//gamma is 0, epsilon is 1
			epsilon = epsilon | 1;
		}
	}
	std::cout << gamma << std::endl;
	std::cout << epsilon << std::endl;
	std::cout << gamma * epsilon << std::endl;
	cleanLines(data,numData);
}