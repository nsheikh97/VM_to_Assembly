#ifndef INS_H
#define INS_H

#include <unordered_map>
#include <string>

using namespace std;

struct instructionTable{
    //comp table that stores the comp value given the comp string
    unordered_map<string,string> compTable = {
        {"pushconstant", "@X\nD=A\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushlocal", "@1\nD=M\n@X\nA=D+A\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushargument", "@2\nD=M\n@X\nA=D+A\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushthis", "@3\nD=M\n@X\nA=D+A\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushthat", "@4\nD=M\n@X\nA=D+A\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushtemp", "@5\nD=M\n@X\nA=D+A\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushstatic", "@X\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushpointer0", "@3\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"pushpointer1", "@4\nD=M\n@0\nA=M\nM=D\n@0\nM=M+1"},
        {"poplocal", "@1\nD=M\n@X\nD=D+A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"popargument", "@2\nD=M\n@X\nD=D+A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"popthis", "@3\nD=M\n@X\nD=D+A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"popthat", "@4\nD=M\n@X\nD=D+A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"poptemp", "@5\nD=M\n@X\nD=D+A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"poppointer0", "@3\nD=A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"poppointer1", "@4\nD=A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"popstatic", "@X\nD=A\n@R13\nM=D\n@0\nAM=M-1\nD=M\n@R13\nA=M\nM=D"},
        {"add", "@0\nAM=M-1\nD=M\nA=A-1\nM=D+M"},
        {"neg", "D=0\n@0\nA=M-1\nM=D-M"},
        {"not", "@0\nA=M-1\nM=!M"},
        {"sub", "@0\nAM=M-1\nD=M\nA=A-1\nM=M-D"},
        {"and", "@0\nAM=M-1\nD=M\nA=A-1\nM=M&D"},
        {"or", "@0\nAM=M-1\nD=M\nA=A-1\nM=M|D"},
        {"lt", "@0\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@FALSE_X\nD;JGE\n@0\nA=M-1\nM=-1\n@CONTINUE_X\n0;JMP\n(FALSE_X)\n@0\nA=M-1\nM=0\n(CONTINUE_X)"},
        {"gt", "@0\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@FALSE_X\nD;JLE\n@0\nA=M-1\nM=-1\n@CONTINUE_X\n0;JMP\n(FALSE_X)\n@0\nA=M-1\nM=0\n(CONTINUE_X)"},
        {"eq", "@0\nAM=M-1\nD=M\nA=A-1\nD=M-D\n@FALSE_X\nD;JNE\n@0\nA=M-1\nM=-1\n@CONTINUE_X\n0;JMP\n(FALSE_X)\n@0\nA=M-1\nM=0\n(CONTINUE_X)"},
        };

    //finds binary equivalent of comp statement
    string find(string toFind){
        string stringFound = compTable.at(toFind);
        return stringFound;
    }
};
#endif
