#include <bits/stdc++.h>
using namespace std;

/*
On election day, a voting machine writes data in the form (voter_id, candidate_id) to a text file.
Write a program that reads this file as a stream and returns the top 3 candidates at any given time.
If you find a voter voting more than once, report this as fraud
*/

void electionVoting(string fileName){
	fstream fin;
	fin.open(fileName.c_str(), ios::in);
	string id, temp;
    vector<pair<string, int>> candidates;
    unordered_map<string, int> votes; // stores the votes wrt the candidate_id
    set<string> voters; // stores the voter_ids
    bool flag = true; // true for voter_id and false for candidate_id
    bool voting_again = false;

	while(fin >> temp){
		stringstream s(temp);
		while(getline(s, id, ',')){
            if(flag){
                if(voters.find(id) != voters.end()){
                    cout << "ID : " << id << ", Voting again is NOT allowed.\n";
                    voting_again = true;
                }
                else{
                    voters.insert(id);
                    voting_again = false;
                }
            }
            else{
                if(!voting_again)
                    votes[id]++;
            }
            flag = !flag;

            if(votes.size() >= 3){
                candidates.clear();
                copy(votes.begin(), votes.end(), back_inserter(candidates));
                sort(candidates.begin(), candidates.end(), [](const pair<string, int> p1, const pair<string, int> p2){return p1.second > p2.second;});
                int count  = 0;
                for(auto it=candidates.begin();it!=candidates.end();it++){
                    cout << "Candidate : " << (*it).first << ", Count : " << (*it).second << "\n";
                    if(++count >= 3)
                        break;
                }
            }
            nanosleep((const struct timespec[]){{1, 0}}, NULL);
            system("cls");
		}
	}
	fin.close();
    for(auto it=candidates.begin();it!=candidates.end();it++)
        cout << "Candidate : " << (*it).first << ", Count : " << (*it).second << "\n";
}

// main function
int main(){
	electionVoting("voters.txt");
	return 0;
}