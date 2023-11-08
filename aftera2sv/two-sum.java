import java.util.ArrayList;
class Solution {
     public int[] twoSum(int[] nums, int target) {
        int[] twosum = new int[2];
        Map<Integer, Integer> mapper = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(mapper.containsKey(target - nums[i])){
                twosum[0] = mapper.get(target - nums[i]);
                twosum[1] = i;
                break;
            }
            else {
                mapper.put(nums[i], i);
            }
        }

        return twosum;
    }
}