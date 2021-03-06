#include <iostream>
#include <vector>
#include <algorithm>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
  int sum;
  int index;
  for (int i = 0; i < x.size(); i++) {
    sum = 0;
    for (int k = 0; k < w.size(); k++) {
      index = i - (int)w.size()/2 + k;
      if (!pack_with_zeros) {
        index = std::max(0, std::min(index, (int)x.size()-1) );
      }
      if (index >= 0 && index < x.size()) {
        sum += x[index] * w[k];
      }
    }
    y.push_back(sum);
  }

  // PRINT
  std::cout << "x: ";
  for (double v : x) {
    std::cout << v << ' ';
  }
  std::cout << std::endl << "w: ";
  for (double v : w) {
    std::cout << v << ' ';
  }
  std::cout << std::endl << "y: ";
  for (double v : y) {
    std::cout << v << ' ';
  }
   std::cout << std::endl;

  // =========== END ===========

  return 0;
}

