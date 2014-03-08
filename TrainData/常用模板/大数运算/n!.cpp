//http://www.acm.inf.ethz.ch/ProblemSetArchive/B_EU_CERC/1999/solution.html
#include <vector>
#include <cmath>        // log10
#include <cstdlib>      // strtol
#include <algorithm>    // for_each
#include <iostream>
#include <iomanip>      // setw, setfill

using namespace std;

void print4d(int d)
{
    cout << setw(4) << setfill('0') << d;
}

int main(int argc, char* argv[])
{
    int n;
    if (1 == argc) {
loop:    cout << "Input N = ";
        cin >> n;
		if (0 == n)
			return 0;

    } else { // get n from command line
        n = strtol(argv[1], (char **)NULL, 10);
    }

    vector<int> fac;
    fac.push_back(1);

    for (int j = 1; j <= n; ++j) {
        int carry = 0;
        for (vector<int>::iterator i = fac.begin(); i != fac.end(); ++i) {
            int product = *i * j + carry;
            carry = product / 10000;
            *i = product - carry * 10000;
        }
        if (carry > 0) {
            fac.push_back(carry);
        }
    }

    cout << *fac.rbegin();
    for_each(fac.rbegin() + 1, fac.rend(), print4d);

    int digits = 4 * fac.size() + int(log10(double(*fac.rbegin()))) - 3;
    cout << "\nTotal: " << digits << " digits\n";
	cout<<endl ;
	cout << "End with Input number 0"<<endl; 
	goto loop;
	return 0;
}
