class MedianFinder {
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        maxi.push(num);
        mini.push(maxi.top());
        maxi.pop();

        if(mini.size()> maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
        
    }
    
    double findMedian() {

        if(mini.size() > maxi.size()){
            return mini.top();
        }
        if(maxi.size() > mini.size()){
            return maxi.top();
        }
        else{
            return (mini.top() + maxi.top())/2.0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */