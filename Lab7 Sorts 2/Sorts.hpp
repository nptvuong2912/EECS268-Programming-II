/**
*	@file : Sorts.hpp
*	@author : Vuong Nguyen
*	@date : 2015.04.08
*	Purpose: Implementation of Sorts class
*/

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
	
	assert( Sorts<T>::isSorted(arr, size) );
}

template<typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    for (int unsorted = 1; unsorted < size; unsorted++)
    {
        for (int k = unsorted; k > 0; k--)
        {
            if (arr[k] < arr[k-1])
            {
                T temp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp;
            }
        }
    }
	assert( Sorts<T>::isSorted(arr, size) );
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    if (size >= 2)
    {
        int sizeLeft = size / 2;
        int sizeRight = size - sizeLeft;
        T* left = arr + 0;
        T* right = arr + size/2;
        mergeSort(left, sizeLeft);
        mergeSort(right, sizeRight);
        merge(left, right, sizeLeft, sizeRight);
        for (int i = 0; i < size; i++)
        {
            arr[i] = left[i];
        }
    }
}

template<typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    quickSortRec(arr, 0, size-1, false);
}

template<typename T>
void Sorts<T>::quickSortMedian(T arr[], int size)
{
    quickSortRec(arr, 0, size-1, true);
}


template<typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        T min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        T temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
	assert( Sorts<T>::isSorted(arr, size) );
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
    bool check = true;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            check = false;
            return check;
        }
    }
    return check;
}

template<typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	start = std::chrono::system_clock::now();
	
	sort(arr, size);
	end = std::chrono::system_clock::now();
	elapsed = end - start;
	return (elapsed.count());
}

template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
    if (size1 >= 1)
    {
        int size = size1 + size2;
        T* merged = new T[size];
        int count1 = 0;
        int count2 = 0;
        int count = 0;
        while (count1 < size1 && count2 < size2)
        {
            if (a1[count1] <= a2[count2])
            {
                merged[count] = a1[count1];
                count1++;
            }
            else
            {
                merged[count] = a2[count2];
                count2++;
            }
            count++;
        }
        if (count1 == size1)
        {
            for (int i = count2; i < size2; i++)
            {
                merged[count] = a2[i];
                count++;
            }
        }
        if (count2 == size2)
        {
            for (int i = count1; i < size1; i++)
            {
                merged[count] = a1[i];
                count++;
            }
        }
        for (int i = 0; i < size; i++)
        {
            a1[i] = merged[i];
        }
        delete[] merged;
    }
}

template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
    if (first < last)
    {
        int pivotIndex = partition(arr, first, last, median);
		quickSortRec(arr, first, pivotIndex - 1, median);
		quickSortRec(arr, pivotIndex + 1, last, median);
    }
}

template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
    int middle = (first+last)/2;
    int median;
    if ((arr[first] <= arr[middle] && arr[last] >= arr[middle]) || (arr[first] >= arr[middle] && arr[last] <= arr[middle]))
    {
        median = middle;
    }
    else if ((arr[middle] <= arr[first] && arr[last] >= arr[first]) || (arr[middle] >= arr[first] && arr[last] <= arr[first]))
    {
        median = first;
    }
    else
    {
        median = last;
    }
    T temp = arr[median];
    arr[median] = arr[last];
    arr[last] = temp;
}

template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    if (median == true)
    {
        setMedianPivot(arr, first, last);
    }
    T pivot = arr[last];
    int storeIndex = first;
    for (int i = first; i < last; i++)
    {
        if (arr[i] <= pivot)
        {
            T temp = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = temp;
            storeIndex ++;
        }
    }
    T temp = arr[last];
    arr[last] = arr[storeIndex];
    arr[storeIndex] = temp;
    return storeIndex;
}

template<typename T>
void Sorts<T>::shuffle(T arr[], int size)
{
	static std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(0,(size-1));

	int randomIndex = 0;
	for (int i=0; i<size; i++)
	{
		randomIndex = distribution(generator);
		T temp = arr[i];
		arr[i] = arr[randomIndex];
		arr[randomIndex] = temp;
	}
	
}



