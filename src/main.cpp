#include <iostream>
#include <string>

#include "dictionary.h"
#include "parser.h"

using namespace std;

int main() {
    try {
        Dictonary d("data/en_US-large.txt");
        ifstream sub("data/sub1.txt");
        if (!sub.is_open()) {
            throw ScheckError("cannot open data/sub1.txt");
        }

        Parser parser(sub);

        string word;
        while ((word = parser.NextWord()) != "") {
            if (!d.Check(word)) {
                // cout << word << " is OK\n";
                cout << word << " is misspelt at line " << parser.LineNo()
                     << "\n";
            } 
            
        }
    }

    catch (const ScheckError &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Error: unknown exception" << endl;
        return 2;
    }
    return 0;
}
