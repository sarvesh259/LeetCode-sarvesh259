class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numberOfRooms=rooms.size();
        vector<bool> checked(numberOfRooms,false);
        // checked[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            checked[temp]=true;
            for(auto it:rooms[temp])
            {
                if(!checked[it])
                {
                    q.push(it);
                }
            }
        }
        for(int i=0;i<numberOfRooms;i++)
        {
            if(!checked[i]) return false;
        }
        return true;
    }
};