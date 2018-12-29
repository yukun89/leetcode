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


public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//1.not equal length.  
		//1.suc
		int extra=0;
		ListNode *result=l1;
		ListNode *tail_l1 = nullptr;
		while (l1 != nullptr && l2 != nullptr)
		{
			tail_l1 = l1;
			int v1=l1->value;
			int v2=l2->value;
			l1->val = (v1+v2+extra)%10;
			extra=(v1+v2+extra)/10;	
			l1=l1->next;
			l2=l2->next;
		}
		ListNode *rlist=l1;	
		if (l2!=nullptr)
		{
			tail_l1->next=l2;
			rlist = l2;
		}
			while (rlist != nullptr){
				tail_l1 = rlist; 
				int v1=rlist->value;
				rlist->value = (v1+extra)%10;
				extra = (v1+extra)/10;
				rlist=rlist->next;
				if(extra == 0)
					break;
			}
			if (extra != 0)
			{
				auto new_node = new ListNode(extra);
				tail_l1->next = new_node;
			}
		return result;
    }
};

//在不损害可读性的情况下，应该让code尽量短，这样有利于减少bug。性能问题，在某种程度上，是最后应该考虑的问题。
Problem: 最长不重复子串
Solution: 滑动窗口算法 slide window.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
 		int i=0, j=0;       
		std::Set<char> cons;
		while(i<s.length() && j<s.length())
		{
			if(cons.find(s[j]) == cons.end())
			{
				cons.insert(s[j++]);
				mx=std::max(mx,j-i)
			}
			else{
				cons.era(s[i++]);
			}
		}
		return mx;
    }
};
//数值计算中的几个问题：
1.是否需要判断正负号
2.取余数对负数有什么影响？ x = (x/M)*M  + N. (N为余数，注意余数也有符号)
3.limit.h >> INT_MAX
Problem: reverse int
public int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }

    return result;
}


==========

problem: printBinaryTree.

递归算法的核心：问题的拆分（递归接口的设定）+ 循环条件的终止.


##数据类型中的陷阱
1>整数的左右边界是非对称的
2>不要size_t之间的差值，很可能由于溢出而变得非常大.
class Solution {
public:
    int strStr(string haystack, string needle) {
 		int ans =-1;       
		int n=haystack.size(), m=needle.size();
		int i;
		for (i=0;i<n-m+1; i++)	
		{
			if(haystack.compare(i, m, needle) ==0)
				return i;
		}
		return -1;
    }
};

##container 长度的陷阱
我们需要特别小心的陷阱：container为空: 我们很难在coding的时候还能照顾到逻辑上的漏洞，所以，对于任何程序，无论大小，design需要在ink之前，这是一条黄金准则.


产生括号问题：
Generate Parentheses.
vector<string> generateParenthesis(int n).
void addingpar(vector<string> &v, string str, int n/*left remain*/, int m/*avail right*/){
暴力穷举+剪纸算法

类似题目：给定一个集合，求a1+a2+...+aI=target, 这样的集合有几种.

如何快速编程: bug free的算法。数学和编程。如果是数学，往往有形式化的需求，而编程的要求，是自然语言的，因此要完成自然语言到形式化语言的转换。另外，我们在数学上的集合是非重复的，而编程意义上container，样式就各种各样，要对这种差异具有足够的敏感。
1.集合大小  2.集合元素重复性  3.集合元素排列性  4.集合元素在实数上的分布。


P: Combination Sum.
S: timecosts 17min.  
Y:编程基本功：注意循环该变量和循环不变量。

P: 二分搜索，找到对应元素位置或者应该插入的位置
S: commit(10min)  pass(19min)
Y: 速度太慢了，原因基本算法不熟悉，基本结论，分类讨论的方法.
基本结论：1.如果left和right相距很近，一定有(left+right)/2==left. 2.二分查找后来的left就是应该插入的地方

P: lower_bound and upper_bound.
S: commit(7min) fail:2 pass(13min)
Y: 写完code之后需要花一分钟review code，避免笔误；
一定要写test case来验证一些分支；
