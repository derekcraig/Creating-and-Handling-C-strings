/*
CS10B - Professor Harden

Creating and Handling C-strings

Date: 10/14/2023

Programmer: Derek Craig
*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;






/*
This function takes a c-string and a "target" char as a parameter and returns
the last instance of that char in the c-string. It uses a while loop terminated
by a null character to iterate through the c-string and a nested if loop 
updates lastIndex with the current index if it matches the target char.
If the target char is not found, it returns -1 which is the initiated value of
lastIndex.
*/

int lastIndexOf(const char* inString, char target) {
    int lastIndex = -1;
    int i = 0;

    while( inString[i] != '\0' ) {
        if( inString[i] == target ) {
            lastIndex = i;
        }
        i++;
    }

    return lastIndex;
}






/*
This function takes a c-string and reverses it. It uses strlen() to get the
length of the c-string so that the while loop can iterate through half of the
it, ignoring the middle character if it is an odd length. At each instance
it uses the swap() function to swap the current index character with the
opposite index using the string length again and subtracting the (current index
-1) to get the opposite index.
*/

void reverse(char* inString) {
    int strLength = strlen( inString );
    int i = 0;

    while( i < strLength / 2 ) {
        swap( inString[i], inString[strLength - i - 1] );
        i++;
    }
}






/*
This function takes a c-string, a "target" char, and a char for it to be 
replaced by and does so. It also counts and returns the number of char
replaced. It uses a while loop terminated by a null character to iterate
through the c-string and a nested if statement to check the current index for
the target char. If found, it incriments replacementsMade and replaces the char
at the current index with replacementChar.
*/

int replace(char* inString, char target, char replacementChar) {
    int replacementsMade = 0;
    int i = 0;

    while( inString[i] != '\0' ) {
        if( inString[i] == target ) {
            replacementsMade++;
            inString[i] = replacementChar;
        }
        i++;
    }

    return replacementsMade;
}






/*
This function takes a c-string as a parameter and checks to see if it is a
special case palindrome, returning a bool value. It uses two loop index
counters, one set to zero and the other set to (strlen() -1), to iterate
through the c-string backward and foreword one char at a time. A while loop
iterates until the foreword counting index is greater than or equal to the
backward counting one. tolower() is used on each char at the separate index's
to convert them to lowercase (so we don't have to worry about case
sensitivity). A nested if statement checks that the current foreword and 
backward index characters are the same. If they are, the if statement 
increments the foreword index counter and decriments the backward one. If any 
iteration is found to be not the same, the function returns false.
*/

bool isPalindrome(const char* inString) {
    int i = 0;
    int j = strlen( inString ) - 1;

    while( i <= j ) {
        char fromLeft = tolower( inString[i] );
        char fromRight = tolower( inString[j] );

        if( fromLeft != fromRight ) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}






/*
This function takes a c-string as a parameter and capitalizes each character in
it. It uses a while loop terminated by a null character to iterate through the
c-string and uses toupper() at each instance to capitalize the current index.
*/

void toupper(char* inString) {
    int i = 0;

    while( inString[i] != '\0' ) {
        inString[i] = toupper( inString[i] );
        i++;
    }
}





/*
This function takes a c-string as a parameter and returns the number of letters
in it. A while loop terminated by a null character iterates through
the c-string with a nested if loop to check the current index using isalpha(), 
if it is, numLetters is incrimented.
*/

int numLetters(const char* inString) {
    int i = 0;
    int numLetters = 0;

    while( inString[i] != '\0' ) {
        if( isalpha( inString[i] ) ) {
            numLetters++;
        }
        i++;
    }

    return numLetters;
}






int main() {
    int i = 0;
    int result = 0;
    bool boolResult = false;
    char findChar = 'a';
    char replaceThis = 'a';
    char replacedWith = 'A';

    char reversedString[100];
    char replacedString[100];

    const char* testStrings[] = {
        "A man, a plan, a canal, Panama!",
        "racecar",
        "hello world",
        "!232!",
        "C++ is fun!",
        "abc cba",
        "",
        " ",
        "A",
        "123",
        nullptr
    };

while ( testStrings[i] != nullptr ) {
    const char* testString = testStrings[i];

        cout << endl << "Testing: " << "\"" << testString << "\"" << endl;

        result = lastIndexOf( testString, findChar );
        cout << "lastIndexOf \"" << findChar << "\": " << result << endl;

        strcpy( reversedString, testString );
        reverse( reversedString) ;
        cout << "reverse: " << "\"" << reversedString << "\""  << endl;

        strcpy( replacedString, testString );
        result = replace( replacedString, replaceThis, replacedWith );
        cout << "replace \"" << replaceThis << "\" with \"" << replacedWith 
             << "\" -> " << result << " replacements made: " << endl;
        cout << "\"" << replacedString << "\"" << endl;

        boolResult = isPalindrome( testString );
        cout << "isPalindrome: ";
        if( boolResult ) { 
            cout << "yes" << endl; 
        } else { cout << "no" << endl; 
        };

        char upperString[100];
        strcpy( upperString, testString );
        toupper( upperString );
        cout << "toupper: " << "\"" << upperString << "\"" << endl;

        result = numLetters( testString );
        cout << "numLetters: " << "\"" << result << "\"" << endl;

        cout << endl;
        i++;
    }

    return 0;
}
