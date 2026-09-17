#include <iostream>
#include <string>
using namespace std;

struct Data {
    string key;
    int value;
};

class HashTable {  // 해시 테이블 클래스 - 직접 구현
private:
    static const int SIZE = 10;
    Data table[SIZE];

    int hashFunction(string key) {
        int sum = 0;

        for (int i = 0; i < key.size(); i++) {
            sum += key[i];
        }

        return sum % SIZE;
    }

public:
    void insert(string key, int value) {
        int index = hashFunction(key);

        table[index].key = key;
        table[index].value = value;
    }

    int get(string key) {
        int index = hashFunction(key);

        return table[index].value;
    }
};

int main() {
    HashTable data;

    data.insert("classic", 100);
    data.insert("pop", 800);

    cout << data.get("classic") << '\n';
    cout << data.get("pop") << '\n';
}