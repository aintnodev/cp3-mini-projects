#include <iostream>
#include <string>
using namespace std;

class Password {
  bool hasInt() {
    const string num = "0123456789";
    for (int i = 0; i < password.length(); i++) {
      for (int j = 0; j < num.length(); j++) {
        if (password[i] == num[j]) {
          return true;
        }
      }
    }
    return false;
  }
  bool hasUppercase() {
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < password.length(); i++) {
      for (int j = 0; j < uppercase.length(); j++) {
        if (password[i] == uppercase[j]) {
          return true;
        }
      }
    }
    return false;
  }
  bool hasLowercase() {
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < password.length(); i++) {
      for (int j = 0; j < lowercase.length(); j++) {
        if (password[i] == lowercase[j]) {
          return true;
        }
      }
    }
    return false;
  }
  bool hasSymbol() {
    const string symbol = "!@#$%^&*()";
    for (int i = 0; i < password.length(); i++) {
      for (int j = 0; j < symbol.length(); j++) {
        if (password[i] == symbol[j]) {
          return true;
        }
      }
    }
    return false;
  }
  int score() {
    int score = 0;
    score += hasInt() ? 1 : 0;
    score += hasUppercase() ? 1 : 0;
    score += hasLowercase() ? 1 : 0;
    score += hasSymbol() ? 1 : 0;
    return score;
  }

public:
  string password;
  void check();
  void generate();
};

void Password::check() {
  const int len = password.length();
  cout << score() << endl;
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
