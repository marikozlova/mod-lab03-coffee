// "Copyright [year] <Copyright Owner>"
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <map>
#include <string>

enum states {Off, Wait, Accept, Check, Cook};

class Automata{
 private:
    int cash;
    std::string menu[3];
    int prices[3];
    states state;
 public:
    Automata();
    ~Automata();
    void on();
    void off();
    void coin(int money);
    void etMenu();
    states getState();
    void choice(int number);
    bool check(int number);
    void cancel();
    void cook(int number);
    void finish(int number);
};
#endif  // INCLUDE_AUTOMATA_H_



