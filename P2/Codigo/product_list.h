/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Daniel Rodriguez Sanchez LOGIN 1: daniel.rodriguez.sanchez1
 * AUTHOR 2: Lucia Docampo Rodriguez LOGIN 2: lucia.docampo
 * GROUP: 4.2
 * DATE: 04 / 04 / 22
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "types.h"

#include "types.h"
#include <stdbool.h>
#include <stdio.h>
#include "types.h"
#include "string.h"
#include "stdlib.h"

#include "bid_stack.h"

#define LNULL NULL

typedef struct tNode *tList;
typedef struct tNode *tPosL;
typedef struct tItemL *tNode;

typedef struct tItemL {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidStack;
} tItemL;

struct tNode {
    tItemL data;
    struct tNode *next;
};

void createEmptyList(tList *);
bool isEmptyList(tList);
tPosL first(tList);
tPosL last(tList);
tPosL next(tPosL, tList);
tPosL previous(tPosL, tList);
bool insertItem(tItemL, tList *);
void deleteAtPosition(tPosL, tList *);
tItemL getItem(tPosL, tList);
void updateItem(tItemL, tPosL, tList *);
tPosL findItem(tProductId , tList);

#endif