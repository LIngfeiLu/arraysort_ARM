/* First partner's name: Lingfei Lu, A91046735
 * Second partner's name: Junxi Li, A91105747
 */

//include libraries
#include <stdio.h>
#include <stdlib.h>
#include "arraysort.h"

/**
 *Test createlist function. test_create takes two parameters ls and maxelements
 */
 void test_create(list *ls, int maxElements)
 {
  //check if the list created is NULL
  if(ls == NULL)
    printf("Test fails. No list struct has been created.\n");
  //check if the size is zero
  if(ls->size != 0)
    printf("Test fails. The size is not initialized correctly\n");
  //check is maxSize equals maxElements
  if(ls->maxSize != maxElements)
    printf("Test fails. maxSize is not initialized correctly\n");
  //else createlist passes test
  else
    printf("createlist passes!\n");
}

/**
 *Test insert function. test_insert takes one parameter ls.
 */
 void test_insert(list *ls)
 {
  //check if insert will return -1 if pass in NULL
  if(insert(NULL, 6) != -1)
    printf("Test fails. Insert should return -1 if we pass in NULL\n");

  //insert 6 check if insert index, sortedlist, size and maxSize are correct.
  if(insert(ls, 6) != 0)
    printf("Test fails. 6 should be inserted at index 0\n");
  if(ls->sortedList[0] != 6)
    printf("Test fails. The first element in sortedList should be 6\n");
  if(ls->size != 1)
    printf("Test fails. Fail to increase the size of list after inserting\n");
  if(ls->maxSize != 1)
    printf("Test fails. The maxSize should not be expanded\n");

  //insert 2 and check if insert index, sortedlist, size, maxSize are correct.
  if(insert(ls, 2) != 0)
    printf("Test fails. 2 should be inserted at index 0\n");
  if(ls->sortedList[0] != 2 || ls->sortedList[1] != 6)
    printf("Test fails. Insert 2 in the sortedList fails\n");
  if(ls->size != 2)
    printf("Test fails. Size fails to increase after insertion 2\n");
  if(ls->maxSize != 2)
    printf("Test fails. maxSize fails to expand after insertion 2\n");

  //insert 2 and check if insert index, sortedlist, size, maxSize are correct.
  if(insert(ls, 8) != 2)
    printf("Test fails. 8 should be inserted at index 2\n");
  if(ls->sortedList[2] != 8)
    printf("Test fails. Insert 8 in the sortedList fails\n");
  if(ls->size != 3)
    printf("Test fails. Size fails to increase after insertion 8\n");
  if(ls->maxSize != 4)
    printf("Test fails. maxSize fails to expand after insertion 8\n");

  //insert 9 and check if insert index, sortedlist, size, maxSize are correct.
  if(insert(ls, 9) != 3)
    printf("Test fails. 9 should be inserted at index 3\n");
  if(ls->sortedList[3] != 9)
    printf("Test fails. Insert 9 in the sortedList fails\n");
  if(ls->size != 4)
    printf("Test fails. Size fails to increase after insertion 9\n");
  if(ls->maxSize != 4)
    printf("Test fails. maxSize fails to expand after insertion 9\n");

  //insert 7, 2 and 2
  insert(ls, 7);

  insert(ls, 2);

  //insert 2 and check if insert index, sortedlist, size, maxSize are correct.
  insert(ls, 2);
  if(ls->sortedList[0] != 2 || ls->sortedList[1] != 2 || ls->sortedList[2] != 2)
    printf("Test fails. Insert 2 in the sortedList fails\n");
  if(ls->size != 7)
    printf("Test fails. Size fails to increase after insertion 2\n");
  if(ls->maxSize != 8)
    printf("Test fails. maxSize fails to expand after insertion 2\n");
  //else insert passes
  else
    printf("insert passes!\n");
}

/**
 * Test get_max_value function, test_get_max_value takes 2 parameter, ls1 and 
 *ls2.
 */
