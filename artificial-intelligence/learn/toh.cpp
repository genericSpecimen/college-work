#include <iostream>
#include <stack>
#include <map>

char source = 'A', spare = 'B', target = 'C';
int count = 0;
void move(int nd, char source, char target, char spare) {
	if(nd == 0) return;
	// move n-1 discs from source to spare using the target peg as a spare
	move(nd-1, source, spare, target);
	std::cout << "Step " << ++count << ": Move disc " << nd << " from peg " << source << " to peg " << target << "\n";
	// move n-1 discs from spare to target using the source peg as a spare
	move(nd-1, spare, target, source);
}


std::stack<int> source_peg, spare_peg, target_peg;
std::map<char, std::stack<int>> pegs = {
	{source, source_peg},
	{spare, spare_peg},
	{target, target_peg}
};


int step = 0;
void legal_move(char p, char q) {
	if(pegs[p].empty() && pegs[q].empty()) return;
	else if(pegs[q].empty()) {
		std::cout << "Step " << ++step << ": Move disc " << pegs[p].top() << " from peg " << p << " to peg " << q << "\n";
		pegs[q].push(pegs[p].top());
		pegs[p].pop();
	} else if(pegs[p].empty()) {
		std::cout << "Step " << ++step << ": Move disc " << pegs[q].top() << " from peg " << q << " to peg " << p << "\n";
		pegs[p].push(pegs[q].top());
		pegs[q].pop();
	
	} else {
		if(pegs[p].top() == pegs[q].top() - 1) {
			std::cout << "Step" << ++step << ": Move disc " << pegs[p].top() << " from peg " << p << " to peg " << q << "\n";
			pegs[q].push(pegs[p].top());
			pegs[p].pop();
		} else {
			std::cout << "Step " << ++step << ": Move disc " << pegs[q].top() << " from peg " << q << " to peg " << p << "\n";
			pegs[p].push(pegs[q].top());
			pegs[q].pop();
		}
	}
}

void toh_iterative(int nd, char source, char target, char spare) {
	int step = 0;
	for(int i=nd; i>=1; i--) source_peg.push(i);

	if(nd % 2 == 0) {
		while(true) {
			legal_move(source, spare);
			legal_move(source, target);
			std::cout << pegs[target].size() << "\n";
			if(pegs[target].size() == nd) break;
			legal_move(spare, target);
			std::cout << pegs[target].size() << "\n";
			if(pegs[target].size() == nd) break;
		}
	} else {
		while(true) {
			legal_move(source, target);
			std::cout << pegs[target].size() << "\n";
			if(pegs[target].size() == nd) break;
			legal_move(source, spare);
			legal_move(spare, target);
			std::cout << pegs[target].size() << "\n";
			if(pegs[target].size() == nd) break;
		}
	}
}


int main() {
	int nd = 3; // num discs
	std::cin >> nd;
	move(nd, source, target, spare);
	//toh_iterative(nd, source, target, spare);
}
