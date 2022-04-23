/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Daniel Rodriguez Sanchez LOGIN 1: daniel.rodriguez.sanchez1
 * AUTHOR 2: Lucia Docampo Rodriguez LOGIN 2: lucia.docampo
 * GROUP: 4.2
 * DATE: 04 / 04 / 22
 */

#include "bid_stack.h"

void createEmptyStack(tStack *S){
    /*Objetivo: Crea una pila vacía
     *Postcondiciones: la pila no tiene elementos
     */
    S->top = SNULL;
}
//*******************************************
bool push(tItemS i, tStack *S){
    /*Objetivo: inserta un elemento en la cima de la pila
     *Precondiciones:Devuelve true si el elemento fue apilado y la pila está previamente inicializada
     */
    if(S->top == SMAX-1)
        return false;
    else{
        S->top++;
        S->data[S->top]=i;
        return true;
    }
}
//*******************************************
void pop(tStack *S){
    /*Objetivo: Elimina de la pila el elemento situado en la cima
     *Precondiciones: la pila no está vacía y está previamente inicializada
     */
    S->top--;
}
//*******************************************
tItemS peek(tStack S){
    /*Objetivo: recupera el elemento de la cima de la pila sin eliminarlo
     *Precondiciones: la pila no está vacía y está previamente inicializada
     */
    return S.data[S.top];
}
//*******************************************
bool isEmptyStack(tStack S){
    /*Objetivo: Determina si una pila está vacía o no
     *Precondiciones: la pila está previamente inicializada
     */
    return (S.top == SNULL);
}
