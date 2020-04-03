#include "./multi_div.h"

bool is_valid_dimensions(char* m, char* n) {
    if (*m > '0' && *m <= '9' && *n > '0' && *n <= '9')
        return true;
    
    return false;
}

void enter_vals(char* m, char* n) {
    while (!is_valid_dimensions(m, n)) {
        if (*m < '0' || *m > '9') {
            cout << "You did not input a valid row.\n" << "Please enter an integer greater than 0 for a row: ";
            cin >> m;
        } else if (*n < '0' || *n > '9') {
            cout << "You did not input a valid column.\n" << "Please enter an integer greater than 0 for a column: ";
            cin >> n;
        }
    }
}

int num_digits(int num) {
    int count = 0;

    while (num != 0) {
        count++;
        num /= 10;
    }

    return count;
}

int high_digits_mult(mult_div_values** table, int m, int n) {
    int max = 1;

    for (int x = 0; x < m; x++)
        for (int i = 0; i < n; i++) {
            int digits = num_digits(table[x][i].mult);

            if (digits > max)
                max = digits;
        }
    
    return max;
}

int high_digits_div(mult_div_values** table, int m, int n) {
    int max = 1;

    for (int x = 0; x < m; x++)
        for (int i = 0; i < n; i++) {
            int digits = num_digits((int) table[x][i].div);

            if (digits > max)
                max = digits;
        }
    
    return max;
}

void set_mult_values(mult_div_values** table, int m, int n) {
    for (int x = 1; x <= m; x++)
        for (int i = 1; i <= n; i++)
            table[x - 1][i - 1].mult = x * i;
}

void set_div_values(mult_div_values** table, int m, int n) {
    for (int x = 1; x <= m; x++) 
        for (int i = 1; i <= n; i++)
            table[x - 1][i - 1].div = (float) x / (float) i;
}

void print_spaces(int max_digits, int num) {
    int spaces = max_digits - num_digits(num) + 1;
    
    if (spaces > max_digits)
      spaces--;

    for (int x = 0; x < spaces; x++)
        cout << " ";
}

void print_mult_table(mult_div_values** table, int m, int n) {
    int max_digits = high_digits_mult(table, m, n);

    cout << "Multiplication Table: " <<endl;

    for (int x = 0; x < m; x++) {
        for (int i = 0; i < n; i++) {
            cout << table[x][i].mult;
            print_spaces(max_digits, table[x][i].mult);
        }

        cout <<endl;
    }
}

void print_div_table(mult_div_values** table, int m, int n) {
    int max_digits = high_digits_div(table, m, n);
    
    cout << "Division Table: " <<endl;
    cout << fixed << setprecision(2);

    for (int x = 0; x < m; x++) {
        for (int i = 0; i < n; i++){
            cout << table[x][i].div;
            print_spaces(max_digits, (int) table[x][i].div);
        }
    
        cout <<endl;
    }
}

mult_div_values** create_table(int m, int n) {
    mult_div_values** table = new mult_div_values*[m];

    for (int x = 0; x < m; x++)
        table[x] = new mult_div_values[n];

    set_mult_values(table, m, n);
    set_div_values(table, m, n);
    
    print_mult_table(table, m, n);
    print_div_table(table, m, n);

    return table;
}

void delete_table(mult_div_values** table, int m) {
    for (int x = 0; x < m; x++)
        delete [] table[x];

    delete [] table;
}

int again(char* m, char* n) {
    int choice = 0;
    
    cout << "Would you like to see a different size matrix (0-no, 1-yes)? ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "Enter the number of rows: ";
        cin >> m;
        
        cout << "Enter the number of cols: ";
        cin >> n;
    }  
    
    return choice;
} 