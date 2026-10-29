
#include <mutex>
#include <condition_variable>
using namespace std;

class Foo {
private:
    mutex m;
    condition_variable cv;
    bool firstDone = false;
    bool secondDone = false;

public:
    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();

        {
            lock_guard<mutex> lock(m);
            firstDone = true;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return firstDone; });

        printSecond();

        secondDone = true;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return secondDone; });

        printThird();
    }
};

