#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
private:
  vector<char> str;
  char ch_num[256];
  
public:
  void Insert(char ch)
  {
	str.push_back(ch);
	ch_num[ch]++;
	
  }

  char firstAppearingonce()
  {
    cout<<"str";
    for(int i=0;i<str.size();i++)
      cout<<str[i]<<" ";
    cout<<endl;
    int i = 0;
    for(i=0;i<str.size();i++)
    {
      if (ch_num[str[i]] == 1)
	  break;

    }
    if (i<str.size())
      return str[i];
    else
      return '#';	
      }
};
int main()
{
    
  Solution solution;
  solution.Insert('g');
  cout<<solution.firstAppearingonce()<<endl;
  solution.Insert('o');
  cout<<solution.firstAppearingonce()<<endl;
  solution.Insert('o');
  cout<<solution.firstAppearingonce()<<endl;
  solution.Insert('g');
  cout<<solution.firstAppearingonce()<<endl;
  solution.Insert('l');
  cout<<solution.firstAppearingonce()<<endl;
  solution.Insert('e');
  cout<<solution.firstAppearingonce()<<endl;
  
  
  return 0;
}


