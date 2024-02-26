#pragma once

#include <stdlib.h>

/********************************************************************************
 *
 * A StrList library.
 *
 * This library provides a StrList of STRINGS data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 *
 ********************************************************************************/

/*
 * StrList represents a StrList data structure.
 */
struct _StrList;
typedef struct _StrList StrList;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc();

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList*);

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList*);

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList*, const char*);

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList*, const char*, int);

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList*);

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList*);

/*
 * Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList*, int);

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList*);

/*
 * Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList*, const char*);

/*
 * Given a string and a list, remove all the appearances of this string in the list.
*/
void StrList_remove(StrList*, const char*);

/*
 * Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList*, int);

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList*, const StrList*);

/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList*);

/*
 * Reverses the given StrList.
 */
void StrList_reverse(StrList*);

/*
 * Sort the given list in lexicographical order
 */
void StrList_sort(StrList*);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList*);

