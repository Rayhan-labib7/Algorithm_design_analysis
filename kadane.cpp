int maxSubArray(vector<int>& nums) 
{
   int curr_sum=0,best_sum=INT_MIN;
   for(int i=0;i<nums.size();i++)
   {
     curr_sum+=nums[i];
     if(nums[i]>curr_sum){
        curr_sum=nums[i];
     }
     if(curr_sum>best_sum){
        best_sum=curr_sum;
     }
   }
   return best_sum;
}