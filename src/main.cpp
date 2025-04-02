#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

#if __cplusplus < 201103L
    #error "This source requires C++ 11 and greater."
#endif

// Helper func for clearing the terminal
//
// - \x1b[2J    Erase entire frame
// - \x1b[0m    Reset all colour modes
// - \x1b[H     Set cursor to (0,0)
void clear_terminal() {
    std::cout << "\x1b[2J\x1b[0m\x1b[H";
}

int main() {
    // Variable setup
    int target_time_hours;
    int target_time_minutes;
    bool alarm_active = false;

    // TUI goofiness - should be improved at some point...
    clear_terminal();
    std::cout << "========================\n";
    std::cout << "C++ MedReminder (24h)\n";
    std::cout << "========================\n";
    std::cout << "\nInsert the target hour: ";
    std::cin >> target_time_hours;
    std::cout << "========================\n";
    std::cout << "C++ MedReminder (24h)\n";
    std::cout << "========================\n";
    std::cout << "\nInsert the target min: " << target_time_hours << ":";
    std::cin >> target_time_minutes;

    // Time checking
    if (target_time_hours > 23 || target_time_hours < 0 || target_time_minutes > 59 || target_time_minutes < 0) {
        clear_terminal();
        std::cerr << "Fatal: Time settings are invalid!" << std::endl;
        return -1;
    }
    
    // Time looks good, setup a realtime clock and start ticking...
    // std::chrono reference -> // https://en.cppreference.com/w/cpp/chrono
    while (!alarm_active) {
        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        std::tm *curr_time = std::localtime(&now_time);

        // Terminal setup, simple and works!
        // setw     -> https://cplusplus.com/reference/iomanip/setw/
        // setfill  -> https://en.cppreference.com/w/cpp/io/manip/setfill

        clear_terminal();
        std::cout << "## Reminder set for " 
                  << std::setw(2) << std::setfill('0') << target_time_hours << ":"
                  << std::setw(2) << std::setfill('0') << target_time_minutes << ".\n";

        std::cout << "## Current time: " 
                  << std::setw(2) << std::setfill('0') << curr_time->tm_hour << ":"
                  << std::setw(2) << std::setfill('0') << curr_time->tm_min << ":"
                  << std::setw(2) << std::setfill('0') << curr_time->tm_sec << "\n";

        if (curr_time->tm_hour == target_time_hours && curr_time->tm_min == target_time_minutes) {
            alarm_active = true;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // If we're here, then the alarm is going off!
    std::cout << "\nTime reached: " 
              << std::setw(2) << std::setfill('0') << target_time_hours << ":"
              << std::setw(2) << std::setfill('0') << target_time_minutes 
              << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}