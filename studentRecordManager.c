#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int reg;
    char name[30];
    float cgpa;
} Student;
typedef struct
{
    Student *studentptr;
    int count;
    int capacity;
} database;

void init_database(database *db, int initial_capacity){
    int *m;
    if(initial_capacity > 0){
        db->studentptr = malloc(sizeof(Student) * initial_capacity);
        if(db->studentptr == NULL){
            printf("Error 404\n");
            exit(1);
        }
        else{
            db->capacity = initial_capacity;
            db->count = 0;
        }
    }
}

int main(){
    int k = sizeof(Student);
    int p = sizeof(database);
    printf("%d", k);
    printf("\n%d", p);
    return 0;
}
