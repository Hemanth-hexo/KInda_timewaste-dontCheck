#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        if (dict.count(beginWord)) {
            dict.erase(beginWord);
        }
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            if (curr == endWord) {
                return steps;
            }
            for (int i = 0; i < curr.size(); ++i) {
                char original = curr[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == original) continue;
                    curr[i] = c;
                    if (dict.count(curr)) {
                        dict.erase(curr);
                        q.push({curr, steps + 1});
                    }
                }
                curr[i] = original;
            }
        }
        return 0;
    }
};