class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n>numCourses*(numCourses-1)/2) return false;
        vector<vector<int>>eages(numCourses,vector<int>());
        vector<int> degree(numCourses);
        for(auto vec:prerequisites)
        {
            eages[vec[0]].push_back(vec[1]);
            ++degree[vec[1]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) 
        {
            if(degree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int i : eages[cur]) if(--degree[i]==0) q.push(i);
        }
        for(int i : degree) if(i>0) return false;
        return true;
    }
};