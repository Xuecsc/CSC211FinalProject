#include <iostream>
using namespace std;
#include "Point.h"

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
  
  cout << readFile("main.cpp") << endl;
  Point point;

  Point pointP(10,15);

  point.print();
  pointP.print();

  httplib::Server svr;
  auto ret = svr.set_mount_point("/", "./");
  svr.Get("/", [](const auto &, auto &res) {
    res.set_content("<html>Hello World!</html>", "text/html");
  });

  std::cout << "start server..." << std::endl;
  svr.listen("0.0.0.0", 8080);
  
}


