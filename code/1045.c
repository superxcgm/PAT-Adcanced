#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int dp[203][10003];
int A[203];
int B[10003];

int main(void)
{
	int ncolor;
	int nfavo;			/* favorite count */
	int nstripe;
	int nstripe_rec;	/* recognize count */
	int i, j;
	int tmp_color;

	scanf("%d", &ncolor);
	scanf("%d", &nfavo);
	for(i = 1; i <= nfavo; ++i)
		scanf("%d", &A[i]);
	scanf("%d", &nstripe);
	nstripe_rec = 0;
	for(i = 1; i <= nstripe; ++i){
		scanf("%d", &tmp_color);
		/* 这个判断没鸟用，我还以为条带中会出现Eva辨别不了的颜色*/
		// if(tmp_color <= ncolor && tmp_color > 0)
		B[++nstripe_rec] = tmp_color;
	}
	memset(dp, 0, sizeof(dp));
	for(i = 1; i <= nfavo; ++i)
		for(j = 1; j <= nstripe_rec; ++j)
			if(A[i] == B[j])
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1);
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	// for(i = 1; i <= nfavo; ++i){
	// 	for(j = 1; j <= nstripe_rec; ++j)
	// 		printf(" %d", dp[i][j]);
	// 	printf("\n");
	// }

	printf("%d\n", dp[nfavo][nstripe_rec]);
	return 0;
}
/*

根据51nod的动规基本篇教程，可得：
LCS(x, y) =
(1) LCS(x - 1, y - 1) + 1 如果Ax ＝ By
(2) max(LCS(x – 1, y) , LCS(x, y – 1)) 如果Ax ≠ By
这个题目是LCS的变种，我们需要对这个式子就行改进。
A为Eva喜欢的颜色序列，B为条带。由测试用例和题意可知，A中的颜色可以在B中出现多次。
改进后的模型如下：
LCS(x, y) =
(1) max(LCS(x - 1, y - 1) + 1, LCS(x, y - 1) + 1) 如果Ax = By
(2) max(LCS(x – 1, y) , LCS(x, y – 1)) 如果Ax ≠ By
 
 */