
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

#include "header.h"
#include "Array.h"
#include "AVLtree.h"
#include "HashTable.h"
#include "OneList.h"
#include "Queue.h"
#include "Stack.h"
#include "TwoList.h"

using namespace std;

int main(int argc, char* argv[])
{

    string filenameConsole = "";
    string queryConsole = "";
    string command;
    inputArguments(argc, argv, filenameConsole, queryConsole);

    if (queryConsole.empty()) {
        string command;
        cout << "Enter the command: ";
        getline(cin, command);
        queryConsole = command;
    }

    try {

        string commandWord;
        string name;
        string element;
        string index;

        command = queryConsole;

        Array array;
        Queue queue;
        Stack stack;
        OneList onelist;
        TwoList twolist;
        AVL avl;
        HashTable hashtable;
        stringstream ss(command);

        ss >> commandWord;
        ss >> name;
        ss >> element;
        ss >> index;

        string filename = name + ".txt";
        ifstream fileCheck(filename);
        if (fileCheck.is_open()) {
            fileCheck.close();
        }
        else {
            fileCheck.close();
            cout << "File opening error!!!" << endl;
            return 0;
        }
        string serialization;
        cout << endl << "Select serialization:" << endl << "1 - binary" << endl << "2 - text" << endl << "==>> ";
        cin >> serialization;
        if (serialization != "2" && serialization != "1") {
            cout << endl << "ERROR INPUT!!";
            return 0;
        }

        if (command.find("INFO") != string::npos) {
            ifstream File("INFO.txt");
            string temp;
            cout << endl;
            while (getline(File, temp)) {
                cout << temp << endl;
            }
        }
        else if (command.find("EXIT") != string::npos) {
            cout << endl << "GOOD BYE!" << endl;
            return 0;
        }
        else if (command.at(0) == 'M') {
            if (serialization == "2") {
                array.WritingFromFileToStructure(filename);
            }
            else {
                array.BinaryDESerialization(filename);
            }
            ;
            if (command.find("MPUSH") != string::npos) {
                if (index == "") {
                    array.MPUSHend(element);
                }
                else {
                    array.MPUSHindex(stoi(index), element);
                }
            }
            else if (command.find("MDEL") != string::npos) {
                index = element;
                array.MDEL(stoi(index));
            }
            else if (command.find("MGETL") != string::npos) {
                index = element;
                string cell = array.MGETL(stoi(index));
                cout << endl << cell << endl;
                return 0;
            }
            else if (command.find("MREPL") != string::npos) {
                array.MREPL(stoi(index), element);
            }
            else if (command.find("MSIZE") != string::npos) {
                int cell = array.MSIZE();
                cout << endl << cell << endl;
                return 0;
            }
            else if (command.find("MREAD") != string::npos) {
                array.MREAD();

            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }
            if (serialization == "2") {
                array.SaveToFile(filename);
            }
            else {
                array.BinarySerialization(filename);
            }
        }
        else if (command.at(0) == 'Q') {
            if (serialization == "2") {
                queue.WritingFromFileToStructure(filename);
            }
            else {
                queue.BinaryDEserialization(filename);
            }
            
            if (command.find("QPUSH") != string::npos) {
                queue.QPUSH(element);
            }
            else if (command.find("QPOP") != string::npos) {
                queue.QPOP();
            }
            else if (command.find("QREAD") != string::npos) {
                queue.QREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }
            if (serialization == "2") {
                queue.WritingFromStructureToFile(filename);
            }
            else {
                queue.BinarySerialization(filename);
            }
            
        }
        else if (command.at(0) == 'S') {
            if (serialization == "2") {
                stack.WritingFromFileToStructure(filename);
            }
            else {
                stack.BinaryDEserialization(filename);
            }
            

            if (command.find("SPUSH") != string::npos) {
                stack.SPUSH(element);
            }
            else if (command.find("SPOP") != string::npos) {
                stack.SPOP();
            }
            else if (command.find("SREAD") != string::npos) {
                stack.SREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }

            if (serialization == "2") {
                stack.WritingFromStructureToFile(filename);
            }
            else {
                stack.BinarySerialization(filename);
            }
            
        }
        else if (command.substr(0, 2) == "LO") {
            if (serialization == "2") {
                onelist.WritingFromFileToStructure(filename);
            }
            else {
                onelist.BinaryDEserialization(filename);
            }
           

            if (command.find("LONEPUSHhead") != string::npos) {
                onelist.LONEPUSHhead(element);
            }
            else if (command.find("LONEPUSHtail") != string::npos) {
                onelist.LONEPUSHtail(element);
            }
            else if (command.find("LONEDELhead") != string::npos) {
                onelist.LONEDELhead();
            }
            else if (command.find("LONEDELtail") != string::npos) {
                onelist.LONEDELtail();
            }
            else if (command.find("LONEDELvalue") != string::npos) {
                onelist.LONEDELvalue(element);
            }
            else if (command.find("LONESEARCH") != string::npos) {
                onelist.LONESEARCH(element);
                return 0;
            }
            else if (command.find("LONEREAD") != string::npos) {
                onelist.LONEREAD();
                return 0;
            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }
            if (serialization == "2") {
                onelist.WritingFromStructureToFile(filename);
            }
            else {
                onelist.BinarySerialization(filename);
            }
            
        }
        else if (command.substr(0, 2) == "LT") {
            if (serialization == "2") {
                twolist.WritingFromFileToStructure(filename);
            }
            else {
                twolist.BinaryDEserialization(filename);
            }

            if (command.find("LTWOPUSHhead") != string::npos) {
                twolist.LTWOPUSHhead(element);
            }
            else if (command.find("LTWOPUSHtail") != string::npos) {
                twolist.LTWOPUSHtail(element);
            }
            else if (command.find("LTWODELhead") != string::npos) {
                twolist.LTWODELhead();
            }
            else if (command.find("LTWODELtail") != string::npos) {
                twolist.LTWODELtail();
            }
            else if (command.find("LTWODELvalue") != string::npos) {
                twolist.LTWODELvalue(element);
            }
            else if (command.find("LTWOSEARCH") != string::npos) {
                twolist.LTWOSEARCH(element);
                return 0;
            }
            else if (command.find("LTWOREAD") != string::npos) {
                twolist.LTWOREAD();
                return 0;
            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }
            if (serialization == "2") {
                twolist.SaveToFile(filename);
            }
            else {
                twolist.BinarySerialization(filename);
            }
            
        }
        else if (command.at(0) == 'T') {
            if (serialization == "2") {
                avl.WritingFromFileToStructure(filename);
            }
            else {
                avl.BinaryDESerialization(filename);
            }

            if (command.find("TPUSH") != string::npos) {
                avl.TPUSH(element);

            }
            else if (command.find("TDEL") != string::npos) {
                avl.TDEL(element);
            }
            else if (command.find("TSEARCH") != string::npos) {
                if (avl.TSEARCH(element)) {
                    cout << endl << "The element was found!!!" << endl;
                }
                else {
                    cout << endl << "The element was not found" << endl;
                }
            }
            else if (command.find("TREAD") != string::npos) {
                avl.TREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }
            if (serialization == "2") {
                avl.SaveToFile(filename);
            }
            else {
                avl.BinarySerialization(filename);
            }
            
        }
        else if (command.at(0) == 'H') {
            string key = element;
            string value = index;

            if (serialization == "2") {
                hashtable.WriteFromFile(filename);
            }
            else {
                hashtable.BinaryDEserialization(filename);
            }

            if (command.find("HPUSH") != string::npos) {
                hashtable.HPUSH(key, value);
            }
            else if (command.find("HDEL") != string::npos) {
                hashtable.HDEL(key);
            }
            else if (command.find("HGET") != string::npos) {
                string temp = hashtable.HGET(key);
                cout << endl << temp << endl;
            }
            else if (command.find("HREAD") != string::npos) {
                hashtable.HREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                return 0;
            }
            if (serialization == "2") {
                hashtable.SaveToFile(filename);
            }
            else {
                hashtable.BinarySerialization(filename);
            }
        }
        else {
            cout << endl << "The command was not found!" << endl;
            return 0;
        }

    }
    catch (...) {
        cerr << endl << "UNKNOWN ERROR!!!" << endl;
    }

}


