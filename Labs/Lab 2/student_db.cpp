#include "./student_db.h"

void sort_id(student* student_db, int n) {
    for (int x = 0; x < n; x++)
        for (int i = x; i < n; i++)
            if (student_db[i].id < student_db[x].id) {
                student temp = student_db[x];
                student_db[x] = student_db[i];
                student_db[i] = temp;
            }
}

void sort_last_name(student* student_db, int n) {
    for (int x = 0; x < n; x++)
        for (int i = x; i < n; i++)
            if (student_db[i].last_name < student_db[x].last_name) {
                student temp = student_db[x];
                student_db[x] = student_db[i];
                student_db[i] = temp;
            }
}

student* create_student_db(int n) {
    return new student[n];
}

void get_student_db_info(student* student_db, int n, fstream& stream_file) {
    string word = "";

    for (int x = 0; x < 4 ; x++) {
        stream_file >> word;

        if (x == 0)
            student_db[n].id = stoi(word);
        else if (x == 1)
            student_db[n].first_name = word;
        else if (x == 2)
            student_db[n].last_name = word;
        else if (x == 3)
            student_db[n].major = word;
    }
} 

void delete_student_db_info(student* student_db) {
    delete [] student_db;
} 
