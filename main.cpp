/*
 NAME: Harish Palani
 CRN: 11467
 ASSIGNMENT: Lab 1
 SOURCES: stackoverflow.com
 */

#include <cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Functions
void determineUnion(string arr1[], string arr2[], int n1, int n2);
void determineIntersection(string arr1[], string arr2[], int n1, int n2);
void determineRelativeComplement(string arr1[], string arr2[], int n1, int n2);
void determineCrossProduct(string arr1[], string arr2[], int n1, int n2);
void determinePSCardinality(string arr1[], string arr2[], int n1, int n2);

// Set definitions    
string setA[256];
string setB[256];

int main() {
    cout << "Enter content for Set A, separated by spaces:" << endl;
    string input;
    getline(cin, input);
    stringstream ssA(input);
    
    int i = 0;
    while (ssA.good() && i < 256) {
        ssA >> setA[i];
        ++i;
    }
    
    cout << "Enter content for Set B, separated by spaces:" << endl;
    getline(cin, input);
    stringstream ssB(input);
    int j = 0;
    while (ssB.good() && j < 256) {
        ssB >> setB[j];
        ++j;
    }
    
    while (true) {
        char response;
        cout << "\n1 | The cardinality and roster of "
                    << "the intersection of A and B"
             << "\n2 | The cardinality and roster of "
                    << "the union of A and B"
             << "\n3 | The cardinality and roster of "
                    << "the relative complement of A and B (i.e. A - B)"
             << "\n4 | The cardinality and roster of "
                    << "the relative complement of B and A (i.e. B - A)"
             << "\n5 | The cardinality and roster of "
                    << "the cross product of A and B"
             << "\n6 | The cardinality of the power set of "
                    << "the cross product of A and B"
             << "\nq | quit"
             << endl;
        cin >> response;
        
        if (response == '1') {
            determineIntersection(setA, setB, i, j);
        } else if (response == '2') {
            determineUnion(setA, setB, i, j);
        } else if (response == '3') {
            determineRelativeComplement(setA, setB, i, j);
        } else if (response == '4') {
            determineRelativeComplement(setB, setA, i, j);
        } else if (response == '5') {
            determineCrossProduct(setA, setB, i, j);
        } else if (response == '6') {
            determinePSCardinality(setA, setB, i, j);
        } else {
            break;
        }
    }
}


// Prints union of arr1[0..n1-1] and arr2[0..n2-1]
void determineUnion(string arr1[], string arr2[], int n1, int n2) {
    set<string> hs;
 
    // Inhsert the elements of arr1[] to set hs
    for (int i = 0; i < n1; i++) {
        hs.insert(arr1[i]);
    }
 
    // Insert the elements of arr2[] to set hs
    for (int i = 0; i < n2; i++) {
        hs.insert(arr2[i]);
    }
 
    // Print the content of set hs
    int cardinality = 0;
    cout << endl;
    cout << "U N I O N" << endl;;
    cout << "Roster: { ";
    for (auto it = hs.begin(); it != hs.end(); it++) {
        cout << *it << " ";
        cardinality++;
    }
    cout << "}" << endl;
    cout << "Cardinality: " << cardinality << endl;
}
 
// Prints intersection of arr1[0..n1-1] and
// arr2[0..n2-1]
void determineIntersection(string arr1[], string arr2[], int n1, int n2) {
    set<string> hs;
 
    // Insert the elements of arr1[] to set S
    for (int i = 0; i < n1; i++) {
        hs.insert(arr1[i]);
    }
    
    // Print the content of set hs
    int cardinality = 0;
    cout << endl;
    cout << "I N T E R S E C T I O N" << endl;
    cout << "Roster: { ";
    for (int i = 0; i < n2; i++) {
        // If element is present in set then
        // push it to vector V
        if (hs.find(arr2[i]) != hs.end()) {
            cout << arr2[i] << " ";
            cardinality++;
        }
    }
    cout << "}" << endl;
    cout << "Cardinality: " << cardinality << endl;
}

void determineRelativeComplement(string arr1[], string arr2[], int n1, int n2) {
    set<string> hs;
 
    // Insert the elements of arr1[] to set S
    for (int i = 0; i < n1; i++) {
        hs.insert(arr2[i]);
    }
    
    // Print the content of set hs
    int cardinality = 0;
    cout << endl;
    cout << "R E L A T I V E\n" << "C O M P L E M E N T" << endl;
    cout << "Roster: { ";
    for (int i = 0; i < n2; i++) {
        // If element is present in set then
        // push it to vector V
        if (hs.find(arr1[i]) == hs.end()) {
            cout << arr1[i] << " ";
            cardinality++;
        }
    }
    cout << "}" << endl;
    cout << "Cardinality: " << cardinality << endl;
}

void determineCrossProduct(string arr1[], string arr2[], int n1, int n2) {
    int cardinality = 0;
    cout << endl;
    cout << "C R O S S\n" << "P R O D U C T" << endl;
    cout << "Roster: { ";
    
    for (int x = 0; x < n1; x++) {
        for (int y = 0; y < n2; y++) {
            cout << "( " << arr1[x] << " , " << arr2[y] << " ) ";
            cardinality++;
        }
    }
    cout << "}" << endl; 
    cout << "Cardinality: " << cardinality << endl;
}

void determinePSCardinality(string arr1[], string arr2[], int n1, int n2) {
    cout << endl;
    cout << "P O W E R\n" << "S E T" << endl;
    cout << "Cardinality: " << pow(2, n1*n2) << endl;
}