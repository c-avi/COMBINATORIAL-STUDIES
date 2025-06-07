#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize frequency count with maximum values
        vector<int> minFreq(26, INT_MAX);

        for (const string& word : words) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (minFreq[i]-- > 0) {
                result.push_back(string(1, i + 'a'));
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    int n;
    
    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter " << n << " words:\n";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        words.push_back(s);
    }

    vector<string> result = sol.commonChars(words);
    
    cout << "Common characters: ";
    for (const string& ch : result) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}
