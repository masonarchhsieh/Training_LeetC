// https://leetcode.com/problems/print-zero-even-odd

#include <mutex>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h> 
  
class ZeroEvenOdd {
private:
    int n;
    sem_t o;
    sem_t e;
    sem_t z;
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&o, 0, false); 
        sem_init(&e, 0, false); 
        sem_init(&z, 0, true); 

    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i=1; i<=this->n; i++) { 
            sem_wait(&z);

            printNumber(0);
            if (i%2 == 1)
                sem_post(&o);
            else
                sem_post(&e);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i=2; i<=this->n; i+=2) {
            sem_wait(&e);
            printNumber(i);
            sem_post(&z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i=1; i<=this->n; i+=2) {
            sem_wait(&o);
            printNumber(i);
            sem_post(&z);
        }
    }
};