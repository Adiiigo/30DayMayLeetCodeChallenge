You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.

Solutions:

Approach 1:
-> use hashMap -> unordered_map 
-> store the frequency of each number on first iteration
-> iterate gain through the lookup table to find the number with the frequency as 1
-> return the number

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        unordered_map<int ,int> lookup ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        for(auto itr = lookup.begin() ; itr != lookup.end() ; itr++){
            if(itr->second == 1){
                return itr->first ;
            }
        }      
        return -1 ;
    }
};

Time complexity : max( O(n) , O((n-1)/2) )= O(n) 
Space Complexity(Extra) : O(n) 

Approach 1 ends //

Approach 2 :
-> Do not use the extra space 
-> Try to find the number in one itration
-> Randomly assign first number as the answer
-> If it is seen again , the set the answer variable as -1
-> If the answer is set to -1, then we are open to new number being as the candidate answer
-> Since, at one point we will never find answer number again, it will never be set as -1 again.
-> return the answer in the end 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     
        int length = nums.size() ;
        int answer = nums[0] ;
        
        for (int i = 1 ; i < length ; i++){
            if(answer == nums[i]){
                answer = -1 ;
            }            
            else if(answer == -1 ){
                answer = nums[i] ;
            }
        }
        return answer ;
    }
};

Time Complexity : O(n) 
Space Complexity(Extra) : O(1) ;

Approach 2 ends //

Approach 3:
