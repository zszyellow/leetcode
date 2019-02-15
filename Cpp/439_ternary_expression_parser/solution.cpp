class Solution {
public:
    string parseTernary(string expression) {
        if (expression.size() == 1) return expression;
        int pos = expression.find('?');
        
        int i = pos;
        for (int cnt = 0; i < expression.size(); i ++) {
            if (expression[i] == '?') cnt ++;
            if (expression[i] == ':') cnt --;
            if (cnt == 0) break;
        }
        
        string t = parseTernary(expression.substr(pos+1, i-pos-1));
        string f = parseTernary(expression.substr(i+1));
        
        return expression[0] == 'T' ? t : f;
    }
};