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
void add_student(database *db, int reg, const char *name, float cgpa){
    if(db == NULL || db->studentptr == NULL){
        return;
    }
    if(db->count == db->capacity){
        int new_capacity = db->capacity * 2;
        Student *temp = realloc(db->studentptr, new_capacity * sizeof(Student));
        if(temp == NULL){
            printf("Reallocation failed!! \n");
            return;
        }
        db->studentptr = temp;
        db->capacity = new_capacity;
    }
    int index = db->count;
    db->studentptr[index].reg = reg;
    strncpy(db->studentptr[index].name, name, sizeof(db->studentptr[index].name) - 1);
    db->studentptr[index].name[sizeof(db->studentptr[index].name) - 1] = '\0';
    db->studentptr[index].cgpa = cgpa;
    db->count++;
}

int main(){
    database db;
    init_database(&db, 2);
    add_student(&db, 101, "Alice Walker", 3.85f);
    add_student(&db, 102, "Marcus Vance", 3.42f);
    add_student(&db, 103, "Elena Rostova", 3.95f);
    printf("%d %d", db.count, db.capacity);
    free_database(&db);
    return 0;
}
