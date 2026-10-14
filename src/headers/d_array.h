#pragma once
#include "libs.h"

#define Alloc(count) ((int *)calloc(count,sizeof(int))) // Allocatpr macro
const int Align=4;

typedef struct D_array{ // D_Array definition
    int* buffer;
    size_t capacity;
    size_t count; 
}D_array;

static inline size_t SetCapacity(int Size){ // small helper for alignment
    return ((Size + (Align-1))/Align)*Align;
}

static inline D_array InitArray(const int Size){ // Dynamic Array initialization
    return (D_array){
        .buffer = Alloc(Size),
        .capacity = SetCapacity(Size),
        .count=0
    };
}



static void Push_Back(D_array* list,int element){ // add new elements

    if(list->count == list->capacity){
        size_t newCapacity = SetCapacity(list->count);
        int* newBuffer = realloc(list->buffer,newCapacity);
        
        if(!newBuffer){
            printf("Allocation Failed!\n");
            exit(EXIT_FAILURE);
        }

        list->buffer = newBuffer;
    }

    *(list->buffer+list->count) = element;
    list->count++;
}

static void Mod_At(D_array* list,int index,int elment){ // modify elements in the list
    if(index >= list->count || index < 0){
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    *(list->buffer+index) = elment;
}

static void Pop_Back(D_array* list){ // delete element at back
    if(list->count > 0){
        list->count--;
        *(list->buffer+list->count) = 0;
    }else{
        printf("Array is Empty!\n");
        exit(EXIT_FAILURE);
    }
}

static int Get(D_array* list,int index){
    if(index < 0 || index >= list->count){
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    return *(list->buffer+index);
}