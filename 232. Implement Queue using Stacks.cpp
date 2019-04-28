// 232. Implement Queue using Stacks.cpp
class MyQueue {
public:
    deque <int> myQueue;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        myQueue.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(myQueue.size()>0){
            int pop =  myQueue.front();
            myQueue.pop_front();
            return pop;
        }
        else
            return 0;
    }
    
    /** Get the front element. */
    int peek() {
        return myQueue.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return myQueue.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */