/* First partner's name: Lingfei Lu, A91046735
 * Second partner's name: Junxi Li, A91105747
 */

#include <stdio.h>
#include <stdlib.h>

#include "arraysort.h"

#define TEN 10
#define TWO 2
/**
 * This function creates an empty list, with space allocated for an array of
 * maxElements ints (pointed to by int *sortedList) and returns a pointer to the
 * list.
 */
 list* createlist(int maxElements)
 {
  //Size of the list must be greater than 0
 	if(maxElements < 1)
 	{
 		//printf("Execption! Capacity of integer array has to be greater than 0\n");
    //if user set maxSize less than 1, set it to 10.
 		maxElements = TEN;
 	}
  //malloc space for struct list
 	list *ls= (list*)malloc(sizeof(list));
  //malloc space for sortedList, int pointer
  //with the size, maxElements * sizeof the integer
 	ls->sortedList = (int*)malloc(maxElements * sizeof(int));
  //default size = 0
 	ls->size = 0;
  //set maxSize = maxElements
 	ls->maxSize = maxElements;
 	return ls;
 }

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should insert the value 'val' into sortedList, update the number of elements
 * in the list and return the index where the element was inserted. If the list
 * is full before inserting the element, it should increase the size of the list
 * to double its previous size and then insert the element. If the result of the
 * insert was not successful it should return -1. Note that the resulting list
 * should be sorted and there should be no information loss. The function should
 * return -1 if no valid list was passed to it..
 */
 int insert(list *ls, int val)
 {
 	int i, index=0;
  //if the passed in list is null, return -1 immediately
 	if(ls == NULL)
 		return -1;
 	
 	else if(ls->size == ls->maxSize)
 	{
    //if the size of list reach the maxSize
    //then double the size of the list, copying all the elements inside
    //over using realloc
 		int *temp = (int*)realloc(ls->sortedList, TWO * sizeof(int)*ls->maxSize);
    //if temp == 0, which means realloc fails, then return -1
 		if(temp == NULL)
 			return -1;
    //otherwise, assign sortedList with temp.
 		ls->sortedList = temp;
    //double the maxSize
 		ls->maxSize *= TWO;
 	}
  //if the value to be inserted is greater than the greatest number
  //in the list, put the val in the last position in the list
 	if(val >= ls->sortedList[ls->size-1])
 		ls->sortedList[ls->size] = val;

  //assign sortedList to a int pointer arr
 	int* arr = ls->sortedList;
  
  //since if size == 0, we cant access the zeroth position as right value
  //in the list, we check the condition.
 	if(ls->size != 0)
 	{
 		while(val > arr[index])
 		{
      //as the val is still greater than arr[index]
      //index should increase
 			index++;
 		}
 		for(i = ls->size; i > index; i--)
 		{
      //swapping each element from [index, size - 1] backward,
      //swap starting from the end of the list
 			arr[i] = arr[i-1];
 		}
 	}
  //replace the arr[index] with val, which should be right position for val
 	arr[index] = val;
  //after that, incremenet size by 1.
 	ls->size++;

 	return index;
 }

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should delete all instances of elements in the sortedList with value 'val',
 * update the number of elements remaining in the list and return the number of
 * elements that were deleted. Once again the resulting list should be sorted.
 */
 int remove_val(list *ls, int val)
 {
 	int k, m, i = 0;
 	int* arr = ls->sortedList;
 	if(ls == NULL)
    //if the list is null, return -1 beacause cant remove anything
 		return -1;

 	 if(ls->size == 0)
    //if the list size is 0, then number of removing a number is zero
 		return 0;

 	 if(val > ls->sortedList[ls->size-1])
    //if val is already greater than the greatest element, then nothing matches
 		return 0;

 	 if(ls->size == 1)
 	{
 		if(ls->sortedList[0] == val)
 		{
      //if the size == 1 and the only element happen to equal to val
      //set that element to 0 and return 1
 		  ls->sortedList[0] = 0;
 		  ls->size--;
 			return 1;
 		}
    //otherwise, no matches, return 0
 		return 0;
 	}

 	while(arr[i] != val)
 	{
    //while arr[i] is not equal to val, keep incrementing
 		i++;
    //checking if i == size in case of seg fault
    //if i reach to the end, then return 0 since no matches
 		if(i == ls->size)
 			return 0;
	}
  //i is where the val value is at
 	int j = i;
 	while(arr[j] == val)
 	{
    //go through the range of the val since couble be multiple vals in the list
 		j++;
	}
 	for(k = i; k <ls->size-(j-i) &&  (k+j-i)<ls->size; k++)
 	{
    //replacing the element w the corresponding val afterwards
    //while keep the index in bound.
 		arr[k] = arr[k+j-i];
 	}
 	
 	for(m = 1; m <= j-i; m++)
 	{
    //set the reduntdant element in the list after to zero
    //since they are moved to previous index in the list
 		arr[ls->size - m] = 0;
 	}
  
  //decrement teh size by the numbers of element to be removed
 	ls->size = ls->size-(j-i);

 	return j-i;
 }

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
 int get_max_value(list *ls)
 {
  //if the list pointer is null or the list size is 0,
  //no way we can get the max, return -1.
 	if(ls == NULL || ls->size == 0)
 		return -1;
  //otherwise ,return the last element of the list
 	return ls->sortedList[ls->size-1];

 }

