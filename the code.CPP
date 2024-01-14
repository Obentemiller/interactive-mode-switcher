#include <iostream>
#include <thread>
#include <conio.h>
#include <vector>

/*
* Execution plan:
* The program allows the user to interactively select modes using arrow keys.
* The selected modes are displayed on the console.
*/

std::vector<int> mode{ 1, 1 }; // Initializes with 1, as it seems to be the initial value in your original code

// Function for interactive mode selection using arrow keys
static void select_mode() {
    char ch;

    int n_modes = 5;
    do {
        ch = _getch();

        switch (ch) {
        case 72: // Up Arrow (↑)
            mode[1] = (mode[1] % n_modes) + 1;
            break;
        case 80: // Down Arrow (↓)
            if (mode[1] <= 1) {
                mode[1] = n_modes;
            }
            else {
                mode[1]--;
            }
            break;
        case 75: // Left Arrow (←)
            mode[0] = (mode[0] % n_modes) + 1;
            break;
        case 77: // Right Arrow (→)
            if (mode[0] <= 1) {
                mode[0] = n_modes;
            }
            else {
                mode[0]--;
            }
            break;
        default:
            break;
        }

    } while (ch != 'q');
}

// Function to display the selected modes on the console
static void graphic_mode(const std::vector<int>& modes) {
    system("cls");
    switch (modes[0]) {
    case 1:
        std::cout << "<mode 1>";
        break;
    case 2:
        std::cout << "<mode 2>";
        break;
    case 3:
        std::cout << "<mode 3>";
        break;
    default:
        std::cout << "<select a mode>";
        break;
    }
    std::cout << " | ";
    switch (modes[1]) {
    case 1:
        std::cout << "<mode 1>";
        break;
    case 2:
        std::cout << "<mode 2>";
        break;
    case 3:
        std::cout << "<mode 3>";
        break;
    default:
        std::cout << "<select a mode>";
        break;
    }
    std::cout << "\r";
}

// Main function
int main() {
    std::thread myThread(select_mode);

    // Continuously display the selected modes on the console
    while (mode[0] != 0 && mode[1] != 0) {
        graphic_mode(mode);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Wait for a short period to avoid overwhelming the display
    }

    myThread.join();

    return 0;
}
