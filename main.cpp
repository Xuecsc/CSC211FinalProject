#include <iostream>
using namespace std;

#include "httplib.h"
#include <string>
#include <fstream>

std::string readFile(std::string fp)
{
  auto file = std::fstream(fp);
  return string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

int main()
{
  httplib::Server svr;
  auto ret = svr.set_mount_point("/", "./");
  svr.Get("/option", [](const auto &req, auto &res) {

    if (req.has_param("age")) {
      if(req.has_param("freeOrPaid"))
      {
        auto age = req.get_param_value("age");
        auto wantsFree = req.get_param_value("freeOrPaid");
        if(wantsFree == "checked")
        res.set_content(readFile("freeUnder18.html"), "text/html");
      else
      res.set_content(readFile("index.html"), "text/html");
      std::cout<<"hi!\n";
      std::cout<<wantsFree<<"\n";
      std::cout<<"hi!\n";
      std::cout<<age<<"\n";
      }
    }
    else
    res.set_content(readFile("index.html"), "text/html");
  });

  std::cout << "start server..." << std::endl;
  svr.listen("0.0.0.0", 8080);
  
}


