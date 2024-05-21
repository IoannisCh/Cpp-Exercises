#include <iostream>
#include <cstdlib> // For system()

int main() {
    int choice;

    while (true) {
        std::cout << "====== System Information ======" << std::endl;
        std::cout << "1. Display CPU Info" << std::endl;
        std::cout << "2. Display Memory Info" << std::endl;
        std::cout << "3. Display Disk Usage" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cat /proc/cpuinfo");
                break;
            case 2:
                system("free -m");
                break;
            case 3:
                system("df -h");
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        // Wait for user to press Enter before clearing the screen
        std::cout << "Press Enter to continue...";
        std::cin.ignore(); // Clear newline
        std::cin.get();    // Wait for Enter
        system("clear");   // Clear the screen (Linux)
    }

    return 0;
}
