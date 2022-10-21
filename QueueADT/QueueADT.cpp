//
// QueueADT.cpp a driver for the Queue ADT class
//

#include <iostream>
#include "Queue.h"
#include "QueueMaxSizeExeededException.h"

using namespace std;

int main()
{
    try
    {
        int i = 0;
        int capacity = 10;
        int index = 9;

        std::cout << "Hello Queue!\n";

        Queue q1 = Queue(capacity);
        Queue q2 = Queue(capacity);

        q1.Enqueue(15);
        q1.Enqueue(150);
        q1.Enqueue(4);
        q1.Enqueue(100);
        q1.Enqueue(1);
        q1.Enqueue(-10);
        q1.Enqueue(-15);
        q1.Enqueue(-1200);
        q1.Enqueue(123);
        q1.Enqueue(-1234);

        //while (true)
        //{
        //    if (!q1.isFull())
        //    {
        //        q1.Enqueue(i);
        //        i += 10;
        //    }
        //    else
        //        break;
        //}

        q1.PrintQueue();

        std::cout << "Front of the Queue holds: " << q1.FrontVal() << std::endl;
        std::cout << "Back of the Queue holds: " << q1.BackVal() << std::endl;


        std::cout << endl; 
        std::cout << q1.PeekValue(index) << std::endl;

        //q2 = q1; //copy q1 contents onto q2 by operator overloading
        //q2.PrintQueue();


        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();
        q1.Dequeue();

        return 0;
    }
    catch (QueueMaxSizeExeededException &e)
    {
        std::cerr << "Runtime Exception: " << e.getMessage() << std::endl;
    }
}

