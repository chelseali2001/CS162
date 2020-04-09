#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student {
    int id;
    string first_name;
    string last_name;
    string major;
};

void sort_id(student*, int);
void sort_last_name(student*, int);
student* create_student_db(int); 
void get_student_db_info(student*, int, fstream&); 
void delete_student_db_info(student*); 