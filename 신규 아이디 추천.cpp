#include <iostream>
#include <string>

using namespace std;

string solution(string new_id) {
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = new_id[i] + 32;
        }
    }

    for (int i = 0; i < new_id.length(); ) {
        if (!((new_id[i] >= 'a' && new_id[i] <= 'z') ||
            (new_id[i] >= '0' && new_id[i] <= '9') ||
            new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_')) {
            new_id.erase(i, 1);
        }
        else {
            i++;
        }
    }

    for (int i = 1; i < new_id.length(); ) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(i, 1);
        }
        else {
            i++;
        }
    }

    if (new_id.front() == '.') new_id.erase(0, 1);
    if (new_id.back() == '.') new_id.erase(new_id.length() - 1, 1);
    if (new_id.empty()) new_id = "a";

    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id.back() == '.') new_id.erase(new_id.length() - 1, 1);
    }

    while (new_id.length() < 3) {
        new_id += new_id.back();
    }

    return new_id;
}

int main() {
    string tmp;
    cin >> tmp;
    cout << solution(tmp) << endl;
}
