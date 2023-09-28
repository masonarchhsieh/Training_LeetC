// https://leetcode.com/problems/fizz-buzz-multithreaded

#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  

class FizzBuzz {
private:
    int n;
    sem_t f;
    sem_t b;
    sem_t fb;

public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&f, 0, 0); 
        sem_init(&b, 0, 0); 
        sem_init(&fb, 0, 0); 

    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i=3; i<=this->n; i+=3) {
            if (i % 5 != 0) {
                sem_wait(&f); 
                printFizz();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i=5; i<=this->n; i+=5) {
            if (i % 3 != 0) {
                sem_wait(&b); 
                printBuzz();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
         for (int i=15; i<=this->n; i+=15) {
            sem_wait(&fb); 
            printFizzBuzz();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
         for (int i=1; i<=this->n; i++) {
            if (i % 3 == 0 & i % 5 == 0)
                sem_post(&fb);
            else if (i % 3 == 0)
                sem_post(&f);
            else if (i % 5 == 0)
                sem_post(&b);
            else
                printNumber(i);
        }
    }

    ~FizzBuzz() {
        sem_destroy(&f);
        sem_destroy(&b);
        sem_destroy(&fb);
    }
};