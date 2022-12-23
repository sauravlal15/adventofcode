#include <bits/stdc++.h>

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int min(int a, int b) { return (a < b) ? a : b; }

/*************************************************************************/

void countPrimes(int n, vector<int>& count) {
    vector<bool>prime(n+1, true);
    prime[0]=false;
    prime[1]=false;
    int cnt=0;
    for(int i=2;i<n;i++){
        for(int j=2*i;j<n;j=j+i){
            prime[j]=false;
        }
    }
    count[0]=0;
    for(int i=1; i<=1e4; i++) {
        count[i] = count[i-1] + (prime[i]==true);
    }
}

int calc(char ch) {
    if(ch>='a' and ch<='z')
        return ch - 'a' + 1;
    return ch - 'A' + 27;
}

int checkRange(int ff, int fs, int sf, int ss) {
    // 1st part
    if(ff>=sf and ff<=ss)
        return 1;
    if(sf>=ff and sf<=fs)
        return 1;
    return 0;
}

void operationNewMove(vector<stack<char>>& vect, vector<int>& number) {
    string temp = "";
    while(number[0]) {
        temp += vect[number[1]].top();
        vect[number[1]].pop();
        number[0]--;
    }
    reverse(temp.begin(), temp.end());
    for(auto x:temp)
        vect[number[2]].push(x);
}

void operationMove(vector<stack<char>>& vect, vector<int>& number) {
    while(number[0]) {
        char temp = vect[number[1]].top();
        vect[number[1]].pop();
        vect[number[2]].push(temp);
        number[0]--;
    }
}

void extractNumber(vector<int>& vect, string str) {
    int i=0;
    int no=-1;
    while(i<str.size()) {
        if(str[i]>='0' and str[i]<='9') {
            if(no==-1)
                no=0;
            no = no*10 + (str[i]-'0');
        } else  {
            if(no!=-1) {
                vect.push_back(no);
                no=-1;
            }
        }
        i++;
    }
    if(no!=-1) {
        vect.push_back(no);
        no=-1;
    }
}

int32_t main()
{
    int flag=0;
    string str, stackStr[20];
    int score=0;
    vector<stack<char>> vect;
    while(getline(cin, str)) {
        if(str.size()>0 and str[0]!='m') {
            int i=1, j=1;
            while(i<str.size()) {
                if(str[i]!=' ')
                    stackStr[j] += str[i];
                i+=4;
                j++;
            }
        }
        else if(str.size()==0) {
            // built stack
            int k=1;
            for(auto x: stackStr) {
                reverse(x.begin(), x.end());
                int i=0, j=0, no=0; 
                while(x[j]>='0' and x[j]<='9') {
                    no = no*10 + (x[j]-'0');
                    j++;
                }
                stack<char> st;
                for(auto y: x)
                    st.push(y);
                
                vect.push_back(st);
            }
            // for(auto x: vect)
            //     if(x.size())
            //         cout<<x.top()<<" ";
        }
        else {
            vector<int> number;
            extractNumber(number, str);
            operationNewMove(vect, number);
        }
    }
    for(auto x: vect)
        if(x.size())
            cout<<x.top();
    return 0;
}

