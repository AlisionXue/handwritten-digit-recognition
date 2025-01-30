#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include "HashType.h" // ������ HashType ���ʵ��

using namespace std;

void buildHashTable(ifstream& inFile, HashType<string>& hashTable, int type) {
    string word;
    int length;
    if (inFile.is_open()) {
        while (inFile >> word) {
            length = word.size();
            for (int i = 0; i < length; i++) {
                // ����ַ��Ƿ�Ϊ������
                if (ispunct(word[i])) {
                    word.erase(i--, 1);
                    length = word.size();
                }
            }
            if (type == 1)
                hashTable.InsertItemLinear(word);
            else
                hashTable.InsertItemQuadratic(word);
        }
    }
}

int main() {
    vector<string> fileNames = { "hashText1.txt", "hashText2.txt", "hashText3.txt", "hashText4.txt" };
    vector<int> aValues = { 33, 37, 39, 41 };

    for (const string& fileName : fileNames) {
        ifstream inFile(fileName);
        if (!inFile) {
            cerr << "�޷����ļ�: " << fileName << endl;
            continue;
        }

        int tableSize;
        inFile >> tableSize; // ��ȡ�ļ��еĹ�ϣ���С
        cout << fileName << endl;

        for (int a : aValues) {
            // ����̽��
            HashType<string> hashTableLinear(tableSize, a);
            inFile.clear();
            inFile.seekg(0, ios::beg);
            inFile >> tableSize; // �������С
            buildHashTable(inFile, hashTableLinear, 1);
            cout << "Linear:\n";
            cout << "Hash table size: " << tableSize << endl;
            cout << "Number of collisions with a = " << a << ": " << hashTableLinear.GetCollisions() << endl;

            // ����̽��
            HashType<string> hashTableQuadratic(tableSize, a);
            inFile.clear();
            inFile.seekg(0, ios::beg);
            inFile >> tableSize; // �������С
            buildHashTable(inFile, hashTableQuadratic, 2);
            cout << "Quadratic:\n";
            cout << "Hash table size: " << tableSize << endl;
            cout << "Number of collisions with a = " << a << ": " << hashTableQuadratic.GetCollisions() << endl;
        }

        inFile.close();
    }

    return 0;
}
