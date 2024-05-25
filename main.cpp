#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

// Initialize the size
// with the total numbers to sorted
// and the gap to be maintained in graph
vector<int> numbers;
int size = 200;
int gap = 4;

// Function for swapping the lines graphically
void swap_colors(int i, int j, int x, int y)
{
    // y is the minimum element,
    // first make this number green
    // Now, swapping it by making black again
    // and then draw the pixels
    // for white colour with x value.
    setcolor(GREEN);
    line(j, size, j, size - y);

    delay(500);

    setcolor(BLACK);
    line(j, size, j, size - y);

    setcolor(WHITE);
    line(j, size, j, size - x);

    // X is the element to be swapped,
    // first make this number black
    // Now, highlight y with green
    // representing the minimum element
    // and then draw the pixels
    // for white colour with y value.
    setcolor(BLACK);
    line(i, size, i, size - x);

    setcolor(GREEN);
    line(i, size, i, size - y);

    delay(500);

    setcolor(WHITE);
    line(i, size, i, size - y);
}

// Selection sort function
void selsort()
{
    for (int i = 0; i < size - 1; i++)
    {

        // Find the minimum element
        // in unsorted array
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element
        // with the first element
        // delay(500);
        swap(&numbers[min_idx], &numbers[i]);

        // Function to show transition in swapping
        swap_colors(gap * i + 1,
                    gap * (min_idx) + 1,
                    numbers[min_idx],
                    numbers[i]);
    }
}

// Bubble sort function
void bubbleSort()
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (numbers[j] > numbers[j+1])
            {
                swap(&numbers[j], &numbers[j+1]);
                swap_colors(gap * j + 1, gap * (j+1) + 1, numbers[j+1], numbers[j]);
            }
        }
    }
}

// Insertion sort function
void insertionSort()
{
    for (int i = 1; i < size; i++)
    {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            swap_colors(gap * (j+1) + 1, gap * j + 1, numbers[j], key);
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

// Function to merge two halves
void merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = numbers[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = numbers[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            numbers[k] = L[i];
            swap_colors(gap * k + 1, gap * (l+i) + 1, L[i], numbers[k]);
            i++;
        }
        else
        {
            numbers[k] = R[j];
            swap_colors(gap * k + 1, gap * (m+1+j) + 1, R[j], numbers[k]);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        numbers[k] = L[i];
        swap_colors(gap * k + 1, gap * (l+i) + 1, L[i], numbers[k]);
        i++;
        k++;
    }

    while (j < n2)
    {
        numbers[k] = R[j];
        swap_colors(gap * k + 1, gap * (m+1+j) + 1, R[j], numbers[k]);
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }
}

// Partition function for QuickSort
int partition(int low, int high)
{
    int pivot = numbers[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (numbers[j] < pivot)
        {
            i++;
            swap(&numbers[i], &numbers[j]);
            swap_colors(gap * i + 1, gap * j + 1, numbers[j], numbers[i]);
        }
    }
    swap(&numbers[i + 1], &numbers[high]);
    swap_colors(gap * (i + 1) + 1, gap * high + 1, numbers[high], numbers[i + 1]);
    return (i + 1);
}

// Quick sort function
void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Driver program
int main()
{
    // auto detection of screen size
    int gd = DETECT, gm;
    int wid1;

    // Graph initialization
    initgraph(&gd, &gm, NULL);

    // setting up window size (gap*size) * (size)
    wid1 = initwindow(gap * size + 1, size + 1);
    setcurrentwindow(wid1);

    // Initializing the array
    for (int i = 1; i <= size; i++)
        numbers.push_back(i);

    // Find a seed and shuffle the array
    // to make it random.
    // Here  different type of array
    // can be taken to results
    // such as nearly sorted, already sorted,
    // reverse sorted to visualize the result
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));

    // Initial plot of numbers in graph taking
    // the vector position as x-axis and its
    // corresponding value will be the height of line.
    for (int i = 1; i <= gap * size; i += gap)
    {
        line(i, size, i, (size - numbers[i / gap]));
    }

    // Delay the code
    delay(200);

    // Uncomment one of the following lines to test each sort
    selsort();
    // bubbleSort();
    // insertionSort();
    // mergeSort(0, size - 1);
    // quickSort(0, size - 1);

    // Wait for sometime .
    delay(5000);

    // Close the graph
    closegraph();

    return 0;
}
