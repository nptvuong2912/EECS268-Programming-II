/**
*	@file : Sorts.hpp
*	@author : Vuong Nguyen
*	@date : 2015.04.01
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
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
	
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

template<typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
	std::default_random_engine generator(time(nullptr));
	
    	while (!isSorted(arr, size))
    	{
    	    shuffle(arr, size, generator);
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

