#include <iostream>
#include <cstring>
#include "utils.h"
const int MAX=1000;


void filterMost(int bit, char* data[], char* removed[], int numData, int width);
void filterLeast(int bit, char* data[], char* removed[], int numData, int width);
int main(int argc, char* argv[]){
	char* data[MAX];
	char* co2[MAX] = {0};
	int numData=readLines("day03input.txt",data,MAX);
	int width=strlen(data[0]);

	unsigned int oxygenRating=0;
	unsigned int co2Rating=0;

	filterMost(0,data,co2,numData,width);

	for(int i=0;i<width;i++){
		oxygenRating=oxygenRating << 1;
		if(data[0][i]=='1'){
			oxygenRating = oxygenRating | 1;
		}
	}

	co2[numData-1]=data[0];
	data[0]=nullptr;
	filterLeast(0,co2,data,numData,width);

	for(int i=0;i<width;i++){
		co2Rating=co2Rating << 1;
		if(co2[0][i]=='1'){
			co2Rating = co2Rating | 1;
		}
	}



	std::cout << oxygenRating << std::endl;
	std::cout << co2Rating << std::endl;
	std::cout << oxygenRating * co2Rating << std::endl;
	cleanLines(data,numData-1);
	cleanLines(co2,1);
}

/* this function will filter the strings in data for the most common bit at position
    bit.  all strings that don't match, will be placed into removed.  If there is only
    one string left function terminates. */
void filterMost(int bit, char* data[], char* removed[], int numData, int width){

	if(numData > 1){
		int numZero=0;
		int numOne=0;
		char keepBit;		
		for(int j=0;j<numData;j++){
			if(data[j][bit]=='0'){
				numZero++;
			}
			else{
				numOne++;
			}
		}
		if(numOne >= numZero){
			keepBit='1';
		}
		else{
			keepBit='0';
		}
		int numRemoved=0;
		int curr=0;
		for(int j=0;j<numData;j++){
			if(data[j][bit]==keepBit){
				data[curr++]=data[j];
			}
			else{
				removed[numRemoved++]=data[j];
				data[j]=nullptr;
			}
		}
		filterMost(bit+1,data,removed+numRemoved,curr,width);
	}

}

/* this function will filter the strings in data for the most common bit at position
    bit.  all strings that don't match, will be placed into removed.  If there is only
    one string left function terminates. */
void filterLeast(int bit, char* data[], char* removed[], int numData, int width){

	if(numData > 1){
		int numZero=0;
		int numOne=0;
		char keepBit;		
		for(int j=0;j<numData;j++){
			if(data[j][bit]=='0'){
				numZero++;
			}
			else{
				numOne++;
			}
		}
		if(numZero <= numOne){
			keepBit='0';
		}
		else{
			keepBit='1';
		}
		int numRemoved=0;
		int curr=0;
		for(int j=0;j<numData;j++){
			if(data[j][bit]==keepBit){
				data[curr++]=data[j];
			}
			else{
				removed[numRemoved++]=data[j];
				data[j]=nullptr;
			}
		}
		filterLeast(bit+1,data,removed+numRemoved,curr,width);
	}

}

