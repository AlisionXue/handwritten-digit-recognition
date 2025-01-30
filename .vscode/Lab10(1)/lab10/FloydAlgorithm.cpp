#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ����������ʾ
const string INF = "-";

// ��������
string addWithInfinity(string a, string b) {
    if (a == INF || b == INF) return INF;
    return to_string(stoi(a) + stoi(b));
}

bool isLessWithInfinity(string a, string b) {
    if (a == INF) return false;
    if (b == INF) return true;
    return stoi(a) < stoi(b);
}

string minWithInfinity(string a, string b) {
    if (isLessWithInfinity(a, b)) return a;
    return b;
}

// Floyd�㷨����
void allPairsShortestPaths(string matrix[50][50], int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = minWithInfinity(matrix[i][j], addWithInfinity(matrix[i][k], matrix[k][j]));
            }
        }
    }
}

// ������������
int main() {
    const int n = 7; // ͼ�ж�������
    string graph[50][50] = {
        {"0", "80", INF, INF, INF, INF, INF},
        {"80", "0", "79", INF, "153", INF, INF},
        {INF, "79", "0", "78", INF, "74", INF},
        {INF, INF, "78", "0", "98", "89", INF},
        {INF, "153", INF, "98", "0", "67", INF},
        {INF, INF, "74", "89", "67", "0", "67"},
        {INF, INF, INF, INF, INF, "67", "0"}
    };

    // ���� Floyd �㷨
    allPairsShortestPaths(graph, n);

    // ������
    cout << "Shortest Paths Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
