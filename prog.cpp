#include "./multi_div.h"

int main(int argc, char* argv[]) {
    int done = 1;
    
    while (done == 1) {
      enter_vals(argv[1], argv[2]);
  
      int rows = atoi(argv[1]), cols = atoi(argv[2]);
  
      mult_div_values** table = create_table(rows, cols);
  
      delete_table(table, rows);
      
      done = again(argv[1], argv[2]);
    }

    return 0;
}
