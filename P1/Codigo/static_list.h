/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniel Rodriguez Sanchez LOGIN 1: daniel.rodriguez.sanchez1
 * AUTHOR 2: Lucia Docampo Rodriguez LOGIN 2: lucia.docampo
 * GROUP: 4.2
 * DATE: 23 / 02 / 22
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "stdio.h"
#include <stdbool.h>
#include "types.h"

#define LNULL -1

#define MAX 25


typedef int tPosL;
typedef struct  {
    tItemL data[25];
    tPosL LastPos;
} tList;

void createEmptyList (tList*);
bool insertItem(tItemL, tPosL, tList*);
bool copyList(tList, tList*);
void updateItem(tItemL, tPosL, tList*);
void deleteAtPosition(tPosL, tList*);
//void deleteList(tList*);
tPosL findItem(tProductId , tList);
bool isEmptyList(tList);
tItemL getItem(tPosL, tList);
tPosL first(tList);
tPosL last(tList);
tPosL previous(tPosL, tList);
tPosL next(tPosL, tList);

#endif
