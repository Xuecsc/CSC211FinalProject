#pragma once
#include <iostream>
using namespace std;

class decision{
  private:
    bool age;
    string courseCategory;
  
  public:
    bool getAge();
    void setAge(bool );
    string getCourseCat();
    string getHtml();
    string getDecision();
    void setCourseCat(string);
    void print();
 
};


