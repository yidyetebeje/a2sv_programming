//{ Driver Code Starts
// Heap Sort in C
#include <stdio.h>
  
// Function to swap the the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
// } Driver Code Ends
//User function Template for C


void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  // If the largest element is not the root
  if (largest != i) {
    // Swap the largest element with the root
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    // Recursively heapify the affected subtree
    heapify(arr, n, largest);
  }
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
    // Build max heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
  // Iterate through the array and remove the root element
  for (int i = n - 1; i >= 0; i--) {
    // Swap the root element with the last element
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Heapify the reduced heap
    heapify(arr, i, 0);
  }

}

//{ Driver Code Starts.
  
// Driver code
int main() {
    int t;
    scanf("%d",&t);
    while (t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    buildHeap(arr, n);
    printArray(arr, n);
    }
  }
// } Driver Code Ends