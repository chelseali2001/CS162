#include "./catalog.h"

/******************************************************
** Program: run_catalog.cpp
** Author: Chelsea Li
** Date: 4/12/20
** Description: Wizard Spellbook Catalog 
** Input: Txt files
** Output: The catalogs
******************************************************/
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Two files need to be provided." <<endl;
    } else if (!file_exists(argv[1]) || !file_exists(argv[2])) {
        cout << "At least one of these files don't exist." <<endl;
    } else {
        bool done = false;
        int id = 0, wizards_size = 0, spellbooks_size = 0, num_spells = 0, choice = 0, display = 0;
        ifstream in_stream;
        string line = "", password = "", filename = "";
    
        in_stream.open(argv[1]);
        in_stream >> line;
        wizards_size = get_int(line);
        wizard* wizards = create_wizards(wizards_size);

        for (int x = 0; x < wizards_size; x++)
            get_wizard_data(wizards, x, in_stream);
        
        in_stream.close();
    
        in_stream.open(argv[2]);
        in_stream >> line;
        spellbooks_size = get_int(line);
        spellbook* spellbooks = create_spellbooks(spellbooks_size);

        for (int x = 0; x < spellbooks_size; x++) {
            get_spellbook_data(spellbooks, x, in_stream);
            spell* spells = create_spells(spellbooks[x].num_spells);
            get_spell_data(spells, spellbooks[x].num_spells, in_stream);
            spellbooks[x].s = spells;
            spellbooks[x].avg_success_rate = average_success_rate(spellbooks[x], spellbooks[x].num_spells);
        }

        in_stream.close();
    
        for (int x = 0; x < spellbooks_size; x++)
            num_spells += spellbooks[x].num_spells;

        spell spells[num_spells];
        int spell_val[num_spells];
        spell_values(spellbooks, spells, spell_val, spellbooks_size);
    
        int wizard_login = login(wizards, wizards_size);
    
        if (wizard_login != -1) {
            cout << "\nWelcome " << wizards[wizard_login].name <<endl;
            cout << "ID: " << wizards[wizard_login].id <<endl;
            cout << "Status: " << wizards[wizard_login].position_title <<endl;
            cout << "Beard Length: " << wizards[wizard_login].beard_length <<endl;
    
            while (!done) {
                bool valid = false;
                
                while (!valid) {
                    cout << "\nWhich option would you like to choose?" <<endl;
                    cout << "Sort spellbooks by number of pages (Press 1)" <<endl;
                    cout << "Group spells by their effect (Press 2)" <<endl;
                    cout << "Sort spellbooks by average success rate (Press 3)" <<endl;
                    cout << "Quit (Press 4)" <<endl;
                    cin >> choice;
                    
                    if (choice < 1 || choice > 4){
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "Invalid choice, try again." <<endl;
                    } else {
                        valid = true;
                    }
                }
                
                if (choice == 4) {
                    done = true;
                } else {
                    while (valid) {
                        cout << "How would you like the information displayed?" <<endl;
                        cout << "Print to screen (Press 1)" <<endl;
                        cout << "Print to file (Press 2)" <<endl;
                        cin >> display;
                        
                        if (display < 1 || display > 2) {
                            cin.clear();
                            cin.ignore(256, '\n');
                            cout << "Invalid option, try again." <<endl;
                        } else {
                            valid = false;
                        }
                    }
                    
                    if (choice == 1)
                        sort_pages(spellbooks, spellbooks_size);
                    else if (choice == 2)
                        sort_effect(spells, spell_val, num_spells);
                    else if (choice == 3)
                        sort_success(spellbooks, spellbooks_size);
    
                    if (display == 1) {
                        if (choice == 1 || choice == 3)
                            for (int x = 0; x < spellbooks_size; x++) {
                                bool poison_death = bad(spellbooks, x);
    
                                if (!poison_death || (poison_death && wizards[wizard_login].position_title != "Student"))
                                    if (choice == 1)
                                        cout << spellbooks[x].title << " " << spellbooks[x].num_pages <<endl;                              
                                    else if (choice == 3)
                                        cout << spellbooks[x].title << " " << spellbooks[x].avg_success_rate <<endl;
                            }
                        else if (choice == 2)
                            for (int x = 0; x < num_spells; x++)
                                if (wizards[wizard_login].position_title == "Student" && (spells[x].effect == "poison" || spells[x].effect == "death"))
                                    continue;
                                else
                                    cout << spells[x].name << " " << spells[x].effect <<endl;
                    } else if (display == 2) {
                        ofstream out_stream;
    
                        cout << "Please provide desired filename: ";
                        cin >> filename;
    
                        out_stream.open(filename.c_str(), ios::app);
    
                        if (choice == 1 || choice == 3)
                            for (int x = 0; x < spellbooks_size; x++) {
                                bool poison_death = bad(spellbooks, x);
    
                                if (!poison_death || (poison_death && wizards[wizard_login].position_title != "Student"))
                                    if (choice == 1)
                                        out_stream << spellbooks[x].title << " " << spellbooks[x].num_pages <<endl;                              
                                    else if (choice == 3)
                                        out_stream << spellbooks[x].title << " " << spellbooks[x].avg_success_rate <<endl;
                            }
                        else if (choice == 2)
                            for (int x = 0; x < num_spells; x++)
                                if (wizards[wizard_login].position_title == "Student" && (spells[x].effect == "poison" || spells[x].effect == "death"))
                                    continue;
                                else
                                    out_stream << spells[x].name << " " << spells[x].effect <<endl;
    
                        out_stream.close();
                        cout << "Appended requested information to file" <<endl;
                    }
                }
            }
        }
    
        delete_info(wizards, spellbooks, spellbooks_size);
    }
    
    return 0;
}