#include <fstream>
#include <iostream>
#include <cstring>
#include "utils.h"
/*function returns total number of integers read*/

size_t readLines(const char* fname, char* line[],int max){
	std::ifstream fp(fname);
	int rc=0;
	if(!fp){
		std::cout << "unable to open " << fname << std::endl;
		return 0;
	}
	else{
		size_t len;
		char currLine[LINEWIDTH];
		while(rc<max && fp.getline(currLine, LINEWIDTH, '\n')){
			len=strlen(currLine);
			line[rc]=new char[len+1];
			strcpy(line[rc],currLine);
			rc++;
		}
		fp.close();
	}
	return rc;

}

void cleanLines(char* line[],size_t numLines){
	for(size_t i=0;i<numLines;i++){
		delete [] line[i];
	}
}
