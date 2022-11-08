#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class HashTable
{
    int BUCKET;

    list<int>* table;
public:
    HashTable(int V);

    void insertHash(int key);

    int firstDigit(int data) {
        while (data >= 10) {
            data /= 10;
        }
        return (data);
    }

    void dispHash(int key);
};

HashTable::HashTable(int i) {
    this->BUCKET = i;
    table = new list<int>[BUCKET];
}