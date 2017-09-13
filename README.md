# PAT-Adcanced
My personal solution of PAT Advanced Level.

## Problems
| Problem  | Accepted  | Remark |
|:--------:|:---------:|:------:|
| 1001 | Y |  水题  |
| 1002 | Y |  水题，注意两项相加后系数为0的情况(应该删去)  |
| 1003 | Y |  最短路，可用dfs  |
| 1004 | Y |  水题，求树的每一层的叶子数，可用bfs  |
| 1005 | Y |  水题  |
| 1006 | Y |  水题，qsort()直接出  |
| 1007 | Y |  最大连续子列和，注意全为负数和多个最大和的情况  |
| 1008 | Y |  水题  |
| 1009 | Y |  水题，注意1000项和1000项相乘的结果会超过1000项  |
| 1010 | Y |  二分、有坑  |
| 1011 | Y |  水题，题目长得一匹  |
| 1012 | Y |  水题，较繁琐，排序  |
| 1013 | Y |  简单并查集  |
| 1014 | Y |  银行排队问题，队列，注意17点之前不能开始的，都要Sorry，可以在16:58来个4分钟  |
| 1015 | Y |  水题，进制转换、素数判定  |
| 1016 | Y |  水题，繁琐，注意有匹配on-off的用户才输出  |
| 1017 | Y |  银行排队问题，队列，17点之后来的，不能服务，也不计入平均等待时间  |
| 1018 | Y |  dfs，注意当发送的车数均为最小时，选择需要带回最小车数的方案  |
| 1019 | Y |  水题，进制转换，注意进制可能很大  |
| 1020 | Y |  二叉树基本操作，由中序和后序序列得出树，然后层序遍历  |
| 1021 | Y |  Deepest Root  |
| 1022 | Y |  哈希，STL map, set的使用  |
| 1023 | Y |  水题，用字符，不要用int  |
| 1024 | Y |  水题，用字符，不要用int，注意有可能输入直接就是回文数，不用再计算，直接输出  |
| 1025 | Y |  水题，排序，注意同分同排名，分数相同按考试号递增  |
| 1026 | P |  29‘，比较复杂的模拟题  |
| 1027 | Y |  水题，进制转换  |
| 1028 | Y |  水题，排序，注意后面两组样例，名字相同，成绩相同，还有注意第6组是个大数据  |
| 1029 | Y |  水题，排序，直接把两个数组拼一起，然后用STL的sort，再算中位数，不会超时，500ms左右。  |
| 1030 | Y |  dfs，没坑。  |
| 1031 | Y |  水题  |
| 1032 | Y |  水题，链表操作，注意第最后一组是大数据，注意优化。  |
| 1033 | Y |  每到一个站先计算使用的部分，然后不管油用不用，把油加满，并且清掉比较贵的油。  |
| 1034 | Y |  简单并查集  |
| 1035 | Y |  水题  |
| 1036 | Y |  水题，排序  |
| 1037 | Y |  水题，排序  |
| 1038 | Y |  字典序排序  |
| 1039 | Y |  水题，注意最后一组的大数据，最好把名字hash成int  |
| 1040 | Y |  最长回文子串  |
| 1041 | Y |  水题  |
| 1042 | Y |  水题  |
| 1043 | Y |  BST  |
| 1044 | Y |  水题，找出连续子序列的和与需要支付的金额的最小差额的子序列集合  |
| 1045 | Y |  LCS变种，超纲？ |
| 1046 | Y |  水题，最后一组是大数据，提示：假设a < b，dis(a, b) = dis(0, b) - dis(0, a); dis(a, b) = min(dis(a, b), total - dis(a, b));  |
| 1047 | Y |  和1039差不多  |
| 1048 | Y |  二分  |
| 1049 | Y |  数字规律  |
| 1050 | Y |  水题，注意对S2的优化，虽然S2可能有10^4个字符，但因为字符都是可见的ascii字符，也就是最多不超过256种情况  |
| 1051 | Y |  栈模拟直接过，没有坑，没有大数据  |
| 1052 | Y |  简单链表排序，注意有些结点不在链上，有可能整个链是空的  |
| 1053 | Y |  dfs，可以在搜索的过程中就选择权重大的结点，也可以随便选，然后最后再排序  |
| 1054 | Y |  水题，找出支配色（出现次数超过nrow*ncol的一半）  |
| 1055 | Y |  排序，没坑，注意时间  |
| 1056 | Y |  简单模拟，题意有坑  |
| 1057 | Y |  注意时间，分左右两个multiset，左set的成员数应该等于右边或比右边的个数多一，这样左边的最后一个元素就是PeekMedian  |
| 1058 | Y |  A+B水题  |
| 1059 | Y |  题目有误，输入N就是一个int，不是long，而且这题数据很弱，直接暴力过，不用素数打表  |
| 1060 | Y |  有坑，注意`standard form "0.d1...dN*10^k" (d1>0 unless the number is 0);`不足n位的要补足，还有就是d1  |
| 1061 | Y |  水题  |
| 1062 | Y |  排序水题  |
| 1063 | Y |  交集、并集、注意时间  |
| 1064 | Y |  完全二叉查找树  |
| 1065 | Y |  可以用long long，注意溢出  |
| 1066 | Y |  二叉查找树的平衡操作，左单旋、右单旋、左-右双旋、右-左双旋  |
| 1067 | Y |  最少的交换次数就是，当0不在0位时，和0所在的位置的数换，当0在0位时，要浪费一次，和随便一个乱序数换  |
| 1068 | Y |  M <= 10^2，直接在1-100之间dfs就可以  |
| 1069 | Y |  水题  |
| 1070 | Y |  水题，贪心  |
| 1071 | Y |  字符处理，哈希  |
| 1072 | Y |  Dijsktra，直接dfs会超时，可以用邻接距阵，不会超时  |
| 1073 | Y |  水题，字符处理  |
| 1074 | Y |  水题，链表部分反转  |
| 1075 | P |  排序  |
| 1076 | Y |  bfs，用dfs的话，过不了  |
| 1077 | Y |  水题，题目废话一大堆，其实就是找N个串的公共尾缀  |
| 1078 | Y |  哈希，二次探测解决冲突  |
| 1079 | Y |  dfs，零售商为叶子结点，从根供应商开始搜索，然后递归的过程中注意价格的提升  |
| 1080 | Y |  排序题，先把学生排序，然后自顶向下看，先看第一志愿，学校招满没，然后依次看其他志愿。有一个要注意的是，如果两个人排名 一样（总分和初试分均相同），且报的同一所学校，如果A被录取，B也应该要被录取，不管是否招满  |
| 1081 | Y |  gcd，lcm，注意结果为0时  |
| 1082 | Y |  字符处理，注意输入为0的时候  |
| 1083 | Y |  排序水题，没坑，10分钟内AC  |
| 1084 | Y |  水题  |
| 1085 | Y |  嗯，水题？贪心？  |
| 1086 | Y |  根据出入栈顺序构造树，然后后序遍历  |
| 1087 | P |  经典题，dfs可出，代码量略大，P  |
| 1088 | Y |  水题，注意解题速度，这是一个20分的题  |
| 1089 | Y |  排序模拟  |
| 1090 | Y |  dfs，求根供应商到零售商的最长路，并记录有几个这样的最长路  |
| 1091 | Y |  bfs，题意有坑，根本没看懂，google之后才知道要把这些切片叠起来  |
| 1092 | Y |  水题  |
| 1093 | Y |  计数  |
| 1094 | Y |  树的层序遍历，找出结点最多的那一层  |
| 1095 | N |  emmm  |
| 1096 | N |  NULL  |
| 1097 | N |  NULL  |
| 1098 | N |  NULL  |
| 1099 | N |  NULL  |
| 1100 | N |  NULL  |
| 1101 | N |  NULL  |
| 1102 | N |  NULL  |
| 1103 | N |  NULL  |
| 1104 | N |  NULL  |
| 1105 | N |  NULL  |
| 1106 | N |  NULL  |
| 1107 | N |  NULL  |
| 1108 | N |  NULL  |
| 1109 | N |  NULL  |
| 1110 | N |  NULL  |
| 1111 | N |  NULL  |
| 1112 | N |  NULL  |
| 1113 | N |  NULL  |
| 1114 | N |  NULL  |
| 1115 | N |  NULL  |
| 1116 | N |  NULL  |
| 1117 | N |  NULL  |
| 1118 | N |  NULL  |
| 1119 | N |  NULL  |
| 1120 | N |  NULL  |
| 1121 | N |  NULL  |
| 1122 | N |  NULL  |
| 1123 | N |  NULL  |
| 1124 | N |  NULL  |
| 1125 | N |  NULL  |
| 1126 | N |  NULL  |
| 1127 | N |  NULL  |
| 1128 | N |  NULL  |
| 1129 | N |  NULL  |
| 1130 | N |  NULL  |
| 1131 | N |  NULL  |