/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniel Rodriguez Sanchez LOGIN 1: daniel.rodriguez.sanchez1
 * AUTHOR 2: Lucia Docampo Rodriguez LOGIN 2: lucia.docampo
 * GROUP: 4.2
 * DATE: 23 / 02 / 22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void New(tList *list, tProductId product, tUserId user, tProductCategory category, tProductPrice price){

    /* Objetivo: alta de un nuevo producto
     * Entradas: lista, id del producto, id del usuario, categoria y precio del producto
     * Salidas: lista
     * Precondiciones: existe el producto (la posición en la lista no es nula)
     * Postcondiciones: cambia la lista (tiene un elemento mas por lo que se modifican las posiciones)
     * */

    tPosL pos;
    if((pos = findItem(product, *list)) != LNULL){ //si la posición no es nula devuelve error
        printf("+ Error: New not possible\n");
        return;
    }
    tItemL item;
    char* categoria = malloc(sizeof(char)); //reserva de memoria para la categoría

    //Metemos cada atributo en el item
    item.productPrice = price;
    item.productCategory = category;
    strcpy(item.productId, product);
    strcpy(item.seller, user);
    item.bidCounter = 0;

    if(insertItem(item, LNULL, list)){ //Inserta un nuevo producto en la lista
        if(item.productCategory == 0){
            strcpy(categoria, "book");
        }else{
            strcpy(categoria, "painting");
        }
        printf("* New: product %s seller %s category %s price %.2f\n",
               item.productId, item.seller, categoria, item.productPrice);
    } else { //Error si el elemento no se inserta en la lista
        printf("+ Error: New not possible\n");
    }
}


void Delete(tList *list, tProductId product){
    /* Objetivo: baja de un producto
     * Entradas: lista y id del producto
     * Salidas: lista
     * Precondiciones: existe el producto (la posición en la lista no es nula)
     * Postcondiciones: cambia la lista (tiene un elemento menos por lo que se modifican las posiciones)
     * */
    tPosL pos;
    tItemL item;
    if((pos = findItem(product, *list)) == LNULL){ //si la posicion es nula devuelve error
        printf("+ Error: Delete not possible\n");
        return;
    }
    item = getItem(pos, *list); //metemos el item en una variable
    char* categoria = malloc(sizeof(char)); //reserva de memoria para la categoría

    if(item.productCategory == 0){
        strcpy(categoria, "book");
    }else{
        strcpy(categoria, "painting");
    }
    deleteAtPosition(pos, list); //borra el elemento de la lista
    printf("* Delete: product %s seller %s category %s price %.2f bids %d\n",
           item.productId, item.seller, categoria, item.productPrice, item.bidCounter);
}


void Bid(tList *list, tProductId product, tUserId user, tProductPrice price){
    /* Objetivo: puja por determinado producto
     * Entradas: lista, id del producto, id del usuario y el precio del producto
     * Salidas: lista
     * Precondiciones: existe el producto en la lista
     * Postcondiciones: las pujas de un usuario cambian en la lista
     * */
    tPosL pos;
    if((pos = findItem(product, *list)) != LNULL){ //Comprueba si la posicion es nula o no
        tItemL item;
        char* categoria = malloc(sizeof(char)); //reserva de memoria para la categoría
        item = getItem(pos, *list); //metemos el item en una variable
        if(strcmp(user, item.seller) != 0){ //comprobamos que el que puja no es vendedor
            if(item.productPrice < price){ //Comprueba que el precio de la puja es mayor que el precio anterior

                if(item.productCategory == 0){
                    strcpy(categoria, "book");
                }else{
                    strcpy(categoria, "painting");
                }

                item.productPrice = price;
                item.bidCounter++;  //incrementa la cuenta de pujas del usuario
                updateItem(item, pos, list); //actualiza el contenido de esa posicion

                printf("* Bid: product %s seller %s category %s price %.2f bids %d\n",
                       item.productId, item.seller, categoria, item.productPrice, item.bidCounter);
                return;
            }
        }
    }
    printf("+ Error: Bid not possible\n");
}


void Stats(tList *list){
    /* Objetivo: listado de los productos actuales y sus datos
     * Entradas: lista
     * Salidas: no hay
     * Precondiciones: la lista no está vacía
     * Postcondiciones: no hay
     * */
    tPosL pos;
    tItemL item;

    //declaramos y inicializamos atributos
    int numProductsBook = 0;
    int numProductsPainting = 0;
    float suma_book = 0.0;
    float suma_painting = 0.0;
    float average_book = 0.0;
    float average_painting = 0.0;
    char* categoria = malloc(sizeof(char)); //reserva de memoria para la categoría

    if (!isEmptyList(*list)) { //comprueba que la lista no está vacía
        pos = first(*list); //se coloca en la primera posicion de la lista
        while (pos != LNULL) { //mientas la posición no sea nula:
            item = getItem(pos, *list); //metemos el item en una variable
            if (item.productCategory == 0) {
                strcpy(categoria, "book");
            } else {
                strcpy(categoria, "painting");
            }
            if(item.bidCounter == 0){
                printf("Product %s seller %s category %s price %.2f bids %d\n",
                       item.productId, item.seller, categoria, item.productPrice, item.bidCounter);
            }
            printf("Product %s seller %s category %s price %.2f bids %d\n",
                   item.productId, item.seller, categoria, item.productPrice, item.bidCounter);
            if (strcmp(categoria, "book") == 0) {
                numProductsBook++; //incrementa el contador de los productos que son libros
                suma_book += item.productPrice;
                average_book = (float) (suma_book / numProductsBook); //calcula la media de libros
            } else {
                numProductsPainting++; //incrementa e contador de los productos que son cuadros
                suma_painting += item.productPrice;
                average_painting = (float) (suma_painting / numProductsPainting); //calcula la media de cuadros
            }
            pos = next(pos, *list); //se coloca en el siguiente elemento
        }
        printf("\nCategory  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n", numProductsBook, suma_book, average_book);
        printf("Painting  %8d %8.2f %8.2f\n", numProductsPainting, suma_painting, average_painting);

    } else { //devuelve error si la lista está vacía
        printf("+ Error: Stats not possible\n");
    }

}

//Funcion que convierte un char a la categoria
tProductCategory char_to_category(char* string){
    tProductCategory category;
    if(strcmp(string, "book") == 0){
        category = book;
        return category;
    }
    if(strcmp(string, "painting") == 0){
        category = painting;
        return category;
    }
    printf("Categoria inexistente");
    return 0;
}

void processCommand(tList *list, char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            New(list, param1, param2, char_to_category(param3), (tProductPrice)strtod(param4, NULL));
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c\n", commandNumber, command);
            Stats(list);
            break;
        case 'B':
            printf("********************\n");
            printf("%s %c: product %s bidder %s price %s\n", commandNumber, command, param1, param2, param3);
            Bid(list, param1, param2, (tProductPrice)strtod(param3, NULL));
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: product %s\n", commandNumber, command, param1);
            Delete(list, param1);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    tList list;
    createEmptyList(&list);

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(&list, commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}







