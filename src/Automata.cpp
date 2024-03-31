#include "Automata.h"
#include <map>
#include <string>
#include<iostream>
using namespace std;

Automata::Automata() {
    cash = 0;
    state = Off;
    menu[0] = ("Americano ");
    menu[1] = ("Cappuccino");
    menu[2] = ("Latte     ");
    prices[0] = 100;
    prices[1] = 150;
    prices[2] = 200;
}

Automata::~Automata() {};

void Automata::on() {
    state = Wait;
}

void Automata::off() {
    state = Off;
}

void Automata::coin(int money) {
    if (state == Wait or state == Accept) {
        cash += money;
        state = Accept;
    }
}

void Automata::etMenu() {
    cout << "\n      Menu" << endl;
    if (state == Wait or state == Accept) {
        for (int i = 0; i < 3; i++) 
            cout <<i+1<<") "<< menu[i] << " -- " << prices[i] << endl;
	}
}

states Automata::getState() {
    return state;
}

bool Automata::check(int number) {
    return (cash >= prices[number-1]);
}

void Automata::choice(int number) {
    if (state = Accept) {
        state = Check;
        if (check(number)) cook(number);
    }
}

void Automata::cancel() {
    state = Wait;
    cash = 0;
}

void Automata::cook(int number) {
    state = Cook;
    cash -= prices[number-1];
    finish(number-1);

}

void Automata::finish(int number) {
    state = Wait;
}



