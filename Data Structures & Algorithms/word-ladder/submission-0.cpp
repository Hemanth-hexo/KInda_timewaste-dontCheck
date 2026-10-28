#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm> // Not strictly needed for this solution, but good practice for general C++

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        // Use an unordered_set for O(1) average time complexity for word lookups and deletions.
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());

        // If the endWord is not in the dictionary, it's impossible to reach it.
        // Return 0 immediately.
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        // BFS queue: stores pairs of {word, level}.
        // The level represents the number of words in the transformation sequence so far.
        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1}); // Start with beginWord at level 1.

        // If beginWord is in the wordList, remove it from the dictionary.
        // This marks it as visited and prevents cycles or redundant processing.
        // If beginWord is not in wordList, it won't be in dict, so this check is safe.
        if (dict.count(beginWord)) {
            dict.erase(beginWord);
        }

        // Perform BFS
        while (!q.empty()) {
            std::string currentWord = q.front().first;
            int currentLevel = q.front().second;
            q.pop();

            // If we reached the endWord, return the current level
            if (currentWord == endWord) {
                return currentLevel;
            }

            // Generate all possible next words by changing one character at a time
            for (int i = 0; i < currentWord.length(); ++i) {
                char originalChar = currentWord[i]; // Store original character to revert later

                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue; // Skip if character is the same, no change

                    currentWord[i] = c; // Change character at position i

                    // Check if the new word is in our dictionary (wordList)
                    if (dict.count(currentWord)) {
                        q.push({currentWord, currentLevel + 1});
                        dict.erase(currentWord); // Mark as visited by removing from dict
                    }
                }
                currentWord[i] = originalChar; // Revert the character change for the next position
            }
        }

        // If the queue becomes empty and endWord was not reached, no sequence exists.
        return 0;
    }
};