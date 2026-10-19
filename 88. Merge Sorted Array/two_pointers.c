#include <stdio.h>


#define LEN(arr) sizeof(arr)/sizeof(int)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    if(n == 0) return ;
    
#if 0
    int end_idx = nums1Size - 1;
    while(m>0 && n>0)
    {
        // printf("%d %d\n", m-1, n-1);
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

    // printf("n\n");
    while(n>0)
    {
        // printf("n = %d\n", n-1);
        nums1[end_idx] = nums2[n-1];
        n--;
        end_idx--;
    }
#else
    int i = m - 1;
    int j = n - 1;
    int end_idx = m + n - 1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[end_idx] = nums1[i];
            end_idx--;
            i--;
        } 
        else {
            nums1[end_idx] = nums2[j];
            end_idx--;
            j--;
        }
    }
#endif
}


int main()
{
    int arr1[] = {2,3,4,7,0,0,0};
    int m = 4;

    int arr2[] = {1,5,6};
    int n = 3;

    merge(arr1, LEN(arr1), m, arr2, LEN(arr2), n);

    printf("\n\n");
    for(int k= 0; k < LEN(arr1); k++)
        printf("%d ", arr1[k]);


    return 0;
}
