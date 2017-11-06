#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <main.h>

void splitData(char buffer[]) {
    char data[250];
    int index = 0;


}

void readStudentFile() {
    int c;
    int n = 0;
    char buffer[250];
    int bufferIndex = 0;
    FILE* studentFile = fopen("C:\\Users\\Florian\\CLionProjects\\Uebung1\\students.csv", "r");

    if (studentFile == nullptr) {
        perror("Datei konnte nicht geoeffnet werden!\n");
    } else {
        while (c != EOF) {
            c = fgetc(studentFile);

            buffer[bufferIndex] = c;
            bufferIndex++;

            if (c == '\n') {
                buffer[bufferIndex] = '\0';

                splitData(buffer);
                printf("%s", buffer);
                bufferIndex = 0;
            }
        }
    }
}

int main() {
    readStudentFile();
    return 0;
}

