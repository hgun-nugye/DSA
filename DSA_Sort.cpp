#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Selection Sort
void SelectionSortMinMax(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;            
        }
        Swap(a[i], a[min]);
    }
}

void SelectionSortMaxMin(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max]) max = j;            
        }
        Swap(a[i], a[max]);
    }
}

// Insert Sort
void InsertSortMinMax(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void InsertSortMaxMin(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void BubbleSortMinMax(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) Swap(a[j], a[j + 1]);
        }
    }
}

void BubbleSortMaxMin(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[j + 1]) Swap(a[j], a[j + 1]);
        }
    }
}

// Quick Sort
void QuickSortMinMax(int a[], int l, int r) {
    
        int p = a[(l + r) / 2];
        int i = l, j = r;
        while (i < j) {
            while (a[i] < p) i++;
            while (a[j] > p) j--;
            if (i <= j) {
                Swap(a[i], a[j]);
                i++;
                j--;
            }
        }
    
    if (l < j) QuickSortMinMax(a, l, j);
        if (i < r) QuickSortMinMax(a, i, r);
}

void QuickSortMaxMin(int a[], int l, int r) {
    if (l < r) {
        int p = a[(l + r) / 2];
        int i = l, j = r;
        while (i <= j) {
            while (a[i] > p) i++;
            while (a[j] < p) j--;
            if (i <= j) {
                Swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (l < j) QuickSortMaxMin(a, l, j);
        if (i < r) QuickSortMaxMin(a, i, r);
    }
}

// Heap Sort
void HeapIfyMinMax(int a[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[max]) max = l;
    if (r < n && a[r] > a[max]) max = r;
    if (max != i) {
        Swap(a[i], a[max]);
        HeapIfyMinMax(a, n, max);
    }
}

void HeapSortMinMax(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        Swap(a[0], a[i]);
        HeapIfyMinMax(a, i, 0);
    }
}

void HeapIfyMaxMin(int a[], int n, int i) {
		int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] < a[min]) min = l;
    if (r < n && a[r] < a[min]) min = r;
    if (min != i) {
        Swap(a[i], a[min]);
        HeapIfyMaxMin(a, n, min);
    }    
}

void HeapSortMaxMin(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        HeapIfyMaxMin(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Swap(a[0], a[i]);
        HeapIfyMaxMin(a, i, 0);
    }
}

// Merge Sort
void MergeMinMax(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSortMinMax(int a[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        MergeSortMinMax(a, l, mid);
        MergeSortMinMax(a, mid + 1, r);
        MergeMinMax(a, l, mid, r);
    }
}

void MergeMaxMin(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSortMaxMin(int a[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        MergeSortMaxMin(a, l, mid);
        MergeSortMaxMin(a, mid + 1, r);
        MergeMaxMin(a, l, mid, r);
    }
}

// Natural Merge Sort

void Natural_MergesortMaxMin(int a[], int n) {
    int *temp = new int[n];
    int i = 0;

    while (i < n) {
        int run_start = i;

        // Find the end of the current run
        while (i + 1 < n && a[i] >= a[i + 1]) i++;
        int run_end = i + 1;

        // If there's a next run, merge the two runs
        if (run_end < n) {
            int next_run_start = run_end;
            while (next_run_start + 1 < n && a[next_run_start] >= a[next_run_start + 1]) {
                next_run_start++;
            }
            int next_run_end = next_run_start+1;
            // Merge the two runs
            MergeMaxMin(a, run_start, run_end - 1, next_run_start);
            i = next_run_start;  // Move to the end of the next run
        } else {
            break;  // No more runs to merge
        }
    }
    delete[] temp;
}

int main() 
{
    int a[100];
    int n;
    FILE *f;
    f=fopen("D:\\C_C++\\DSA\\Sort\\file_sort.txt","r");
    if(f==NULL)
    {
    	fprintf(stderr, "Khong the mo file\n");
   		fclose(f);
   		return 1;
		}
		else
		{
			fscanf(f, "%d",&n);
 			for(int i=0; i<n; i++)
			{
				fscanf(f,"%d",&a[i]);			
			}
		}
    // Selection Sort
    cout << "\n\nSelectionSort min -> max: ";
    SelectionSortMinMax(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nSelectionSort max -> min: ";
    SelectionSortMaxMin(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Insert Sort
    cout << "\n\nInsertSort min -> max: ";
    InsertSortMinMax(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nInsertSort max -> min: ";
    InsertSortMaxMin(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Bubble Sort
    cout << "\n\nBubbleSort min -> max: ";
    BubbleSortMinMax(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nBubbleSort max -> min: ";
    BubbleSortMaxMin(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Quick Sort
    cout << "\n\nQuickSort min -> max: ";
    QuickSortMinMax(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nQuickSort max -> min: ";
    QuickSortMaxMin(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Heap Sort
    cout << "\n\nHeapSort min -> max: ";
    HeapSortMinMax(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nHeapSort max -> min: ";
    HeapSortMaxMin(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Merge Sort
    cout << "\n\nMergeSort min -> max: ";
    MergeSortMinMax(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\nMergeSort max -> min: ";
    MergeSortMaxMin(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    // Natural Merge Sort
    cout << "\n\nNatural MergeSort max -> min: ";
    Natural_MergesortMaxMin(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
        
    fclose(f);
    return 0;
}