class MedianFinder {
    vector<int> max_heap;
    vector<int> min_heap;
    template<typename Comp>
    void push(vector<int>& heap, int val, Comp comp)
    {
        heap.push_back(val);
        int k = heap.size()-1;
        while(k>0)
        {
            int parent = (k-1)/2;
            if(!comp(heap[parent],heap[k])) break;
            swap(heap[parent],heap[k]);
            k=parent;
        }
    }
    template<typename Comp>
    void pop(vector<int>& heap, Comp comp)
    {
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0;
        while(true)
        {
            int best = i;
            int l = 2*i+1, r = 2*i+2;
            if(l<heap.size() && comp(heap[best],heap[l])) best = l;
            if(r<heap.size() && comp(heap[best],heap[r])) best = r;
            if(best == i) break;
            swap(heap[best],heap[i]);
            i = best;
        }
    }
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        push(max_heap, num, less<int>());                       // 1. 先放大根堆
        push(min_heap, max_heap[0], greater<int>());            // 2. 最大值搬到小根堆
        pop(max_heap, less<int>());

        if (min_heap.size() > max_heap.size()) {                // 3. 平衡
            push(max_heap, min_heap[0], less<int>());
            pop(min_heap, greater<int>());
        }
    }

    
    double findMedian() {
    if (max_heap.empty()) return 0.0;                    // 空保护
    if (max_heap.size() > min_heap.size())
        return max_heap[0];                              // 奇数：大根堆顶
    return (max_heap[0] + min_heap[0]) / 2.0;            // 偶数：两顶平均
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */