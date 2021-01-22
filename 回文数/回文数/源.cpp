#define _CRT_SECURE_NO_WARNINGS 1
bool isPalindrome(int x){
	long sum = 0;
	int m = x;
	if (x<0){
		return false;
	}
	while (x>0){
		sum = sum * 10 + x % 10;
		x /= 10;
	}
	if (sum == m){
		return true;
	}
	else{
		return false;
	}
}
