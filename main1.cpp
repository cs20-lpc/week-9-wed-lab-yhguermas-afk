#include "ArrayQueue.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    ArrayQueue<int> queueA(10);

    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    queueA.enqueue(-5);

    cout << "queue A length: " << queueA.getLength() << " ";
    cout << "queue A front: "  << queueA.front()     << " ";
    cout << "queue A back: "   << queueA.back()      << " ";

    queueA.dequeue();

    cout << "queue A length: " << queueA.getLength() << " ";
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    for (int i = 0; i < queueA.getMaxSize(); i++) {
        queueA.enqueue(i);
    }

    if (queueA.isFull()) {
        cout << "queue A is full! ";
    }

    cout << "queue A length: " << queueA.getLength() << " ";
    cout << "queue A front: "  << queueA.front()     << " ";
    cout << "queue A back: "   << queueA.back()      << " ";

    ArrayQueue<int> queueB = queueA;

    cout << "queue A contains: ";
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << " ";

    if (queueA.isEmpty()) {
        cout << "queue A is now empty ";
    }

    cout << "queue B length: " << queueB.getLength() << " ";
    cout << "queue B front: "  << queueB.front()     << " ";
    cout << "queue B back: "   << queueB.back()      << " ";

    ArrayQueue<int> queueC;
    queueC = queueB;

    queueB.clear();

    if (queueB.isEmpty()) {
        cout << "queue B is now empty ";
    }

    cout << "queue C length: " << queueC.getLength() << " ";
    cout << "queue C front: "  << queueC.front()     << " ";
    cout << "queue C back: "   << queueC.back()      << " ";

    return 0;
}