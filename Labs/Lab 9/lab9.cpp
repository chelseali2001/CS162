#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

void insertion_sort(int* ascending_nums, int n) {
    if (n > 1) {
        insertion_sort(ascending_nums, n - 1);

        int n1 = ascending_nums[n - 1]; 
        int n2 = n - 2; 
    
        while (n2 >= 0 && ascending_nums[n2] > n1)  { 
            ascending_nums[n2 + 1] = ascending_nums[n2]; 
            n2--; 
        } 

        ascending_nums[n2 + 1] = n1; 
    }
}

bool check_prime(int n) {
    if (n <= 1) 
        return false; 

    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
}

void print_array(string prompt, int* arr, int n) {
    cout << prompt;

    for (int x = 0; x < n; x++)
        if (x < n - 1)
            cout << arr[x] << ", ";
        else
            cout << arr[x] <<endl;
}

int main() {
    bool valid = false;
    int n;

    srand(time(NULL));

    while (!valid) {
        try {
            cout << "Enter a number between 1 and 25: ";
            cin >> n;

            if (n > 0 && n <= 25)
                valid = true;
            else
                throw "Error: Input must be an int between 1 and 25\n";
        } catch (const char* str) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << str <<endl;
        }
    }

    int* numbers = new int[n];

    for (int x = 0; x < n; x++)
        numbers[x] = rand() % 99 + 1;

    print_array("Original array: ", numbers, n);  
    
    int* ascending_nums = numbers;
    insertion_sort(ascending_nums, n);
    print_array("Sorted array: ", ascending_nums, n);    

    cout << "Prime numbers: ";

    for (int x = 0; x < n; x++)
        if (check_prime(ascending_nums[x]))
            cout << ascending_nums[x] << " ";
    
    cout <<endl;

    delete [] numbers;

    return 0;
}
