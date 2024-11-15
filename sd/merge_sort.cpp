#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void bubbleSort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		bool swapped = false;
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = true;
			}
		}
		if(!swapped)
		break;
	}	
}

void insertionSort(int arr[],int size){
	for(int i=1;i<size;i++){
            int current = arr[i];
            int j = i-1;

            while(j>=0 && current < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            
            arr[j+1] = current;
        }
}

int partition(int arr[], int low, int high) {
  
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
  
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void display(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int min(int x, int y) { return (x <= y) ? x : y; }
 
int fiboSearch(int arr[], int x, int n)
{
    
    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 
 
    
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    int offset = -1;
 
    while (fibM > 1) {
       
        int i = min(offset + fibMMm2, n - 1);
 
        
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        
        else
            return i;
    }
 
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;
        
    return -1;
}


int main() {
    int size;
    int arr[size];

	cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int choice,num,found,ind;

    do {
    	
        cout << "\nMenu\n";
        cout << "1. Bubble Sort \n";
        cout << "2. Merge Sort \n";
        cout << "3. Insertion Sort \n";
        cout << "4. Quick Sort \n";
        cout << "5. Display the array\n";
        cout << "6. Binary Search\n";
        cout << "7. Fibonacci Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	case 1:
        		bubbleSort(arr,size);
        		cout<< "Array sorted.\n";
        		break;
            case 2:
                sort(arr, 0, size - 1);
                cout << "Array sorted.\n";
                break;
            case 3:
        		insertionSort(arr,size);
        		cout<< "Array sorted.\n";
        		break;
        	case 4:
        		quickSort(arr,0,size-1);
        		cout<< "Array sorted.\n";
        		break;
            case 5:
                display(arr, size);
                break;
            case 6:
            	cout << "Enter element to be searched : ";
            	cin>>num;
        		found = binarySearch(arr,0,size-1,num);
        		cout<< "Element found at "<<found<<".\n";
        		break;	
        	case 7:
        		cout << "Enter element to be searched : ";
            	cin>>num;
        		ind = fiboSearch(arr,num,size);
        		if(ind>=0)
    				cout << "Found at index: " << ind;
  				else
    				cout << num << " isn't present in the array";
        		break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

