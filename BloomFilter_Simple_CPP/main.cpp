#include "BloomFilter.h"
#include <iostream>
#include <string>
#include <cctype>

bool validId(const std::string& id) {
    if (id.empty() || id.size() > 20) return false;
    for (unsigned char ch : id) {
        if (!std::isalnum(ch)) return false;
    }
    return true;
}

int main() {
    BloomFilter filter(16);
    int choice = 0;

    std::cout << "=== Fast Transaction / Member ID Checker ===\n";

    while (true) {
        std::cout << "\n1. Add transaction/member ID\n"
                  << "2. Check an ID\n"
                  << "3. Display Bloom Filter\n"
                  << "4. Exit\n"
                  << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a menu number.\n";
            return 0;
        }

        if (choice == 1) {
            std::string id;
            std::cout << "Enter an ID (letters and numbers only, max 20 characters): ";
            std::cin >> id;
            if (!validId(id)) {
                std::cout << "Invalid ID. Use 1-20 letters or numbers, with no spaces or symbols.\n";
                continue;
            }
            filter.add(id);
            std::cout << "ID added to the Bloom Filter.\n";
        } else if (choice == 2) {
            std::string id;
            std::cout << "Enter an ID to check: ";
            std::cin >> id;
            if (!validId(id)) {
                std::cout << "Invalid ID. Use 1-20 letters or numbers, with no spaces or symbols.\n";
                continue;
            }
            if (filter.mightContain(id)) {
                std::cout << "Result: This ID MIGHT exist (possible match).\n"
                          << "A Bloom Filter can give false positives, so verify with the real database.\n";
            } else {
                std::cout << "Result: This ID is DEFINITELY NOT in the filter.\n";
            }
        } else if (choice == 3) {
            filter.display();
        } else if (choice == 4) {
            std::cout << "Goodbye!\n";
            break;
        } else {
            std::cout << "Please choose 1, 2, 3, or 4.\n";
        }
    }
    return 0;
}
