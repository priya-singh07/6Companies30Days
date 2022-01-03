// Decode the string

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ']') {
            string t;
            while (!st.empty() && st.top() != '[') {
                t = st.top() + t;
                st.pop();
            }
            st.pop();
            string num;
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int number = stoi(num);
            string repeat;
            for (int j = 0; j < number; j++)
                repeat += t;
            for (char c : repeat)
                st.push(c);
        }
        else
            st.push(s[i]);
    }
    string currstr;
    while (!st.empty()) {
        currstr = st.top() + currstr;
        st.pop();
    }
    return currstr;
    }
};