#include "./catalog.h"

/**************************************************************************************************************
 ** Function: file_exists
 ** Description: Checks if a file exists.
 ** Parameters: string file
 ** Pre-Conditions: 1 string
 ** Post-Conditions: Returns a bool to indicate if a file exists.
**************************************************************************************************************/
bool file_exists(string file) {
    ifstream in_stream(file.c_str());
    
    if (in_stream)
        return true;
        
    return false;
}

/**************************************************************************************************************
 ** Function: get_int
 ** Description: Converts a string to an int.
 ** Parameters: string n
 ** Pre-Conditions: 1 string
 ** Post-Conditions: Returns the int value of the given string.
**************************************************************************************************************/
int get_int(string n) {
    int num = 0;

    for (int x = 0; x < n.length(); x++)
        num += (n[x] - 48) * pow(10, n.length() - x - 1);

    return num;
}

/**************************************************************************************************************
 ** Function: is_int
 ** Description: Indicates if the given string is an int.
 ** Parameters: string n
 ** Pre-Conditions: 1 string
 ** Post-Conditions: Returns a bool indicating if the string is an int.
**************************************************************************************************************/
bool is_int(string n) {
    for (int x = 0; x < n.length(); x++)
        if (n[x] < '0' || n[x] > '9')
            return false;
    
    return true;
}

/**************************************************************************************************************
 ** Function: get_float
 ** Description: Converts a string to a float.
 ** Parameters: string n
 ** Pre-Conditions: 1 string
 ** Post-Conditions: Returns the float value of the given string.
**************************************************************************************************************/
float get_float(string n) {
    int decimal_point = n.length();
    float num = 0;

    for (int x = 0; x < n.length(); x++)
        if (n[x] == '.') {
            decimal_point = x;
            break;
        }

    for (int x = 0; x < decimal_point; x++)
        num += (n[x] - 48) * pow(10, decimal_point - x - 1);
    
    if (n.length() != decimal_point)
        for (int x = decimal_point + 1; x < n.length(); x++) 
            num += (n[x] - 48) * pow(0.1, x - decimal_point);

    return num;
}

/**************************************************************************************************************
 ** Function: round_float
 ** Description: Rounds a float to the hundreth place.
 ** Parameters: float num
 ** Pre-Conditions: 1 float
 ** Post-Conditions: Returns a float rounded to the hundreth place.
**************************************************************************************************************/
float round_float(float num) { 
    float n = (int) (num * 100 + 0.5); 
    return (float) n / 100; 
} 

/**************************************************************************************************************
 ** Function: average_success_rate
 ** Description: Calculates the average success rate of the spells in a spellbook.
 ** Parameters: spellbook* spellbooks, int n
 ** Pre-Conditions: 1 1D spellbook struct array and 1 int
 ** Post-Conditions: Calculates the average success rate.
**************************************************************************************************************/
float average_success_rate(spellbook the_spellbook, int n) { 
    float average = 0;
    
    for (int x = 0; x < n; x++)
        average += the_spellbook.s[x].success_rate;
    
    average /= the_spellbook.num_spells;
    return round_float(average);
}

/**************************************************************************************************************
 ** Function: bad
 ** Description: Indicates if there's a poison or death spell in a spellbook.
 ** Parameters: spellbook* spellbooks, int index
 ** Pre-Conditions: 1 1D spellbook struct array and 1 int
 ** Post-Conditions: Returns a bool indicating if there's a poison or death spell in a spellbook.
**************************************************************************************************************/
bool bad(spellbook* spellbooks, int index) {
    for (int x = 0; x < spellbooks[index].num_spells; x++)
        if (spellbooks[index].s[x].effect == "poison" || spellbooks[index].s[x].effect == "death")
            return true;

    return false;
}

/**************************************************************************************************************
 ** Function: enter_id
 ** Description: Checks if the user enters an int for the id.
 ** Parameters: nothing
 ** Pre-Conditions: nothing
 ** Post-Conditions: Returns the int value of the id.
**************************************************************************************************************/
int enter_id() {
    bool valid_int = false;
    string id = "";
    
    while (!valid_int) {
        cout << "Please enter your id: ";
        cin >> id;
        
        if (is_int(id))
            return get_int(id);
        
        cout << "The id must be an int." <<endl;
    }
}

