#include <bits/stdc++.h>
using namespace std;

/*
Alice wants to join her school's Probability Student Club.
Membership dues are computed via one of two simple probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six.
Your number of rolls is the amount you pay, in dollars.

The second game: same, except that the stopping condition is a five followed by a five.

Which of the two games should Alice elect to play? Does it even matter?
Write a program to simulate the two games and calculate their expected value.
*/


// Theoritically she should choose the first game.
// https://stats.stackexchange.com/questions/428386/expected-amount-of-dice-tosses-in-two-games
void game_simulator(int number_of_trial){
	int trials[number_of_trial+1];
	
	for(int i=0;i<=number_of_trial;i++)
		trials[i] = rand()%6 + 1;
	
	int trial_win1 = 0, trial_win2 = 0;
	
	for(int i=1;i<=number_of_trial;i++){
		if(trials[i-1] == 5 && trials[i] == 6){
			trial_win1 = i;
			break;
		}
	}
	
	for(int i=1; i<=number_of_trial; i++){
		if(trials[i-1] == 5 && trials[i] == 5){
			trial_win2 = i;
			break;
		}
	}

	cout << "Total number of trials : " << number_of_trial << "\n"; 
	cout << "Number of trials needed to win first game : " << trial_win1 << "\n";
	cout << "Number of trials needed to win second game : " << trial_win2 << "\n";
}

// main function
int main(){
	srand(time(0));
	
	for(int i : {1000, 2000, 3000, 4000, 5000}){
		game_simulator(i);
		cout << "\n";
	}
	return 0;
}