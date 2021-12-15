#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "resource.h"
#include "decision.h"
using namespace std;

class rescourcePageCreator{
  private:
    vector<Resource> freeUnder18;
    vector<Resource> paidUnder18;
    vector<Resource> freeCollegeAge;
    vector<Resource> paidCollegeAge;

  public:
    string getWebpage(decision);
    rescourcePageCreator();
    void print();
 
};