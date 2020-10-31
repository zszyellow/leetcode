/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode *dummy = new PolyNode();
        PolyNode *cur = dummy;
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                cur->next = poly1;
                cur = cur->next;
                poly1 = poly1->next;
            } else if (poly1->power == poly2->power) {
                poly1->coefficient += poly2->coefficient;
                if (poly1->coefficient != 0) {
                    cur->next = poly1;
                    cur = cur->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else {
                cur->next = poly2;
                cur = cur->next;
                poly2 = poly2->next;
            }
        }
        if (!poly1 && !poly2) {
            cur->next = nullptr;
        }
        
        while (poly1) {
            cur->next = poly1;
            cur = cur->next;
            poly1 = poly1->next;
        }
        while (poly2) {
            cur->next = poly2;
            cur = cur->next;
            poly2 = poly2->next;
        }
        return dummy->next;
    }
};