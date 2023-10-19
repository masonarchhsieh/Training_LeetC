class Foo {
    std::mutex lock1, lock2;
public:
    Foo() {
        lock1.lock();
        lock2.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock1.unlock();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        lock1.lock();
        printSecond();
        lock2.unlock();

    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        lock2.lock();
        printThird();
    }
};