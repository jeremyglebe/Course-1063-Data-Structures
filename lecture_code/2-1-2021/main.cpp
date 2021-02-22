#include <iostream>
#include <string>
using namespace std;

class Player{
    public:
    // Constructor runs when object of the type Player is created
    Player(){
        username = "NO_NAME";
        health = 100;
        speed = 1.5;
    }
    // Constructors can have parameters and can be overloaded
    Player(string startName){
        int sz = startName.size();
        // Conditions on which to update username
        if(sz > 3 && sz < 13){
            // Update the username
            username = startName;
        }
        else{
            // Don't update, print error
            cout << "Username must be 4-12 characters!\n";
            username = "BAD_NAME";
        }
        // Initial values NOT based on parameters
        health = 100;
        speed = 1.5;
    }
    string getUsername(){
        return username;
    }
    void setUsername(string name){
        int sz = name.size();
        // Conditions on which to update username
        if(sz > 3 && sz < 13){
            // Update the username
            username = name;
        }
        else{
            // Don't update, print error
            cout << "Username must be 4-12 characters!\n";
        }
    }
    void print(){
        cout << username << ": " << health << " hp, " << speed << "m/s\n";
    }
    private:
    string username;
    int health;
    float speed;
};

int main() {
    // Initial name value using a constructor
    Player p("John");
    cout << p.getUsername() << '\n';
    // Bad value will initialize to BAD_NAME (because we told it to!)
    // Player p("Jeremy Dale Glebe");
    // Updates!
    p.setUsername("Jeremy");
    // Fails to update!
    p.setUsername("Joe");
    // Prints the last successful username
    p.print();

    // With overloads, we have two methods of construction!
    Player varThing("Geralt");
    varThing.print();
    Player bobTheHero;
    bobTheHero.print();
}