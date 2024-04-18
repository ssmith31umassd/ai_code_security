#include <iostream>
using namespace std;

int main() {
    const int BUFSIZE = 256;
    char buf[BUFSIZE];

    cout << "Enter a string: ";
    cin.getline(buf, BUFSIZE);

    cout << "You entered: " << buf << endl;

    return 0;
}
