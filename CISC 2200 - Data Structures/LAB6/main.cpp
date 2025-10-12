#include <iostream>
using namespace std;


int bunnyEars2(int n){
    if (n <= 0) return 0;
    if (n % 2 == 0) return 3 + bunnyEars2(n-1);
    return 2 + bunnyEars2(n-1);

}

int sumDigits(int num){
    if (num <= 0) return 0;
    return (num % 10) + sumDigits(num / 10);

}
int rangeSum(int from, int to){
    if (from > to) return rangeSum(to, from);
    if (from == to) return from;
    return from + rangeSum(from + 1, to);
}

bool array220(int * nums,int size, int index){
    if (index >= size - 1) return false;
    if (nums[index] * 10 == nums[index + 1]) return true;
    return array220(nums, size, index + 1);
}

int triangle(int rows){
    if (rows <= 0) return 0;
    return rows + triangle(rows - 1);
}

int array11(int * nums, int size, int index){
    if (index >= size) return 0;
    int add = (nums[index] == 11) ? 1 : 0;
    return add + array11(nums, size, index + 1);
}

int main() 
{

    return 0;
}