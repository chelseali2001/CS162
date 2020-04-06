#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct wizard {
    string name;
    int id;
    string password;
    string position_title; 
    float beard_length;
};

struct spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell* s;
};

struct spell {
    string name;
    float success_rate;
    string effect; 
};

bool file_exists(string);
int get_int(string);
bool is_int(string);
float get_float(string);
float round_float(float);
float average_success_rate(spellbook, int);
bool bad(spellbook*, int);
int enter_id();
int login(wizard*, int);
void sort_pages(spellbook*, int);
void spell_values(spellbook*, spell*, int*, int);
void sort_effect(spell*, int*, int);
void sort_success(spellbook*, int);
void get_wizard_data(wizard*, int, ifstream&);
wizard* create_wizards(int);
void get_spell_data(spell*, int, ifstream&);
spell* create_spells(int);
void get_spellbook_data(spellbook*, int, ifstream&);
spellbook* create_spellbooks(int);
void delete_info(wizard*, spellbook*, int);