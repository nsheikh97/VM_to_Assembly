#include "parser.h"
#include "instructionTable.h"
#include <fstream>
using namespace std;

string replaceChar(string str, string ch1, string ch2) {

      while (str.find(ch1) != string::npos)
          str.replace(str.find(ch1), 1, ch2);


  return str;
}

int main(int argc, char const *argv[]) {
    int jmpFlag = 0;

    string filename = argv[1];
    Parser parser9000(argv[1]);
    //creating table objects that store appropriate binary values
    instructionTable instTable;
    vector<vector<string>> parsedFile = parser9000.parseFile();

    string outputFile;
    for(int i=0; filename[i] != '.'; i++) outputFile += filename[i];

    //outpute file
    ofstream asmFile;
    asmFile.open (outputFile+".asm");

    for(auto v : parsedFile){
        //if mem location exists
        //cout << v.at(0) << "/" << v.at(1) << endl;
        if(v.at(1) != "NULL"){
            if(v.at(0) =="pushtemp" || v.at(0) == "poptemp"){
                string string2write = instTable.find(v.at(0));
                string2write = replaceChar(string2write, "X", to_string(stoi(v.at(1))+5));
                asmFile << string2write << endl;
            }
            else if(v.at(0) =="pushstatic" || v.at(0) == "popstatic"){
                string string2write = instTable.find(v.at(0));
                string2write = replaceChar(string2write, "X", to_string(stoi(v.at(1))+16));
                asmFile << string2write << endl;
            }
            else if(v.at(0) == "pushpointer" || v.at(0) == "poppointer"){
                if(v.at(1) == "0") asmFile << instTable.find(v.at(0)+'0') << endl;
                else asmFile << instTable.find(v.at(0)+'1') << endl;
            }
            else{
                string string2write = instTable.find(v.at(0));
                string2write = replaceChar(string2write, "X", to_string(stoi(v.at(1))));
                asmFile << string2write << endl;
            }
        }
        //only instruction
        else if(v.at(0) == "gt" || v.at(0) == "lt" || v.at(0) == "eq"){
            string string2write = instTable.find(v.at(0));
            string2write = replaceChar(string2write, "X", to_string(jmpFlag));
            asmFile << string2write << endl;
            jmpFlag++;
        }
        else
            asmFile << instTable.find(v.at(0)) << endl;
    }

    //Ending asm file with infinite loop
    asmFile << "(END)" << endl << "@END" << endl << "0;JMP";

    //close file
    asmFile.close();


    return 0;
}
