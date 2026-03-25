#include "ArrayQueue.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    //created a queue of 10 integers
    ArrayQueue<int> queueA(10);

    //called front() and back () on an empty queue and caught the exceptions
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

    //inserted an element(-5 in this case) and checks length front and back
    queueA.enqueue(-5);

    cout << "queue A length: " << queueA.getLength() << " ";
    cout << "queue A front: "  << queueA.front()     << " ";
    cout << "queue A back: "   << queueA.back()      << " ";

    //dequeues an element and tests empty queue 
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

    //filled the queue completley anc checks isFull()
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        queueA.enqueue(i);
    }

    if (queueA.isFull()) {
        cout << "queue A is full! ";
    }

    cout << "queue A length: " << queueA.getLength() << " ";
    cout << "queue A front: "  << queueA.front()     << " ";
    cout << "queue A back: "   << queueA.back()      << " ";

    //copy constructor which createss queueB as a deep copy of queueA 
    ArrayQueue<int> queueB = queueA;

    cout << "queue A contains: ";

    //dequeued all elements from queueA, which prints and empties it completely 
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << " ";

    if (queueA.isEmpty()) {
        cout << "queue A is now empty ";
    }

    //checked if the queueB is indpendent of queueA
    cout << "queue B length: " << queueB.getLength() << " ";
    cout << "queue B front: "  << queueB.front()     << " ";
    cout << "queue B back: "   << queueB.back()      << " ";

    //tested assignment operator
    ArrayQueue<int> queueC;
    queueC = queueB;

    queueB.clear();

    //clear queueB
    if (queueB.isEmpty()) {
        cout << "queue B is now empty ";
    }

    //checks if queueC still has data after queueB was cleared
    cout << "queue C length: " << queueC.getLength() << " ";
    cout << "queue C front: "  << queueC.front()     << " ";
    cout << "queue C back: "   << queueC.back()      << " ";

    return 0;
}
