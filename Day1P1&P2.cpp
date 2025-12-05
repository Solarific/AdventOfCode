#include <fstream> 
#include <iostream>
#include <string>
using namespace std;

//Part 1
int main() {

  ifstream file("combos.txt");
  if (!file.is_open()) {
    cerr << "Error opening file!\n";
    return 1;
  }

  int zeroCounter = 0;
  int dialPos = 50;
  string line;

  while (getline(file, line)) {
    char turnDir = line[0];
    int turnAmt = stoi(line.substr(1));

    if (turnDir == 'L') {
      dialPos = (dialPos - turnAmt + 100) % 100;
    } else if (turnDir == 'R') {
      dialPos = (dialPos + turnAmt) % 100;
    }

    if (dialPos == 0) {
      zeroCounter++;
    }
  }

  cout << "Password: " << zeroCounter << endl;
}

//Part 2
int main() {
  int zeroCounter = 0;
  int dialPos = 50;
  string line;

  ifstream file("combo.txt");
  if (!file.is_open()) {
    cerr << "Error opening file!\n";
    return 1;
  }

  while (getline(file, line)) {
    char turnDir = line[0];
    int turnAmt = stoi(line.substr(1));

    int fullLoops = turnAmt / 100;
    int remainder = turnAmt % 100;
    zeroCounter += fullLoops;

    for(int i = 0; i < remainder; i++){

    if (turnDir == 'R') {
      dialPos++;
    } else if (turnDir == 'L') {
      dialPos--;
    }

    dialPos = (dialPos + 100) % 100;

    if (dialPos == 0) {
      zeroCounter++;
    }
   }
  }

  cout << "Password: " << zeroCounter << endl;
}