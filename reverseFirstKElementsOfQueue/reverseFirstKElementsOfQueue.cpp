queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        for(int i=0;i<k;i++) 
        {
            s.push(q.front());
            q.pop();
        }
        while(s.size()!=0)
        {
            q.push(s.top());
            s.pop();
        }
        for(int i=0;i<(q.size()-k);i++)
        {
            q.push(q.front());
            q.pop();
        }
        return q;
    }