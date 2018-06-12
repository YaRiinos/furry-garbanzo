//
// Created by yarin665 on 09/06/18.
//

#include "TestCase.hpp"

void TestCase::print(){

    stringstream printResult;


    printResult <<errString<< ": " << numFail << " failed, " << numSucsses <<
                " passed, " << numFail + numSucsses << " total." << endl
                << "---" << endl;
    errStream << printResult.str();
}

void TestCase::passedTest(){
    numSucsses++;

}

void TestCase::failedTest(string errMsg){
    numFail++;
    errStream<<errMsg;
}
