#include <iostream>
#include <cstdlib> // For system()
#include <ncurses.h>
#include <curl/curl.h>

void initialize_curl() {
    CURL *curl;
    CURLcode res;

    // Initialize CURL globally
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialize a CURL session
    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the CURL session
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // Cleanup the CURL session
        curl_easy_cleanup(curl);
    }

    // Cleanup CURL globally
    curl_global_cleanup();
}

void initialize_ncurses() {
    // Initialize ncurses
    initscr();
    printw("Hello World"); // Example of ncurses output
    refresh();
    getch();
    endwin();
}

int main() {
    // Initialize CURL and ncurses
    initialize_curl();
    initialize_ncurses();

    int choice;

    while (true) {
        std::cout << "====== System Information ======" << std::endl;
        std::cout << "1. Display CPU Info" << std::endl;
        std::cout << "2. Display Memory Info" << std::endl;
        std::cout << "3. Display Disk Usage" << std::endl;
        std::cout << "4. Display uptime" << std::endl;
        std::cout << "5. Display user" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cat /proc/cpuinfo > cpuinfo.log");
                break;
            case 2:
                system("free -m");
                break;
            case 3:
                system("df -h");
                break;
            case 4:
                system("uptime");
                break;
            case 5:
                system("who");
                break;
            case 6:
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
