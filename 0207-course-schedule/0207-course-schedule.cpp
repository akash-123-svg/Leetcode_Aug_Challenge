class Solution {
public:
    bool Toposort(int n,vector<vector<int>>& prerequisites,vector<int>&indegree,map<int,vector<int>>&adj){
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto &v: adj[f]){
                indegree[v]--;
                if(indegree[v]==0){
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt==n;  
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &vec : prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return Toposort(n,prerequisites,indegree,adj);
    }
};