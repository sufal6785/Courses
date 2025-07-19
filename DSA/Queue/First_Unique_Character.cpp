#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> frq;
        queue<pair<char, int>> q;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            frq[ch]++;
            q.push({ch, i});

            while (!q.empty() && frq[q.front().first] > 1)
            {
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front().second;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> frq;
        for (char ch : s)
        {
            frq[ch]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (frq[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> frq;
        queue<int> q;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            frq[ch]++;
            q.push(i);

            while (!q.empty() && frq[s[q.front()]] > 1)
            {
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};