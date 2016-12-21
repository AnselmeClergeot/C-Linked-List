
/*This is a complete implementation of a linked list in C. It offers many useful functions and it is similar to Java ArrayList.
Code : Anselme Clergeot. Feel free to modify the sources without giving me credits.*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*An Element contains its value and a pointer to the next Element of the list.
You don't need to use this struct if you want to use a List normally.*/
typedef struct Element Element;
struct Element
{
    int value; //The value of the element.
    Element *next; //Pointer to the next element of the list.
};

/*A List contains a pointer to the first element of the list and stores the total number of linked Element.
This is the struct you need to use. To use it declare a List pointer and assign it to listInitialize().
Then List is ready to be used.*/
typedef struct List List;
struct List
{
    Element *first; //Pointer to the first element of the list. Is NULL after listInitialize().
    int size; //The number of Element in the list.
};

/*In case of normal List using, don't use the following function. It is used in internal List managing.
This function returns a pointer to the Element at a specified index.*/
Element *_gat(List *list, int index);

/*These are the functions you can use to interact with your list.
Be careful to send a valid List pointer to the functions that needs one
For functions that needs an index :
Be careful to send a correct index. Each index must follow this pattern : 0 <= index < list->size. So do not call these functions if list is empty.*/

/*Allocates memory for a List, initialize it and returns a pointer to the allocated list.
Use this function to initialize your list.*/
List *listInitialize();
/*This function deallocate memory used by the list and elements.
Call this function ONLY when you don't need your list anymore.*/
void listDestroy(List *list);
/*This function deallocate memory used by the elements and removes all these elements.
Use this function to make your list empty.*/
void listMakeEmpty(List *list);
/*Use this function to add a value in end of the list*/
void listAddLast(List *list, int value);
/*Use this function to add a value in front of the list.*/
void listAddFirst(List *list, int value);
/*Use this function to add a value after the value at specified index.
This function returns 1 if the value was successfully added, 0 otherwise.*/
int listAddElementAfter(List *list, int index, int value);
/*Use this function to remove the  last value of the list.*/
void listRemoveLast(List *list);
/*Use this function to remove the first value of the list.*/
void listRemoveFirst(List *list);
/*Use this function to remove the value at a specified index.
This function returns 1 if the value has been deleted, 0 otherwise.*/
int listRemoveElementAt(List *list, int index);
/*Use this function to know how many value there is in the list.*/
int listGetSize(List *list);
/*Use this function to get the value at a specified index.
THIS IS AN UNSAFE FUNCTION, PLEASE CHECK IF INDEX IS IN BOUNDS OF THE LIST*/
int listGetValueAt(List *list, int index);
/*Use this function to debug the list. This function will print in console everything about your list : size, values...*/
void listDebug(List *list);
/*Use this function to know if the list contains a specific value. The method returns 1 if the value was found in the list, 0 otherwise.*/
int listContainsValue(List *list, int value);
/*Use this function to know how many times a specific value appears in the list.*/
int listNumberOfValue(List *list, int value);
/*Use this function to remove all occurrences of a specific value in the list*/
void listRemoveValue(List *list, int value);
/*Use this function to get the first index of the specific value in the list.
This function will return -1 if the value is not in the list.*/
int listFirstIndexOfValue(List *list, int value);
/*Use this function to get the last index of the specific value in the list.
This function will return -1 if the value is not in the list.*/
int listLastIndexOfValue(List *list, int value);

#endif // LINKEDLIST_H
