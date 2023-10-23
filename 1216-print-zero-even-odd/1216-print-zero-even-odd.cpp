class ZeroEvenOdd {
private:
    int n;
    sem_t e, o, z;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&e, 0, false);
        sem_init(&o, 0, false);
        sem_init(&z, 0, true);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; i++) {
            sem_wait(&z);       // this thread will be blocked until the value of semaphore z is no longer 0  

            printNumber(0);
            if (i % 2 == 1)
                sem_post(&o);
            else
                sem_post(&e);
        }
    }

    void even(function<void(int)> printNumber) {
        for (auto i = 2; i <= n; i += 2) {
            sem_wait(&e);
            printNumber(i);
            sem_post(&z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; i += 2) {
            sem_wait(&o);
            printNumber(i);
            sem_post(&z);
        }
    }
};