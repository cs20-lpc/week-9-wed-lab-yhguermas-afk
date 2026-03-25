//constructor: allocated dynamic array buffer and set length to 0. initialized frontIndex to 0 and backIndex to -1
template <typename T>
ArrayQueue<T>::ArrayQueue(int size) {
    maxSize = size;
    buffer = new T[maxSize];
    this->length = 0;

    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
        clear();
}

//back:throws an exception if queue is empty and returns the back element 
template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[backIndex];
}

//clear:deletes old buffer which reallocates, then resets the queue to its initial state and length 
template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;

    buffer = new T[maxSize];
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
}

//copy:implements a deep fake in order to not share memory and copies all attributes and buffer contents 
template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    buffer = new T[maxSize];

    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

//dequeue:throws the excepetion if queue is empty then circularly increments frontIndex, and decrements length.
template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("dequeue: error, queue is empty");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
}
//enqueue:throws exception if queue is full and increments length 
template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        throw string("enqueue: error, queue is full");
    }

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}
//front:returns the front element and throws exception if queue is empty
template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
