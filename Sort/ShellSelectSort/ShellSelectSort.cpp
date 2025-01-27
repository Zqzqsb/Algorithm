#include <iostream>
#include <vector>
using namespace std;

void shell_sort(vector<int>& v) {
    // 初始步长设为数组长度的一半，每次减半
    for(int gap = v.size() / 2; gap > 0; gap /= 2) {
        // 对每个子序列进行插入排序
        for(int i = gap; i < v.size(); i++) {
            int temp = v[i];
            int j = i;
            // 在子序列中进行插入排序
            while(j >= gap && v[j - gap] > temp) {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = temp;
        }
    }
}

// 打印数组
void print_array(const vector<int>& v) {
    for(int i : v)
        cout << i << " ";
    cout << endl;
}

// 运行测试用例
void run_test_case(vector<int> v, string test_name) {
    cout << test_name << "排序前：";
    print_array(v);
    
    shell_sort(v);
    
    cout << test_name << "排序后：";
    print_array(v);
    cout << endl;
}

int main() {
    // 测试用例1：随机数据
    vector<int> test1 = {37, 33, 42, 28, 46, 5, 6, 8, 81, 23, 28, 66, 47, 1, 58, 80, 29, 67, 95, 97};
    cout << "=== 测试用例1：随机数据 ===" << endl;
    run_test_case(test1, "随机数据");
    
    // 测试用例2：逆序数据
    vector<int> test2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "\n=== 测试用例2：逆序数据 ===" << endl;
    run_test_case(test2, "逆序数据");
    
    // 测试用例3：部分有序数据
    vector<int> test3 = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
    cout << "\n=== 测试用例3：部分有序数据 ===" << endl;
    run_test_case(test3, "部分有序数据");
    
    // 测试用例4：重复元素数据
    vector<int> test4 = {4, 2, 4, 1, 3, 2, 4, 2, 1, 3};
    cout << "\n=== 测试用例4：重复元素数据 ===" << endl;
    run_test_case(test4, "重复元素数据");
    
    // 测试用例5：已排序数据
    vector<int> test5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "\n=== 测试用例5：已排序数据 ===" << endl;
    run_test_case(test5, "已排序数据");
    
    return 0;
}
