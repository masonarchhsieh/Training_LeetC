// https://leetcode.com/problems/print-in-order

#include <unistd.h>
class Foo {
    bool volatile f = false;
    bool volatile s = false;

public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f = true;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(!f) { usleep(10);}
        printSecond();
        s = true;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while (!s) { usleep(10); }
        printThird();
    }
};