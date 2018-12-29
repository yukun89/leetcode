leetcode真题汇编

section 1.从一个集合中，选取符合条件的子集。
关键点：如何存储已经识别的子集A; 如果目标子集为T,那么如何T包含A、S-A的一部分，应该如何处理？



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> value_index;
		for (int i=0; i< nums.size(); i++){
			int to_find = target-nums[i];
			if( value_index.find(to_find) != value_index.end()){
				result.push_back(value_index[to_find]);
				result.push_back(i);
			}
			value_index[nums[i]] = i;
		}
		return result;
    }
};
//Search can be finished in O(n) for unsorted list
//Search can be finished in O(lg(n)) for sorted list


Problem: two sum sorted.
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2


Solution: 这道题目的关键，在于有序。于是，我们可以利用数学证明,可以在O(n)的时间内找到index1, index2。

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
 		int idx1=0, idx2=numbers.size()-1;
		while(idx1 < idx2)
		{
			int sum = numbers[idx1] + numbers[idx2];
			if(sum > target)
				idx2--;
			else if(sum < target)
				idx1++;
			else
				break;
		}
		vector<int> result;
		result.push_back(idx1+1);
		result.push_back(idx2+1);
		return result;
    }
};



Section 2: 暴力计算类
算法是确定的,主要在于实现。

problem: Implement pow(x, n).

此题的难点在于对数值计算的敏感性:
1> int 的表示范围并不是(-A, A) 而是(-A, B), 所以A = (-1)*(-A)并不恒成立.
2> double 类型的精度大概能表示到小数点后面100多位, 如果继续缩小，结果将变成0
3> 除0异常, 输出为inf
4> 递归与循环互转，一个重要的条件就是收敛性.
5> 判断奇数偶数, 最好用&, 不用%.
6> 整数关于2的乘除法则, 最好用移位来实现。

class Solution {
	public:
    double myPow(double x, int n) {
		double ans;
		long long p = n;
		if (x == 0.0)
			return 1.0;
		if (n< 0)
		{
			p = -1*n;
			x=1/x;	
	    }

		while(p)
		{
			if(p&1)
				ans *= x;
			x *= x;
			p >>= 1;
		}
		return ans;
};
