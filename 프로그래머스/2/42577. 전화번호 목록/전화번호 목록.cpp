#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution (vector<string> phone_book) {
    map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++) {
        hash_map[phone_book[i]] = 1;
    }
    for (int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])
                return false;
        }
    }
    return true;
}