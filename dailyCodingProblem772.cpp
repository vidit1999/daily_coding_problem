#include <bits/stdc++.h>
using namespace std;

#define SIZE 3
#define DIRECTIONS 8

/*
Boggle is a game played on a 4 x 4 grid of letters.
The goal is to find as many words as possible that
can be formed by a sequence of adjacent letters in
the grid, using each cell at most once. Given a game
board and a dictionary of valid words, implement a Boggle solver.
*/

void dfs(
    vector<vector<char>>& board,
    unordered_set<string>& words,
    unordered_set<string>& dictionary,
    string& word,
    vector<vector<bool>>& visited,
    int dx[], int dy[],
    int x, int y
){
    word.push_back(board[x][y]);
    visited[x][y] = true;

    if(dictionary.find(word) != dictionary.end()){
        words.insert(word);
    }

    for(int i=0; i<DIRECTIONS; i++){
        int new_x = x+dx[i];
        int new_y = y+dy[i];

        if(
            new_x >= 0 && new_x < SIZE &&
            new_y >= 0 && new_y < SIZE &&
            !visited[new_x][new_y]
        ){
            dfs(
                board, words, dictionary,
                word, visited,
                dx, dy, new_x, new_y
            );
        }
    }

    visited[x][y] = false;
    word.pop_back();
}

unordered_set<string> getWords(
    vector<vector<char>>& board,
    unordered_set<string>& dictionary
){
    int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

    vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
    unordered_set<string> words;
    string word = "";

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            dfs(board, words, dictionary, word, visited, dx, dy, i, j);
        }
    }

    return words;
}

unordered_set<string> boggle(
    vector<vector<char>>& board,
    unordered_set<string>& dictionary
){
    return getWords(board, dictionary);
}

int main() {
    vector<vector<char>> board = {
        { 'G', 'I', 'Z' },
        { 'U', 'E', 'K' },
        { 'Q', 'S', 'E' }
    };

    unordered_set<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

    for(string s : boggle(board, dictionary)){
        cout << s << "\n";
    }

    return 0;
}
