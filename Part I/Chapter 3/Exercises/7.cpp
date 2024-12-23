/*
    Make a vector holding the ten string values "zero", "one", . . . "nine". 
    Use that in a program that converts a digit to its corresponding spelled-out value; e.g., the input 7 gives the output seven. 
    Have the same program, using the same input loop, convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find

int main() {
    // Create a vector to store the spelled-out values of digits
    std::vector<std::string> digit_words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Inform the user about the program's functionality
    std::cout << "This program converts digits to spelled-out numbers and vice versa.\n";
    std::cout << "Enter a single digit (0-9) or a spelled-out number (e.g., 'seven'). Enter 'exit' to quit.\n\n";

    std::string input;

    while (true) {
        // Prompt the user for input
        std::cout << "Enter input: ";
        std::cin >> input;

        // Exit the loop if the user types 'exit'
        if (input == "exit") {
            break;
        }

        // Check if the input is a digit (0-9)
        if (input.size() == 1 && isdigit(input[0])) {
            // Convert character to integer
            int digit = input[0] - '0';
            // Output the corresponding spelled-out value
            std::cout << "The spelled-out number is: " << digit_words[digit] << "\n\n";
        } else {
            // Try to find the input in the vector of digit words
            auto it = std::find(digit_words.begin(), digit_words.end(), input);

            if (it != digit_words.end()) {
                // Calculate the index of the found element
                int index = it - digit_words.begin();
                // Output the corresponding digit
                std::cout << "The digit is: " << index << "\n\n";
            } else {
                // Handle invalid input
                std::cout << "Invalid input. Please enter a single digit or a spelled-out number.\n\n";
            }
        }
    }

    std::cout << "Program terminated. Goodbye!\n";
    return 0;
}
