class NumArray {
    vector<int> Tree;
    int n;
    int BuildSegmentTree(int index,int low,int high,vector<int>& nums){
        if(low==high){
            return Tree[index]=nums[low];
        }
        int mid=(low+high)/2;
        int LeftSum=BuildSegmentTree(2*index+1,low,mid,nums);
        int RightSum=BuildSegmentTree(2*index+2,mid+1,high,nums);
        Tree[index]=LeftSum+RightSum;
        return Tree[index];
    }
    int UpdateQuery(int index,int& UpdateIndex,int& value,int low,int high){
        if(low==high && low==UpdateIndex){
            return Tree[index]=value;
        }
        int mid=(low+high)/2;
        if(UpdateIndex>mid){
            Tree[index]=Tree[2*index+1]+UpdateQuery(2*index+2,UpdateIndex,value,mid+1,high);
            return Tree[index];
        }
        Tree[index]=Tree[2*index+2]+UpdateQuery(2*index+1,UpdateIndex,value,low,mid);
        return Tree[index];
    }
    int SegmentQuery(int index,int& l,int& r,int low,int high){
        if(low>r || high<l){
            return 0;
        }
        if(low>=l && high<=r){
            return Tree[index];
        }
        int mid=(low+high)/2;
        int LeftSum=SegmentQuery(2*index+1,l,r,low,mid);
        int RightSum=SegmentQuery(2*index+2,l,r,mid+1,high);
        return LeftSum+RightSum;
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        Tree.resize(4*n);
        BuildSegmentTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        UpdateQuery(0,index,val,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return SegmentQuery(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */