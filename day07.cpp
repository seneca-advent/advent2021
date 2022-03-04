#include <iostream>
#include <cstring>

#include "utils.h"
const int MAX=5000;

/**********************************************************/
/*                                                        */
/* this program will read in every line of input.txt and  */
/* put each line into its own cstring.  The cleanLines()  */
/* function will deallocate all strings                   */
/*                                                        */
/* compile: c++ fileReader.cpp utils.cpp                  */
/*                                                        */
/**********************************************************/


unsigned int absolute(int number){
	return (number < 0)? -number:number;
}

unsigned long long totalDistance(unsigned int pos, unsigned int crabPositions[], int numPositions);
int main(int argc, char* argv[]){
	char* data[MAX];
	int numData=readLines("day07input.txt",data,MAX);
	unsigned int crabs[MAX];
	char* value=strtok(data[0],",\n");
	unsigned int numCrabs=0;
	unsigned int* crabPositions;
	unsigned int max=atoi(value);
	unsigned int min=max;
	unsigned int curr;
	while(value){
		curr=atoi(value);
		if(curr > max){
			max=curr;
		}
		if(curr<min){
			min=curr;
		}
		crabs[numCrabs++]=atoi(value);
		value=strtok(NULL,",\n");
	}
	unsigned int numPositions=max+1;
	crabPositions=new unsigned int[numPositions];

	for(int i=0;i<numPositions;i++){
		crabPositions[i]=0;		
	}
	for(int i=0;i<numCrabs;i++){
		crabPositions[crabs[i]]++;
	}
	unsigned long long minDistance = totalDistance(min,crabPositions,numPositions);
	int minPosition=min;
	for(int i=min+1;i<numPositions;i++){
		if(crabPositions[i]!=0){
			unsigned long long curr=totalDistance(i,crabPositions,numPositions);
			if(curr < minDistance){
				minPosition=i;
				minDistance=curr;
			}
		}
	}	

	std::cout << "min position: " << minPosition << std::endl;
	std::cout << "distance: " << minDistance << std::endl;

	delete [] crabPositions;
	cleanLines(data,numData);
}


unsigned long long totalDistance(unsigned int pos, unsigned int crabPositions[], int numPositions){
	unsigned long long rc=0;
	for(int i=0;i<numPositions;i++){
		rc+=absolute(pos-i)*crabPositions[i];
	}
	return rc;
}
