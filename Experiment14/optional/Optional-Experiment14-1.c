#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct {
    char num[7];
    char name[8];
    char sex[3];
    char age[5];
    char grade[9];
} Student;

FILE* open_file(char* filename, char* mode) {
    FILE* f = fopen(filename, mode);
    if (f == NULL) {
        perror("Error");
        _exit(1);
    }
    return f;
}

int main() {
    Student stu1[10] = {
        "101", "Zhang", "M", "19", "95.6", \
        "102", "Wang", "F", "18", "92.4", \
        "103", "Zhao", "M", "19", "85.7", \
        "104", "Li", "M", "20", "96.3", \
        "105", "Gao", "M", "19", "90.2", \
        "106", "Lin", "M", "18", "91.5", \
        "107", "Ma", "F", "17", "98.7", \
        "108", "Zhen", "M", "21", "90.1", \
        "109", "Xu", "M", "19", "89.5", \
        "110", "Mao", "F", "18", "94.5"
    };

    FILE* fin = open_file("stu.dat", "wb");
    fwrite(stu1, sizeof(Student), 10, fin);
    fclose(fin);
    fin = open_file("stu.dat", "rb");
    fclose(fin);

    struct stat buf;
    stat("stu.dat", &buf);
    int size = buf.st_size / sizeof(Student);
    Student* stu2 = (Student*)malloc(sizeof(Student) * size);
    FILE* fout = open_file("stu.dat", "rb");
    fread(stu2, sizeof(Student), size, fout);
    fclose(fout);

    printf("num\tname\tsex\tage\tgrade\n");
    printf("-------------------------------------\n");
    for (int i=0; i<size; ++i) 
        printf("%s\t%s\t%s\t%s\t%s\n", stu2[i].num, stu2[i].name, stu2[i].sex, stu2[i].age, stu2[i].grade);
    return 0;
}