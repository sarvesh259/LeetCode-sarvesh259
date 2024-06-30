class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        class UnionFind{
        public:
            int component;
            vector<int> parent,size;
            UnionFind(int n)
            {
                component=n;
                parent.resize(n+1);
                size.resize(n+1,1);
                for(int i=0;i<=n;i++) parent[i]=i;
            }
            int find(int x)
            {
                if(parent[x]==x)
                    return x;
                return parent[x]=find(parent[x]);
            }
            bool Union(int a,int b)
            {
                int aPar=find(a);
                int bPar=find(b);
                if(aPar==bPar)
                    return false;
                if(size[aPar]<size[bPar]) swap(aPar,bPar);
                parent[bPar]=aPar;
                size[aPar]+=size[bPar];
                component--;
                return true;
            }
            bool isCon(){
                return component==1;
            }
        };
        UnionFind alice(n),bob(n);
        int edgesReq=0;
        for(auto it:edges)
        {
            if(it[0]==3)
            {
                if(alice.Union(it[1],it[2])|bob.Union(it[1],it[2])) edgesReq++;
            }
        }
        for(auto it:edges)
        {
            if(it[0]==1)
            {
                if(alice.Union(it[1],it[2])) edgesReq++;
            }
            else if(it[0]==2)
            {
                if(bob.Union(it[1],it[2])) edgesReq++;
            }
        }
        return ((alice.isCon() && bob.isCon())?edges.size()-edgesReq:-1);

    }
};