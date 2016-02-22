//
//  main.cpp
//  Alien_Dictionary
//
//  Created by Shujie Hu on 1/13/16.
//  Copyright © 2016 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, wherewords are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
//For example,
//Given the following words in dictionary,
//
//[
// "wrt",
// "wrf",
// "er",
// "ett",
// "rftt"
// ]
//The correct order is: "wertf".

class Solution {
private:
    typedef unordered_map<char, unordered_set<char>> graph;
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        //based on the dictionary, initialize a graph
        graph G = make_graph(words);
        //if the words form a cycle return empty string
        if (isCyclic(G)) {
            return res;
        }
        
    }
    
    graph make_graph(vector<string>& words) {
        graph res;
        if (words.size() <= 1) {
            return res;
        }
        
        //only more than one word can make the connection
        for (int i = 1; i < words.size(); i++) {
            //compare two adjacent words to establish the directed graph i and i - 1
            string word1 = words[i - 1];
            string word2 = words[i];
            int w1 = word1.size();
            int w2 = word2.size();
            for (int j = 0; j < min(w1, w2); j++) {
                //compare each position, find the first position with different letters
                if (word1[j] != words[j]) {
                    if (res.find(word1[j]) == res.end()) {
                        //never find the letter
                        res[word1[j]].insert(word2[j]);
                    }
                    break;
                    //it is enough to find the first different letters
                }
            }
            return res;
        }
    }
    
    bool isCyclic(graph G) {
        //if dfs from a node and it goes back to itself, return false;
        if (G.size() == 0) return false;
        for (int i = 0; i < G.size(); i++) {
            
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
