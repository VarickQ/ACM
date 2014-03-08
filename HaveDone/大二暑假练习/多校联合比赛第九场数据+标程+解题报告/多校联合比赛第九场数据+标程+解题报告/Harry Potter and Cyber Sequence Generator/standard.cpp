#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>


const int mod = 1000000007;
int T;
int C1, C2;

int str_to_int(const char *str){
		int k;
		sscanf(str, "%d", &k);
		return k;
}


const struct Mat{
		long long  a[3][3];
} I = {{{1,0,0}, {0,1,0}, {0,0,1}}};

struct Bignum_t{
		int data[400];
		int len;
		static const int piece = 100000000;
		static const int half  =  piece >> 1;
		Bignum_t(int k){
				memset(data, 0, sizeof(data));
				data[len = 0] = k;
		}
		Bignum_t(char *str){
				int n = strlen(str);
				int start = n - 8;
				len = -1;
				while(start > 0){
						data[++len] = str_to_int(&str[start]);
						str[start]=0;
						start-= 8;
				}
				if (start < 0) {
						start = 0;
					    data[++len] = str_to_int(&str[start]);
				}
		}
		int rbit() const {				//the last bit
				return data[0] & 1;
		}
		void rshift_inplace(){
				int carry = 0;
				for(int i=len; i>=0; --i){
						carry *= piece;
						int newcarry = (data[i] + carry) & 1;
						data[i] = (data[i] + carry) >> 1;
						carry = newcarry;
				}
				while(data[len] == 0 && len > -1) --len;
		}
		void print(){
				printf("%d", data[len]);
				for(int i=len-1; ~i; --i)
						printf("%08d", data[i]);
				puts("");

		}
};

Mat unit;
Mat mul(Mat a, Mat b){
		Mat c = {};
		for(int i=0; i<3; ++i)
				for(int j=0; j<3; ++j){
						long long val = 0;
						for(int k=0; k<3; ++k){
								val += a.a[i][k] % mod * b.a[k][j] % mod;
								if (val >= mod) val %= mod;
						}
						c.a[i][j] = val % mod ;  
				}
		return c;
}

Mat pwr(Mat a, Bignum_t &b){
		Mat d = I, c = a;
		while(~b.len){
				if (b.rbit()) d = mul(d, c);
				c = mul(c, c);
				b.rshift_inplace();
		}
		return d;
}

char s1[10], s2[10], s3[10], s[40];
Mat gen_mat(int col, int x1, int x2, int x3){	//=>assemble matrix?
		Mat p = I;
		p.a[0][col] = x1 % mod;
		p.a[1][col] = x2 % mod;
		p.a[2][col] = x3 % mod;
		return p;
}

void compile(){
		int col = s2[1] - '1'; //C1 => 0, C2 => 1
		int val;
		int op2;
		switch(s1[0]){	   
				case 'M':
						val = str_to_int(s3);
						unit = mul(unit, gen_mat(col, !col * val, col * val, 0));
						break;
				case 'S':
						if(s3[0]=='C'){
								op2 = s3[1]-'1';//C1 => 0, C2 => 1
								unit = mul(unit, gen_mat(col, !op2, op2, 0));
						}else{
								val = str_to_int(s3);
								unit = mul(unit, gen_mat(col, 0, 0, val));
						}
						break;
				case 'A':
						if(s3[0]=='C'){
								op2 = s3[1]-'1';//C1 => 0, C2 => 1
								unit = mul(unit, gen_mat(col, !op2 + !col, op2 + col, 0));
						}else{
								val = str_to_int(s3);
								unit = mul(unit, gen_mat(col, !col, col, val));
						}	
						break;
				default:
						;
		}
}


void to_compile(){
		scanf("%d\n", &C1);
		C2 = 0;
		unit = I;
		while(strcmp(gets(s), "END")){
				sscanf(s, "%s %s%s", s1, s2, s3);
				compile();
		}
}

char str[1024];
int ncase = 0;
void to_run(){	
		printf("Case %d:\n", ++ncase);
		int Q;
		scanf("%d\n", &Q);
		while(Q--){
				Bignum_t x = gets(str);
				Mat q = pwr(unit, x);
				//C1 * q[0][1] + C2 * q[1][1] + 1 * q[2][1]
				long long ans = C1 * q.a[0][1] % mod + q.a[2][1] % mod;
				printf("%d\n", (int)(ans % mod));
		}
}

void go(){
		to_compile();
		to_run();
}

int main(){	
     //   freopen("C:\\stdin1.txt", "r", stdin);
     //   freopen("C:\\stdout1.txt", "w", stdout);
     freopen("data.in","r",stdin);
     freopen("1003.out","w",stdout);
		scanf("%d", &T);
		while(T--) {
				go();
		} 
	//	fprintf(stderr, "here");
	//	while(1);
}

