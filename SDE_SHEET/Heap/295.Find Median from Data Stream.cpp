// Find Median from Data Stream



class MedianFinder {
    // Max-heap to store the lower half of the numbers
    priority_queue<int> maxHeap;
    // Min-heap to store the upper half of the numbers
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Add to max-heap
        maxHeap.push(num);
        
        // Balance the heaps
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Ensure max-heap has more elements or both heaps have equal elements
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

