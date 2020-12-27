#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>

using namespace std;
//Default Period and symbols
long period = 400;
string symbol = "=";
string symbol_end = ">";
//////////////////////////////
int max_statusbar_length = 20;
int process_space_count = 0;
string spaces = "";
string statusbar = "";
int process_count = 0;
int percent = 0;
//////////////////////////////

void run() {
    process_count = percent / 5;
    statusbar = "";
    spaces = "";

    for (int num = 0; num < process_count; num++) {
        if (symbol.length() > 1) {
            statusbar += " " + symbol;
        }
        else {
            statusbar += symbol;
        }
    }
    
    process_space_count = max_statusbar_length - process_count;
    
    for (int num = 0; num < process_space_count; num++) {
        spaces += " ";
    }
    
    percent += 3;
    
    if (percent > 100) {
        percent = 100;
    }
    
    cout << "Load complete at " << percent << "% ";
    
    if (percent < 10) {
        cout << "  ";
    }
    
    if (percent >= 10 && percent < 100) {
        cout << " ";
    }
    
    cout << "[" << statusbar << symbol_end << spaces << "] [" << process_count << "] \r";
}
int main() {
    //*************************************************************************************************
    process_count = percent / 5;
    process_space_count = max_statusbar_length - process_count;
    
    for (int num = 0; num < process_space_count + 1; num++) {
        spaces += " ";
    }
    
    cout << "Load complete at " << percent << "%   [" << spaces << "] [" << process_count << "]\r";
    
    //*************************************************************************************************
    
    while (true) {
        Sleep(period);
        run();
        
        if (percent >= 100) {
            cout << "Load complete at 100% [" << statusbar << symbol << symbol_end << "] [" << (process_count + 1) << "]" << endl << endl;
            system("pause");
            return 0;
        }
    
    }

}
