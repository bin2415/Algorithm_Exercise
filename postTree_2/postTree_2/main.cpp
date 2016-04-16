#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void post_tree(string s1, string s2)
{
	int length = s1.length();
	if (length < 1) return;
	char root = s1[0];
	
	int charAt = s2.find_first_of(root);
	string tempS11 = s1.substr(1, charAt);
	string tempS21 = s2.substr(0, charAt);
	
	int secendLength = length - charAt - 1;
	string tempS12 = s1.substr(charAt + 1, secendLength);
	string tempS22 = s2.substr(charAt + 1, secendLength);

	post_tree(tempS12, tempS22);
	post_tree(tempS11, tempS21);
	printf("%c", root);
	//return post_tree(tempS12, tempS22).append(post_tree(tempS11, tempS21)) += root;

}
int main(int argc, char** argv)
{
	string s1, s2;
	cin >> s1;
	cin >> s2;

	//string result = 
	post_tree(s1, s2);
	printf("\n");
	//cout << result << endl;
	return 0;
}
