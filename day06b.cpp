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
std::string convert(__uint128_t value){
	std::string rc;
	char valueString[100];
	int idx=0;
	while(value != 0){
		valueString[idx++]='0' + value%10;
		value=value/10;
	}
	char tmp;
	for(int i=0;i<idx/2;i++){
		tmp=valueString[i];
		valueString[i]=valueString[idx-1-i];
		valueString[idx-1-i]=tmp;
	}
	valueString[idx]='\0';
	rc=valueString;
	return rc;
}
int main(int argc, char* argv[]){
	char* data[MAX];
	int numData=readLines("day06input.txt",data,MAX);
	int initialFishes[MAX];
	char* value=strtok(data[0],",\n");
	int numInitialFishes=0;
	while(value){
		initialFishes[numInitialFishes++]=atoi(value);
		value=strtok(NULL,",\n");
	}
	unsigned long long daysFromBirth[9]={0};
	for(int i=0;i<numInitialFishes;i++){
		daysFromBirth[initialFishes[i]]++;
	}
	unsigned long long numFishes=numInitialFishes;
	for(int i=0;i<256;i++){
		unsigned long long numAtZero=daysFromBirth[0];
		for(int j= 1;j < 9;j++){
			daysFromBirth[j-1]=daysFromBirth[j];
		}
		daysFromBirth[8]=numAtZero;
		daysFromBirth[6]+=numAtZero;
		numFishes+=numAtZero;
		std::cout << "after "<< i+1 << " days: " << numFishes << std::endl;
	}

	cleanLines(data,numData);
}