void test_get_max_value(list* ls1, list* ls2)
 {
  //check if get max value get the value at the end of the list
  if(get_max_value(ls1) != 9)
    printf("Test fails. The max value should bw 9\n");
  //check if list will return -1 if pass in NULL
  if(get_max_value(ls2) != -1)
    printf("Test fails. Should return -1 if the list is empty\n");
  //else get max value passes the test
  else
    printf("get_max_value passes!\n");
 }

/**
 *Test get min value. test_get_min_value takes 2 parameter ls1 and ls2
 */
void test_get_min_value(list* ls1, list* ls2)
{
  //check if get min value get the first element in list
  if(get_min_value(ls1) != 2)
    printf("Test fails. get_min_value should return 2\n");
  //check if get min value will return -1 if pass in NULL
  if(get_min_value(ls2) != -1)
    printf("Test fails. get_min_value should return -1 if the list is empty\n");
  //else get min value passes the test
  else
    printf("get_min_value passes!\n");
}

/**
 *Test search function. test_search takes ls as parameter
 */
void test_search(list* ls)
{
  //search int 2 in the list
  if(search(ls, 2) != 0){
    printf("Test fails, search should return index 0\n");
  }
  //search int 7 in the list
  if(search(ls, 7) != 4 ){
    printf("Test fails, search should return index 5\n");
  }
  //search in 9 in the list
  if(search(ls, 9) != 6){
    printf("Test fails, search should return index 7\n");
  }
  //else search passes the test
  else
    printf("search passes!\n");
}

/**
 *Test remove_val function. test_remove_val takes ls as parameter
 */
void test_remove_val(list *ls)
{
  //first insert 2 twice
  insert(ls, 2);
  insert(ls, 2);

  //remove 2, should return 5 and then check if sortedlist and size are correct
  if(remove_val(ls, 2) != 5)
    printf("Test fails. Return value of remove fails. Should return 5\n");
  if(ls->sortedList[0] != 6)
    printf("Test fails. remove 2 from sortedList fails\n");
  if(ls->size != 4)
    printf("Test fails. Size fails to decrease after remove 2\n");

  //remove 7, should return 1 and then check if sortedlist and size are correct.
  if(remove_val(ls, 7) != 1)
    printf("Test fails. Return value of remove 7 should be 1\n");
  if(ls->sortedList[0] != 6 || ls->sortedList[1] != 8)
    printf("Test fails. Elements fail to shift after remove 7\n");
  if(ls->size != 3)
    printf("Test fails. Size fails to decrease after remove 7\n");

  //remove 6, should return 1 and then check is sortedlist and size are correct.
  if(remove_val(ls, 6) != 1)
    printf("Test fails. Return value should be 1 after remove 6\n");
  if(ls->sortedList[0] != 8)
    printf("Test fails. The first element should be 8 after remove\n");

  //remove 10, should return 0
  if(remove_val(ls, 10) != 0)
    printf("Test fails. 10 is not in the list, should return 0\n");
  else
    printf("remove passes!\n");
}

/**
 *test_pop_min takes one parameter ls
 */
void test_pop_min(list* ls)
{
  //pop min should return 8
  if(pop_min(ls) != 8)
    printf("Test fails. pop min should return 8\n");
  //pop in should return 9
  if(pop_min(ls) != 9)
    printf("Test fails. pop min should return 9\n");
  else
    printf("pop_min passes!\n");
}

void test_get_min_ARM(list* ls1, list* ls2)
{
  //check if get min value get the first element in list
  if(get_min_ARM(ls1) != 2)
    printf("Test fails. get_min_value should return 2\n");
  //check if get min value will return -1 if pass in NULL
  if(get_min_ARM(ls2) != -1)
    printf("Test fails. get_min_value should return -1 if the list is empty\n");
  //else get min value passes the test
  else
    printf("get_min_ARM passes!\n");
}

