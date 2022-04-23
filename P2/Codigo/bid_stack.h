/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Daniel Rodriguez Sanchez LOGIN 1: daniel.rodriguez.sanchez1
 * AUTHOR 2: Lucia Docampo Rodriguez LOGIN 2: lucia.docampo
 * GROUP: 4.2
 * DATE: 04 / 04 / 22
 */
#include "stdbool.h"
#ifndef BID_STACK_H
#define BID_STACK_H
#define SNULL -1
#define SMAX 25

#include "types.h"

typedef int tPosS;

typedef struct tItemS{
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;

typedef struct tStack{
    tItemS data[SMAX];
    tPosS top;
}tStack;


void createEmptyStack(tStack *S);
bool push(tItemS i, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);

#endif