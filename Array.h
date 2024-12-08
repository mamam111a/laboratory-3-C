#pragma once
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

class Array {

private:
    string* data;
    int size;
    int maxSize;
public:
    Array() : size(0), maxSize(1000) {
        data = new string[maxSize];
    }
    ~Array() {
        delete[] data;
    }
    void MPUSHend(string& value) {
        data[size++] = value + " ";
    }
    void MPUSHindex(const int& index, string& value) {
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value + " ";
        size++;
    }

    string MGETL(const int& index) {
        if (index < 0 || index >= size) {
            //cout << endl << "INCORRECT INPUT!!!" << endl; 
            return "ERROR";
        }
        return data[index];
    }

    void MDEL(const int& index) {
        if (index < 0 || index >= size) {
            //cout << endl << "INCORRECT INPUT!!!" << endl; 
            return;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void MREPL(const int& index, string& value) {
        if (index < 0 || index >= size) {
            //cout << endl << "INCORRECT INPUT!!!" << endl; 
            return;
        }
        data[index] = " " + value + " ";
    }

    int MSIZE() {
        return size;
    }

    void MREAD() {
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << data[i];
        }
        cout << endl;
    }
    void SaveToFile(string &fileName) {
        ofstream FileWrite(fileName);
        for (int i = 0; i < size; i++) {
            FileWrite << MGETL(i);
        }
        FileWrite.close();
    }

    void WritingFromFileToStructure(string& filename) {
        ifstream FileRead(filename);
        string tempValue;

        while (getline(FileRead, tempValue)) {
            stringstream ss(tempValue);
            string element;
            while (ss >> element) {
                MPUSHend(element);
            }
        }
        FileRead.close();
    }

    void BinarySerialization(string& fileName) {
        ofstream File(fileName, ios::binary);
        for (int i = 0; i < size; i++) {
            string value = MGETL(i);
            int valueLen = value.size();
            File.write(reinterpret_cast<char*>(&valueLen), sizeof(valueLen));
            File.write(value.c_str(), valueLen);
        }
        File.close();
    }

    void BinaryDESerialization(string& fileName) {
        ifstream File(fileName, ios::binary);
        while (File) {
            int len;
            File.read(reinterpret_cast<char*>(&len), sizeof(len)); 

            if (File.eof())
                break;

            char* buffer = new char[len + 1];
            File.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            data[size++] = text;
            delete buffer;
        }
        File.close();
    }

};