#pragma once
#include "libs.h"

#define Alloc(count) ((int *)calloc(count,sizeof(int))) // Allocatpr macro
const int Align=4;

typedef struct D_array{ // D_Array definition
    int* buffer;
    size_t capacity;
    size_t count; 
}D_array;

size_t SetCapacity(int Size){ // small helper for alignment
    return ((Size + (Align-1))/Align)*Align;
}

D_array InitArray(const int Size){ // Dynamic Array initialization
    return (D_array){
        .buffer = Alloc(Size),
        .capacity = SetCapacity(Size),
        .count=0
    };
}



void Push_Back(D_array* list,int element){

    if(list->count == list->capacity){
        size_t newCapacity = SetCapacity(list->count);
        int* newBuffer = realloc(list->buffer,newCapacity);
        
        if(!newBuffer){
            printf("Allocation Failed!");
            exit(EXIT_FAILURE);
        }

        list->buffer = newBuffer;
    }

    *(list->buffer+list->count) = element;
    list->count++;
}

void Pop_Back(D_array* list){
    if(list->count > 0){
        list->count--;
        *(list->buffer+list->count) = 0;
    }

    printf("Array is Empty!");
    exit(EXIT_FAILURE);
}

int Get(D_array* list,int index){
    if(index < 0 || index > list->count){
        printf("Index out of bounds");
        exit(EXIT_FAILURE);
    }

    return *(list->buffer+index);
}