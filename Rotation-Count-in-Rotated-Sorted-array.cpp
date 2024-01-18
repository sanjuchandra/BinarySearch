// GFG link -> https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

// My linked in profile -> https://www.linkedin.com/in/sanju-chandra-89a54018b/
int findKRotation(int arr[], int n) {
    int low = 0, high = n - 1;

    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
            return mid; // found the minimum element
        } else if (arr[mid] >= arr[low]) {
            // left part is sorted
            // i will store the minimum from it and eliminate it
            if(arr[ans] > arr[low]){
            	ans = low;
            }
            low = mid + 1;
        } else {
        	// right part is sorted
            // i will store the minimum from it and eliminate it
            if(arr[ans] > arr[high]){
            	ans = high;
            }
            high = mid - 1;
        }
    }

    return ans;
}




