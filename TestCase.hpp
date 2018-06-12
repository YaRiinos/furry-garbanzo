//
// Created by yarin665 on 09/06/18.
//

#ifndef TASK9_TESTCASE_H
#define TASK9_TESTCASE_H

#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

class TestCase {

    string errString;
    ostream& errStream;

    void passedTest();
    void failedTest(string errMsg);

public:

    int numSucsses, numFail;

    TestCase(string newErrString, ostream& newErrStream) :
            errString(newErrString), errStream(newErrStream), numSucsses(0), numFail(0){}

    void print();

    template<typename T> TestCase& check_equal(T x, T y){
        if (x==y){
            passedTest();
        }else{
            stringstream outputStream;
            outputStream << errString << ": Failure in test #" <<
                         numSucsses+numFail+1 << ": " << y << " should equal " << x << "!"<<endl;
            failedTest(outputStream.str());
        }
        return *this;
    }

    template<typename T> TestCase& check_different(T x, T y){
        if (x!=y){
            passedTest();
        }else{
            stringstream outputStream;
            outputStream << errString << ": Failure in test #" << numSucsses+numFail+1 << ": " <<
                 y << " should not equal " << x << "!"<<endl;
            failedTest(outputStream.str());
        }
        return *this;
    }


    template<typename Function, typename T, typename S> TestCase& check_function(Function f,T x, S y) {
        if(f(x)==y){
            passedTest();
        }
        else{
            stringstream outputStream;
            outputStream << errString << ": Failure in test #" <<
                 numSucsses+numFail+1 << ": " << "Function should return "<< y <<
                 " but returned " << f(x) << "!"<<endl;
            failedTest(outputStream.str());
        }

        return *this;

    }


    template<typename T> TestCase& check_output(T x, const string &y) {
        stringstream s;
        s << x;

        if(s.str()==y){
            passedTest();
        }
        else{
            stringstream outputStream;
            outputStream << errString << ": Failure in test #" << numSucsses+numFail+1 <<
                ": " << "string value should be "<< y
                << " but is " << s.str() << "!"<<endl;
            failedTest(outputStream.str());
        }

        return *this;

    }
};


#endif //TASK9_TESTCASE_H
