#include<iostream>
using namespace std;
struct Node {
        int coeff;
        int pow;
        Node* next;
};
Node* newNode(int coeff, int pow) {
        Node* node = new Node;
        node->coeff = coeff;
        node->pow = pow;
        node->next = nullptr;
        return node;
}
void insert (Node*& poly,int coeff,int pow) {
        Node* node = newNode(coeff,pow);
        if(!poly) {
                poly = node;
        }
        else {
                Node* temp = poly;
                while(temp->next)
                        temp = temp->next;
                temp->next = node;
        }
}
Node* addPolynomials(Node* poly1,Node* poly2) {
        Node* result = nullptr;
        Node* temp = nullptr;
        while(poly1 && poly2) {
                if(poly1->pow > poly2->pow) {
                        insert(result, poly1->coeff, poly2->pow);
                        poly1 = poly1->next;
                }
                else if(poly1->pow < poly2->pow) {
                        insert(result, poly2->coeff, poly2->pow);
                        poly2 = poly2->next;
                }
                else {
                        int sum = poly1->coeff + poly2->coeff;
                        if(sum!=0)
                                insert(result, sum, poly1->pow);
                        poly1 = poly1->next;
                        poly2 = poly2->next;
                }
        }
        while(poly1) {
                insert(result, poly1->coeff, poly1->pow);
                poly1 = poly1->next;
        }
        while(poly2) {
                insert(result, poly2->coeff, poly2->pow);
                 poly2 = poly2->next;
        }
        return result;
}
void printPoly(Node* poly) {
        while(poly) {
                cout << poly->coeff << "x^" << poly->pow;
                poly = poly->next;
if(poly)
        cout << " + ";
        }
        cout << endl;
}
int main() {
        Node* poly1 = nullptr;
        Node* poly2 = nullptr;
        insert(poly1, 10, 4);
        insert(poly1, 4, 2);
        insert(poly1, 3, 0);
        insert(poly2, 10, 2);
        insert(poly2, 10, 0);
        cout << " First Polynomial: ";
        printPoly(poly1);
        cout << " Second Polynomial: ";
        printPoly(poly2);
        Node* sum =addPolynomials(poly1,poly2);
        cout << "Sum of Polynomials: ";
        printPoly(sum);
}
Polynomials.cpp
Displaying Polynomials.cpp.
