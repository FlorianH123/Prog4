//
// Created by Florian on 21.11.2017.
//

#ifndef UEBUNG1_BUBBLESORT_H
#define UEBUNG1_BUBBLESORT_H

#include "studentStruct.h"
void bubbleSortAlgorithm(student *array, int elemente) {
    int i;
    student temp{};

    while(elemente--)
        for(i = 1; i <= elemente; i++)
            if(array[i-1].notenSchnitt > array[i].notenSchnitt) {
                temp=array[i];
                array[i]=array[i-1];
                array[i-1]=temp;
                
            }
}

#endif //UEBUNG1_BUBBLESORT_H
