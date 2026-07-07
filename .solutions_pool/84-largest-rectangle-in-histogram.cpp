#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea_01(vector<int>& heights) {
    if (heights.size() == 0) return 0;

    
    vector<int> left(heights.size()); 
    vector<int> right(heights.size());

    right[heights.size() - 1] = heights.size();
    left[0] = -1;

    for (int i = 1; i < heights.size(); i++) {
        int l = i - 1;
        while (l >= 0 && heights[l] >= heights[i]) {
            l--;
        }
        left[i] = l;
    }

    for (int i = heights.size() - 2; i >= 0; i--) {
        int r = i + 1;
        while (r < heights.size() && heights[r] >= heights[i]) {
            r++;
        }
        right[i] = r;
    }

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
    }

    return maxArea;        

}

int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    
    vector<int> stack;
    
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<height.size(); i++){
        
        if ( stack.size()<=0 || height[i] >= height[stack.back()] ) {
            stack.push_back(i);
            continue;
        }
        
        
        
        int topIdx = stack.back();
        stack.pop_back();
        int area = height[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
        
        i--;
    }

    return maxArea;
}

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}
void test(int a[], int n)
{
    vector<int> v(a, a + n);
    printArray(v);
    cout << largestRectangleArea(v) << endl;
}

int main()
{
#define TEST(a) test(a, sizeof(a)/sizeof(int))

    int a0[] = {2,1,3,1};
    TEST(a0);
    int a1[] = {2,1,5,6,2,3};
    TEST(a1);

    return 0;
}