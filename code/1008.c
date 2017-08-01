#include <stdio.h>

int main(void)
{
	int n;
	int t;
	int floor;
	int cur;
	int dis;

	scanf("%d", &n);
	t = n * 5;
	cur = 0;
	while(n--){
		scanf("%d", &floor);
		dis = floor - cur;
		t += dis > 0 ? (6 * dis) : (4 * -dis);
		cur = floor;
	}
	printf("%d", t);
	return 0;
}