#include <iostream>
#include <string>
using namespace std;

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
  const int len = password.length();
  if (len > 8 and score() > 2 or len > 16) {
    cout << "It is a strong password" << endl;
  } else if (len >= 8) {
    cout << "It is a good password" << endl;
  } else if (len > 0 and len < 8) {
    cout << "It is a weak password" << endl;
  }
}

int main() {
  Password pass;
  cout << "Enter a password: ";
  cin >> pass.password;
  pass.check();
  return 0;
}
