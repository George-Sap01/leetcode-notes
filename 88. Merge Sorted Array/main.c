#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    if(n == 0) return ;

    int end_idx = nums1Size-1;

    while(m>0 && n>0)
    {
        printf("%d %d\n", m-1, n-1);
        if(nums2[n-1] >= nums1[m-1]) {
            nums1[end_idx] = nums2[n-1];
            n--;
        }
        else {
            nums1[end_idx] = nums1[m-1];
            m--;
        }
        end_idx--;
    }

    printf("n\n");
    while(n>0)
    {
        printf("n = %d\n", n-1);
        nums1[end_idx] = nums2[n-1];
        n--;
        end_idx--;
    }

}

/* 
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    
*/


int main()
{

    int arr1[] = {1,2,3,0,0,0};
    int m = 3;

    int arr2[] = {2,5,6};
    int n = 3;

    int arr3[] = {4,0,0,0,0,0};
    m = 1;

    int arr4[] = {1,2,3,5,6};
    n = 5;


    merge(arr3, LEN(arr3), m, arr4, LEN(arr4), n);

    printf("\n\n");
    for(int k= 0; k < LEN(arr3); k++)
        printf("%d ", arr3[k]);

    // -1 -1 -1 0 0 0 0 0 1 2 3
    // -1 -1 -1 0 0 0 0 1 2 0 3 
    return 0;
}


int main2()
{
    int i = 1;
    int arr[] = {0, 1, 2, 3, 0};

    for(int k= 5-1; k > i; k--)
        arr[k] = arr[k-1];

    arr[i] = 15;

    for(int k= 0; k < 5; k++)
        printf("%d ", arr[k]);


    return 0;
}