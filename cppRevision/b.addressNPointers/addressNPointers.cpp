#include <iostream>
using namespace std;

void incrementNum(int *num) {
  for (int i = 0; i < 5; i++) {
    *num++;
  }
}

void test(int *num) {
  incrementNum(num);
}


int main() {
  int num = 0;
  test(&num);
  cout << num << endl;
}
