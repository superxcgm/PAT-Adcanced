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
| 1065 | N |  NULL  |
| 1066 | N |  NULL  |
| 1067 | N |  NULL  |
| 1068 | N |  NULL  |
| 1069 | N |  NULL  |
| 1070 | N |  NULL  |
| 1071 | N |  NULL  |
| 1072 | N |  NULL  |
| 1073 | N |  NULL  |
| 1074 | N |  NULL  |
| 1075 | N |  NULL  |
| 1076 | N |  NULL  |
| 1077 | N |  NULL  |
| 1078 | N |  NULL  |
| 1079 | N |  NULL  |
| 1080 | N |  NULL  |
| 1081 | N |  NULL  |
| 1082 | N |  NULL  |
| 1083 | N |  NULL  |
| 1084 | N |  NULL  |
| 1085 | N |  NULL  |
| 1086 | N |  NULL  |
| 1087 | N |  NULL  |
| 1088 | N |  NULL  |
| 1089 | N |  NULL  |
| 1090 | N |  NULL  |
| 1091 | N |  NULL  |
| 1092 | N |  NULL  |
| 1093 | N |  NULL  |
| 1094 | N |  NULL  |
| 1095 | N |  NULL  |
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