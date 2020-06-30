/* difficult ques - such ques are often asked with different format but same kind of forming string combinations */
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool isValid(string ip) {
    //split each section that are separated by '.'
    vector<string> ips;
    string ex = "";

    for(int i=0; i<ip.size(); i++) {
        if(ip[i]=='.') {
            ips.push_back(ex);
            ex = "";    //start next sextion
        }
        else {
            ex = ex + ip[i];
        }
    }

    ips.push_back(ex);      //last section

    for(int i=0; i<ips.size(); i++) {
        if(ips[i].length()>3 || stoi(ips[i])<0 || stoi(ips[i])>255)
            return false;
        
        if(ips[i].length()>1 && stoi(ips[i])==0)
            return false;

        if(ips[i].length()>1 && stoi(ips[i])!=0 && ips[i][0]=='0')
            return false;
    }

    return true;
}

void makeIP(string ip) {
    int l = ip.length();

    if(l>12 || l<4)         //not possible to make IP address
        return;

    string check = ip;
    vector<string> ans;

    for(int i=1; i<l-2; i++) {
        for(int j=i+1; j<l-2; j++) {
            for(int k=j+1; k<l; k++) {
                check = check.substr(0,k) + "." + check.substr(k,l-k+2);
                check = check.substr(0,j) + "." + check.substr(j, l-j+3);
                check = check.substr(0,i) + "." + check.substr(i, l-i+4);

                if(isValid(check))      //perform validations 
                {
                    ans.push_back(check);
                    cout << check << endl;
                }
                check = ip;
            }
        }
    }
}

int main() {
    string A;
    cin >> A;

    makeIP(A);

    return (0);
}