#include <iostream>
#include <vector>
#include "complejo.cpp"
#include <algorithm>


vector<Complejo> genVector(Complejo complejo1, int n){

    vector<Complejo> vector1;

    /**
     * Primer elemento
     */

    vector1.push_back(Complejo(1,0));


    for (int i = 1; i < n; i++) {
        vector1.push_back(vector1.at(i-1) * complejo1 );
    }

    reverse(vector1.begin(), vector1.end());

    return vector1;
}

int main() {
    
    return 0;
}
