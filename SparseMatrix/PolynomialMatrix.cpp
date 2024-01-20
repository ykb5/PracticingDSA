#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int coe;
    int exp;
    node* next;
};

void insert(node*& poly, int coe, int exp) {
    node* newNode = new node;
    newNode->coe = coe;
    newNode->exp = exp;
    newNode->next = nullptr;

    if(!poly)
        poly = newNode;
    else {
        node* temp = poly;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(node* poly) {
    if(!poly) {
        cout << "Polynomial is empty." << endl;
    }
    else {
        node* temp = poly;
        cout << "Polynomial: ";
        while(temp) {
            cout << temp->coe << "x^" << temp->exp;
            if(temp->next)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
}

double evaluate(node* poly, int x) {
    double res = 0;
    node* temp = poly;
    while(temp) {
        res += temp->coe * pow(x, temp->exp);
        temp = temp->next;
    }
    return res;
}

int main() {
    node* poly = nullptr;
    int n;
    cout << "Enter the no. of terms: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        int coe, exp;
        cout << "Enter coefficient for term " << i+1 << ": ";
        cin >> coe;
        cout << "Enter exponent for term " << i+1 << ": ";
        cin >> exp;
        insert(poly, coe, exp);
    }
    display(poly);

    int x;
    double res = 0;
    cout << "Enter the value of x to evaluate: ";
    cin >> x;
    res = evaluate(poly, x);
    cout << "Result is: "<< res << endl;

    return 0;
}