class Solution {
public:
    bool isValid(string arra) {

        stack<char> st;

        for (int i = 0; i < arra.size(); i++)
        {
            if (arra[i] == '(' || arra[i] == '{' || arra[i] == '[')
            {
                st.push(arra[i]);
            }
            else
            {
                if (st.size() == 0)
                {
                    return false;
                }

                if (st.top() == '(' && arra[i] == ')' ||
                    st.top() == '{' && arra[i] == '}' ||
                    st.top() == '[' && arra[i] == ']')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};