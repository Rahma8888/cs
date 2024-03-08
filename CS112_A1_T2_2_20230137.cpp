#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_sum(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            for (int k = j + 1; k < numbers.size(); k++) {
                if (numbers[i] + numbers[j] + numbers[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> player1;
    vector<int> player2;
    int choice;

    do {
        // Display available numbers
        cout << "Available numbers: ";
        for (int i : numbers) {
            cout << i << " ";
        }
        cout << endl;

        // Player 1's turn
        cout<<"player 1 enter your number: ";
        cin >> choice;
         try{
          if(choice<0 || choice <10){
           throw exception();

         }}
       catch(exception a){
        cout<<"invild mum";}
        
    

        auto it = find(numbers.begin(), numbers.end(), choice);
        if (it != numbers.end()) {
            numbers.erase(it);
            player1.push_back(choice);
            if (check_sum(player1)) {
                cout << "Player 1 wins!" << endl;
                break;
            }
        } else {
            cout << "Invalid choice. Please enter a valid number." << endl;
        }

        if (numbers.empty()) {
            cout << "Players are equal! It's a draw." << endl;
            break;
        }

        // Display available numbers
        cout << "Available numbers: ";
        for (int i : numbers) {
            cout << i << " ";
        }
        cout << endl;

        // Player 2's turn
        cout<<"player 2 enter your number: ";
        cin >> choice;
        auto its = find(numbers.begin(), numbers.end(), choice);
        if (its != numbers.end()) {
            numbers.erase(its);
            player2.push_back(choice);
            if (check_sum(player2)) {
                cout << "Player 2 wins!" << endl;
                break;
            }
        } else {
            cout << "Invalid choice. Please enter a valid number." << endl;
        }

    } while (!numbers.empty());

    return 0;
}
