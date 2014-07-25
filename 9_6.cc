#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void addParen(int nl, int nr,  char* paren, int count, vector<char*>& parens)
{

    if (nl == 0 && nr == 0) {
        paren[count] = '\0';
        char* newParen = new char[count+1];
        strcpy(newParen, paren);
        parens.push_back(newParen);
    }

    if (nl > 0) {
        paren[count] = '(';
        addParen(nl-1, nr, paren, count+1, parens);
    } 

    if (nl < nr) {
        paren[count] = ')';
        addParen(nl, nr-1, paren, count+1, parens);
    }

}


void calParen(int n, vector<char*>& parens)
{
    char* paren = new char[2*n+1];
    addParen(n, n, paren, 0, parens);

    delete[] paren;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        cout << "Usage: 9_6 n" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    cout << "n = " << n << endl;

    vector<char*> parens;
    calParen(n, parens);

    for (size_t i = 0; i < parens.size(); ++i)
    {
        cout << parens[i] << endl;
        delete[] parens[i];
    }

    return 0;
}
