#include <cctype>
#include <cstring>
#include <iostream>
#include <random>
#include <string>

using namespace std;
using u32 = uint_least32_t;
using engine = mt19937;

class Password {
  const string number = "0123456789";
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
    score += hasLoop(password, number) ? 1 : 0;
    score += hasLoop(password, uppercase) ? 1 : 0;
    score += hasLoop(password, lowercase) ? 1 : 0;
    score += hasLoop(password, symbol) ? 1 : 0;
    return score;
  }

public:
  string password;
  void check();
  void generate(int, bool, bool, bool, bool);
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

void Password::generate(int len = 20, bool addUpper = true,
                        bool addLower = true, bool addNum = true,
                        bool addSym = true) {
  string password, rstring;
  rstring += (addUpper) ? uppercase : "";
  rstring += (addLower) ? lowercase : "";
  rstring += (addNum) ? number : "";
  rstring += (addSym) ? symbol : "";
  for (int i = 0; i < len; i++) {
    password += rstring[randNum(rstring.length())];
  }
  cout << "Generated password:" << password << endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Error:\tno argument specified" << endl
         << " -c\tcheck a password" << endl
         << " -g\tgenerate a password" << endl
         << " -l\tlength of password" << endl
         << " -U\tinclude uppercase chars (not implemented yet)" << endl
         << " -u\tinclude lowercase chars (not implemented yet)" << endl
         << " -s\tinclude symbol chars (not implemented yet)" << endl
         << " -n\tinclude number chars (not implemented yet)" << endl;
    return 1;
  }

  Password pass;

  if (strcmp(argv[1], "-g") == 0) {
    if (argv[2]) {
      if (strcmp(argv[2], "-l") == 0) {
        if (argv[3]) {
          int len = stoi(argv[3]);
          if (len > 0) {
            pass.generate(len);
          } else {
            cerr << "Error:\tpassword length must be a positive integer"
                 << endl;
          }
        } else {
          cerr << "Error:\tprovide a integer value as password length" << endl;
        }
      } else {
        cerr << "Error:\t" << argv[2] << " is not a valid argument" << endl;
      }
    } else {
      pass.generate();
    }
  } else if (strcmp(argv[1], "-c") == 0) {
    pass.password = argv[2];
    cout << pass.password;
    pass.check();
  } else {
    cerr << "Error:\t" << argv[2] << " is not a valid argument" << endl;
  }

  return 0;
}
