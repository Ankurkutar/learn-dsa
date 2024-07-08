#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.empty())
            return -1;
        if (needle.empty())
            return 0;

        int hSize = haystack.size();
        int nSize = needle.size();

        for(int i=0; i<= hSize - nSize; i++){
            if(haystack.substr(i, nSize) == needle){
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;

    string haystack = "sadbutsad";
    string needle = "sad";

    int result = solution.strStr(haystack, needle);
    cout << "The index of the first occurrence of needle in haystack is: " << result << endl;

    return 0;
}