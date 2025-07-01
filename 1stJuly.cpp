//***********GOVIND************//

//       QUESTION DESCRIPTION     //

// Motivation : Push yourself because no one else is going to do it for you.


// LeetCode - 3330  Find the Original typed String I
// Easy marked; Topics - String 

// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

// Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

// You are given a string word, which represents the final output displayed on Alice's screen.

// Return the total number of possible original strings that Alice might have intended to type.

 

// Example 1:

// Input: word = "abbcccc"

// Output: 5

// Explanation:

// The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

// Example 2:

// Input: word = "abcd"

// Output: 1

// Explanation:

// The only possible string is "abcd".

// Example 3:

// Input: word = "aaaa"

// Output: 4

 

// Constraints:

// 1 <= word.length <= 100
// word consists only of lowercase English letters.


//*************** SOLUTION *********//

//#APPROACH :- 

//  here in this problem  1st observation is i have atleast 1 possible string (original String) in every cases which alice might intended to type. It's possible that she might not have done any mistake anytime.because there is given ( she is aware that she may still have done this **at most** once.),

//2nd - For every repeating charcter there is a possiblity that she might press a key multiple times.

//3rd - the duplicate charcter will be together.

//so, here i take a count starting from 1; and apply a loop on given string starting from 1 index if anywhere i found that there is two similar characters repeated with (i-1)index i will increase value of cnt by 1.


//CODE :-

#include<iostream>
using namespace std;

class Solution {
    public: 

    int PossibleStringCount(string word){
         int n = word.size();
         int cnt = 1;

         for(int i = 1; i<n;  i++){

            if(word[i] == word[i-1]){
                cnt++;
            }
         }

         return cnt;
    }
};

int main(){

    Solution sol;

    string input;
    cout<<"Enter a string :";
    cin>>input;

    int result = sol.PossibleStringCount(input);
    cout<< "Count of consecutive character is : " << result << endl;

    return 0;


}

//OUTPUT : 

// Enter a string :abbssss
// Count of consecutive character is : 5


//Time & Space Complexity:
//T.C -> O(n)
//S.C -> O(1)


