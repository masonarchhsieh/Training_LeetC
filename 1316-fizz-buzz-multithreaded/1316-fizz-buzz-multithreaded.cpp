class FizzBuzz {
private:
    int n;
    sem_t fb, f, b, normal;
public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&fb, 0, false); 
        sem_init(&f, 0, false); 
        sem_init(&b, 0, false);
        sem_init(&normal, 0, true);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (auto i = 3; i <= n; i += 3) {
            if (i % 5 != 0) {
                sem_wait(&f);
                printFizz();
                sem_post(&normal);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (auto i = 5; i <= n; i += 5) {
            if (i % 3 != 0) {
                sem_wait(&b);
                printBuzz();
                sem_post(&normal);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (auto i = 15; i <= n; i += 15) {
            sem_wait(&fb);
            printFizzBuzz();
            sem_post(&normal);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; i++) {
            sem_wait(&normal);
            if (i % 5 == 0 && i % 3 == 0)
                sem_post(&fb);
            else if (i % 3 == 0)
                sem_post(&f);
            else if (i % 5 == 0)
                sem_post(&b);
            else {
                printNumber(i);
                sem_post(&normal);
            }
        }
    }
};