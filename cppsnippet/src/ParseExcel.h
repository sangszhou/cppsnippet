/*
 * ParseExcel.h
 *
 *  Created on: 2014年10月1日
 *      Author: sangs
 */

#ifndef PARSEEXCEL_H_
#define PARSEEXCEL_H_

#include <iostream>
using namespace std;

//should use vector for safety
//numSplits indicate the row of return two dimensional array
//
char** str_split(char* str, char delim, int *numSplits) {
	char** ret;
	int retLen;
	char* c;

	if((str == NULL) || (delim == '\0')) {
		ret = NULL;
		retLen = -1;
		printf("Input is NULL or invalid delim\n");
	}else {
		retLen = 0;
		c = str;
		/*
		 * Pre-calculate number of elements
		 */
		do {
			if(*c == delim) {
				retLen ++;
			}
			c ++;
		} while(*c != '\0');
	}
	ret = (char**)malloc((retLen+1) * sizeof(*ret));
	ret[retLen] = NULL;

	c = str;
	retLen = 1;
	ret[0] = str;

	do {
		if(*c == delim) {
			ret[retLen++] = &c[1];
			*c = '\0';
		}
		c++;
	} while(*c != '\0');

	if(numSplits != NULL) {
		*numSplits = retLen;
	}else {
		printf("Invalid numSplits\n");
	}

	return ret;
}



#endif /* PARSEEXCEL_H_ */
