#include <cctype>
#include <iostream>
#include <random>
#include <string>

using namespace std;
using u32 = uint_least32_t;
using engine = mt19937;

class Password {
  const string num = "0123456789";
  const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const string lowercase = "abcdefghijklmnopqrstuvwxyz";
  const string symbol = "!@#$%^&*()";
  bool hasLoop(string pass, string array) {
    for (int i = 0; i < pass.length(); i++) {
      for (int j = 0; j < array.length(); j++) {
        if (pass[i] == array[j]) {
          return true;
        }
      }
    }
    return false;
  }
  int randNum(int len) {
    random_device os_seed;
    const u32 seed = os_seed();
    engine generator(seed);
    uniform_int_distribution<u32> distribute(0, len);
    return distribute(generator);
  }
  int score() {
    int score = 0;
    score += hasLoop(password, num) ? 1 : 0;
    score += hasLoop(password, uppercase) ? 1 : 0;
    score += hasLoop(password, lowercase) ? 1 : 0;
    score += hasLoop(password, symbol) ? 1 : 0;
    return score;
  }

public:
  string password;
  void check();
  void generate();
};

void Password::check() {
  cout << "Enter a password: ";
  cin >> password;
  const int len = password.length();
  if (len > 8 and score() > 2 or len > 16) {
    cout << "It is a strong password" << endl;
  } else if (len >= 8) {
    cout << "It is a good password" << endl;
  } else if (len > 0 and len < 8) {
    cout << "It is a weak password" << endl;
  }
}

void Password::generate() {
  int len;
  string password;
  const string rstring = num + uppercase + lowercase + symbol;
  cout << "Enter password's length: ";
  cin >> len;
  cout << randNum(rstring.length()) << endl;
  for (int i = 0; i < len; i++) {
    password += rstring[randNum(rstring.length())];
  }
  cout << "Generated password: " << password << endl;
}

int main() {
  Password pass;
  pass.check();
  pass.generate();
  return 0;
}
