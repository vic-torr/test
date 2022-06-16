#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
using namespace std;

class BigInt {
public:
  BigInt(unsigned len);
  BigInt(const BigInt &bi);
  BigInt(BigInt &&bi);
  BigInt &operator=(const BigInt &bi);
  BigInt &operator=(BigInt &&bi);
  int size() { return len_; }

  ~BigInt();

private:
  unsigned len_;
  uint8_t *mag_;
};
BigInt::BigInt(unsigned len)
    : len_(len), mag_(len ? new uint8_t[len] : nullptr) {}
BigInt::BigInt(const BigInt &bi)
    : len_(bi.len_), mag_(len_ ? new uint8_t[bi.len_] : nullptr) {
  std::copy(bi.mag_, bi.mag_ + len_, mag_);
}

// Move constructor implementation
BigInt::BigInt(BigInt &&bi) : len_(bi.len_), mag_(bi.mag_) {
  bi.mag_ = nullptr;
  bi.len_ = 0;
}

BigInt &BigInt::operator=(const BigInt &bi) {
  if (&bi == this)
    return *this;
  len_ = bi.len_;
  delete[] mag_;
  mag_ = len_ ? new uint8_t[bi.len_] : nullptr;
  std::copy(bi.mag_, bi.mag_ + len_, mag_);
  return *this;
}

// Move assingnment operator overload
BigInt &BigInt::operator=(BigInt &&bi) {
  if (&bi == this)
    return *this;
  len_ = bi.len_;
  delete[] mag_;
  mag_ = bi.mag_;
  bi.mag_ = nullptr;
  bi.len_ = 0;
  return *this;
}

BigInt::~BigInt() { delete[] mag_; }

void swap(BigInt &a, BigInt &b) {
  BigInt t(std::move(a));
  a = std::move(b);
  b = std::move(t);
}

int main() {
  auto a = BigInt(10);
  auto b = BigInt(20);

  std::cout << a.size() << endl;
  std::cout << b.size() << endl;
  auto c = move(a);
  std::cout << c.size() << endl;
  std::cout << a.size() << endl;

  swap(c, b);

  std::cout << c.size() << endl;
  std::cout << b.size() << endl;
  return 0;
}