/**************************************************************************************************************
 ** Function: login
 ** Description: Checks if the user enters the right login info.
 ** Parameters: wizard* wizards, int n
 ** Pre-Conditions: 1 1D wizard struct array and 1 int
 ** Post-Conditions: Returns the index of the logged in user in the wizards array.
**************************************************************************************************************/
int login(wizard* wizards, int n) {
    bool valid_login = false;
    int id = 0, invalid = 0;
    string password = "";

    while (!valid_login) {
        id = enter_id();
        
        cout << "Please enter your password: ";
        cin >> password;
    
        for (int x = 0; x < n; x++)
            if (id == wizards[x].id && password == wizards[x].password)
                return x;
    
        cout << "Incorrect id or password" <<endl;
        invalid++;
    
        if (invalid == 3)
            valid_login = true;
    }
    
    cout << "You've entered the wrong id or password too many times." <<endl;
    
    return -1;
}

/**************************************************************************************************************
 ** Function: sort_pages
 ** Description: Sorts the list of spellbooks according to number of pages.
 ** Parameters: spellbook* spellbooks, int n
 ** Pre-Conditions: 1 1D spellbook struct array and 1 int
 ** Post-Conditions: Sorts the list of spellbooks according to number of pages in accending order.
**************************************************************************************************************/
void sort_pages(spellbook* spellbooks, int n) {
    for (int x = 0; x < n; x++) 
        for (int i = x; i < n; i++) 
            if (spellbooks[i].num_pages < spellbooks[x].num_pages) {
                spellbook temp = spellbooks[x];
                spellbooks[x] = spellbooks[i];
                spellbooks[i] = temp;
            }
}

/**************************************************************************************************************
 ** Function: spell_values
 ** Description: Collects all of spells and gives the effects of the spells a value.
 ** Parameters: spellbook* spellbooks, spell* spells, int* spell_val, int n
 ** Pre-Conditions: 1 1D spellbook struct array, 1 1D spell struct array, 1 1D int array, and 1 int
 ** Post-Conditions: Changes the values of an object in the 2D array treasure object.
**************************************************************************************************************/
void spell_values(spellbook* spellbooks, spell* spells, int* spell_val, int n) {
    int index = 0;

    for (int x = 0; x < n; x++)
        for (int i = 0; i < spellbooks[x].num_spells; i++) {
            spells[index] = spellbooks[x].s[i];
            
            if (spells[index].effect == "bubble") {
                spell_val[index] = 1;
            } else if (spells[index].effect == "memory_loss") {
                spell_val[index] = 2;
            } else if (spells[index].effect == "fire") {
                spell_val[index] = 3;
            } else if (spells[index].effect == "poison") {
                spell_val[index] = 4;
            } else if (spells[index].effect == "death") {
                spell_val[index] = 5;
            }
            
            index++;
        }
    
    cout <<endl;
}

/**************************************************************************************************************
 ** Function: sort_effect
 ** Description: Sorts the spells by their effects.
 ** Parameters: spell* spells, int* spell_val, int n
 ** Pre-Conditions: 1 1D spell struct array, 1 1D int array, and 1 int
 ** Post-Conditions: Sorts the spells by their effects (bubbles, memory_loss, fire, poison, then death).
**************************************************************************************************************/
void sort_effect(spell* spells, int* spell_val, int n) {
    for (int x = 0; x < n; x++) 
        for (int i = x; i < n; i++) 
            if (spell_val[i] < spell_val[x]) {
                int num_temp = spell_val[x];
                spell_val[x] = spell_val[i];
                spell_val[i] = num_temp;

                spell temp = spells[x];
                spells[x] = spells[i];
                spells[i] = temp;
            }
}

/**************************************************************************************************************
 ** Function: sort_success
 ** Description: Sorts the spellbooks by average success rate.
 ** Parameters: spellbook* spellbooks, int n
 ** Pre-Conditions: 1 1D spellbook struct array and 1 int
 ** Post-Conditions: Sorts the spellbooks by avereage success rate in ascending order.
**************************************************************************************************************/
void sort_success(spellbook* spellbooks, int n) {
    for (int x = 0; x < n; x++) 
        for (int i = x; i < n; i++) 
            if (spellbooks[i].avg_success_rate < spellbooks[x].avg_success_rate) {
                spellbook temp = spellbooks[x];
                spellbooks[x] = spellbooks[i];
                spellbooks[i] = temp;
            }
}

