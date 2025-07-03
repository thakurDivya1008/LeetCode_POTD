//************GOVIND**********/

//MOTIVATION: PUSH YOURSELF BECAUSE NO ONE ELSE IS GOING TO DO IT FOR YOU.

// ***** QUESTION DESCRIPTION *****//

// LEETCODE - 3304, Easy Marked, Topic - String

// Alice and Bob are playing a game. Initially, Alice has a string word = "a".

// You are given a positive integer k.

// Now Bob will ask Alice to perform the following operation forever:

// Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
// For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

// Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

// Note that the character 'z' can be changed to 'a' in the operation.

 

// Example 1:

// Input: k = 5

// Output: "b"

// Explanation:

// Initially, word = "a". We need to do the operation three times:

// Generated string is "b", word becomes "ab".
// Generated string is "bc", word becomes "abbc".
// Generated string is "bccd", word becomes "abbcbccd".
// Example 2:

// Input: k = 10

// Output: "c"

 

// Constraints:

// 1 <= k <= 500



//*************** SOLUTION *********//

//#APPROACH :- 

//1st :

//Here as you can see there is low constraint so, here you can generate a new string every time. that's why the BROOT FORCE solution can be : -

// as we've given the first character is 'a'. so, we apply a loop till the our string length would become greater than or equals to k;

// Inside it we apply a loop on string for generating a new next string by (char)(((ch-'a' + 1) % 26) + 'a');

//here  the line (char)(((ch-'a' + 1) % 26) + 'a');

// (ch - 'a')          // Get zero-based index of the character
//                    // Example: 'c' - 'a' = 2
// cpp
// Copy
// Edit
// (ch - 'a' + 1)      // Move to the next character
//                    // Example: 2 + 1 = 3 (which is 'd')
// cpp
// Copy
// Edit
// (ch - 'a' + 1) % 26 // Wrap around after 'z'
//                    // Example: 'z' - 'a' = 25 → 25 + 1 = 26 → 26 % 26 = 0 → 'a'
// cpp
// Copy
// Edit
// ((ch - 'a' + 1) % 26) + 'a'  // Convert back to character
//                             // Example: 3 + 'a' = 'd'
// cpp
// Copy
// Edit
// (char)(((ch - 'a' + 1) % 26) + 'a') // Cast to char
// cpp
// Copy
// Edit
// next_part += ...; // Append the new character to the string
// 🔄 Example:
// If ch = 'y'
// → 'y' - 'a' = 24
// → 24 + 1 = 25
// → 25 % 26 = 25
// → 25 + 'a' = 'z'

// If ch = 'z'
// → 'z' - 'a' = 25
// → 25 + 1 = 26
// → 26 % 26 = 0
// → 0 + 'a' = 'a' ✅ wrap-around!




// after geenrating the new string, we will add a new string to the original one.

// after the loop ended we return the k-1th index of charcter from the string .


//***** CODE: - */

#include<iostream>
using namespace std;


char kthCharacter(int k) {
        
        string res = "a";
        while(res.length() <= k){
           string next = "";

           for(char ch: res){
             next += (char)(((ch-'a' + 1) % 26) + 'a');
           }

           res += next;

        }

         return res[k-1];
    }

    int main(){
        int k;
    cout << "Enter the value of k: ";
    cin >> k;

    char result = kthCharacter(k);
    cout << "The " << k << "th character in the transformed string is: " << result << endl;

    return 0;
    }


    //OUTPUT : 
    //Enter the value of k: 7
//The 7th character in the transformed string is: c


//Time & Space Complexity : 
// | Aspect           | Complexity |
// | ---------------- | ---------- |
// | Time Complexity  | O(k)       |
// | Space Complexity | O(k)       |



// 2nd approach - BETTER SOLUTION

// 🧠 Observation:
// Each operation doubles the size of the string:

// word = "a"

// 1st op → "a" + "b" = "ab"

// 2nd op → "ab" + "bc" = "abbc"

// 3rd op → "abbc" + "bccd" = "abbcbccd"

// 4th op → "abbcbccd" + "bcccddee" = ...

// 🧠 Key Insight (Efficient solution using Recursion or Simulation):
// Instead of generating the full string, we can simulate backward.

// Let's say:
// The string becomes S after n operations.

// At any point:

// ini
// Copy
// Edit
// S = original + next(S)
// So, to find k-th character:

// If k <= original.size(), stay in left half.

// If k > original.size(), move to right half:

// Right half is created from original using next_char(c)

// So recurse with k - original.size() on previous level

// And then prev_char = solve(k - len/2), and return next_char(prev_char)

// ✅ C++ Code:
#include <iostream>
using namespace std;

// Helper to get the next character in alphabet with wrap-around
char nextChar(char c) {
    return (c == 'z') ? 'a' : c + 1;
}

// Recursive function to find the kth character
char findKthChar(int k) {
    if (k == 1)
        return 'a';

    int len = 1; // initial length of "a"
    // Find the smallest length >= k
    while (len < k) {
        len *= 2;
    }

    // Go back in recursion
    if (k <= len / 2) {
        return findKthChar(k); // left half is same as previous string
    } else {
        char prevChar = findKthChar(k - len / 2); // map to previous
        return nextChar(prevChar); // and take next char
    }
}

int main() {
    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "The " << k << "th character is: " << findKthChar(k) << endl;

    return 0;
}
// 🧪 Example:
// If k = 7:


// word becomes → "abbcbccd"
// 7th character = 'c'
// 💡 Time Complexity:
// O(log k) – each step we reduce the size by half.