/**
 * This function takes a pointer to the list and returns the minimum value in
 * the list OR -1 if the list is empty.
 */
 int get_min_value(list *ls){
  //if the list pointer is null or the list size is 0.
  //no way we can get the min, return -1
 	if(ls == NULL || ls->size == 0)
 		return -1;
  //otherwise, return the first element of the list
 	return ls->sortedList[0];
 }

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
 int search(list *ls, int val){
 	int i;
  //if the list pointer is null, we cant search the list at all
 	if(ls == NULL)
 		return -1;
 	for(i = 0; i < ls->size; i++)
 	{
    //loop thru the code, if find any match, immediately return that index
 		if(ls->sortedList[i] == val)
 			return i;
 	}
  //no matches found, return -1
 	return -1;
 }

/**
 * This function returns the minimum value from the list and removes it from the
 * list. It returns -1 if the list is empty.
 */
 int pop_min(list *ls){
 	int *arr = ls->sortedList;
  //pop is the val to be returned, which is the minimum value
 	int pop = ls->sortedList[0];
 	int i;
  //if the list pointer is null, or list size is zero
  //no way we can pop the min out, return -1
 	if(ls == NULL || ls->size == 0)
 		return -1;

 	for(i = 0; i < ls->size-1; i++)
 	{
    //swapping each value forward.
 		arr[i] = arr[i+1];
 	}
  //the last element of the list should be set to zero sicne
  //it is swapped to the previous position.
 	arr[ls->size-1] = 0;
  //decrement the size by 1
 	ls->size--;
 	return pop;
 }

/**
 * This function print the contents of the sorted list on a single line as follows:
 * 1 4 6 7 8
 */
 void print(list *ls){
 	int i;
 	for(i = 0; i < ls->size; i++)
 	{
    //loop thru the list and print every element out
 		printf("%d ", ls->sortedList[i]);
 	}
 	printf("\n");
 }

/**
 * Identical to get_min_value(), but implemented in ARM assembly
 * (use given file get_min_ARM.s)
 */
 int get_min_ARM(list *ls);

/**
 * Identical to get_max_value(), but implemented in ARM assembly
 * (use given file get_max_ARM.s)
 */
 int get_max_ARM(list *ls);
 
 
 int createlist_ARM(int maxElement);
 
 int search_ARM(list *ls, int val);

 int insert_ARM(list *ls, int val);
 
 int remove_val_ARM(list *ls, int val);
 
 int pop_min_ARM(list *ls);
 
 void print_ARM(list *ls);