/**************************************************************************************************************
 ** Function: get_wizard_data
 ** Description: Collects the information on each wizard.
 ** Parameters: wizard* wizards, int index, ifstream& in_stream
 ** Pre-Conditions: 1 1D wizard struct array, 1 int, and 1 ifstream&
 ** Post-Conditions: Records information from "wizard.txt" in wizard struct and array.
**************************************************************************************************************/
void get_wizard_data(wizard* wizards, int index, ifstream& in_stream) {
    int num_words = 0;
    string word = "";

    while (in_stream >> word) {
        if (num_words == 0) {
            wizards[index].name = word;
        } else if (num_words == 1) {
            wizards[index].id = get_int(word);
        } else if (num_words == 2) {
            wizards[index].password = word;
        } else if (num_words == 3) {
            wizards[index].position_title = word;
        } else if (num_words == 4) {
            wizards[index].beard_length = get_float(word);
            break;
        }
    
        num_words++;
    }
}

/**************************************************************************************************************
 ** Function: create_wizards
 ** Description: Creates a wizard array.
 ** Parameters: int n
 ** Pre-Conditions: 1 int
 ** Post-Conditions: Returns a dynamically allocated wizard array.
**************************************************************************************************************/
wizard* create_wizards(int n) {
    return new wizard[n];
}

/**************************************************************************************************************
 ** Function: get_spell_data
 ** Description: Collects the information on each spell from a spellbook.
 ** Parameters: spell* spells, int num_spells, ifstream& in_stream
 ** Pre-Conditions: 1 1D spell struct array, 1 int, and 1 ifstream&
 ** Post-Conditions: Records information from "spellbooks.txt" in spell struct and array.
**************************************************************************************************************/
void get_spell_data(spell* spells, int num_spells, ifstream& in_stream) {
    string word = "";

    for (int x = 0; x < num_spells; x++) {
        int num_words = 0;

        while (in_stream >> word) {
            if (num_words == 0) {
                spells[x].name = word;
            } else if (num_words == 1) {
                spells[x].success_rate = get_float(word);
            } else if (num_words == 2) {
                spells[x].effect = word;
                break;
            }
            
            num_words++;
        }
    }
}

/**************************************************************************************************************
 ** Function: create_spells
 ** Description: Creates a spell array.
 ** Parameters: int n
 ** Pre-Conditions: 1 int
 ** Post-Conditions: Returns a dynamically allocated spell array.
**************************************************************************************************************/
spell* create_spells(int n) {
    return new spell[n];
}

/**************************************************************************************************************
 ** Function: get_spellbook_data
 ** Description: Collects the information on each spellbook.
 ** Parameters: spellbook* spellbooks, int index, ifstream& in_stream
 ** Pre-Conditions: 1 1D spellbook struct array, 1 int, and 1 ifstream&
 ** Post-Conditions: Records information from "spellbooks.txt" in spellbook struct and array.
**************************************************************************************************************/
void get_spellbook_data(spellbook* spellbooks, int index, ifstream& in_stream) {
    int num_words = 0;
    string word = "";

    while (in_stream >> word) {
        if (num_words == 0) {
            spellbooks[index].title = word;
        } else if (num_words == 1) {
            spellbooks[index].author = word;
        } else if (num_words == 2) {
            spellbooks[index].num_pages = get_int(word);
        } else if (num_words == 3) {
            spellbooks[index].edition = get_int(word);
        } else if (num_words == 4) {
            spellbooks[index].num_spells = get_int(word);
            break;
        }
        
        num_words++;
    }
}

/**************************************************************************************************************
 ** Function: create_spellbooks
 ** Description: Creates a spellbook array.
 ** Parameters: int n
 ** Pre-Conditions: 1 int
 ** Post-Conditions: Returns a dynamically allocated spellbook array.
**************************************************************************************************************/
spellbook* create_spellbooks(int n) {
    return new spellbook[n];
}

/**************************************************************************************************************
 ** Function: delete_info
 ** Description: Deletes the dynamically allocated arrays.
 ** Parameters: wizard* wizards, spellbook* spellbooks
 ** Pre-Conditions: 1 1D wizard struct array and 1 1D spellbook struct array
 ** Post-Conditions: Deletes all memory that was dynamically allocated.
**************************************************************************************************************/
void delete_info(wizard* wizards, spellbook* spellbooks, int spellbooks_size) {
    delete [] wizards;
    
    for (int x = 0; x < spellbooks_size; x++)
        delete [] spellbooks[x].s;
    
    delete [] spellbooks;
}