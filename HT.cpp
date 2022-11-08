#include "HT.h"

void HashTable::insertHash(int key) {//Inserts values into the Hash Table
    int index = firstDigit(key);
    table[index].push_back(key);
}

void HashTable::dispHash(int key) {//Display table
        if (key != 0) {
            cout << key;
            for (auto x : table[key]) {
                cout << " --> " << x;
            }
            cout << endl;
        } else {//Display whole table
            for (int i = 0; i < BUCKET; i++) {
                cout << i;
                for (auto x : table[i])
                    cout << " --> " << x;
                cout << endl;
            }
        }
}

void remove(std::vector<int>& v)//Removes from Hash Table
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }

    v.erase(end, v.end());
}

int main() {
    int size = 1000;
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 90 + 10;
    }

    std::unordered_set<int> s(data.begin(), data.end());//Deletes duplicates
    data.assign(s.begin(), s.end());



    //insert data into hash table
    HashTable HT(10);
    for (auto it = data.cbegin(); it != data.cend(); ++it) {
        HT.insertHash(*it);
    }

    int slotNUM;
    cout << "Enter 0 for whole table" << endl << "Enter Table slot number[0-9]:  ";
    cin >> slotNUM;
    while (!(slotNUM >= 0 && slotNUM <= 9)) {//Make sure the user enters a valid number
        cout << "Error! Try Again!" << endl << "Enter Table slot number[1 - 9]: ";
        cin >> slotNUM;
    }
    HT.dispHash(slotNUM);

    return 0;
}