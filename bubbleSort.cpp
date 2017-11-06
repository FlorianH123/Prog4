//
// Created by Florian on 06.11.2017.
//

void bubble(float *array, int elemente) {
    int i;
    float temp;

    while(elemente--)
        for(i = 1; i <= elemente; i++)
            if(array[i-1] > array[i]) {
                temp=array[i];
                array[i]=array[i-1];
                array[i-1]=temp;
            }
}

