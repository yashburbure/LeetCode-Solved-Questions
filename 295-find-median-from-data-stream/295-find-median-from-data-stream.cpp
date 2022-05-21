class MedianFinder {
public:
    priority_queue<int,vector<int>> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    MedianFinder() {
        
    }
    void addNum(int num) {
        int sz=q1.size()+q2.size();
        if(sz&1){
            if(num<q1.top()){
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
            else{
                q2.push(num);
            }
        }
        else{
            if(q1.size()==0) q1.push(num);
            else{
                if(num>q2.top()){
                    q1.push(q2.top());
                    q2.pop();
                    q2.push(num);
                }
                else{
                    q1.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        int sz=q1.size()+q2.size();
        if(sz&1) return q1.top();
        return (q1.top()+q2.top())/2.0;   
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */