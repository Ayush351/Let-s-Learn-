/*
Firstly, we start by creating a queue data structure in order to store the word 
and the length of the sequence to reach that word as a pair. We store them in 
form of {word, steps}. 

we push the startWord into the queue with length as ‘1’ indicating that this 
is the word from which the sequence needs to start from.

We now create a hash set wherein, we put all the elements in wordList to keep 
a check on if we’ve visited that word before or not. In order to mark a word as 
visited here, we simply delete the word from the hash set. There is no point in 
visiting someone multiple times during the algorithm. 

Now, we pop the first element out of the queue and carry out the BFS traversal
where, for each word popped out of the queue, we try to replace every character 
with ‘a’ - ‘z’, and we get a transformed word. We check if the transformed word 
is present in the wordList or not.

If the word is present, we push it in the queue and increase the count of the 
sequence by 1 and if not, we simply move on to replacing the original character 
with the next character.

Remember, we also need to delete the word from the wordList if it matches with 
the transformed word to ensure that we do not reach the same point again in the 
transformation which would only increase our sequence length

Now, we pop the next element out of the queue ds and if at any point in time, 
the transformed word becomes the same as the targetWord, we return the count of 
the steps taken to reach that word. 

*/


#include <bits/stdc++.h>
using namespace std;
 
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
};
 
int main()
{
 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
    return 0;
}
