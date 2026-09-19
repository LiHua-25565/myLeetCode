class Solution {
void _up(vector<pair<int,int>>& heap, int k)
{
    while (k > 0) {
        int parent = (k - 1) / 2;
        if (heap[parent].first <= heap[k].first) break;   
        swap(heap[parent], heap[k]);
        k = parent;                                       
    }
}

void _down(vector<pair<int,int>>& heap, int i, int k)
{
    while (true) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l <= k && heap[l].first < heap[largest].first) largest = l;   
        if (r <= k && heap[r].first < heap[largest].first) largest = r;
        if (largest == i) break;
        swap(heap[i], heap[largest]);
        i = largest;
    }
}

void pop_sort(vector<pair<int,int>>& heap, int k)
{
    for (int i = k; i > 0; --i) {
        swap(heap[i], heap[0]);
        _down(heap, 0, i - 1);  
    }
}
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<pair<int,int>> vec;
        for(int i : nums) ++map[i];

        for(auto& [val, f]:map)
        {
            if(vec.size()<k)
            {
                vec.push_back({f,val}); 
                _up(vec,vec.size()-1);
            }
            else if (f>vec[0].first)
            {
                vec[0] = {f,val};
                _down(vec,0,vec.size()-1);
            }
        }
        vector<int> result;
        for(auto& p:vec) result.push_back(p.second);
        return result;
    }
};