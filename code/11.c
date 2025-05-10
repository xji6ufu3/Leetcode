// Two Pointer Approach
// Time Complexity: O(n)

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int width = right - left;
        int minHeight = (height[left] < height[right]) ? height[left] : height[right];
        int area = width * minHeight;

        if (area > maxArea) {
            maxArea = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}