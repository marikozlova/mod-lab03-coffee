// "Copyright [year] <Copyright Owner>"
#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
 protected:
    Automata Machine;
};

TEST(AutomataTest, test1) {
    Automata Machine;
    Machine.on();
    EXPECT_EQ(Wait, Machine.getState());
}

TEST(AutomataTest, test2) {
    Automata Machine;
    Machine.on();
    Machine.coin(50);
    EXPECT_EQ(Accept, Machine.getState());
}

TEST(AutomataTest, test3) {
    Automata Machine;
    Machine.on();
    Machine.off();
    EXPECT_EQ(Off, Machine.check(1));
}

TEST(AutomataTest, test4) {
    Automata Machine;
    Machine.on();
    Machine.coin(50);
    EXPECT_EQ(false, Machine.check(1));
}

TEST(AutomataTest, test5) {
    Automata Machine;
    Machine.on();
    Machine.coin(30);
    Machine.choice(2);
    Machine.cook(2);
    Machine.finish(2);
    EXPECT_EQ(Wait, Machine.getState());
}

TEST(AutomataTest, test6) {
    Automata Machine;
    Machine.on();
    Machine.coin(200);
    EXPECT_EQ(true, Machine.check(1));
}

TEST(AutomataTest, test7) {
    Automata Machine;
    Machine.on();
    Machine.coin(200);
    Machine.choice(3);
    EXPECT_EQ(false, Machine.check(3));
}

TEST(AutomataTest, test8) {
    Automata Machine;
    Machine.on();
    Machine.coin(50);
    Machine.coin(50);
    EXPECT_EQ(true, Machine.check(1));
}
