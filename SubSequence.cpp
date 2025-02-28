// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// void subsequence(string &s1, string output, int index, vector<string> &res) {
//     if (index == s1.size()) {
//         res.push_back(output); 
//         return;
//     }

//     subsequence(s1, output, index + 1, res);

//     output.push_back(s1[index]);

//     subsequence(s1, output, index + 1, res);
// }

// int main() {
//     string s1 = "abc";
//     vector<string> res;
//     string output = "";

//     subsequence(s1, output, 0, res);

//     for (const string &subseq : res) {
//         cout << subseq << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void subsequence(string s, string output, int index) {
    if (index == s.size()) {
        cout << output << endl;
        return;
    }

    // Exclude the current character
    subsequence(s, output, index + 1);

    // Include the current character
    subsequence(s, output + s[index], index + 1);
}

int main() {
    string s;
    getline(cin,s);
    subsequence(s, "", 0);
    return 0;
}
