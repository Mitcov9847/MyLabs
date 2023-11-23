#include <iostream>
using namespace std;
int hello(int x) { 
    return x * 2;
}

int main() {
    int result = hello(5);
    cout << "Результат: " << result << endl;
    return 0;
}
