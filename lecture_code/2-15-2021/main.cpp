#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pokemon
{
    int id;
    string name;
    string type1, type2;
    int hp, attack, defense,
        special_attack, special_defense, speed;
};

void readDatabase(ifstream &file, Pokemon *list, int size);
int searchDatabase(string key_name, Pokemon *list, int size);
void printPokemon(Pokemon p);
void printPokemonList(Pokemon *list, int size);

int main()
{
    Pokemon *pokeArr = nullptr;
    ifstream ifile("pokemon.dat");
    int num_pokemon;
    ifile >> num_pokemon;
    pokeArr = new Pokemon[num_pokemon];
    readDatabase(ifile, pokeArr, num_pokemon);

    string userKey;
    cout << "Enter a pokemon name: ";
    cin >> userKey;
    int foundIndex = searchDatabase(userKey, pokeArr, num_pokemon);
    if (foundIndex >= 0)
    {
        printPokemon(pokeArr[foundIndex]);
    }
    else
    {
        cout << "That pokemon doesn't exist... :(\n";
    }

    ifile.close();
    return 0;
}

void readDatabase(ifstream &file, Pokemon *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        file >> list[i].id >> list[i].name >> list[i].type1 >> list[i].type2;
        file >> list[i].hp >> list[i].attack >> list[i].defense;
        file >> list[i].special_attack >> list[i].special_defense >> list[i].speed;
    }
}

int searchDatabase(string key_name, Pokemon *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (key_name == list[i].name)
        {
            return i;
        }
    }
    return -1;
}

void printPokemon(Pokemon p)
{
    cout << string(40, '*') << '\n';
    cout << p.id << ": " << p.name << '\n';
    cout << p.type1 << ' ' << p.type2 << '\n';
    cout << p.hp << ' ' << p.attack << ' ' << p.defense << ' ';
    cout << p.special_attack << ' ' << p.special_defense << ' ';
    cout << p.speed << '\n';
    cout << string(40, '*') << '\n';
}

void printPokemonList(Pokemon *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printPokemon(list[i]);
    }
}