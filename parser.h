#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
class Parser{
private:
    string filename;
    int lineNumber = 0;
    vector<vector<string>> parsedFields;
    Parser();

public:
    //constructor takes a filename
    Parser(string filename) : filename(filename) {};
    vector<vector<string>> parseFile(){
        //creating input file object with filename
        ifstream file {filename};
        string line;

        while(getline(file,line)){
            //remove spaces,tabs, returns, and comments from line
            string newString;
            for(int i = 0; (i < line.length()-1 && line[i] != '/'); i++){
                if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n') newString += line[i];
            }
            if(newString.length() > 1){
                int pos = newString.find_first_of("1234567890");
                string instruction;
                string memLocation;
                if (pos != -1){
                    for (int i = 0; i < pos; i++) {
                        instruction += newString[i];
                    }
                    for (int i = pos; i < newString.length(); i++) {
                        memLocation += newString[i];
                    }
                    vector<string> tempVector = {instruction, memLocation};
                    parsedFields.push_back(tempVector);
                    //cout << instruction << " " << stoi(memLocation) << endl;
                }

                else{
                    vector<string> vect{newString, "NULL"};
                    parsedFields.push_back(vect);
                }
                lineNumber++;
            }
        }

        return parsedFields;
    }
    //returns line number which ignores appropriate lines
    int getLineNumber() {return lineNumber;}
};
#endif
