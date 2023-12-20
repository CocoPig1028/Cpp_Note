//
//  main.cpp
//  mdCpp_1
//
//  Created by 박대영 on 12/21/23.
//

#include <iostream>
using namespace std;

int change_val(int *p) {
    *p = 3;
    
    return 0;
}

int main() {
    int number = 5;
    
    cout << number << endl;
    change_val(&number);
    cout << number << endl;
}
