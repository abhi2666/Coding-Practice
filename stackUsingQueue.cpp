/*
Approach --> 2 Queues 
to insert --> put everything from q1 to q2 and then insert new element into q1
and then again put everything back from q2 to q1.

Note : - Can do it in single queue also
*/

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        // Jai Shre Ram
    }
    
    void push(int x) {
        // put all elements from q1 to q2
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()) return true;
        else return false;
    }
};
