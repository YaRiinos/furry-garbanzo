//
// Created by yarin665 on 09/06/18.
//

#include "TestCase.hpp"

void TestCase::print(){

    stringstream printResult;

    printResult <<  "Test int operators: " << numFail << " failed, " <<
                numSucsses << " passed, " << numFail + numSucsses << " total."
                << endl << "---" << endl;
    cout << printResult.str();
}

void TestCase::passedTest(){
    numSucsses++;

}

void TestCase::failedTest(string nameFail){
    numFail++;
    errStream << nameFail << "\n";
}
