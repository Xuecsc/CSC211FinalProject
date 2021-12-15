#include "resource.h"

Resource :: Resource() { }

Resource :: Resource(string n, string w, string t) {
  name = n;
  website = w;
  type = t;
}

string Resource::getHtml()
{
  string start = "<tr><td><a href=\"";
  string end ="</a> </td></tr>";
  
  string result = start + website + "\">Click here for this: " + name + end;
  
  //<a href="/this->website">click here for this->name</a> <br>
  return result;
}