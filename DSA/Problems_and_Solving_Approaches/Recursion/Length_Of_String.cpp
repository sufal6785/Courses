#include <iostream>
#include <string>
using namespace std;

class StringLength {
public:
    // Method 1: Using character array (C-style string)
    int lengthRecursive(char str[], int index = 0) {
        // Base case: if we reach null terminator
        if (str[index] == '\0') {
            return 0;
        }
        
        // Recursive case: 1 + length of remaining string
        return 1 + lengthRecursive(str, index + 1);
    }
    
    // Method 2: Using string object with index
    int lengthRecursive(const string& str, int index = 0) {
        // Base case: if we reach end of string
        if (index >= str.length()) {
            return 0;
        }
        
        // Recursive case: 1 + length of remaining string
        return 1 + lengthRecursive(str, index + 1);
    }
    
    // Method 3: Using substring (less efficient but elegant)
    int lengthRecursiveSubstring(const string& str) {
        // Base case: empty string
        if (str.empty()) {
            return 0;
        }
        
        // Recursive case: 1 + length of substring from position 1
        return 1 + lengthRecursiveSubstring(str.substr(1));
    }
    
    // Method 4: Using pointer arithmetic (advanced)
    int lengthRecursivePointer(const char* str) {
        // Base case: null character
        if (*str == '\0') {
            return 0;
        }
        
        // Recursive case: 1 + length of string starting from next character
        return 1 + lengthRecursivePointer(str + 1);
    }
    
    // Method 5: Tail recursive version (more efficient)
    int lengthTailRecursive(const string& str, int index = 0, int count = 0) {
        // Base case: reached end of string
        if (index >= str.length()) {
            return count;
        }
        
        // Tail recursive call: accumulate count
        return lengthTailRecursive(str, index + 1, count + 1);
    }
};
