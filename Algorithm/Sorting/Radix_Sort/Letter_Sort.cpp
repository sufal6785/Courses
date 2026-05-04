#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// key: ' ' -> 0, 'a'..'z' -> 1..26
int key_at_pos_with_leading_space(const string &s, int max_len, int pos)
{
    int idx = (int)s.size() - max_len + pos; // map to left-padded position
    if (idx < 0) return 0;                   // leading space
    char ch = (char)tolower((unsigned char)s[idx]);
    if (ch < 'a' || ch > 'z') return 0;      // treat non-letters as space
    return ch - 'a' + 1;
}

void count_sort(vector<string> &v, int pos, int max_len)
{
    int n = (int)v.size();
    vector<string> result(n);
    vector<int> count(27, 0);

    for (int i = 0; i < n; i++)
    {
        int k = key_at_pos_with_leading_space(v[i], max_len, pos);
        count[k]++;
    }

    for (int i = 1; i < 27; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int k = key_at_pos_with_leading_space(v[i], max_len, pos);
        result[--count[k]] = v[i];
    }

    v = result;
}

void radix_sort(vector<string> &v)
{
    int max_len = 0;
    for (const string &s : v) max_len = max(max_len, (int)s.size());

    // LSD: rightmost to leftmost
    for (int pos = max_len - 1; pos >= 0; pos--)
    {
        count_sort(v, pos, max_len);
    }
}

int main()
{
    vector<string> v = {"apple", "banana", "grape", "fig", "kiwi", "cherry"};
    radix_sort(v);

    for (const string &s : v) cout << s << '\n';
    return 0;
}