#include <iostream>
#include <string>
using namespace std;

class Player{
// Public is accessible everywhere (including main())
public:
    // Constructor runs on creation of variable
    Player(){
        username = "NO_NAME";
        health = 100;
        speed = 3.5;
        nemesis = NULL;
    }
    // Overloading works on constructors too!
    // Constructors can have parameters!
    Player(string startName){
        username = startName;
        health = 100;
        speed = 3.5;
        nemesis = NULL;
    }
    // Destructor runs when the variable is destroyed
    ~Player(){
        if(nemesis != NULL){
            delete nemesis;
        }
    }
    // Methods to modify and access private members
    void setNemesis(Player* uglyPerson){
        nemesis = uglyPerson;
    }
    void setUsername(string name){
        if(name.size() > 3 && name.size() < 13){
            username = name;
        }
        else{
            cout << "Username must be 4-12 characters!\n";
        }
    }
    string getUsername(){
        return username;
    }
    // Method to print the character
    void print(){
        cout << username << ": " << health << "hp; " << speed << "m/s\n";
    }
// Private can only be modified by functions in this class
private:
    // These variables are used internally by objects of type Player
    int health;
    float speed;
    string username;
    Player* nemesis;
};

int main() {
    Player p("Jeremy");
    cout << p.getUsername() << '\n';
    p.setUsername("John");
    p.print();
    p.setUsername("Joe");
    p.setUsername("Teddy Roosevelt");
    Player var;
    var.print();
    var.setNemesis(new Player("Steve"));
    return 0;
}