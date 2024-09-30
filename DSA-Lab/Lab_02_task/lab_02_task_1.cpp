#include <iostream>
using namespace std;

void displayArrangement(int arrangement[10][15]) {
    cout << "\t\tSeating Arrangement\t\t" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            cout << arrangement[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrangement[10][15] = {0};
    
    while (true) {
        displayArrangement(arrangement);
        
        cout << "Enter the row (1-10) and the seat number (1-15) for booking (Enter 0 0 to exit):" << endl;
        int row, seat;
        cout << "Row: ";
        cin >> row;
        cout << "Seat: ";
        cin >> seat;
        if (row == 0 && seat == 0) {
            break;
        }
        row--;
        seat--;
        if (row < 0 || row >= 10 || seat < 0 || seat >= 15) {
            cout << "You entered an invalid row or seat number!!!" << endl;
            continue; 
        }
        
        if (arrangement[row][seat] == 0) {
            arrangement[row][seat] = 1;
            cout << "You booked the seat." << endl;
        } else {
            cout << "This seat is already booked." << endl;
        }
    }
    
    cout << "Exiting program. Final seating arrangement:" << endl;
    displayArrangement(arrangement);
    
    return 0;
}
