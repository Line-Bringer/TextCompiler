#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char* argv[]){
    vector<string> lines;
    set<string> uniqueLines;
    string line;
    string filename;//reuse

    cout << "Enter the first file: " << endl;
    cin >> filename;
    filename = filename + ".txt";
    ifstream file1(filename);

    cout << "\nEnter the second file: " << endl;
    cin >> filename;
    filename = filename + ".txt";
    ifstream file2(filename);

    //read and store first file lines
    while (getline(file1, line)){
        lines.push_back(line);
        uniqueLines.insert(line);
    }
    file1.close();
    
    //read and store second file lines, check for duplicates
    while(getline(file2, line)){
        if(line.empty()){
            lines.push_back(line);
        }
        else if(uniqueLines.find(line) == uniqueLines.end()){
        lines.push_back(line);
        uniqueLines.insert(line);
        }
    }
    file2.close();

    //output file for compiled
    cout << "Enter desired output file name: " << endl;
    cin >> filename;
    filename = filename + ".txt";
    cout << "Chosen output file name is: " << filename << endl;

    ofstream outputFile(filename);
    for(const auto& line : lines){
        outputFile << line << "\n";
    }
    outputFile.close();

    cout << "File combined successfully." << endl;


    return 0;
}