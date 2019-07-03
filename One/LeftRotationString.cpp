#include <iostream>
#include <string>
using namespace std;

// 定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部，如把字符串abcdef左旋转2位得到字符串cdefab。请实现字符串左旋转的函数。
void rotate(string &str, int m){
    if(str.length() == 0 || m <= 0){
        return;
    }
    int n = str.length();
    if (m % n <= 0)
    {
        return;
    }
    int p1 = 0, p2 = m;
    int k = (n-m) - n % m;
    
    while (k--)
    {
        swap(str[p1], str[p2]);
        p1++;
        p2++;
    }

    int r = n - p2;
    while (r--)
    {
        int i = p2;
        while(i > p1){
            swap(str[i],str[i-1]);
            i--;
        }
        p2++;
        p1++;
    }

}

int main(int argc, char const *argv[])
{
    string ch = "abcdefghijk";
    rotate(ch,3);
    cout<<ch<<endl;
    return 0;
}

