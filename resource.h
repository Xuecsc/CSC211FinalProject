#pragma once
#include <iostream>
#include <string>
using namespace std;

class Resource
{

public:
  string name;
  string website;
  string type;
  string getHtml();
  Resource();
  Resource(string n, string w, string t);
};