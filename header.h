#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

string elementA = "hehe";
string elementB = "meme";
string elementC = "lol";

struct DoubleNode {
    string cell;
    DoubleNode* next;
    DoubleNode* prev;
};

struct SingleNode {
    string cell;
    SingleNode* next;
};
//const char* args[] = {"./program", "--file", "file.txt", "--query", "CREATE TABLE meme"};
void inputArguments(int argc, char* argv[], string& filename, string& query) {
    bool fileFound = false;
    bool queryFound = false;

    for (int i = 1; i < argc; i++) {
        string part = argv[i];

        if (part.find("--file") != string::npos ) {
            if (i + 1 < argc && argv[i+1] != "--query") {
                filename = argv[i + 1];
                fileFound = true;
                i++;
            } else {
                //cout << "ERROR!!!!! Missing file" << endl;
                return;
            }
        }

        else if (part.find("--query") != string::npos) {
            if (i + 1 < argc) {
                query = argv[i + 1];
                queryFound = true;
                i++; 
            } else {
                //cout << "ERROR!!!!! Missing query" << endl;
                return;
            }
        }
    }
    if (!fileFound) {
        //cout << "ERROR!!!!! Missing --file" << endl;
    }

    if (!queryFound) {
        //cout << "ERROR!!!!! Missing --query" << endl;
    }
}

