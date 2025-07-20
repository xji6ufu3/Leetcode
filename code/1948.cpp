#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct Trie {
    // current node structure's serialized representation
    string subPaths;
    // current node's child nodes
    unordered_map<string, Trie*> children;
};

class Solution {
private:
    // hash table counts the occurrence times of each serialized representation
    unordered_map<string, int> freq;
    vector<vector<string>> ans;
    // record the path from the root node to the current node.
    vector<string> path;
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {

        Trie* root = new Trie();

        for (const vector<string>& path : paths) {
            Trie* cur = root;
            for (const string& node : path) {
                if (!cur->children.count(node)) {
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }

        constructSubPaths(root);

        checkAnswer(root);

        freeTrie(root);
        delete root;

        return ans;
    }

    void constructSubPaths(Trie* node){
        // if it is a leaf node, then the serialization is represented as an
        // empty string, and no operation is required.
        if (node->children.empty()) {
            return;
        }

        vector<string> v;
        // if it is not a leaf node, the serialization representation of the
        // child node structure needs to be calculated first.
        for (const auto& [folder, child] : node->children) {
            constructSubPaths(child);
            v.push_back(folder + "(" + child->subPaths + ")");
        }
        // to prevent issues with order, sorting is needed
        sort(v.begin(), v.end());
        for (string& s : v) {
            node->subPaths += move(s);
        }
        // add to hash table
        ++freq[node->subPaths];
    }

    void checkAnswer(Trie* node){
        // if the serialization appears more than once in the hash table, it
        // needs to be deleted.
        if (freq[node->subPaths] > 1) {
            return;
        }
        // otherwise add the path to the answer
        // when meet root, the path is empty
        if (!path.empty()) {
            ans.push_back(path);
        }
        for (const auto& [folder, child] : node->children) {
            path.push_back(folder);
            checkAnswer(child);
            path.pop_back();
        }
    }

    void freeTrie(Trie* node) {
        for (auto& [_, child] : node->children) {
            freeTrie(child);
            delete child;
        }
    }
};