#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &str, char del) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, del)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream inputFileKho("NHAP.txt");
    ofstream outputFileKho("KHO.txt");

    // Check if files are open
    if (!inputFileKho.is_open()) {
        cerr << "Error: Could not open input file NHAP.txt" << endl;
        return 1;
    }
    if (!outputFileKho.is_open()) {
        cerr << "Error: Could not open output file KHO.txt" << endl;
        return 1;
    }

    string line;
    vector<vector<string>> tokensss;
    
    // Read lines from the input file
    while (getline(inputFileKho, line)) {
        vector<string> tokens = split(line, ',');
        tokensss.push_back(tokens);
    }
    
    // Write tokens to the output file
    for (const auto &tokens : tokensss) {
        for (size_t i = 0; i < tokens.size(); ++i) {
            outputFileKho << tokens[i];
            if (i < tokens.size() - 1) {
                outputFileKho << ",";
            }
        }
        outputFileKho << endl;
    }

    inputFileKho.close();
    outputFileKho.close();
    return 0;
}
