#include <bits/stdc++.h>
using namespace std;

// converting excel format eg.  BC23
// to RC format eg. R23C55
string excelToRC(const string &s) {
    string colStr, rowStr;
    // separate letters (col), digits (row)
    for (char ch : s) {
        if (isalpha(ch)) colStr += ch;
        else rowStr += ch;
    }
    // convert col letters to number (base 26)
    int col = 0;
    for (char ch : colStr) {
        col = col * 26 + (ch - 'A' + 1);
    }
    // put it together in RC format
    return "R" + rowStr + "C" + to_string(col);
}

// convert RC format eg. R23C55 to excel
// eg. BC23
string rcToExcel(const string &s) {
    int rPos = 1; // start after 'R'
    // find where the row number ends (digits after 'R')
    while (isdigit(s[rPos])) rPos++;
    string rowStr = s.substr(1, rPos - 1); // extract row number
    string colStr = s.substr(rPos + 1); // extract col num after 'C'
    int col = stoi(colStr); // convert col string to int
    string colLetters = "";
    while (col > 0) {
        col--; // adjust for 1-indexed letters
        colLetters = char('A' + (col % 26)) + colLetters;
        col /= 26;
    }
    return colLetters + rowStr;
}

// detect format and convert accordingly
string convert(const string &s) {
    // if it starts with 'R', contains 1 'C'
    // second char is digit then RC format
    if (s[0] == 'R' && count(s.begin(), s.end(), 'C') == 1 && isdigit(s[1])) {
        return rcToExcel(s);
    } else {
        return excelToRC(s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> coords(n);
    // read all coords
    for (int i = 0; i < n; i++) cin >> coords[i];
    // process each and print conversion
    for (int i = 0; i < n; i++) cout << convert(coords[i]) << "\n";
}