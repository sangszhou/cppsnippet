/*
 * MultidimensionalArray.h
 *
 *  Created on: 2014年10月1日
 *      Author: sangs
 */
#include <stdio.h>
#include <memory.h>

#ifndef MULTIDIMENSIONALARRAY_H_
#define MULTIDIMENSIONALARRAY_H_

int **createMultiD(int row, int column) {
	int** ary = new int*[row];

	for(int i = 0; i < row; i ++)
		ary[i] = new int[column];
	return ary;
}

void test() {
	int ** ary = createMultiD(3, 4);
	ary[2][3] = 1;
	printf("%d", ary[2][3]);
}


#endif /* MULTIDIMENSIONALARRAY_H_ */
