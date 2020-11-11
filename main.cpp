#include <repr/repr.hpp>
#include <array>
#include <map>
#include <string>
#include <string_view>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <tuple>
#include <optional>

int main() {
  {
    std::vector<int> vec{1, 2, 3};
    std::cout << repr(vec) << "\n";
  }

  {
    std::map<std::string,int> map{{"a", 1}, {"b", 2}, {"c", 3}};
    std::cout << repr(map) << "\n";
  }

  {
    std::vector<std::vector<int>> vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << repr(vec) << "\n";
  }

  {
    std::array<int, 3> arr{1, 2, 3};
    std::cout << repr(arr) << "\n";
  }

  {
    std::cout << repr(5) << "\n";
  }

  {
    std::cout << repr('a') << "\n";
  }

  {
    std::string str{"Hello"};
    std::cout << repr(str) << "\n";
  }

  {
    std::cout << repr("Hello World!") << "\n";
  }

  {
    std::string_view str{"World"};
    std::cout << repr(str) << "\n";
  }

  {
    float f{3.14f};
    std::cout << repr(f) << "\n";
  }

  {
    double f{2.1753284};
    std::cout << repr(f) << "\n";
  }

  {
    long double f{241.4124186412};
    std::cout << repr(f) << "\n";
  }

  {
    int * ptr = nullptr;
    std::cout << repr(ptr) << "\n";
  }

  {
    int * ptr = new int(5);
    std::cout << repr(ptr) << "\n";
    delete ptr;
  }

  {
    std::map<std::string, std::vector<int>> map{{"a", {1, 2, 3}}, {"b", {4, 5, 6}}, {"c", {7, 8, 9}}};
    std::cout << repr(map) << "\n";
  }

  {
    std::set<int> set{1, 2, 3};
    std::cout << repr(set) << "\n";
  }

  {
    std::list<double> list{1., 2., 3.};
    std::cout << repr(list) << "\n";
  }

  {
    enum class Color { RED = 2, BLUE = 4, GREEN = 8 };
    Color color = Color::BLUE;
    std::cout << repr(color) << "\n";
  }

  {
    std::complex<double> c{1, 4};
    std::cout << repr(c) << "\n";
  }

  {
    std::complex<double> c{1.5323, 4.12415};
    std::cout << repr(c) << "\n";
  }

  {
    typedef std::array<std::array<int, 3>, 3> Mat3x3;
    Mat3x3 matrix;
    matrix[0] = {1, 2, 3};
    matrix[1] = {4, 5, 6};
    matrix[2] = {7, 8, 9};
    std::cout << repr(matrix) << "\n";
  }

  {
    std::map<std::string, std::set<int>> foo{ 
      {"foo", {1, 2, 3, 3, 2, 1}}, {"bar", {7, 6, 5, 4}}};
    std::cout << repr(foo) << "\n";
  }

  {
    std::priority_queue<int> queue;
    for(int n : {1,8,5,6,3,4,0,9,7,2}) queue.push(n);
    std::cout << repr(queue) << "\n";
  }

  {
    std::queue<int> queue;
    for(int n : {1,8,5,6,3,4,0,9,7,2}) queue.push(n);
    std::cout << repr(queue) << "\n";
  }

  {
    std::tuple<int, double, std::string> tup{1, 3.14, "Hello"};
    std::cout << repr(tup) << "\n";
  }

  {
    auto get_student = [](int id) {
      if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
      if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
      if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
      throw std::invalid_argument("id");
    };
    auto arr = {get_student(0), get_student(1), get_student(2)};
    std::cout << repr(arr) << "\n";
  }

  {
    std::cout << repr(true) << "\n";
    std::cout << repr(false) << "\n";

    std::array<bool, 3> arr{true, false, true};
    std::cout << repr(arr) << "\n";
  }

  {
    std::optional<int> a = 5;
    std::cout << repr(a) << "\n";

    std::optional<int> b;
    std::cout << repr(b) << "\n";
  }
}