#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*
	删除有序数组的重复项（去重）并使用O(1)额外空间的条件下完成
	输入：nums = {0,0,1,1,2,2,3,3,4}
	输出：5,nums = {0,1,2,3,4}

*/
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//	{
//		return 0;
//	}
//
//	int i = 0, j = 1;
//	int dest = 0;
//	while (j < numsSize)
//	{
//		if (nums[i] == nums[j])
//		{
//			j++;
//		}
//		else
//		{
//			nums[dest] = nums[i];
//			dest++;
//			i = j;
//			j++;
//		}
//	}
//
//	nums[dest] = nums[i];
//	dest++;
//
//	return dest;
//}
//
//int main()
//{
//	int a[] = {0,0,1,1,2,3,4,5,5,5,6,6,7};
//	int sz = sizeof(a) / sizeof(a[0]);
//	int ret = removeDuplicates(a, sz);
//
//	printf("%d\n", ret);
//
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//	return 0;
//}



/*
合并两个有序数组

给你两个按非递减顺序排列的整数数组nums1 和nums2 ，另有两个整数
m和n,分别表示nums1和nums2 中的元素数目。

请你合并nums2到nums1中,使合并后的数组同样按非递减顺序排列。

注意:最终，合并后数组不应由函数返回，而是存储在数组nums1 中。为
了应对这种情况，nums1 的初始长度为m + n,其中前m个元素表示应
合并的元素，后n个元素为0，应忽略。nums2的长度为n。


输入: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出: [1,2,2,3,5,6]
解释:需要合并[1,2,3] 和[2,5,6]
合并结果是[1,2,2,3,5,6] ，其中斜体加粗标注的为nums1中的元素。


输入:nums1=[1],m=1,nums2=[],n=0
输出: [1]
解释:需要合并[1]和[]。
合并结果是[1]

*/

int main()
{

	return 0;
}