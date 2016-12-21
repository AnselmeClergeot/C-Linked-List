
/*This is a complete implementation of a linked list in C. It offers many useful functions and it is similar to Java ArrayList.
Code : Anselme Clergeot. Feel free to modify the sources without giving me credits.

To know how to use this linked list, go to linkedlist.h to see all functions available.*/

#include "linkedlist.h"
#include <stdlib.h>

List *listInitialize()
{
    List *list = malloc(sizeof(*list));

    if(list != NULL)
    {
        list->size = 0;
        list->first = NULL;
    }

    return list;
}

Element *_gat(List *list, int index)
{
    if(list != NULL)
    {
        if(list->size > 0 && index >= 0 && index < list->size)
        {
            int curIndex = 0;
            Element *elem = list->first;

            for(; curIndex < index; curIndex++)
            {
                elem = elem->next;
            }

            return elem;
        }
    }

    return NULL;
}

void listDestroy(List *list)
{
    listMakeEmpty(list);
    free(list);
}

void listMakeEmpty(List *list)
{
    if(list != NULL)
    {
        int i = 0;

        for(; i < listGetSize(list); i++)
            listRemoveLast(list);

        list->first = NULL;
        list->size = 0;
    }
}

void listAddLast(List *list, int value)
{
    if(list != NULL)
    {
        listAddElementAfter(list, listGetSize(list)-1, value);
    }
}

void listAddFirst(List *list, int value)
{
    if(list != NULL)
    {
        listAddElementAfter(list, -1, value);
    }
}

int listAddElementAfter(List *list, int index, int value)
{
        if(list != NULL && index >=-1 && index < listGetSize(list)) //If the specified index corresponds to a valid position to add the new value
            {
            /*
            We suppose element will be added between two element already on the list, so we get a pointer to the element before the new one and after the new one.
            If one of them is NULL (add in front or end of list) then we manage the insertion of the new element differently.
            */
            Element *before = _gat(list, index);
            Element *next = _gat(list, index+1);



            Element *toAdd = malloc(sizeof(*toAdd));

            toAdd->value = value;
            toAdd->next = NULL;

            if(before != NULL) //If the specified index exists (if do not we add the new element in front of the list)
                before->next = toAdd; //Then set the pointer of the previous element to the element that will be added just after

            else //Else, if the previous element does not exist
            {
                list->first = toAdd; //Then toAdd becomes the first element of the list
            }

            if(next != NULL) //If we do not add the value in end of the list
                toAdd->next = next;

            list->size++;

            return 1;
        }
            return 0;
}

void listRemoveLast(List *list)
{
    if(list !=NULL)
    {
        listRemoveElementAt(list, list->size-1);
    }
}

void listRemoveFirst(List *list)
{
    if(list != NULL)
    {
        listRemoveElementAt(list, 0);
    }
}

int listRemoveElementAt(List *list, int index)
{
    if(list != NULL && listGetSize(list) > 0 && index >= 0 && index < listGetSize(list)) //If the specified index is valid then we can delete the element
    {
            Element *toDelete = _gat(list, index); //Pointer to the element to delete

            if(toDelete != NULL)
            {
                /*When the element at the index will be deleted we will need to keep link between the elements before and after the one deleted*/
                Element *before = _gat(list, index-1);
                Element *after = _gat(list, index+1);

                if(before != NULL) //If we do not remove the first element of the list
                {
                    before->next = after; //Then set the "next" pointer of the previous object directly to the one after
                }
                else //If we want to remove the first element of the list
                {
                    list->first = after; //The element after the one deleted becomes the first one
                }

                toDelete->next = NULL; //Precautions !
                free(toDelete); //Deallocating memory

                list->size--;
                return 1;
            }
    }
    return 0;
}

int listGetSize(List *list)
{
    if(list != NULL)
    {
        return list->size;
    }
    return -1;
}

int listGetValueAt(List *list, int index)
{
    if(list != NULL)
    {
        return _gat(list, index)->value;
    }
}

void listDebug(List *list)
{
    if(listGetSize(list) == 0)
    {
        printf("List is empty\n");
    }

    else
    {
        printf("List contains %d value(s)\n", listGetSize(list));
        printf("[");

        if(list != NULL)
        {
            int i = 0;

            for(; i < listGetSize(list); i++)
            {
                printf("%d", listGetValueAt(list, i));
                if(i+1 < listGetSize(list))
                    printf(", ");
            }
        }
    printf("]\n");
    }
}

int listContainsValue(List *list, int value)
{
    return (listNumberOfValue(list, value) > 0);
}

int listNumberOfValue(List *list, int value)
{
    int count = 0;

    if(list != NULL)
    {
        int i = 0;

        for(; i < listGetSize(list); i++)
        {
            if(listGetValueAt(list, i) == value)
                count++;
        }
    }

    return count;
}

void listRemoveValue(List *list, int value)
{
    if(list != NULL)
    {
        int i = 0;

        for(; i < listGetSize(list); i++)
        {
            if(listGetValueAt(list, i) == value)
                listRemoveElementAt(list, i);
        }
    }
}

int listFirstIndexOfValue(List *list, int value)
{
    if(list != NULL && listContainsValue(list, value))
    {
        int index = 0;
        while(index < listGetSize(list) && listGetValueAt(list, index) != value)
        {
            index++;
        }
        return index;
    }
        return -1;
}

int listLastIndexOfValue(List *list, int value)
{
    if(list != NULL && listContainsValue(list, value))
    {
        int index = listGetSize(list)-1;

            while(index >= 0 && listGetValueAt(list, index) != value)
            {
                index--;
            }

    return index;
    }
    return -1;
}
