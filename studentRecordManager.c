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
        db->capacity = initial_capacity;
        db->count = 0;
    }
}
void free_database(database *db){
    if(db != NULL && db->studentptr != NULL){
        free(db->studentptr);
        db->studentptr = NULL;
        db->count = 0;
        db->capacity = 0;
    }
}

int main(){
    database db;
    init_database(&db, 2);
    printf("%d %p\n",db.capacity, db.studentptr);
    free_database(&db);
    printf("%d %p\n",db.capacity, db.studentptr);
    return 0;
}
