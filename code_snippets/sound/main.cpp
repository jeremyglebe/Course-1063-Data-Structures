// MUST LINK: winmm.lib
// #pragma comment(lib, "Winmm.lib")
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

int main()
{
    PlaySound("forest.wav", NULL, SND_FILENAME | SND_ASYNC);
    cin.get();
}