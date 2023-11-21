#include <stdio.h>
#include <math.h>
int main()
{
    int arr[100];
    int currentIndex = 0;
    do
    {
        int sum = 0, max, min, count = 0, m;
        printf("---------------------------MENU--------------------------\n");
        printf("1. Nhap gia tri n phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang\n");
        printf("3. Tinh tong cac phan tu chia het cho 2 va 3 trong mang\n");
        printf("4. In ra gia tri phan tu lon nhat va nho nhat trong mang\n");
        printf("5. Su dung thuat toan sap xep chen sap xep mang tang dan\n");
        printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
        printf("7. Sap xep cac phan tu le chia het cho 5 o dau mang theo thu tu giam dan, cac phan tu chan chia het cho 5 o cuoi mang theo thu tu tang dan,cac phan tu con lai o giua mang theo thu tu giam dan\n");
        printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang (sap xep tang dan) dung vi tri\n");
        printf("9. Thoat\n");
        int choice;
        printf("Nhap lua chon cua  ban  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap so phan tu cua mang ");
            int n;
            scanf("%d", &n);
            if ((n + currentIndex) > 100)
            {
                printf("INVALID");
            }
            else
            {

                for (int i = 0; i < n; i++)
                {
                    printf("arr[%d]=", currentIndex);
                    scanf("%d", &arr[currentIndex]);
                    currentIndex++;
                }
            }
            break;
        case 2:
            for (int i = 0; i < currentIndex; i++)
            {
                printf("arr[%d]=%d\n", i, arr[i]);
            }
            break;
        case 3:
            for (int i = 0; i < currentIndex; i++)
            {
                if (arr[i] % 2 == 0 && arr[i] % 3 == 0)
                {
                    sum += arr[i];
                }
            }
            printf("Tong cac phan tu chia het cho 2 va 3 trong mang la %d\n", sum);
            break;
        case 4:
            max = arr[0];
            min = arr[0];
            for (int i = 0; i < currentIndex; i++)
            {
                max = (max > arr[i]) ? max : arr[i];
                min = (min < arr[i]) ? min : arr[i];
            }
            printf("Max=%d\tMin=%d\n", max, min);
            break;
        case 5:
            for (int i = 1; i < currentIndex; i++)
            {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && key < arr[j])
                {
                    arr[j + 1] = arr[j];
                    j -= 1;
                }
                arr[j + 1] = key;
            }
            for (int i = 0; i < currentIndex; i++)
            {
                printf("arr[%d]=%d\n", i, arr[i]);
            }

            break;
        case 6:
            sum = 0;
            for (int i = 0; i < currentIndex; i++)
            {
                count = 0;
                for (int j = 1; j <= sqrt(arr[i]); j++)
                {
                    if (arr[i] % j == 0 && j != 1)
                    {
                        count++;
                        break;
                    }
                }
                if (count == 0 && arr[i] >= 2)
                {
                    sum += arr[i];
                }
            }
            printf("Tong cac so nguyen to co trong mang la %d\n", sum);
            break;
        case 7:
            int start[100], mid[100], end[100], count = 0;
            int startCount = 0, midCount = 0, endCount = 0;
            for (int i = 0; i < currentIndex; i++)
            {
                if (arr[i] % 10 == 5)
                {
                    start[startCount] = arr[i];
                    startCount++;
                }
                else if (arr[i] % 10 == 0)
                {
                    end[endCount] = arr[i];
                    endCount++;
                }
                else
                {
                    mid[midCount] = arr[i];
                    midCount++;
                }
            }

            // sap xep
            for (int i = 1; i < startCount; i++)
            {
                int key = start[i];
                int j = i - 1;
                while (j >= 0 && key > start[j])
                {
                    start[j + 1] = start[j];
                    j -= 1;
                }
                start[j + 1] = key;
            }
            for (int i = 1; i < midCount; i++)
            {
                int key = mid[i];
                int j = i - 1;
                while (j >= 0 && key > mid[j])
                {
                    mid[j + 1] = mid[j];
                    j -= 1;
                }
                mid[j + 1] = key;
            }
            for (int i = 1; i < endCount; i++)
            {
                int key = end[i];
                int j = i - 1;
                while (j >= 0 && key < end[j])
                {
                    end[j + 1] = end[j];
                    j -= 1;
                }
                end[j + 1] = key;
            }

            // day vao mang
            for (int i = 0; i < startCount; i++)
            {
                arr[i] = start[i];
                count++;
            }
            for (int i = 0; i < midCount; i++)
            {
                arr[count] = mid[i];
                count++;
            }
            for (int i = 0; i < endCount; i++)
            {
                arr[count] = end[i];
                count++;
            }
            for (int i = 0; i < currentIndex; i++)
            {
                printf("arr[%d]=%d\n", i, arr[i]);
            }
            break;
        case 8:
            printf("Nhap gia tri m tu ban phim vao mang ");
            scanf("%d", &m);
            arr[currentIndex] = m;
            currentIndex++;
            for (int i = 1; i < currentIndex; i++)
            {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && key < arr[j])
                {
                    arr[j + 1] = arr[j];
                    j -= 1;
                }
                arr[j + 1] = key;
            }
            for (int i = 0; i < currentIndex; i++)
            {
                printf("arr[%d]=%d\n", i, arr[i]);
            }
            break;
        case 9:
            return 0;
        default:
            printf("Vui long nhap cac gia tri 1-9\n");
            break;
        }
    } while (1 == 1);
}