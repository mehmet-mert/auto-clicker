#include <iostream>
#include <windows.h>

using namespace std;

int x=0, y=0, cps;
bool click=false;

void menu()
{
    cout << "Start with 'W' and stop with 'Q'" << endl;
    cout << "How many clicks per second: " ;
    cin >> cps;
    cout << "CPS(clicks per second) set to " << cps<< endl;
}
void clicker()
{
    while(1)
    {
        if(GetAsyncKeyState(0x57)) // W
        {
            click=true;
        }
        if(GetAsyncKeyState(0x51)) // Q
        {
            click=false;
        }
        if (click == true){
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
            Sleep(1000/cps);
        }
    }
}
int main()
{
    menu();
    clicker();
}



