#include <iostream>
using namespace std;
int hello(int x) { 
    return x * 2;
}

int main() {
    int result = hello(5);
    cout << "���������: " << result << endl;
    return 0;
}
