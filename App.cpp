#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        // only 1 letter
        if (s.length() <= 1)
        {
            return true;
        }

        // pointers
        int front_pointer = 0;
        int end_pointer = s.length() - 1;

        // while the front pointer is on the left side of the end pointer
        while (front_pointer < end_pointer)
        {
            // if character is NOT alphanumeric
            // helps move forward, skipping over any non alphanumeric characters
            while (front_pointer < end_pointer && !isalnum(s[front_pointer]))
            {
                front_pointer++;
            }

            // if character is NOT alphanumeric
            // helps move back, skipping any non alphanumeric characters
            while (front_pointer < end_pointer && !isalnum(s[end_pointer]))
            {
                end_pointer--;
            }

            // characters do NOT match : return false
            if (front_pointer < end_pointer && tolower(s[front_pointer]) != tolower(s[end_pointer]))
            {
                return false;
            }

            // increment
            front_pointer++;
            // decrement
            end_pointer--;
        }

        // if we make it to this point, return true
        return true;
    }
};

int main()
{
    Solution solution;
    string example_one = "A man, a plan, a canal: Panama";
    string example_two = "race a car";
    string example_three = " ";

    cout << "Example One : " << solution.isPalindrome(example_one) << endl;
    cout << "Example Two : " << solution.isPalindrome(example_two) << endl;
    cout << "Example Three : " << solution.isPalindrome(example_three) << endl;
	return 0;
}
