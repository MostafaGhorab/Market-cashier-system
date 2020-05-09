#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;
FILE *fp;
char  file_name[10]; ///modification as the file name may be scanned from user


typedef struct structure
{
 char *PtrCat; ///POINTER TO STRING THE CATEGORY NAME SAVED AS STRING USING malloc
 char *Elements [6]; ///ARRAY OF POINTERS TO CHARACTER SAVE ELEMENTS' WITHIN EACH CATEGORY SYTING
 char NoOfElements; ///as the number of elements is not constant in each category so this will be the index to move between prices and element strings
 char *price;
 char *counter;
 char flagOrder;  ///INDICATION IF THIS CATEGORY CONTAINS AN ELEMENT INSIDE ORDER FILE

 struct node *next;
}node ;




void  FileReading(void); ///reads the data base
void OrderReading (void); ///reads the order, not case sensitive
node* addNode (void); ///adds new category
void display(void); ///only for debugging
void  Search (void); ///search if order is available or not and print the receipt

#endif // HEADER_H_INCLUDED
