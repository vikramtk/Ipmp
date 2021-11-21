/* "Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. Example
Input: tact coa
Output: true 
Input can be rearranged as taco cat" */

#include<bits/stdc++.h>
using namespace std;

void ispalindrome(string s)
{
    int check=0,temp=0;
    
    for(int i=0;i<s.length();i++)
    {
        int bitatindex=s[i]-'a';
        check=check ^ (1<<bitatindex);
    }
    
    for(int i=0;i<26;i++)
    {
        if(check&(1<<i))
        temp++;
    }
    if(check==0 || temp==1)
    cout<<"\nPalindrome";
    else
    cout<<"\nNot a palindrome";
}

int main()
{
    string s="malayalam";
    ispalindrome(s);
    
    s="aabcdbdc";
    ispalindrome(s);
    
    s="cgsg";
    ispalindrome(s);
    return 0;
}
