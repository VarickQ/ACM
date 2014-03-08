#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 2000000000;
const int N = 2000;

bool arr[26],bed[26];
char str[N];
int main(){
	int n;
	while(scanf("%d",&n) && n){
		memset(arr,0,sizeof(arr));
		memset(bed,0,sizeof(bed));
		scanf("%s",str);
		int used = 0,ans = 0;
		for(int i=0 ; str[i] ; ++i){
			if(arr[str[i]-'A'] || bed[str[i]-'A']){
				if(used < n){
					if(bed[str[i]-'A']){
						arr[str[i]-'A'] = false;
						bed[str[i]-'A'] = false;
						used--;
					} else {
						bed[str[i]-'A'] = true;
						used++;
					}
				} else {
					if(bed[str[i]-'A']){
						arr[str[i]-'A'] = false;
						bed[str[i]-'A'] = false;
						used--;
					} else {
						arr[str[i]-'A'] = false;
						ans++;
					}
				}
			} else {
				if(used < n){
					bed[str[i]-'A'] = true;
					used++;
				} else {
					arr[str[i]-'A'] = true;
					bed[str[i]-'A'] = false;
				}
			}
		}
		if(ans == 0)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n",ans);
	}
	return 0;
}