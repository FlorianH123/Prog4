#include <cstdlib>
#include <cstdio>
#include "studentStruct.h"


const int ARRAY_SIZE = 5;

struct student splitData(const char[]);

void bubbleSort(student *array, int elemente) {
    int i;
    student temp;

    while(elemente--)
        for(i = 1; i <= elemente; i++)
            if(array[i-1].notenSchnitt > array[i].notenSchnitt) {
                temp=array[i];
                array[i]=array[i-1];
                array[i-1]=temp;
            }
}

void readStudentFile() {
    int c;
    struct student studentArray[ARRAY_SIZE];
    int i = 0;
    int numberOfElementsInArray = 0;
    char buffer[250];
    int bufferIndex = 0;
    FILE* studentFile = fopen("students.csv", "r");

    if (studentFile == nullptr) {
        perror("Datei konnte nicht geoeffnet werden!\n");
    } else {
        while (c != EOF) {
            c = fgetc(studentFile);

            buffer[bufferIndex] = c;
            bufferIndex++;

            if (c == '\n') {
                buffer[bufferIndex] = '\0';

                studentArray[i] = splitData(buffer);
                printf("%s", buffer);
                i++;
                numberOfElementsInArray++;
                bufferIndex = 0;
            }
        }
    }

    bubbleSort(studentArray, numberOfElementsInArray);
    printf("\n\nNach dem Sortieren\n");
    for (student student : studentArray) {
        printf("Vorname %s\n", studentArray->vorname);
        printf("Name %s\n", studentArray->name);
        printf("Matrikelnummer %d\n", studentArray->matrikelnummer);
        printf("Datum %s\n", studentArray->date);
        printf("Notendurchschnitt %f\n", studentArray->notenSchnitt);
    }

}

void copyString(char *string, const char stringToCopy[], int size) {
    for (int i = 0; i < size; i++) {
        string[i] = stringToCopy[i];
    }
}

void readCharArrayToInt(int *number, const char *string, int sizeToRead, int *bufferPointer) {
    int i = 0;
    char buffer[sizeToRead + 1];
    while (i < sizeToRead && string[*bufferPointer] != '\0' && string[*bufferPointer] != ';') {
        buffer[i] = string[*bufferPointer];
        (*bufferPointer)++;
        i++;
    }
    (*bufferPointer)++;
    buffer[i] = '\0';
    *number = atoi(buffer);
}

void readCharArrayToFloat(float *number, const char *string, int sizeToRead, int *bufferPointer) {
    int i = 0;
    char buffer[sizeToRead + 1];
    while (i < sizeToRead && string[*bufferPointer] != '\0' && string[*bufferPointer] != ';') {
        buffer[i] = string[*bufferPointer];
        (*bufferPointer)++;
        i++;
    }
    (*bufferPointer)++;
    buffer[i] = '\0';
    *number = atof(buffer);
}

void readCharArrayToCharArray(char *string, const char *stringArray, int sizeToRead, int *bufferPointer) {
    int i = 0;
    char buffer[sizeToRead + 1];
    while (i < sizeToRead && stringArray[*bufferPointer] != '\0' && stringArray[*bufferPointer] != ';') {
        buffer[i] = stringArray[*bufferPointer];
        (*bufferPointer)++;
        i++;
    }
    (*bufferPointer)++;
    buffer[i] = '\0';
    copyString(string, buffer, sizeToRead);
}

struct student splitData(const char studentString[]) {
    struct student student1;
    char *vornamePointer, *namePointer, *datePointer;
    int studentStringPointer = 0;

    vornamePointer = student1.vorname;
    namePointer = student1.name;
    datePointer = student1.date;

    readCharArrayToInt(&student1.matrikelnummer, studentString, 10, &studentStringPointer);
    printf("Matrikelnummer: %d\n", student1.matrikelnummer);
    readCharArrayToCharArray(vornamePointer, studentString, 50, &studentStringPointer);
    printf("Vorname: %s\n", student1.vorname);
    readCharArrayToCharArray(namePointer, studentString, 50, &studentStringPointer);
    printf("Name: %s\n", student1.name);
    readCharArrayToCharArray(datePointer, studentString, 15, &studentStringPointer);
    printf("Datum: %s\n", student1.date);
    readCharArrayToFloat(&student1.notenSchnitt, studentString, 4, &studentStringPointer);
    printf("Schnit: %f\n", student1.notenSchnitt);

    return student1;
}

int main() {
    readStudentFile();
    return 0;
}
