#include <iostream>
using namespace std;

class MyClassOne {
  public:
    int calculate() { return 1; }
};
class MyClassTwo : public MyClassOne {
  public:
    virtual int calculate() { return 2; }
};
class MyClassThree : public MyClassTwo {
  public:
    int calculate() { return 3; }
};
int main() {
  int result = 0;
  MyClassOne *objs[3];
  objs[0] = new MyClassOne();
  objs[1] = new MyClassTwo();
  objs[2] = new MyClassThree();
  for (int i = 0; i < 3; ++i) {
    cout << objs[i]->calculate() << endl;
  }
  return 0;
}
