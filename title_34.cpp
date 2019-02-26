#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int charNum[52]={0};
        int charPos[52]={0};
        for(int i=0;i<str.length();i++)
        {
            if ('A'<=str[i] && str[i]<='Z')
            {
                if (charNum[str[i]-'A'] == 0)
                    charPos[str[i]-'A'] = i;
                charNum[str[i]-'A']++;

            }
            else if ('a'<=str[i] && str[i]<='z')
            {
                if (charNum[str[i]-'a'+26] == 0)
                    charPos[str[i]-'a'+26] = i;
                charNum[str[i]-'a'+26]++;
            }
        }
        int min = 10001;
        for(int i=0;i<52;i++)
        {
            if (charNum[i] == 1)
            {
                if (charPos[i] < min)
                    min = charPos[i];
            }
        }
        return (min == 10001) ? -1:min+1;
    }
};

int main()
{
    Solution solution;
    cout<<solution.FirstNotRepeatingChar("aaabbbcdddef");
    return 0;

}
