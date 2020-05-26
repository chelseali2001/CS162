#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
    vector<int> v;   //Our vector class
    std::vector<int> stdv; //Standard vector

    //Compare operation of our vector to std
    v.push_back(23);
    stdv.push_back(23);

    vector<int> new_v(v);
    v = new_v;

    cout << "Our vector copy size: " << new_v.size() <<endl;
    cout << "Our vector size: " << v.size() << endl;
    cout << "STL vector size: " << stdv.size() << endl;
    cout << "Our vector element v[0]: " << v[0] <<endl;
    cout << "Our vector element at 0: " << v.at(0) <<endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "\nThree new values were added." <<endl;
    cout << "Our vector capacity: " << v.capacity() <<endl;
    cout << "Our vector size: " << v.size() <<endl;

    vector<int> final_v(5);
    cout << "\nThe final_v template has 5 numbers initialized to it" <<endl;
    cout << "The final_v is limited to size " << final_v.size() <<endl;

    return 0;
}
