// Check whether a number is a happy number.
// A number is said to be happy if we first divide it into each specific digit.
// We then square each digit are added.
// We repeat with the result.
// If we ever get a result that is equal to 1, then the number is happy.
// EX: n = 19. 1^2 + 9^2 = 82. 8^2 + 2^2 = 68. 6^2 + 8^2 = 100. 1^2 + 0^2 + 0^2 = 1.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

int main (int argc, char* argv[]) {

    // Power to which we will raise each digit of an input.
    const int powerOf = 2;

    std::string inputString;

    // The int representation of the user input.
    int input;
    // Used to know the sum of each digit square for each iteration.
    int result = 0;
    
    bool isHappy = false;
    bool inLoop = false;

    // Set used to keep track of the results we have seen already.
    // This way we can tell when we are stuck in a loop.
    std::set<int> numberSeen;

    std::cout << "Please enter an integer to check if it is happy" << std::endl;

    std::cin >> inputString;

    // TO-DO: check to see if String can be converted.
    // Convert string to int.
    input = stoi(inputString);

    // By using a Do-while loop we will always try the input first.
    do 
    {
        result = 0;

        while (input > 0) {

            // Constantly mod by 10 to get the current lastDigit.
            int lastDigit = input % 10;

            result += (std::pow(lastDigit, powerOf));

            // Use concatenation to get rid of the remainder.
            input /= 10;
        }
        
        // If we found the element, since we did not go all the way past the last element.
        if (auto search = numberSeen.find(result); search != numberSeen.end()) {

            // We are stuck in a loop and the number is not happy. Stop the calculations.
            inLoop = true;
            break;
        
        }

        else {
            // Push the number we just saw 
            numberSeen.insert(result);

            // Set the result as the input to enter the previous while loop (input > 0)
            input = result;
        }
        
    // Stop only if we found that the number is happy or that we are in an infinite loop.
    } while (result != 1 && !inLoop);
    
    isHappy = (result == 1 && !inLoop);

    std::cout << "The number " << inputString << " is";
    isHappy ? std::cout << " " : std::cout << " not ";

    std::cout << "a happy number." << std::endl;

    return 0;
}