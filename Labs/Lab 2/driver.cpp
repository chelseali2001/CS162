#include "./student_db.h"

int main(int argc, char* argv[]) {
    fstream f_stream(argv[1]);
    string line;

    if (!f_stream) {
        cout << "This file does not exist.";
    } else {
        getline(f_stream, line);
        student* student_db = create_student_db(stoi(line));

        for (int x = 0; x < stoi(line); x++)
            get_student_db_info(student_db, x, f_stream);
        
        f_stream.close();

        f_stream.open("students.txt", ios::out);

        sort_id(student_db, stoi(line));
        f_stream << "STUDENTS ID" <<endl;

        for (int x = 0; x < stoi(line); x++)
            f_stream << student_db[x].id << " " << student_db[x].first_name << " " << student_db[x].last_name << " " << student_db[x].major << " " <<endl;

        sort_last_name(student_db, stoi(line));
        f_stream << "\nSTUDENTS LAST NAME" <<endl;

        for (int x = 0; x < stoi(line); x++)
            f_stream << student_db[x].id << " " << student_db[x].first_name << " " << student_db[x].last_name << " " << student_db[x].major << " " <<endl;
    
        delete_student_db_info(student_db);
    }

    return 0;
}