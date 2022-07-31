class NumArray {
private:
    vector<int> Tree;
    int n;
    int BuildSegmentTree(int index,int left,int right,vector<int>& nums){
        if(left==right){
            return Tree[index]=nums[left];
        }
        int mid=(left+right)/2;
        int left_ans=BuildSegmentTree(2*index+1,left,mid,nums);
        int right_ans=BuildSegmentTree(2*index+2,mid+1,right,nums);
        Tree[index]=left_ans+right_ans;
        return Tree[index];
    }
    int Query(int index,int &l,int &r,int left,int right){
        if(left>r || right<l){
            return 0;
        }
        if(left>=l && right<=r){
            return Tree[index];
        }
        int mid=(left+right)/2;
        int left_sum=Query(2*index+1,l,r,left,mid);
        int right_sum=Query(2*index+2,l,r,mid+1,right);
        return left_sum+right_sum;
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        Tree.resize(4*n);
        Tree[0]=BuildSegmentTree(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return Query(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */