#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void countHits(const string& solution, const string& guess, int& hits, int& phits)
{
    int freq[26];
    hits = phits = 0;
    memset(freq, 0, sizeof(freq)); 
    for (int i = 0; i < solution.size(); ++i)
    {
        if (solution[i] == guess[i]) {
            hits++;
        }
        freq[solution[i] - 'A']++;
    }

    for (int i = 0; i < guess.size(); ++i)
    {
        if (freq[guess[i] - 'A']) {
            phits++;
            freq[guess[i] - 'A']--;
        }
    }
    phits -= hits;
}

int main(int argc, char** argv)
{
    vector<string> solutions {"RGBY", "YYGR", "YGRB"};
    vector<string> guesses {"GGRR", "GRYY", "GGBB"};

    for (int i = 0; i < solutions.size(); ++i)
    {
        int hitNum;
        int phitNum;
        countHits(solutions[i], guesses[i], hitNum, phitNum);
        cout << solutions[i] << ": " << guesses[i] << " ? "; 
        cout << hitNum  << "H" << phitNum << "P" << endl;
    }
}
