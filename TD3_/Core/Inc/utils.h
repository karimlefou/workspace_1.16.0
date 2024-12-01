/*
 * utils.h
 *
 *  Created on: Oct 6, 2024
 *      Author: karim
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_
void setup(void);
void loop(void);
void getMinPosition(int * array, int * toBeIgnored, int size,int * index,int * min);
int sortArray(int * toSort, int * sorted, int size);
void displayArray(int array[], int size);



#endif /* INC_UTILS_H_ */
