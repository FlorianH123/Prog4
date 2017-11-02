#include <cstdlib>
#include <cstdio>
#include <cstring>

struct student {
    int matrikelnummer;
    char name[50];
    char vorname[50];
    char date[15];
    float notenSchnitt;
};

void readStudentFile() {
    int c;
    int n = 0;
    char buffer[250];
    int bufferIndex = 0;
    FILE* studentFile = fopen("C:\\Users\\Florian\\CLionProjects\\Uebung1\\students.csv", "r");

    if (studentFile == NULL) {
        perror("Datei konnte nicht geoeffnet werden!\n");
    } else {
        while (c != EOF) {
            c = fgetc(studentFile);

            buffer[bufferIndex] = c;
            bufferIndex++;

            if (c == '\n') {
                buffer[bufferIndex] = '\0';
                printf("%s", buffer);
                bufferIndex = 0;

                //memset(buffer, ' ', 249);

                //printf("%s", buffer);
            }
        }
    }
}

int main() {
    readStudentFile();
    return 0;
}

