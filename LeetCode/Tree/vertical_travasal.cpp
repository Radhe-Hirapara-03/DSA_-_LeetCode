class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        map<int, vector<int>> mp;
        queue<pair<int, Node*>> q;
        
        q.push({0, root});
        
        while(!q.empty()){
            auto [ind, node] = q.front();
            q.pop();
            
            mp[ind].push_back(node->data);
            
            if(node->left)
                q.push({ind - 1, node->left});
                
            if(node->right)
                q.push({ind + 1, node->right});
        }
        
        vector<vector<int>> ans;
        
        for(auto &verti : mp){
            ans.push_back(verti.second);
        }
        
        return ans;
    }
};
