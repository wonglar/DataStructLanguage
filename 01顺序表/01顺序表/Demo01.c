#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*
	ɾ������������ظ��ȥ�أ���ʹ��O(1)����ռ�����������
	���룺nums = {0,0,1,1,2,2,3,3,4}
	�����5,nums = {0,1,2,3,4}

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
�ϲ�������������

�����������ǵݼ�˳�����е���������nums1 ��nums2 ��������������
m��n,�ֱ��ʾnums1��nums2 �е�Ԫ����Ŀ��

����ϲ�nums2��nums1��,ʹ�ϲ��������ͬ�����ǵݼ�˳�����С�

ע��:���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������nums1 �С�Ϊ
��Ӧ�����������nums1 �ĳ�ʼ����Ϊm + n,����ǰm��Ԫ�ر�ʾӦ
�ϲ���Ԫ�أ���n��Ԫ��Ϊ0��Ӧ���ԡ�nums2�ĳ���Ϊn��


����: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
���: [1,2,2,3,5,6]
����:��Ҫ�ϲ�[1,2,3] ��[2,5,6]
�ϲ������[1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊnums1�е�Ԫ�ء�


����:nums1=[1],m=1,nums2=[],n=0
���: [1]
����:��Ҫ�ϲ�[1]��[]��
�ϲ������[1]

*/

int main()
{

	return 0;
}