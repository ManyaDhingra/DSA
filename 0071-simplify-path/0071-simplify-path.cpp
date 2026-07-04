class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        string dir = "";
        int n = path.size();
        for(int i = 0 ; i <= n ; i++){
            if(i == path.size() || path[i] == '/'){
                if(dir == "" || dir == "."){

                }
                else if(dir == ".."){
                    if(!stack.empty()){
                        stack.pop();
                    }
                }
                else{
                    stack.push(dir);
                }

                dir = "";
            }
            else{
                dir += path[i];
            }
    
        }

        if(stack.empty()){
            return "/";
        }

        vector<string> temp;
        while(!stack.empty()) {
            temp.push_back(stack.top());
            stack.pop();
        }

        reverse(temp.begin(), temp.end());
        string ans = "";

        for(string s : temp) {
            ans += "/" + s;
        }
       

        return ans;

        
    }
};