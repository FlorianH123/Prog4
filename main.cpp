#include <cstdlib>
#include <cstdio>
#include "studentStruct.h"
#include "bubbleSort.cpp"

const int ARRAY_SIZE = 5;

struct student splitData(const char[]);

/**
 * Methode um ein Studenten auszugeben
 * @param aStudent
 */
void printStudent(student aStudent) {
    printf("Vorname %s\n", aStudent.vorname);
    printf("Name %s\n", aStudent.name);
    printf("Matrikelnummer %d\n", aStudent.matrikelnummer);
    printf("Datum %s\n", aStudent.date);
    printf("Notendurchschnitt %.2f\n", aStudent.notenSchnitt);
}

/**
 * Methode um zu überprüfen, ob ein Student valide ist
 * @param student ein Student
 * @return true wenn valide sonst false
 */
bool isStudentValide(struct student *student) {
    if (student -> notenSchnitt == 0) {
        return false;
    }

    if (student -> date[0] == '\0') {
        return false;
    }

    if (student -> vorname[0] == '\0') {
        return false;
    }

    if (student -> name[0] == '\0') {
        return false;
    }

    return student -> matrikelnummer != 0.0;

}

/**
 * Methode um Studenten von einer Datei einzulesen
 */
void readStudentFile() {
    int c = 0;
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

            buffer[bufferIndex] = static_cast<char>(c);
            bufferIndex++;

            if (c == '\n') {
                buffer[bufferIndex] = '\0';
                printf("%s\n", buffer);
                struct student student = splitData(buffer);
                if (isStudentValide(&student)) {
                    printf("Richtig\n");
                    studentArray[i] = student;
                    i++;
                    numberOfElementsInArray++;
                }
                bufferIndex = 0;
            }
        }
    }

    printf("<-- Vor dem Sortieren -->");
    for (int j = 0 ; j < numberOfElementsInArray ; j++) {
        printf("\n");
        printStudent(studentArray[j]);
    }
    printf("<-- ------------- -->\n");

    bubbleSortAlgorithm(studentArray, numberOfElementsInArray);

    printf("\n\n<-- Nach dem Sortieren -->");
    for (int j = 0 ; j < numberOfElementsInArray ; j++) {
        printf("\n");
        printStudent(studentArray[j]);
    }
    printf("<-- ------------- -->\n");

}

/**
 * Kopiert ein char Array in ein anderes
 * @param string neues Array
 * @param stringToCopy altes Array
 * @param size Größe des Arrays
 */
void copyString(char *string, const char stringToCopy[], int size) {
    for (int i = 0; i < size; i++) {
        string[i] = stringToCopy[i];
    }
}

/**
 * Konvertiert ein char Array in ein int
 * @param number
 * @param string
 * @param sizeToRead
 * @param bufferPointer
 */
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

/**
 * Konvertiert ein char Array in ein float
 * @param number
 * @param string
 * @param sizeToRead
 * @param bufferPointer
 */
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
    *number = static_cast<float>(atof(buffer));
}

void readCharArrayToCharArray(char *string, const char *stringArray, int sizeToRead, int *bufferPointer) {
    int i = 0;
    char buffer[sizeToRead + 1];
    while (i < sizeToRead && stringArray[*bufferPointer] != '\0' && stringArray[*bufferPointer] != '\n' && stringArray[*bufferPointer] != ';') {
        buffer[i] = stringArray[*bufferPointer];
        (*bufferPointer)++;
        i++;
    }
    (*bufferPointer)++;
    buffer[i] = '\0';
    copyString(string, buffer, sizeToRead);
}

/**
 * Initialisisert das Student struct
 * @param student
 */
void initializeStudent(struct student *student) {
    student -> matrikelnummer = 0;
    student -> notenSchnitt = 0.0;
    student -> name[0] = '\0';
    student -> date[0] = '\0';
    student -> vorname[0] = '\0';
}

/**
 * Teilt den Studenten String in Teilstrings
 * @param studentString
 * @return
 */
struct student splitData(const char studentString[]) {
    struct student student{};
    char *vornamePointer, *namePointer, *datePointer;
    int studentStringPointer = 0;

    initializeStudent(&student);

    vornamePointer = student.vorname;
    namePointer = student.name;
    datePointer = student.date;

    readCharArrayToInt(&student.matrikelnummer, studentString, 10, &studentStringPointer);
    readCharArrayToCharArray(vornamePointer, studentString, 50, &studentStringPointer);
    readCharArrayToCharArray(namePointer, studentString, 50, &studentStringPointer);
    readCharArrayToCharArray(datePointer, studentString, 15, &studentStringPointer);
    readCharArrayToFloat(&student.notenSchnitt, studentString, 4, &studentStringPointer);

    return student;
}

int main() {
    readStudentFile();
    return 0;
}

