
*******************************LEETCODE POTD*************************
*	               T.C = O(nlogn)							                * 
*	               							                        * 
*	               S.C = O(nlogn)                                          * 
*	                                                                * 
*********************************************************************
class Node{
    public: 
        int data;
        int i;
        int j;
        Node(int d, int row, int col){
            data = d;
            i = row;
            j = col;
        }
};
class compare{
    public:
        bool operator()(Node* n1, Node* n2){
            return n1->data > n2->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<Node*, vector<Node*>, compare> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int k = nums.size();
        
        for(int i = 0; i<k; i++){
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push(new Node(nums[i][0], i, 0));
        }
        int start = mini;
        int end = maxi;
        while(!pq.empty()){
            Node* tmp = pq.top();
            pq.pop();
            mini = tmp->data;
            int i = tmp->i;
            int j = tmp->j;

            if(maxi-mini < end-start)
            {
                start = mini;
                end = maxi;
            }
            if(j+1 < nums[i].size()){
                pq.push(new Node(nums[i][j+1], i, j+1));
                maxi = max(maxi, nums[i][j+1]);
            }

            else
            {
                break;
            }

        }

        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};