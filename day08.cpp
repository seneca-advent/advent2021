#include <iostream>
#include <cstring>
#include "utils.h"
const int MAX=1000;

class Entry{
	char input_[10][8];
	char output_[4][8];
public:
	Entry(char* entryText){
		char* value=strtok(entryText," ");
		unsigned int curr;
		for(int i=0;i<10;i++){
			strcpy(input_[i],value);
			value=strtok(NULL," |");

		}
		for(int i=0;i<4;i++){
			strcpy(output_[i],value);
			value=strtok(NULL," |");			
		}
	}
	void print() const{
		for(int i=0;i<10;i++){
			std::cout << input_[i] << ", ";
		}
		std::cout << "||";
		for(int i=0;i<4;i++){
			std::cout << output_[i] << ", ";
		}
		std::cout << std::endl;
	}
	int countEasyOutput() const{
		int rc=0;
		for(int i=0;i<4;i++){
			int len=strlen(output_[i]);
			if(len==2 || len==4 || len==3 || len==7){
				rc++;
			}
		}
		return rc;
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
	int numData=readLines("day08input.txt",data,MAX);
	Entry* entries[MAX];
	int total=0;
	for(int i=0;i<numData;i++){
		entries[i]=new Entry(data[i]);
		total+=entries[i]->countEasyOutput();
	}
	std::cout << "total: " << total << std::endl;
	for(int i=0;i<numData;i++){
		delete entries[i];
	}

	cleanLines(data,numData);
}