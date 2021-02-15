#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream ifile;
    string file;
    cout << "File name: ";
    cin >> file;
    // ifile.open("in.dat");
    ifile.open(file);
    for(int i = 0; i < 9; i++){
        char var;
        ifile >> var;
        cout << "We read " << var << " from a file!\n";
    }
    ifile.close();
    return 0;
}