# LeetCode Solution
- 题目后第一个框框记录耗费**时间**在提交时击败网友的百分比
- 题目后第二个框框记录耗费**空间**在提交时击败网友的百分比

**#1 Two Sum** `92.82%` `39.78%`

用Hash Table加速检索，一边插入一边检索可以实现插完查完出结果。

**#2 Add Two Numbers** `88.95%` `5.14%`

**#3 Longest Substring Without Repeating Characters** `82.53%` `59.20%`

滑窗的方式，头和尾一起前进。

**#4 Median of Two Sorted Arrays** `99.86%` `84.54%`

注意到给出的两个数组已排序，直接快速合并取中位数就好。

**#5 Longest Palindromic Substring** `91.17%` `62.76%`

先寻找中心块，可为空，然后向左右延申寻找最长的对称字符串，计算当前长度和历史最长进行比较，更大就覆盖。

**#6 ZigZag Conversion** `94.01%` `100.00%`

简单分发后拼起来效率也挺高，但应注意到每组有（2 x 行数 - 2）个字符，分组后组内的前行数个字符就是组成`|`的字符，剩下的对应`/`中的字符，且同行同组的两个字符位置存在固定计算方式。于是可以用行数外循环，每行`|`上元素内循环，无需分发直接组合出结果。

**#7 Reverse Integer** `100.00%` `100.00%`

注意如何在不实际溢出的情况下预判将要溢出的情况。

**#8 String to Integer (atoi)** `100.00%` `100.00%`

规则要理解清楚，最开始的空格都可以忽略，第一个不是空格的只能是符号或数字，否则不合法，一旦接触到数字或符号后再遇到其他字符则应停止转换。

**#9 Palindrome Number** `90.24%` `100.00%`

整个反转会有溢出风险，并且重点不是找到中心位置。规避前者只要不断地拿走个位数使原数字变小，取得和后者相同的效果只要用取下的数字构建出一个镜像数字与原数字剩下的一半比较即可。

**#10 Regular Expression Matching** `100.00%` `100.00%`

甚难，首先想到动态规划，然后想到不能反复递归调用，不然会重复计算，必须自底向上才能暂存结果。于是开辟(lenS + 1) x (lenP + 1)大小的数组（其实可以只开3行来大幅减少空间复杂度，因为新一行结果最多只需要用到前两行的结果），设置第0行和第0列均为false（因为空字符串匹配非空正则一般都是不匹配，特殊情况后面处理，而正则实际不为空的情况匹配字符串空位一定是false），然后初始化isMatch\[0\]\[0\]为true。处理a\*b \* ce\*这种特殊情况，即非空正则匹配空字符串，一旦检测到\*，就把当前位置和前一个位置均设置成向前两格的值。初始化完毕后开始逐行叠加，不出现\*时，只要当前字符和正则符匹配，则匹配情况同各减去一个字符的情况，若出现了\*，分两种情况，一种是正则的前一个字符与当前字符匹配，则可能是它重复出现的情况或者重复0或1次的情况，不匹配的情况考虑是否出现0次取正则向前两个字符的结果。

**#11 Container With Most Water** `96.33%` `100.00%`

从左右向内夹逼，每次更短地前进，相同高度情况下下一格更高的前进。

**#12 Integer to Roman** `76.39%` `100.00%`

一级一级往下减减到0，一边减一边生成罗马数字。

**#13 Roman to Integer** `57.95%` `41.18%`

Hash Table加速检索，先处理特殊情况，单字符直接返回。其余情况下若后一个数字比自己大则总数减去自己，否则加上自己。

**#14 Longest Common Prefix** `100.00%` `100.00%`

纵向扫描。

**#15 3Sum** `99.66%` `100.00%`

先排序，C++有内置的没必要造轮子。排序后从头向后遍历，以自己为目标数，对自己以后的内容做已排序的2Sum：前后向内夹逼，和大于则大数后退，和小于则小数前进，和等于向内去重后各靠近一步。大的遍历到0就可以停止，因为大于0的数之后也全大于0，和不可能是0。另外大的遍历中和前一位数字一样的可以跳过，这样导出的结果一定是没有重复的。

**#16 3Sum Closest** `99.13%` `100.00%`

基于3Sum小改一下即可，去掉超过目标就停止的限制，修改大小于的情况为计算差值与最小差值比较并更新最小差值和最接近数字，遇到相等的情况直接返回目标。

**#20 Valid Parentheses** `100%` `100.00%`

用堆，左边压入右边弹出，弹出的不是自己另一半就错，最后有剩的也错，注意堆一开始可以放一个无关紧要的，防止一上来就是右半边但是栈顶没东西导致出错。