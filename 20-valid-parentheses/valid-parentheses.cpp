class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
       for(int i = 0; i < s.length(); i++) {

        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(st.empty()) 
                return false;
            else if(st.top() == '(' && s[i] == ')') 
                st.pop();
            else if(st.top() == '{' && s[i] == '}') 
                st.pop();
            else if(st.top() == '[' && s[i] == ']') 
                st.pop();
            else return false; // for absence of this else condition my logic was failing for ([) case. When iterating over s[i] == ']', it skipped and move on to ')', so it got popped, and then returned true. So write algorithm for checking every element.
        }
            
        // else if(st.top() == '(' && s[i] == ')') // I was doing mistake for this condition in all cases, here I put s[i] = ( and { and [ instead of ) and } and ]
        //     return true;
        // else if(st.top() == '{' && s[i] == '}')
        //     return true;
        // else if(st.top() == '[' && s[i] == ']')
        //     return true;
        // else 
        //     return false;
        // ans = return;
       }
        return st.empty();
    }
};