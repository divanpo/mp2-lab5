#include "forwardlist.h"
#include "tqueue.h"
#include <iostream>

using namespace std;

int main() {
    //TForwardList<int> list;
    //list.insert(1);
    //list.insert(22);
    //list.insert(31);
    //TForwardList<int> list2;
    //list2 = list;
    //list.print();
    //list2.print();
    //cout << list2[2] << '\n';
    //
    TQueue<int> que(5);
    que.push(5);
    cout << que.top() << '\n';
    que.push(4);
    cout << que.top() << '\n';
    que.pop();
    cout << que.top() << '\n';

    return 0;
}
