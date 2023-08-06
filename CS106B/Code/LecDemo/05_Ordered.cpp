#include <iostream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "grid.h"
#include "vector.h"
#include <string>

using namespace std;


void queueExample();
void stackExample();
void emptyStack();
void emptyQueue();
void iterOverStack();
void iterOverQueue();

int main(){
    return 0;
}


void queueExample(){
    Queue<int> line;
    // Queue<int> line = {42, -19, 6}
    line.enqueue(42);
    line.enqueue(-19);
    line.unqueue(6);
    cout << line.dequeue() << endl;  // 42
    cout << line.peek() << endl;  // -19
    cout << line.dequeue() << endl;  // -19
}

void stackExample(){
    Stack<string> wordStack;
    wordStack.push("Kylie");  // {"Kylie"}
    wordStack.push("Nick");  // {"Kylie", "Nick"}
    wordStack.push("Trip");  // {"Kylie", "Nick", "Trip"}
    cout << wordStack.pop() << endl;  // "Trip"
    cout << wordStack.peek() << endl;  // "Nick"
    cout << wordStack.pop() << endl;  // "Nick" (stack is {"Kylie"})
    // You can also create a stack using:
    Stack<string> wordStack = {"Kylie", "Nick", "Trip"};
    // the "top" is the rightmost element
}

void emptyQueue(){
    Queue<int> queueIdiom;
    // produce: {1, 2, 3, 4, 5, 6}
    for (int i = 1; i <= 6; i++) {
        queueIdiom.enqueue(i);
    }
    while (!queueIdiom.isEmpty()) {
        cout << queueIdiom.dequeue() << " ";
    }
    cout << endl;
    // prints: 1 2 3 4 5 6
}

void emptyStack(){
    Stack<int> stackIdiom;
    // produce: {1, 2, 3, 4, 5, 6}
    for (int i = 1; i <= 6; i++) {
        stackIdiom.push(i);
    }
    while (!stackIdiom.isEmpty()) {
        cout << stackIdiom.pop() << " ";
    }
    cout << endl;
    // prints: 6 5 4 3 2 1
}

void iterOverQueue(){
    Queue<int> queueIdiom = {1, 2, 3, 4, 5, 6};
    int origSize = queueIdiom.size();
    for (int i = 0; i < origSize; i++){
        int value = queueIdiom.dequeue();
        // re-enqueue even values
        if (value % 2 == 0){
            queueIdiom.enqueue(value);
        }
    }
    cout << queueIdiom << endl;
    // prints: {2, 4, 6}
}

void iterOverStack(){
    Stack<int> stackIdiom2 = {1,2,3,4,5,6};
    Stack<int> result;
    int origSSize = stackIdiom2.size();
    for (int i = 0; i < origSSize; i++) {
        int value = stackIdiom2.pop();
        // add even values to result
        if (value % 2 == 0) {
            result.push(value);
        }
    }
    cout << result << endl;
    // prints: {6, 4, 2}

