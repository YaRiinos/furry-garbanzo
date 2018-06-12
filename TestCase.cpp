//
// Created by yarin665 on 09/06/18.
//

#include "TestCase.hpp"

void TestCase::print(){

    stringstream printResult;
    cerr <<outputStream.str();

    outputStream.str("");
    outputStream.clear();

    outputStream<< "Test int operators: " << numFail << " failed, " <<
                numSucsses << " passed, " << numFail + numSucsses << " total."
                << endl << "---" << endl;

    cerr << outputStream.str();
}

void TestCase::passedTest(){
    numSucsses++;

}

void TestCase::failedTest(){
    numFail++;
}
