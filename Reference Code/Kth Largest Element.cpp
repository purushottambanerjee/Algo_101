class Solution {
public:
    inline int partition(vector<int>& nums,int low, int high,int k){
        
        int pivot = nums[high];
        int p = low; //index of the pivot
        for (int i= low; i<high; i++){
            if (nums[i] <= pivot){
                swap(nums[i],nums[p]);
                p++; 
       //a number is less than pivot, index of pivot increment by 1
            }
        }
        swap(nums[p],nums[high]);     
        //cout <<low << " " << high << " " <<p <<endl;
        if (k == p){
            return nums[p];
        }
        else if (k > p) { 
        //since all the numberis less pivot is in the left of the pivot, the result can only be in the range [high-k,high]
             return partition (nums, p+1,high,k);
        }
        else{
            return partition (nums, low,p-1,k);
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k; //index
        return partition (nums,0,nums.size()-1,k);
    }
};