/**
 * Test get_max_value function, test_get_max_value takes 2 parameter, ls1 and 
 *ls2.
 */
void test_get_max_ARM(list* ls1, list* ls2)
 {
  //check if get max value get the value at the end of the list
  if(get_max_ARM(ls1) != 9)
    printf("Test fails. The max value should bw 9\n");
  //check if list will return -1 if pass in NULL
  if(get_max_ARM(ls2) != -1)
    printf("Test fails. Should return -1 if the list is empty\n");
  //else get max value passes the test
  else
    printf("get_max_ARM passes!\n");
 }
 
 /**
 *Test createlist function. test_create takes two parameters ls and maxelements
 */
 void test_createlist_ARM(list *ls, int maxElements)
 {
  //check if the list created is NULL
  if(ls == NULL)
    printf("Test fails. No list struct has been created.\n");
  //check if the size is zero
  if(ls->size != 0)
    printf("Test fails. The size is not initialized correctly\n");
  //check is maxSize equals maxElements
  if(ls->maxSize != maxElements)
    printf("Test fails. maxSize is not initialized correctly\n");
  //else createlist passes test
  else
    printf("createlist_ARM passes!\n");
}

/**
 *Test insert function. test_insert takes one parameter ls.
 */
 void test_insert_ARM(list *ls)
 {
  //check if insert will return -1 if pass in NULL
  if(insert_ARM(NULL, 6) != -1)
    printf("Test fails. Insert should return -1 if we pass in NULL\n");

  //insert 6 check if insert index, sortedlist, size and maxSize are correct.
  if(insert_ARM(ls, 6) != 0)
    printf("Test fails. 6 should be inserted at index 0\n");
  if(ls->sortedList[0] != 6)
    printf("Test fails. The first element in sortedList should be 6\n");
  if(ls->size != 1)
    printf("Test fails. Fail to increase the size of list after inserting\n");
  if(ls->maxSize != 1)
    printf("Test fails. The maxSize should not be expanded\n");

  //insert 2 and check if insert index, sortedlist, size, maxSize are correct.
  if(insert_ARM(ls, 2) != 0)
    printf("Test fails. 2 should be inserted at index 0\n");
  if(ls->sortedList[0] != 2 || ls->sortedList[1] != 6)
    printf("Test fails. Insert 2 in the sortedList fails\n");
  if(ls->size != 2)
    printf("Test fails. Size fails to increase after insertion 2\n");
  if(ls->maxSize != 2)
    printf("Test fails. maxSize fails to expand after insertion 2\n");

  //insert 2 and check if insert index, sortedlist, size, maxSize are correct.
  if(insert_ARM(ls, 8) != 2)
    printf("Test fails. 8 should be inserted at index 2\n");
  if(ls->sortedList[2] != 8)
    printf("Test fails. Insert 8 in the sortedList fails\n");
  if(ls->size != 3)
    printf("Test fails. Size fails to increase after insertion 8\n");
  if(ls->maxSize != 4)
    printf("Test fails. maxSize fails to expand after insertion 8\n");

  //insert 9 and check if insert index, sortedlist, size, maxSize are correct.
  if(insert_ARM(ls, 9) != 3)
    printf("Test fails. 9 should be inserted at index 3\n");
   if(ls->sortedList[3] != 9)
    printf("Test fails. Insert 9 in the sortedList fails\n");
  if(ls->size != 4)
    printf("Test fails. Size fails to increase after insertion 9\n");
  if(ls->maxSize != 4)
    printf("Test fails. maxSize fails to expand after insertion 9\n");
  //insert 7, 2 and 2
  insert_ARM(ls, 7);

  insert_ARM(ls, 2);

  //insert 2 and check if insert index, sortedlist, size, maxSize are correct.
  insert_ARM(ls, 2);
  if(ls->sortedList[0] != 2 || ls->sortedList[1] != 2 || ls->sortedList[2] != 2)
    printf("Test fails. Insert 2 in the sortedList fails\n");
  if(ls->size != 7)
    printf("Test fails. Size fails to increase after insertion 2\n");
  if(ls->maxSize != 8)
    printf("Test fails. maxSize fails to expand after insertion 2\n");
  //else insert passes
  else
    printf("insert_ARM passes!\n");
}

void test_pop_min_ARM(list* ls)
{
  //pop min should return 8
  if(pop_min_ARM(ls) != 8)
    printf("Test fails. pop min should return 8\n");
  //pop in should return 9
  if(pop_min_ARM(ls) != 9)
    printf("Test fails. pop min should return 9\n");
  else
    printf("test_pop_min_ARM passes!\n");
}

void test_search_ARM(list* ls)
{
  //search int 2 in the list
  if(search_ARM(ls, 2) != 0){
    printf("Test fails, search should return index 0\n");
  }
  //search int 7 in the list
  if(search_ARM(ls, 7) != 4 ){
    printf("Test fails, search should return index 5\n");
  }
  //search in 9 in the list
  if(search_ARM(ls, 9) != 6){
    printf("Test fails, search should return index 7\n");
  }
  //else search passes the test
  else
    printf("search_ARM passes!\n");
}

void test_remove_val_ARM(list *ls)
{
  //first insert 2 twice
  insert_ARM(ls, 2);
  insert_ARM(ls, 2);

  //remove 2, should return 5 and then check if sortedlist and size are correct
  if(remove_val_ARM(ls, 2) != 5)
    printf("Test fails. Return value of remove fails. Should return 5\n");
  if(ls->sortedList[0] != 6)
    printf("Test fails. remove 2 from sortedList fails\n");
  if(ls->size != 4)
    printf("Test fails. Size fails to decrease after remove 2\n");
  //remove 7, should return 1 and then check if sortedlist and size are correct.
  if(remove_val_ARM(ls, 7) != 1)
    printf("Test fails. Return value of remove 7 should be 1\n");
  if(ls->sortedList[0] != 6 || ls->sortedList[1] != 8)
    printf("Test fails. Elements fail to shift after remove 7\n");
  if(ls->size != 3)
    printf("Test fails. Size fails to decrease after remove 7\n");
  //remove 6, should return 1 and then check is sortedlist and size are correct.
  if(remove_val_ARM(ls, 6) != 1)
    printf("Test fails. Return value should be 1 after remove 6\n");
  if(ls->sortedList[0] != 8)
    printf("Test fails. The first element should be 8 after remove\n");
  //remove 10, should return 0
  if(remove_val_ARM(ls, 10) != 0)
    printf("Test fails. 10 is not in the list, should return 0\n");
  else
    printf("remove_val_ARM passes!\n");
}

/*
 * main function return int
 */
int main(void)
{
  //create two list first
  list* ls1 = (list*)createlist(1);
  list* ls2 = (list*)createlist(1);
  //test each function
  test_create(ls1, 1);
  test_insert(ls1);
  test_get_max_value(ls1, ls2);
  test_get_min_value(ls1, ls2);
  test_search(ls1);
  test_remove_val(ls1);
  test_pop_min(ls1);
  //free malloc
  free(ls1->sortedList);
  free(ls1);
  free(ls2->sortedList);
  free(ls2);
  
  
  //create two list first
  list* ls3 = (list*)createlist_ARM(1);
  list* ls4 = (list*)createlist_ARM(1);
  //test each function
  test_createlist_ARM(ls3, 1);
  test_insert_ARM(ls3);
  print_ARM(ls3);
  test_get_min_ARM(ls3, ls4);
  test_get_max_ARM(ls3, ls4);
  test_search_ARM(ls3);
  test_remove_val_ARM(ls3);
  print_ARM(ls3);
  test_pop_min_ARM(ls3);
  //free malloc
  free(ls3->sortedList);
  free(ls3);
  free(ls4->sortedList);
  free(ls4);


  return 0;
}



