/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (q_min.empty() || num <= q_min.top()) {
            q_min.push(num);
            if (q_max.size() + 1 < q_min.size()) {
                q_max.push(q_min.top());
                q_min.pop();
            }
        } else {
            q_max.push(num);
            if (q_min.size() < q_max.size()) {
                q_min.push(q_max.top());
                q_max.pop();
            }
        }
    }
    
    double findMedian() {
        if (q_min.size() == q_max.size()) return (q_min.top() + q_max.top()) / 2.0;
        else return q_min.top();
    }
private:
    priority_queue<int, vector<int>, less<int> > q_min;
    priority_queue<int, vector<int>, greater<int> > q_max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main()
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    cout << param_2 << endl;
    return 0;
}